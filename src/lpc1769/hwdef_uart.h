#ifndef __hwdefs_uart_h
#define __hwdefs_uart_h
//TODO: MAJOR.  get the other UART ports defined in here

#include "micro_types.h"

typedef union{
    uint32_t val;
    struct{
        unsigned buffer    : 8;
        unsigned           :24;
    }bits;
}UartTranscieveBuffer;
//set appropriate divisor_latch to 0 
#define UART0_RBR   (*(volatile UartTranscieveBuffer *)(0x400C0000))
#define UART0_THR   (*(volatile UartTranscieveBuffer *)(0x400C0000))
//set UART divisor_latch to 1 first
#define UART0_DLL   (*(volatile UartTranscieveBuffer *)(0x400C0000))
#define UART0_DLM   (*(volatile UartTranscieveBuffer *)(0x400C0004))

typedef union{
    uint32_t val;
    struct{
        unsigned fifo_enable      : 1;
        unsigned rx_fifo_reset    : 1;
        unsigned tx_fifo_reset    : 1;
        unsigned dma_mode         : 1;
        unsigned                  : 2;
        unsigned rx_trigger_lvl   : 3;
        unsigned                  : 24;
    }bits;
}UartFifoControl;
#define UART0_FIFO_CTL (*(volatile UartFifoControl *)(0x400C008))

typedef union{
    uint32_t val;
    struct{
        unsigned word_length    : 2;  //word length select
        unsigned stop_bits      : 1;  //stob bit select
        unsigned parity_enable  : 1;  //parity enable
        unsigned parity_sel     : 2;  //parity select
        unsigned break_ctl      : 1;  //break control
        unsigned divisor_latch  : 1;  //divisor latch bit
        unsigned                :24;  //reserved
    }bits;
}UartLineControl;
#define UART0_LINE_CTL (*(volatile UartLineControl *)(0x4000C00C))


typedef union{
    uint32_t val;
    struct{
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
    }bits;
}UartLineStatus;
#define UART0_LINE_STATUS (*(volatile UartLineStatus *)(0x4000C014))

typedef union{
    uint32_t val;
    struct{
        unsigned enable   : 1;
        unsigned          :31;
    }bits;
}UartTransmitEnable;  
#define UART0_TRANSMIT_ENABLE (*(volatile UartTransmitEnable *)(0x4000C030))

typedef union{
    uint32_t val;
    struct{
        unsigned divaddval  : 4;
        unsigned mulval     : 4;
        unsigned            :24;
    }bits;
}UartFractionalDivider;
#define UART0_FRACTIONAL_DIVIDER (*(volatile UartFractionalDivider *)(0x40081028))

typedef union{
    uint32_t val;
    struct{
        unsigned irqStatus       : 1;
        unsigned irqIdentity     : 3;
        unsigned                 : 2;
        unsigned fifoEnable      : 2;
        unsigned autoBaudEnd     : 1;
        unsigned autoBaudTimeout : 1;
        unsigned                 :22;
    }bits;
}UartInterruptIdentification;

#define UART0_IIR (*(volatile UartInterruptIdentification *)(0x40081008))

typedef union{
    uint32_t val;
    struct{
        unsigned  enableReceive           : 1;
        unsigned  enableTransmit          : 1;
        unsigned  enableReceiveLineStatus : 1;
        unsigned                          : 1;
        unsigned                          : 3;
        unsigned                          : 1;
        unsigned  enableAutoBaudEnd       : 1;
        unsigned  enableAutoBaudTimeout   : 1;
        unsigned                          :22;
    }bits;
}UartInterruptEnable;

#define UART0_IRQ_ENABLE  (*(volatile UartInterruptEnable *)(0x40081004))



#endif //__usart_defs_h

