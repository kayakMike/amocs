#ifndef __nvic_defs_h
#define __nvic_defs_h

#include "system_types.h"
/**
 *  @brief interrupt vector control structure
 */
struct InterruptVectorControl{            //exception  index
    unsigned dac         : 1;  //!< 16        0 DAC 
    unsigned m0app       : 1;  //!< 17        1 M0APP Core interrupt
    unsigned dma         : 1;  //!< 18        2 DMA
    unsigned             : 1;  //!< 19        3 EZH/EDM 
    unsigned             : 1;  //!< 20        4 RESERVED 
    unsigned ethernet    : 1;  //!< 21        5 ETHERNET 
    unsigned sdio        : 1;  //!< 22        6 SDIO
    unsigned lcd         : 1;  //!< 23        7 LCD
    unsigned usb0        : 1;  //!< 24        8 USB0
    unsigned usb1        : 1;  //!< 25        9 USB1
    unsigned sct         : 1;  //!< 26       10 SCT
    unsigned ritimer     : 1;  //!< 27       11 RITIMER
    unsigned timer0      : 1;  //!< 28       12 TIMER0
    unsigned timer1      : 1;  //!< 29       13 TIMER1
    unsigned timer2      : 1;  //!< 30       14 TIMER2
    unsigned timer3      : 1;  //!< 31       15 TIMER3
    unsigned mcpwm       : 1;  //!< 32       16 MCPWM
    unsigned adc0        : 1;  //!< 33       17 ADC0
    unsigned i2c0        : 1;  //!< 34       18 I2C0
    unsigned i2c1        : 1;  //!< 35       19 I2C1
    unsigned spi         : 1;  //!< 36       20 SPI_INT
    unsigned adc1        : 1;  //!< 37       21 ADC1
    unsigned ssp0        : 1;  //!< 38       22 SSP0
    unsigned ssp1        : 1;  //!< 39       23 SSP1
    unsigned usart0      : 1;  //!< 40       24 USART0
    unsigned uart1       : 1;  //!< 41       25 UART1
    unsigned usart2      : 1;  //!< 42       26 USART2
    unsigned usart3      : 1;  //!< 43       27 USART3
    unsigned i2s0        : 1;  //!< 44       28 I2S0
    unsigned i2s1        : 1;  //!< 45       29 I2S1
    unsigned irq30       : 1;  //!< 46       30 RESERVED
    unsigned sgpio       : 1;  //!< 47       31 SGPIO_IINT
    unsigned pin0        : 1;  //!< 48       32 PIN_INT0
    unsigned pin1        : 1;  //!< 49       33 PIN_INT1
    unsigned pin2        : 1;  //!< 50       34 PIN_INT2
    unsigned pin3        : 1;  //!< 51       35 PIN_INT3
    unsigned pin4        : 1;  //!< 52       36 PIN_INT4
    unsigned pin5        : 1;  //!< 53       37 PIN_INT5
    unsigned pin6        : 1;  //!< 54       38 PIN_INT6
    unsigned pin7        : 1;  //!< 55       39 PIN_INT7
    unsigned gint0       : 1;  //!< 56       40 GINT0
    unsigned gint1       : 1;  //!< 57       41 GINT1
    unsigned eventrouter : 1;  //!< 58       42 EVENTROUTER
    unsigned can1        : 1;  //!< 59       43 C_CAN1
    unsigned irq44       : 1;  //!< 60       44 RESERVED
    unsigned adchs       : 1;  //!< 61       45 ADCHS interrupt
    unsigned atimer      : 1;  //!< 62       46 ATIMER
    unsigned rtc         : 1;  //!< 63       47 RTC
    unsigned reserved8   : 1;  //!< 64       48 RESERVED
    unsigned wwdt        : 1;  //!< 65       49 WWDT
    unsigned m0sub       : 1;  //!< 66       50 M0SUB core interrupt
    unsigned can0        : 1;  //!< 67       51 C_CAN0
    unsigned qei         : 1;  //!< 68       52 QEI
    unsigned             :11;  //!< ????????out to 64 bits.
};


#define NVIC_SET_ENABLE   (*(volatile struct InterruptVectorControl *)(0xE000E100))
#define NVIC_CLEAR_ENABLE (*(volatile struct InterruptVectorControl *)(0xE000E180))

#define NVIC_SET_PENDING   (*(volatile struct InterruptVectorControl *)(0xE000E200))
#define NVIC_CLEAR_PENDING (*(volatile struct InterruptVectorControl *)(0xE000E280))

#define NVIC_ACTIVE  (*(volatile struct InterruptVectorControl *)(0xE000E300))

struct InterruptPriorityControl{                    //exception  index
    uint8_t dac         ;   /*!<  0 DAC */                 
    uint8_t m0app       ;   /*!<  1 M0APP Core interrupt */
    uint8_t dma         ;   /*!<  2 DMA */
    uint8_t res1        ;   /*!<  3 EZH/EDM */
    uint8_t res2        ;   /*!<  4 RESERVED */ 
    uint8_t ethernet    ;   /*!<  5 ETHERNET */
    uint8_t sdio        ;   /*!<  6 SDIO */
    uint8_t lcd         ;   /*!<  7 LCD */
    uint8_t usb0        ;   /*!<  8 USB0 */
    uint8_t usb1        ;   /*!<  9 USB1 */
    uint8_t sct         ;   /*!< 10 SCT */
    uint8_t ritimer     ;   /*!< 11 RITIMER */
    uint8_t timer0      ;   /*!< 12 TIMER0 */             
    uint8_t timer1      ;   /*!< 13 TIMER1 */
    uint8_t timer2      ;   /*!< 14 TIMER2 */
    uint8_t timer3      ;   /*!< 15 TIMER3 */
    uint8_t mcpwm       ;   /*!< 16 MCPWM */
    uint8_t adc0        ;   /*!< 17 ADC0 */              
    uint8_t i2c0        ;   /*!< 18 I2C0 */
    uint8_t i2c1        ;   /*!< 19 I2C1 */
    uint8_t spi         ;   /*!< 20 SPI_INT */
    uint8_t adc1        ;   /*!< 21 ADC1 */
    uint8_t ssp0        ;   /*!< 22 SSP0 */
    uint8_t ssp1        ;   /*!< 23 SSP1 */
    uint8_t usart0      ;   /*!< 24 USART0 */
    uint8_t uart1       ;   /*!< 25 UART1 */
    uint8_t usart2      ;   /*!< 26 USART2 */
    uint8_t usart3      ;   /*!< 27 USART3 */
    uint8_t i2s0        ;   /*!< 28 I2S0 */
    uint8_t i2s1        ;   /*!< 29 I2S1 */
    uint8_t irq30       ;   /*!< 30 RESERVED */ 
    uint8_t sgpio       ;   /*!< 31 SGPIO_IINT */
    uint8_t pin0        ;   /*!< 32 PIN_INT0 */
    uint8_t pin1        ;   /*!< 33 PIN_INT1 */
    uint8_t pin2        ;   /*!< 34 PIN_INT2 */
    uint8_t pin3        ;   /*!< 35 PIN_INT3 */
    uint8_t pin4        ;   /*!< 36 PIN_INT4 */
    uint8_t pin5        ;   /*!< 37 PIN_INT5 */
    uint8_t pin6        ;   /*!< 38 PIN_INT6 */
    uint8_t pin7        ;   /*!< 39 PIN_INT7 */
    uint8_t gint0       ;   /*!< 40 GINT0 */
    uint8_t gint1       ;   /*!< 41 GINT1 */
    uint8_t event       ;   /*!< 42 EVENTROUTER */
    uint8_t can1        ;   /*!< 43 C_CAN1 */
    uint8_t irq44       ;   /*!< 44 RESERVED */
    uint8_t adchs       ;   /*!< 45 ADCHS interrupt */
    uint8_t atimer      ;   /*!< 46 ATIMER */
    uint8_t rtc         ;   /*!< 47 RTC */
    uint8_t reserved48  ;   /*!< 48 RESERVED */  
    uint8_t wwdt        ;   /*!< 49 WWDT */
    uint8_t m0sub       ;   /*!< 50 M0SUB core interrupt */
    uint8_t can0        ;   /*!< 51 C_CAN0 */
    uint8_t qei         ;   /*!< 52 QEI */
    uint8_t res[11]     ;   /*!< pad this out to 64 bits. */
};
#define NVIC_PRIORITY_CONTROL (*(volatile struct InterruptPriorityControl *)(0xE000E400))

/**
 * @brief VectorTableOffset indicates where the vector table lives
 */
struct VectorTableOffset{
    unsigned           : 7;  //!< this pad group should always 0
    unsigned           :21;
    unsigned tableBase : 1;  //!< table base bit
    unsigned           : 3;
};
#define NVIC_VECTOR_TABLE (*(volatile struct VectorTableOffset *)(0xE000ED08))
#define NVIC_VECTOR_TABLE_VALUE (*(volatile uint32_t *)(0xE000ED08))




#endif  //__nvic_defs.h


/*
typedef union{
    uint32_t val;
    struct{
        unsigned bit_select     : 5;
        unsigned reg_select     : 3;
        unsigned                :24;
    }bits;
}IrqNumber;

#define NVIC_ENABLE  

void NVIC_enable_irq(IrqNumber irq){

    irq.bits.reg_select
    irq.bits.bit_select

}
*/
