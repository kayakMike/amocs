#ifndef __nvic_defs_h
#define __nvic_defs_h

#include "micro_types.h"
/**
 *  @brief interrupt vector control structure
 */
typedef struct{            //exception  index
    unsigned watchdog    : 1;  //!< 1
    unsigned timer0      : 1;  //!< 1
    unsigned timer1      : 1;  //!< 2
    unsigned timer2      : 1;  //!< 3
    unsigned timer3      : 1;  //!<
    unsigned uart0       : 1;  //!<
    unsigned uart1       : 1;  //!<
    unsigned uart2       : 1;  //!<
    unsigned uart3       : 1;  //!<
    unsigned pwm         : 1;  //!<
    unsigned i2c0        : 1;  //!<
    unsigned i2c1        : 1;  //!<
    unsigned i2c2        : 1;  //!<
    unsigned spi         : 1;  //!<
    unsigned ssp0        : 1;  //!<
    unsigned ssp1        : 1;  //!<
    unsigned pll0        : 1;  //!<
    unsigned rtc         : 1;  //!<
    unsigned ext0        : 1;  //!<
    unsigned ext1        : 1;  //!<
    unsigned ext2        : 1;  //!<
    unsigned ext3        : 1;  //!<
    unsigned adc         : 1;  //!<
    unsigned bod         : 1;  //!<
    unsigned usb         : 1;  //!<
    unsigned can         : 1;  //!<
    unsigned dma         : 1;  //!<
    unsigned i2s         : 1;  //!<
    unsigned enet        : 1;  //!<
    unsigned rit         : 1;  //!<
    unsigned mcpwm       : 1;  //!<
    unsigned qei         : 1;  //!< 32
    unsigned pll1        : 1;
    unsigned usbact      : 1;
    unsigned canact      : 1;
    unsigned             :30; 
}InterruptVectorControl;


#define NVIC_SET_ENABLE   (*(volatile InterruptVectorControl *)(0xE000E100))
#define NVIC_CLEAR_ENABLE (*(volatile InterruptVectorControl *)(0xE000E180))

#define NVIC_SET_PENDING   (*(volatile InterruptVectorControl *)(0xE000E200))
#define NVIC_CLEAR_PENDING (*(volatile InterruptVectorControl *)(0xE000E280))

#define NVIC_ACTIVE  (*(volatile InterruptVectorControl *)(0xE000E300))

typedef struct{                    //exception  index
    uint8_t watchdog  ; 
    uint8_t timer0    ;
    uint8_t timer1    ;
    uint8_t timer2    ;
    uint8_t timer3    ;
    uint8_t uart0     ;
    uint8_t uart1     ;
    uint8_t uart2     ;
    uint8_t uart3     ;
    uint8_t pwm       ;
    uint8_t i2c0      ;
    uint8_t i2c1      ;
    uint8_t i2c2      ;
    uint8_t spi       ;
    uint8_t ssp0      ;
    uint8_t ssp1      ;
    uint8_t pll0      ;
    uint8_t rtc       ;
    uint8_t ext0      ;
    uint8_t ext1      ;
    uint8_t ext2      ;
    uint8_t ext3      ;
    uint8_t adc       ;
    uint8_t bod       ;
    uint8_t usb       ;
    uint8_t can       ;
    uint8_t dma       ;
    uint8_t i2s       ;
    uint8_t enet      ;
    uint8_t rit       ;
    uint8_t mcpwm     ;
    uint8_t qei       ;
    uint8_t pll1      ;
    uint8_t usbact    ;
    uint8_t canact    ;
    uint8_t res[30]   ;
}InterruptPriorityControl;
#define NVIC_PRIORITY_CONTROL (*(volatile InterruptPriorityControl *)(0xE000E400))

/**
s
 * @brief VectorTableOffset indicates where the vector table lives
 */
typedef struct{
    unsigned           : 7;  //!< this pad group should always 0
    unsigned           :21;
    unsigned tableBase : 1;  //!< table base bit
    unsigned           : 3;
}VectorTableOffset;
#define NVIC_VECTOR_TABLE (*(volatile VectorTableOffset *)(0xE000ED08))
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

