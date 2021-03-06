#include "micro_types.h"
#include "pinmx.h"
#include "spi.h"
#include "clock.h"
#include "spicom.h"
#include "blink.h"


void spicom_initialize(void){
    PIN_FUNC.p0_19=0;  //select
    PIN_FUNC.p0_15=3;  //sck
    PIN_FUNC.p0_17=3;  //miso
    PIN_FUNC.p0_18=3;  //mosi
   
    PIN_MODE.p0_19=PIN_MODE_PULLDOWN;
    PIN_MODE.p0_15=PIN_MODE_PULLDOWN;
    PIN_MODE.p0_17=PIN_MODE_PULLUP;
    PIN_MODE.p0_18=PIN_MODE_PULLDOWN;

    blink_initializeOutput(0,19);
    blink_setOutput(0,19);
    
    PERIPHERAL_CLOCK_SEL0.spi=1; 
    SPI_CLOCK.clk_counter=120;    
   
    SPI_CTL.master_sel   =1;
    SPI_CTL.clk_phase    =0;
    SPI_CTL.clk_polarity =0;
    SPI_CTL.byte_order   =0;
    SPI_CTL.bits_enable  =0;
//    SPI_CTL.bit_count    =0x08;
}

//these could be function pointers
void spicom_select(void){
    //low on the output selects the chip
    blink_clearOutput(0,19);
}

void spicom_deselect(void){
    //high on the output deselects the chip
    blink_setOutput(0,19);
}

uint8_t spicom_xmit(uint8_t val){
    SPI_DATA.low=val;
    while(SPI_STATUS.xmit_complete==0){}
    return SPI_DATA.low;
} 

void spicom_recv(uint8_t *msg, uint32_t len){
    uint32_t i;
    spicom_select();
    for(i=0;i<len;i++){
        msg[i]=spicom_xmit(0xFF);
    }
    spicom_deselect();
}

void spicom_send(uint8_t *msg, uint32_t len){
    uint32_t i;
    spicom_select();
    for(i=0;i<len;i++){
        spicom_xmit(msg[i]);
    }
    spicom_deselect();
}

