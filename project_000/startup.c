#include "startup.h"
#include "meminit.h"
#include "types.h"

// these are all referenced in the linker script
// and describe the bss and data sections
//
extern void *bss;
extern size_t bss_size;
extern void *data_start;
extern void *data;
extern size_t data_size;

//void *stack_address __attribute__ (section(".startup")) = STACK_ADDRESS;

void *stack_address = STACK_ADDRESS;
void main(uint32_t argc, uint8_t **argv);


// stack init is obtained in the linker script
// externvoid *system_stack; 
//the attribute links to the "vectors" location described in the linker script
//void (*isr_table[ISR_TABLE_LENGTH])(void) __attribute__ ((section(".startup")))={
void (*isr_table[ISR_TABLE_LENGTH])(void)=
{
    isr_reset,            //    1       
    isr_nmi,              //    2 
    isr_hardfault,        //    3 
    isr_memmanage,        //    4 
    isr_busfault,         //    5 
    isr_usagefault,       //    6 
    NULL,                 //    7 
    NULL,                 //    8 
    NULL,                 //    9 
    NULL,                 //    10
    isr_svc,              //-5  11
    isr_debugmon,         //-4  12
    NULL,                 //-3  13
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
    NULL,                 //    51 
    NULL,                 //    52
    NULL,                 //    53
    NULL,                 //    54
    NULL,                 //    55
    NULL,                 //    56
    NULL,                 //    57
    NULL,                 //    58
    NULL,                 //    59
    NULL,                 //    60
    NULL,                 //    61
    NULL,                 //    62
    NULL,                 //    63
    NULL                  //    64
};


void isr_default(void){
    while(TRUE){
    }
}



/*  The system is started in the isr reset handler
 * 
 */
void isr_reset(void)
{
    memcpy(data, data_start, data_size);
    memset(bss, 0, bss_size);

    //init_data(&_data_start, &_data_end, &_sidata);
    //init_bss(&_bss_start, &_bss_end);
    //call main
    main(0, NULL);
    while(TRUE)
    {
        //do nothing
        //this is what the system does if main ever exits
    }
} 

