#ifndef __hwdefs_uart_h
#define __hwdefs_uart_h
//TODO: MAJOR.  get the other UART ports defined in here

#include "micro_types.h"

typedef struct{
    unsigned buffer    : 8;
    unsigned           :24;
}UartTranscieveBuffer;
//set appropriate divisor_latch to 0 
#define UART0_RBR   (*(volatile UartTranscieveBuffer *)(0x400C0000))
#define UART2_RBR   (*(volatile UartTranscieveBuffer *)(0x40098000))
#define UART3_RBR   (*(volatile UartTranscieveBuffer *)(0x4009C000))

#define UART0_THR   (*(volatile UartTranscieveBuffer *)(0x400C0000))
#define UART2_THR   (*(volatile UartTranscieveBuffer *)(0x40098000))
#define UART3_THR   (*(volatile UartTranscieveBuffer *)(0x4009C000))
//set UART divisor_latch to 1 first
#define UART0_DLL   (*(volatile UartTranscieveBuffer *)(0x400C0000))
#define UART2_DLL   (*(volatile UartTranscieveBuffer *)(0x40098000))
#define UART3_DLL   (*(volatile UartTranscieveBuffer *)(0x4009C000))

//
#define UART0_DLM   (*(volatile UartTranscieveBuffer *)(0x400C0004))
#define UART2_DLM   (*(volatile UartTranscieveBuffer *)(0x40098004))
#define UART3_DLM   (*(volatile UartTranscieveBuffer *)(0x4009C004))


typedef struct{
    unsigned status       : 1;
    unsigned identity     : 3;
    unsigned              : 2;
    unsigned fifo_enable  : 2;
    unsigned ab_end       : 1;
    unsigned ab_timeout   : 1;
    unsigned              :22;
}UartInterruptIdentification;
#define UART0_IIR (*(volatile UartInterruptIdentification *)(0x4000C004))
#define UART2_IIR (*(volatile UartInterruptIdentification *)(0x40098004))
#define UART3_IIR (*(volatile UartInterruptIdentification *)(0x4009C004))

typedef struct{
    unsigned rx           : 1;
    unsigned tx           : 1;
    unsigned rx_status    : 1;
    unsigned              : 5;
    unsigned ab_end       : 1;
    unsigned ab_timeout   : 1;
    unsigned              :22;
}UartInterruptEnable;
#define UART0_IRQ_ENABLE  (*(volatile UartInterruptEnable *)(0x4000C008))
#define UART2_IRQ_ENABLE  (*(volatile UartInterruptEnable *)(0x40098008))
#define UART3_IRQ_ENABLE  (*(volatile UartInterruptEnable *)(0x4009C008))

typedef struct{
    unsigned enable           : 1;
    unsigned rx_reset         : 1;
    unsigned tx_reset         : 1;
    unsigned dma              : 1;
    unsigned                  : 2;
    unsigned rx_trigger_lvl   : 3;
    unsigned                  : 24;
}UartFifoControl;
#define UART0_FIFO_CTL (*(volatile UartFifoControl *)(0x4000C008))
#define UART2_FIFO_CTL (*(volatile UartFifoControl *)(0x40098008))
#define UART3_FIFO_CTL (*(volatile UartFifoControl *)(0x4009C008))

typedef struct{
    unsigned word_length    : 2;  //word length select
    unsigned stop_bits      : 1;  //stob bit select
    unsigned parity_enable  : 1;  //parity enable
    unsigned parity_sel     : 2;  //parity select
    unsigned break_ctl      : 1;  //break control
    unsigned divisor_latch  : 1;  //divisor latch bit
    unsigned                :24;  //reserved
}UartLineControl;
#define UART0_LINE_CTL (*(volatile UartLineControl *)(0x4000C00C))
#define UART2_LINE_CTL (*(volatile UartLineControl *)(0x4009800C))
#define UART3_LINE_CTL (*(volatile UartLineControl *)(0x4009C00C))


typedef struct{
    unsigned rx_ready      : 1;  //recieve data ready
    unsigned overrun_err   : 1;  //overrun error
    unsigned parity_err    : 1;  //parity error
    unsigned framing_err   : 1;  //framing error
    unsigned break_irq     : 1;  //break interrupt
    unsigned tx_hold_empty : 1;  //transmit holding register empty
    unsigned tx_empty      : 1;  //transmitter empty
    unsigned rx_fifo_err   : 1;  //error in RX FIFO
    unsigned tx_fifo_err   : 1;  //error in TX FIFO
    unsigned               :24;  //resrved
}UartLineStatus;
#define UART0_LINE_STATUS (*(volatile UartLineStatus *)(0x4000C014))
#define UART2_LINE_STATUS (*(volatile UartLineStatus *)(0x40098014))
#define UART3_LINE_STATUS (*(volatile UartLineStatus *)(0x4009C014))

//TODO: SCRATCH PAD
//TODO: AUTOBAUD
//TODO: IRDA

typedef struct{
    unsigned divaddval  : 4;
    unsigned mulval     : 4;
    unsigned            :24;
}UartFractionalDivider;
#define UART0_FRACTIONAL_DIVIDER (*(volatile UartFractionalDivider *)(0x4000C028))
#define UART2_FRACTIONAL_DIVIDER (*(volatile UartFractionalDivider *)(0x40098028))
#define UART3_FRACTIONAL_DIVIDER (*(volatile UartFractionalDivider *)(0x4009C028))

typedef struct{
    unsigned            : 7;
    unsigned tx_enable  : 1;
}UartTransmitEnable;  
#define UART0_TRANSMIT_ENABLE (*(volatile UartTransmitEnable *)(0x4000C030))
#define UART2_TRANSMIT_ENABLE (*(volatile UartTransmitEnable *)(0x40098030))
#define UART3_TRANSMIT_ENABLE (*(volatile UartTransmitEnable *)(0x4009C030))

#endif //__usart_defs_h

