#include "micro_types.h"
#include "gpio.h"
#include "pinmx.h"
#include "spi.h"
#include "clock.h"
#include "mutex.h"
#include "system.h"

/* SPI port could also be modled as a state machine
 *    

typedef struct SpiPort{
    SpiControl spi_ctl;
    SpiClock spi_clock;
    void (*select)(void); 
    void (*deselect)(void);
};

*/


void spi_initialize(void){
    PIN_FUNC.p0_19=0;  //select
    PIN_FUNC.p0_15=3;  //sck
    PIN_FUNC.p0_17=3;  //miso
    PIN_FUNC.p0_18=3;  //mosi
   
    PIN_MODE.p0_19=PIN_MODE_PULLDOWN;
    PIN_MODE.p0_15=PIN_MODE_PULLDOWN;
    PIN_MODE.p0_17=PIN_MODE_PULLUP;
    PIN_MODE.p0_18=PIN_MODE_PULLDOWN;

    PORT0_DIR.pin19=1;
    PORT0_SET.pin19=1; 
    
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
void spi_select(void){
    //low on the output selects the chip
    PORT0_CLR.pin19=1;
}

void spi_deselect(void){
    //high on the output deselects the chip
    PORT0_SET.pin19=1;
}

uint8_t spi_xmit(uint8_t val){
    SPI_DATA.low=val;
    while(SPI_STATUS.xmit_complete==0){}
    return SPI_DATA.low;
} 

void spi_recv(uint8_t *msg, uint32_t len){
    uint32_t i;
    spi_select();
    for(i=0;i<len;i++){
        msg[i]=spi_xmit(0xFF);
    }
    spi_deselect();
}

void spi_send(uint8_t *msg, uint32_t len){
    uint32_t i;
    spi_select();
    for(i=0;i<len;i++){
        spi_xmit(msg[i]);
    }
    spi_deselect();
}

