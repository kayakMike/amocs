#include "micro_types.h"
#include "hwdef_gpio.h"
#include "hwdef_pinmx.h"
#include "hwdef_uart.h"
#include "hwdef_clock.h"

#include "system.h"

//icky....
void uart0_send(char *msg){
    uint32_t i;
    for(i=0;msg[i]!='\0';i++){
        while(UART0_LINE_STATUS.tx_hold_empty==0){
            //spin until UART0 is not busy anymore
        }
        UART0_THR.buffer=msg[i];
    }    
}

//better
void uart0_send_message(uint8_t *msg, uint32_t len){
    while(len){
        if(UART0_LINE_STATUS.tx_hold_empty==1){
            UART0_THR.buffer=*msg;
            msg++;
            len--;
        }
    }
}

//uart0 initialization for debug messages
void uart0_initialize(void){
    PIN_FUNC.p0_02=1;
    PIN_FUNC.p0_03=1;
    PIN_MODE.p0_02=2;  //pulldown
    PIN_MODE.p0_03=2;  //pulldown

    PERIPHERAL_CLOCK_SEL0.uart0=1;
    
    UART0_TRANSMIT_ENABLE.tx_enable=1;

    UART0_FIFO_CTL.enable=1;
    UART0_FIFO_CTL.rx_reset=1;
    UART0_FIFO_CTL.tx_reset=1;
    UART0_FIFO_CTL.rx_trigger_lvl=0;
    UART0_FIFO_CTL.dma=0;            //no dma...

    UART0_LINE_CTL.word_length=3;    //8
    UART0_LINE_CTL.parity_enable=0;  //N
    UART0_LINE_CTL.stop_bits=0;      //1

    UART0_FRACTIONAL_DIVIDER.divaddval=1;
    UART0_FRACTIONAL_DIVIDER.mulval=2;

    UART0_LINE_CTL.divisor_latch=1;    //unlock divisors
    UART0_DLM.buffer=0;
//    UART0_DLL.buffer=17;
    UART0_DLL.buffer=43;
    UART0_LINE_CTL.divisor_latch=0;    //relock divisors
    UART0_TRANSMIT_ENABLE.tx_enable=1;
} 




//  ASSUMPTION: SYSTEM_CORE_CLOCK is 120MHz...
//    Calculation from Data Sheets 
//    UART0_TRANSMIT_ENABLE.tx_enable=0;
//    UART0_FRACTIONAL_DIVIDER.divaddval=1;
//    UART0_FRACTIONAL_DIVIDER.mulval=2;
//    UART0_DLL.buffer=43;
//    UART0_DLM.buffer=0;

