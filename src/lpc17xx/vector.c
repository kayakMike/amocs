#include "micro_types.h"
#include "systime.h"

void isr_reset      (void) __attribute__((weak,alias("isr_default")));
void isr_nmi        (void) __attribute__((weak,alias("isr_default")));
void isr_hardfault  (void) __attribute__((weak,alias("isr_default")));
void isr_memmanage  (void) __attribute__((weak,alias("isr_default")));
void isr_busfault   (void) __attribute__((weak,alias("isr_default")));
void isr_usagefault (void) __attribute__((weak,alias("isr_default")));
void isr_svc        (void) __attribute__((weak,alias("isr_default")));
void isr_debugmon   (void) __attribute__((weak,alias("isr_default")));
void isr_pendsv     (void) __attribute__((weak,alias("isr_default")));
void isr_sysTick    (void) __attribute__((weak,alias("isr_default")));
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

void (*vectors[64])(void) __attribute__ ((section(".vectors")))={
    (void *)&_stack_init, //    0 
    isr_reset,            //    1       
    isr_nmi,              //    2 
    isr_hardfault,        //    3 
    isr_memmanage,        //    4 
    isr_busfault,         //    5 
    isr_usagefault,       //    6 
    0,                    //    7 
    0,                    //    8 
    0,                    //    9 
    0,                    //    10
    isr_svc,              //-5  11
    isr_debugmon,         //-4  12
    0,                    //-3  13
    isr_pendsv,           //-2  14
    isr_sysTick,          //-1  15 
    isr_watchdog,         // 0  16 0x40 WDT Watchdog Interrupt (WDINT)
    isr_timer0,           // 1  17 0x44 Timer 0 Match 0 - 1 (MR0, MR1) Capture 0 - 1 (CR0, CR1)
    isr_timer1,           // 2  18 0x48 Timer 1 Match 0 - 2 (MR0, MR1, MR2) Capture 0 - 1 (CR0, CR1)
    isr_timer2,           // 3  19 0x4C Timer 2 Match 0-3 Capture 0-1
    isr_timer3,           // 4  20 0x50 Timer 3 Match 0-3 Capture 0-1
    isr_uart0,            // 5  21 0x54 UART0 Rx Line Status (RLS) Transmit Holding Register Empty (THRE) Rx Data Available (RDA) Character Time-out Indicator (CTI) End of Auto-Baud (ABEO) Auto-Baud Time-Out (ABTO)
    isr_uart1,            // 6  22 0x58 UART1 Rx Line Status (RLS) Transmit Holding Register Empty (THRE) Rx Data Available (RDA) Character Time-out Indicator (CTI) Modem Control Change End of Auto-Baud (ABEO) Auto-Baud Time-Out (ABTO)
    isr_uart2,            // 7  23 0x5C UART 2 Rx Line Status (RLS) Transmit Holding Register Empty (THRE) Rx Data Available (RDA) Character Time-out Indicator (CTI) End of Auto-Baud (ABEO) Auto-Baud Time-Out (ABTO)
    isr_uart3,            // 8  24 0x60 UART 3 Rx Line Status (RLS) Transmit Holding Register Empty (THRE) Rx Data Available (RDA) Character Time-out Indicator (CTI) End of Auto-Baud (ABEO) Auto-Baud Time-Out (ABTO)
    isr_pmw,              // 9  25 0x64 PWM1 Match 0 - 6 of PWM1 Capture 0-1 of PWM1
    isr_i2c0,             // 10 26 0x68 I2C0 SI (state change)
    isr_i2c1,             // 11 27 0x6C I2C1 SI (state change)
    isr_i2c2,             // 12 28 0x70 I2C2 SI (state change)
    isr_spi,              // 13 29 0x74 SPI SPI Interrupt Flag (SPIF) Mode Fault (MODF)
    isr_ssp0,             // 14 30 0x78 SSP0 Tx FIFO half empty of SSP0 Rx FIFO half full of SSP0 Rx Timeout of SSP0 Rx Overrun of SSP0
    isr_ssp1,             // 15 31 0x7C SSP 1 Tx FIFO half empty Rx FIFO half full Rx Timeout Rx Overrun
    isr_pll0,             // 16 32 0x80 PLL0 (Main PLL) PLL0 Lock (PLOCK0)
    isr_rtc,              // 17 33 0x84 RTC Counter Increment (RTCCIF) Alarm (RTCALF)
    isr_ext0,             // 18 34 0x88 External Interrupt External Interrupt 0 (EINT0)
    isr_ext1,             // 19 35 0x8C External Interrupt External Interrupt 1 (EINT1)
    isr_ext2,             // 20 36 0x90 External Interrupt External Interrupt 2 (EINT2)
    isr_ext3,             // 21 37 0x94 External Interrupt External Interrupt 3 (EINT3).  Note: EINT3 channel is shared with GPIO interrupts
    isr_adc,              // 22 38 0x98 ADC A/D Converter end of conversion
    isr_bod,              // 23 39 0x9C BOD Brown Out detect
    isr_usb,              // 24 40 0xA0 USB USB_INT_REQ_LP, USB_INT_REQ_HP, USB_INT_REQ_DMA
    isr_can,              // 25 41 0xA4 CAN CAN Common, CAN 0 Tx, CAN 0 Rx, CAN 1 Tx, CAN 1 Rx
    isr_dma,              // 26 42 0xA8 GPDMA IntStatus of DMA channel 0, IntStatus of DMA channel 1
    isr_i2s,              // 27 43 0xAC I2S irq, dmareq1, dmareq2
    isr_enet,             // 28 44 0xB0 Ethernet WakeupInt, SoftInt, TxDoneInt, TxFinishedInt, TxErrorInt, TxUnderrunInt, RxDoneInt, RxFinishedInt, RxErrorInt, RxOverrunInt.
    isr_rit,              // 29 45 0xB4 Repetitive Interrupt Timer RITINT
    isr_mcpwm,            // 30 46 0xB8 Motor Control PWM IPER[2:0], IPW[2:0], ICAP[2:0], FES
    isr_qei,              // 31 47 0xBC Quadrature Encoder INX_Int, TIM_Int, VELC_Int, DIR_Int, ERR_Int, ENCLK_Int, POS0_Int, POS1_Int, POS2_Int, REV_Int, POS0REV_Int, POS1REV_Int, POS2REV_Int
    isr_pll1,             // 32 48 0xC0 PLL1 (USB PLL) PLL1 Lock (PLOCK1)
    isr_usbact,           // 33 49 0xC4 USB Activity Interrupt USB_NEED_CLK
    isr_canact,           // 34 50 0xC8 CAN Activity Interrupt CAN1WAKE, CAN2WAKE                                                                                                                                                                                 
    isr_soft0             // 35 51      This is probably the wraong way to do this.
};


void isr_default(void){
    while(true){
    }
}






































