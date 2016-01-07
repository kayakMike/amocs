#include "system.h"
#include "micro_types.h"

void Reset_ISR      (void) __attribute__((weak,alias("Default_ISR")));
void NMI_ISR        (void) __attribute__((weak,alias("Default_ISR")));
void HardFault_ISR  (void) __attribute__((weak,alias("Default_ISR")));
void MemManage_ISR  (void) __attribute__((weak,alias("Default_ISR")));
void BusFault_ISR   (void) __attribute__((weak,alias("Default_ISR")));
void UsageFault_ISR (void) __attribute__((weak,alias("Default_ISR")));
void SVC_ISR        (void) __attribute__((weak,alias("Default_ISR")));
void DebugMon_ISR   (void) __attribute__((weak,alias("Default_ISR")));
void PendSV_ISR     (void) __attribute__((weak,alias("Default_ISR")));
void SysTick_ISR    (void) __attribute__((weak,alias("Default_ISR")));
void WatchDog_ISR   (void) __attribute__((weak,alias("Default_ISR")));
void Timer0_ISR     (void) __attribute__((weak,alias("Default_ISR")));
void Timer1_ISR     (void) __attribute__((weak,alias("Default_ISR")));
void Timer2_ISR     (void) __attribute__((weak,alias("Default_ISR")));
void Timer3_ISR     (void) __attribute__((weak,alias("Default_ISR")));
void Uart0_ISR      (void) __attribute__((weak,alias("Default_ISR")));
void Uart1_ISR      (void) __attribute__((weak,alias("Default_ISR")));
void Uart2_ISR      (void) __attribute__((weak,alias("Default_ISR")));
void Uart3_ISR      (void) __attribute__((weak,alias("Default_ISR")));
void Pmw_ISR        (void) __attribute__((weak,alias("Default_ISR")));
void I2c0_ISR       (void) __attribute__((weak,alias("Default_ISR")));
void I2c1_ISR       (void) __attribute__((weak,alias("Default_ISR")));
void I2c2_ISR       (void) __attribute__((weak,alias("Default_ISR")));
void Spi_ISR        (void) __attribute__((weak,alias("Default_ISR")));
void Ssp0_ISR       (void) __attribute__((weak,alias("Default_ISR")));
void Ssp1_ISR       (void) __attribute__((weak,alias("Default_ISR")));
void Pll0_ISR       (void) __attribute__((weak,alias("Default_ISR")));
void Rtc_ISR        (void) __attribute__((weak,alias("Default_ISR")));
void Ext0_ISR       (void) __attribute__((weak,alias("Default_ISR")));
void Ext1_ISR       (void) __attribute__((weak,alias("Default_ISR")));
void Ext2_ISR       (void) __attribute__((weak,alias("Default_ISR")));
void Ext3_ISR       (void) __attribute__((weak,alias("Default_ISR")));
void Adc_ISR        (void) __attribute__((weak,alias("Default_ISR")));
void Bod_ISR        (void) __attribute__((weak,alias("Default_ISR")));
void Usb_ISR        (void) __attribute__((weak,alias("Default_ISR")));
void Can_ISR        (void) __attribute__((weak,alias("Default_ISR")));
void Dma_ISR        (void) __attribute__((weak,alias("Default_ISR")));
void I2s_ISR        (void) __attribute__((weak,alias("Default_ISR")));
void Enet_ISR       (void) __attribute__((weak,alias("Default_ISR")));
void Rit_ISR        (void) __attribute__((weak,alias("Default_ISR")));
void Mcpwm_ISR      (void) __attribute__((weak,alias("Default_ISR")));
void Qei_ISR        (void) __attribute__((weak,alias("Default_ISR")));
void Pll1_ISR       (void) __attribute__((weak,alias("Default_ISR")));
void Usbact_ISR     (void) __attribute__((weak,alias("Default_ISR")));
void CanAct_ISR     (void) __attribute__((weak,alias("Default_ISR")));
void Soft0_ISR      (void) __attribute__((weak,alias("Default_ISR")));

extern uint32_t _stack_init;

void (*vectors[68])(void) __attribute__ ((section(".vectors")))={
    (void *)&_stack_init,
    Reset_ISR,            //1
    NMI_ISR,              //2
    HardFault_ISR,
    MemManage_ISR,  
    BusFault_ISR,   
    UsageFault_ISR, 
    0,
    0,
    0,
    0,            
    SVC_ISR,        
    DebugMon_ISR,   
    0,                  
    PendSV_ISR,     
    SysTick_ISR,
    WatchDog_ISR,
    Timer0_ISR,
    Timer1_ISR,
    Timer2_ISR,
    Timer3_ISR,
    Uart0_ISR,
    Uart1_ISR,
    Uart2_ISR,
    Uart3_ISR,
    Pmw_ISR,
    I2c0_ISR,
    I2c1_ISR,
    I2c2_ISR,
    Spi_ISR,
    Ssp0_ISR,
    Ssp1_ISR,
    Pll0_ISR,
    Rtc_ISR,
    Ext0_ISR,
    Ext1_ISR,
    Ext2_ISR,
    Ext3_ISR,
    Adc_ISR,
    Bod_ISR,
    Usb_ISR,
    Can_ISR,
    Dma_ISR,
    I2s_ISR,
    Enet_ISR,
    Rit_ISR,
    Mcpwm_ISR,
    Qei_ISR,
    Pll1_ISR,
    Usbact_ISR,
    CanAct_ISR,
    Soft0_ISR
};


void Default_ISR(void){
    while(true){
    }
}

