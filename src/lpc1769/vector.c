#include "system.h"
#include "micro_types.h"

void isr_reset      (void) __attribute__((weak,alias("isr_default")));
void isr_nmi        (void) __attribute__((weak,alias("isr_default")));
void isr_hardfault  (void) __attribute__((weak,alias("isr_default")));
void isr_memmanage  (void) __attribute__((weak,alias("isr_default")));
void isr_busfault   (void) __attribute__((weak,alias("isr_default")));
void isr_usagefault (void) __attribute__((weak,alias("isr_default")));
void isr_svc        (void) __attribute__((weak,alias("isr_default")));
void isr_debugmon   (void) __attribute__((weak,alias("isr_default")));
void isr_pendsv     (void) __attribute__((weak,alias("isr_default")));
void isr_systick    (void) __attribute__((weak,alias("isr_default")));
void isr_watchdog   (void) __attribute__((weak,alias("isr_default")));
void isr_timer0     (void) __attribute__((weak,alias("isr_default")));
void isr_timer1     (void) __attribute__((weak,alias("isr_default")));
void isr_timer2     (void) __attribute__((weak,alias("isr_default")));
void isr_timer3     (void) __attribute__((weak,alias("isr_default")));
void isr_uart0      (void) __attribute__((weak,alias("isr_default")));
void isr_uart1      (void) __attribute__((weak,alias("isr_default")));
void isr_uart2      (void) __attribute__((weak,alias("isr_default")));
void isr_uart3      (void) __attribute__((weak,alias("isr_default")));
void isr_pmw        (void) __attribute__((weak,alias("isr_default")));
void isr_i2c0       (void) __attribute__((weak,alias("isr_default")));
void isr_i2c1       (void) __attribute__((weak,alias("isr_default")));
void isr_i2c2       (void) __attribute__((weak,alias("isr_default")));
void isr_spi        (void) __attribute__((weak,alias("isr_default")));
void isr_ssp0       (void) __attribute__((weak,alias("isr_default")));
void isr_ssp1       (void) __attribute__((weak,alias("isr_default")));
void isr_pll0       (void) __attribute__((weak,alias("isr_default")));
void isr_rtc        (void) __attribute__((weak,alias("isr_default")));
void isr_ext0       (void) __attribute__((weak,alias("isr_default")));
void isr_ext1       (void) __attribute__((weak,alias("isr_default")));
void isr_ext2       (void) __attribute__((weak,alias("isr_default")));
void isr_ext3       (void) __attribute__((weak,alias("isr_default")));
void isr_adc        (void) __attribute__((weak,alias("isr_default")));
void isr_bod        (void) __attribute__((weak,alias("isr_default")));
void isr_usb        (void) __attribute__((weak,alias("isr_default")));
void isr_can        (void) __attribute__((weak,alias("isr_default")));
void isr_dma        (void) __attribute__((weak,alias("isr_default")));
void isr_i2s        (void) __attribute__((weak,alias("isr_default")));
void isr_enet       (void) __attribute__((weak,alias("isr_default")));
void isr_rit        (void) __attribute__((weak,alias("isr_default")));
void isr_mcpwm      (void) __attribute__((weak,alias("isr_default")));
void isr_qei        (void) __attribute__((weak,alias("isr_default")));
void isr_pll1       (void) __attribute__((weak,alias("isr_default")));
void isr_usbact     (void) __attribute__((weak,alias("isr_default")));
void isr_canact     (void) __attribute__((weak,alias("isr_default")));
void isr_soft0      (void) __attribute__((weak,alias("isr_default")));

extern uint32_t _stack_init;

void (*vectors[68])(void) __attribute__ ((section(".vectors")))={
    (void *)&_stack_init,
    isr_reset,            //1
    isr_nmi,              //2
    isr_hardfault,
    isr_memmanage,  
    isr_busfault,   
    isr_usagefault, 
    0,
    0,
    0,
    0,            
    isr_svc,        
    isr_debugmon,   
    0,                  
    isr_pendsv,     
    isr_systick,
    isr_watchdog,
    isr_timer0,
    isr_timer1,
    isr_timer2,
    isr_timer3,
    isr_uart0,
    isr_uart1,
    isr_uart2,
    isr_uart3,
    isr_pmw,
    isr_i2c0,
    isr_i2c1,
    isr_i2c2,
    isr_spi,
    isr_ssp0,
    isr_ssp1,
    isr_pll0,
    isr_rtc,
    isr_ext0,
    isr_ext1,
    isr_ext2,
    isr_ext3,
    isr_adc,
    isr_bod,
    isr_usb,
    isr_can,
    isr_dma,
    isr_i2s,
    isr_enet,
    isr_rit,
    isr_mcpwm,
    isr_qei,
    isr_pll1,
    isr_usbact,
    isr_canact,
    isr_soft0
};


void isr_default(void){
    while(true){
    }
}

