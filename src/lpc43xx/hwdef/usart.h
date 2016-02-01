#ifndef __usart_defs_h
#define __usart_defs_h


#include "system_types.h"
/**
 * @brief UM10503.pdf section 39.6.1 table 921
 * The Divisor Latch Access Bit (DLAB) in Line Control Register must be
 * zero to access th rx buffer register. this register is always Read Only
 * Corresponds to the "RBR" in the description, Receive buffer register
 */
struct UsartTranscieveBuffer{
    unsigned byte      : 8;
    unsigned           :24;
};
//set appropriate divisor latch to 0 
#define USART0_RX_BUFFER   (*(volatile struct UsartTranscieveBuffer *)(0x40081000))
#define USART2_RX_BUFFER   (*(volatile struct UsartTranscieveBuffer *)(0x400C1000))
#define USART3_RX_BUFFER   (*(volatile struct UsartTranscieveBuffer *)(0x400C2000))
/* @brief UM10503.pdf section 39.6.2 table 922
 * The Divisor Latch Access Bit (DLAB) in the Line Control Register must be 
 * zero in order to access tx buffer. This register is always Write Only
 * Corresponds to the Transmit Holding Register in the user manual
 */
#define USART0_TX_BUFFER   (*(volatile struct UsartTranscieveBuffer *)(0x40081000))
#define USART2_TX_BUFFER   (*(volatile struct UsartTranscieveBuffer *)(0x400C1000))
#define USART3_TX_BUFFER   (*(volatile struct UsartTranscieveBuffer *)(0x400C2000))

/**
 * @brief UM10503.pdf section 39.6.3 table 923
 * THe Divisor Latch Acces Bit (DLAB in the Line Control Register must be
 * set to 1 to access the divisor latch Least Significant Bit Field and 
 * the Most Significant Bitfield.  These registers are used to configure the
 * baude rate of the UART.  
 */
#define USART0_DIVISOR_LATCH_LSB   (*(volatile struct UsartTranscieveBuffer *)(0x40081000))
#define USART0_DIVISOR_LATCH_MSB   (*(volatile struct UsartTranscieveBuffer *)(0x40081004))
#define USART2_DIVISOR_LATCH_LSB   (*(volatile struct UsartTranscieveBuffer *)(0x400C1000))
#define USART2_DIVISOR_LATCH_MSB   (*(volatile struct UsartTranscieveBuffer *)(0x400C1004))
#define USART3_DIVISOR_LATCH_LSB   (*(volatile struct UsartTranscieveBuffer *)(0x400C2000))
#define USART3_DIVISOR_LATCH_MSB   (*(volatile struct UsartTranscieveBuffer *)(0x400C2004))


/**
 * @brief UM10503.pdf section 39.6.4 table 925
 * Register for configuration of the relevant UART interrupt source
 * Reset status
 */
struct UsartInterruptEnable{
    unsigned  rxEnable              : 1;  //RBR  Interrupt Enable bit
    unsigned  txEnable              : 1;  //THRE Interrupt Enable bit
    unsigned  rxLineStatusEnable    : 1;  //RXIE Rx Line Interrupt Enable
    unsigned                        : 1;  
    unsigned                        : 3;
    unsigned                        : 1;
    unsigned  autoBaudEndEnable     : 1;  //ABEOINTEN  
    unsigned  autoBaudTimeoutEnable : 1;  //ABTOINTEN
    unsigned                        :22;
};

#define USART0_INTERRUPT_ENABLE  (*(volatile struct UsartInterruptEnable *)(0x40081004))
#define USART2_INTERRUPT_ENABLE  (*(volatile struct UsartInterruptEnable *)(0x400C1004))
#define USART3_INTERRUPT_ENABLE  (*(volatile struct UsartInterruptEnable *)(0x400C2004))

/**
 *  @brief UM10503.pdf section 39.6.5 table 926
 *    status -- 1 if the interrupt has been serviced 0 if the interrupt is pending
 *    identity --
 *        0x3 RxLineStatus     -- overrun, parity, framing, break error occured
 *        0x2 RxDataAvailable  -- the Rx Fifo has hit the trigger level
 *        0x6 CharacterTimeOut -- bytes are in the Rx Fifo that have not
 *                                yet been read in 3.5 to 4.5 timings.
 *        0x1 Transmit Holding Register is Empty
 */
struct UsartInterruptIdentification{
    unsigned status             : 1;  // 1 indicates interrupt is not pending
    unsigned identity           : 3;  // 
    unsigned                    : 2;
    unsigned fifoEnable         : 2;
    unsigned autoBaudEnd        : 1;
    unsigned autoBaudTimeout    : 1;
    unsigned                    :22;
};

#define USART0_INTERRRUPT_IDENTITY (*(volatile struct UsartInterruptIdentification *)(0x40081008))
#define USART1_INTERRRUPT_IDENTITY (*(volatile struct UsartInterruptIdentification *)(0x400C1008))
#define USART2_INTERRRUPT_IDENTITY (*(volatile struct UsartInterruptIdentification *)(0x400C2008))

/**
 * @brief UM10503.pdf section 39.6.6 table 928
 *  
 *   dmaMode looks like use the DMA controller if set to 1 
 *   usart will make DMA requests if the rx Trigger level is set
 *   
 *   Reseting the Fifo, write 1 to the Reset fields
 *
 *   must always enable the uart Fifo to use the UART
 *   <br>
 *   ###rxTriggerLevel
 *   -0x0 Level 0. Trigger level 0 (1 character or 0x01).
 *   -0x1 Level 1. Trigger level 1 (4 characters or 0x04).
 *   -0x2 Level 2. Trigger level 2 (8 characters or 0x08).
 *   -0x3 Level 3. Trigger level 3 (14 characters or 0x0E).
 *
 */
struct UsartFifoControl{
    unsigned fifoEnable        : 1;
    unsigned rxFifoReset       : 1;
    unsigned txFifoReset       : 1;
    unsigned dmaMode           : 1;
    unsigned                   : 2;
    unsigned rxTriggerLevel    : 3;
    unsigned                   : 24;
};
#define USART0_FIFO_CONTROL (*(volatile struct UsartFifoControl *)(0x40081008))
#define USART2_FIFO_CONTROL (*(volatile struct UsartFifoControl *)(0x400C1008))
#define USART3_FIFO_CONTROL (*(volatile struct UsartFifoControl *)(0x400C2008))

/**
 * @brief UM10503.pdf section 39.6.6 table 929
 *   @var wordLengthSelect 
 *   + 0x0 5 bit word length 
 *   + 0x1 6
 *   + 0x2 7
 *   + 0x3 8
 *   
 *   ##stopBitSelect    
 *   + 0x0 1 stop bit
 *   + 0x1 2 stop bits
 *   
 *   ##paritySelect     
 *   + 0x0 odd parity
 *   + 0x1 even parity
 *   + 0x2 force high
 *   + 0x3 force low
 *   
 *   breakControl     -- 0x1 enabeld 0x0 disabled
 *   
 *   divisorLatch     -- 0x1 enabeld 0x0 disabled
 *
 */
struct UsartLineControl{
    unsigned wordLengthSelect   : 2;  
    unsigned stopBitSelect      : 1;  //!< stob bit select
    unsigned parityEnable       : 1;  //!< parity enable
    unsigned paritySelect       : 2;  //!< parity select
    unsigned breakControlEnable : 1;  //!< break control
    unsigned divisorLatchEnable : 1;  //!< divisor latch bit
    unsigned                    :24;  //!< reserved
};
#define USART0_LINE_CONTROL (*(volatile struct UsartLineControl *)(0x4008100C))
#define USART2_LINE_CONTROL (*(volatile struct UsartLineControl *)(0x400C100C))
#define USART3_LINE_CONTROL (*(volatile struct UsartLineControl *)(0x400C200C))



struct UsartTransmitEnable{
    unsigned txEnable : 1;
    unsigned          :31;
};
#define USART0_TX_ENABLE (*(volatile struct UsartTransmitEnable *)(0x4008105C))
#define USART2_TX_ENABLE (*(volatile struct UsartTransmitEnable *)(0x400C105C))
#define USART3_TX_ENABLE (*(volatile struct UsartTransmitEnable *)(0x400C205C))

/**
 * @brief UM10503.pdf section 39.6.8 table 930
 *
 */
struct UsartLineStatus{
    unsigned rxDataReady     : 1;  //!< recieve data ready
    unsigned overrunError    : 1;  //!< overrun error
    unsigned parityError     : 1;  //!< parity error
    unsigned framingError    : 1;  //!< framing error
    unsigned interruptBreak  : 1;  //!< break interrupt
    unsigned txHoldEmpty     : 1;  //!< transmit holding register empty
    unsigned txEmpty         : 1;  //!< transmitter empty
    unsigned rxFifoError     : 1;  //!< error in RX FIFO
    unsigned txFifoErr       : 1;  //!< error in TX FIFO
    unsigned                 :24;  //!< resrved
};
#define USART0_LINE_STATUS (*(volatile struct UsartLineStatus *)(0x40081014))
#define USART2_LINE_STATUS (*(volatile struct UsartLineStatus *)(0x400C1014))
#define USART3_LINE_STATUS (*(volatile struct UsartLineStatus *)(0x400C2014))

/**
 * @brief UM10503.pdf section 39.6.12 table 935
 *
 */
struct UsartFractionalDivider{
    unsigned divisor    : 4;   //divaddval symbol
    unsigned multiplier : 4;
    unsigned            :24;
};
#define USART0_FRACTIONAL_DIVIDER (*(volatile struct UsartFractionalDivider *)(0x40081028))
#define USART2_FRACTIONAL_DIVIDER (*(volatile struct UsartFractionalDivider *)(0x400C1028))
#define USART3_FRACTIONAL_DIVIDER (*(volatile struct UsartFractionalDivider *)(0x400C2028))




#endif //__usart_defs_h

