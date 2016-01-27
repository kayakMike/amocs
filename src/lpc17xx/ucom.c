#include "pinmx.h"
#include "clock.h"
#include "power.h"
#include "uart.h"
#include "ucom.h"


void uart0_initialize(void);
void uart0_send(uint8_t *msg);
void uart0_send_message(uint8_t *msg, uint32_t len);

void uart2_send(uint8_t *msg);
void uart2_send_message(uint8_t *msg, uint32_t len);
void uart2_initialize(void);

void ucom_initializePort(uint8_t port){
    switch(port){
        case UART0:
            uart0_initialize();
            break;
        case UART2:
            uart2_initialize();
            break;
        default:
            //error occured
            break;
    }
}

void ucom_sendString(uint8_t port, uint8_t *msg){
    switch(port){
        case UART0:
            uart0_send(msg);
            break;
        case UART2:
            uart2_send(msg);
            break;
        default:
            //error occured
            break;
    }
}

void ucom_sendMessage(uint8_t port, uint8_t *msg, uint32_t len){
    switch(port){
        case UART0:
            uart0_send_message(msg,len);
            break;
        case UART2:
            uart2_send_message(msg,len);
            break;
        default:
            break;
    }
}


void uart0_send(uint8_t *msg){
    uint32_t i;
    for(i=0;msg[i]!='\0';i++){
        while(UART0_LINE_STATUS.tx_hold_empty==0){
        }
        UART0_THR.buffer=msg[i];
    }    
}

void uart0_send_message(uint8_t *msg, uint32_t len){
    while(len){
        if(UART0_LINE_STATUS.tx_hold_empty==1){
            UART0_THR.buffer=*msg;
            msg++;
            len--;
        }
    }
}


void uart2_send(uint8_t *msg){
    uint32_t i;
    for(i=0;msg[i]!='\0';i++){
        while(UART2_LINE_STATUS.tx_hold_empty==0){
        }
        UART2_THR.buffer=msg[i];
    }    
}

void uart2_send_message(uint8_t *msg, uint32_t len){
    while(len){
        if(UART2_LINE_STATUS.tx_hold_empty==1){
            UART2_THR.buffer=*msg;
            msg++;
            len--;
        }
    }
}


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
    UART0_DLL.buffer=43;
    UART0_LINE_CTL.divisor_latch=0;    //relock divisors
    UART0_TRANSMIT_ENABLE.tx_enable=1;
} 

void uart2_initialize(void){
    PIN_FUNC.p0_10=1;
    PIN_FUNC.p0_11=1;
    PIN_MODE.p0_10=2;  //pulldown
    PIN_MODE.p0_11=2;  //pulldown

    //turn on UART2
    PERIPHERAL_POWER.uart2=1;
    PERIPHERAL_CLOCK_SEL1.uart2=1;
    
    UART2_TRANSMIT_ENABLE.tx_enable=1;

    UART2_FIFO_CTL.enable=1;
    UART2_FIFO_CTL.rx_reset=1;
    UART2_FIFO_CTL.tx_reset=1;
    UART2_FIFO_CTL.rx_trigger_lvl=0;
    UART2_FIFO_CTL.dma=0;            //no dma...

    UART2_LINE_CTL.word_length=3;    //8
    UART2_LINE_CTL.parity_enable=0;  //N
    UART2_LINE_CTL.stop_bits=0;      //1

    UART2_FRACTIONAL_DIVIDER.divaddval=1;
    UART2_FRACTIONAL_DIVIDER.mulval=2;

    UART2_LINE_CTL.divisor_latch=1;    //unlock divisors
    UART2_DLM.buffer=0;
    UART2_DLL.buffer=43;
    UART2_LINE_CTL.divisor_latch=0;    //relock divisors
    UART2_TRANSMIT_ENABLE.tx_enable=1;
} 
