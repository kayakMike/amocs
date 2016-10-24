#include "types.h"

void isr_reset      (void) __attribute__((weak,alias("isr_default")));
void isr_nmi        (void) __attribute__((weak,alias("isr_default")));
void isr_hardfault  (void) __attribute__((weak,alias("isr_default")));
void isr_svc        (void) __attribute__((weak,alias("isr_default")));
void isr_pendsv     (void) __attribute__((weak,alias("isr_default")));
void isr_sysTick    (void) __attribute__((weak,alias("isr_default")));
void isr_spi0       (void) __attribute__((weak,alias("isr_default")));
void isr_spi1       (void) __attribute__((weak,alias("isr_default")));
void isr_uart0      (void) __attribute__((weak,alias("isr_default")));
void isr_uart1      (void) __attribute__((weak,alias("isr_default")));
void isr_uart2      (void) __attribute__((weak,alias("isr_default")));
void isr_i2c0       (void) __attribute__((weak,alias("isr_default")));
void isr_i2c1       (void) __attribute__((weak,alias("isr_default")));
void isr_i2c2       (void) __attribute__((weak,alias("isr_default")));
void isr_i2c3       (void) __attribute__((weak,alias("isr_default")));
void isr_sct        (void) __attribute__((weak,alias("isr_default")));
void isr_wdt        (void) __attribute__((weak,alias("isr_default")));
void isr_dma        (void) __attribute__((weak,alias("isr_default")));
void isr_mrt        (void) __attribute__((weak,alias("isr_default")));
void isr_cmp        (void) __attribute__((weak,alias("isr_default")));
void isr_bod        (void) __attribute__((weak,alias("isr_default")));
void isr_wkt        (void) __attribute__((weak,alias("isr_default")));
void isr_flash      (void) __attribute__((weak,alias("isr_default")));
void isr_adcseqa    (void) __attribute__((weak,alias("isr_default")));
void isr_adcseqb    (void) __attribute__((weak,alias("isr_default")));
void isr_adcthcmp   (void) __attribute__((weak,alias("isr_default")));
void isr_adcovr     (void) __attribute__((weak,alias("isr_default")));
void isr_pinint0    (void) __attribute__((weak,alias("isr_default"))); 
void isr_pinint1    (void) __attribute__((weak,alias("isr_default")));
void isr_pinint2    (void) __attribute__((weak,alias("isr_default")));
void isr_pinint3    (void) __attribute__((weak,alias("isr_default")));
void isr_pinint4    (void) __attribute__((weak,alias("isr_default")));
void isr_pinint5    (void) __attribute__((weak,alias("isr_default")));
void isr_pinint6    (void) __attribute__((weak,alias("isr_default")));
void isr_pinint8    (void) __attribute__((weak,alias("isr_default")));

// stack init is obtained in the linker script
extern uint32_t _stack_init;

//the attribute links to the "vectors" location described in the linker script
void (*vectors[64])(void) __attribute__ ((section(".vectors")))={
    (void *)&_stack_init, //    0 
    isr_reset,            //    1       
    isr_nmi,              //    2 
    isr_hardfault,        //    3 
    0,                    //    4 
    0,                    //    5 
    0,                    //    6 
    0,                    //    7 
    0,                    //    8 
    0,                    //    9 
    0,                    //    10
    isr_svc,              //-5  11
    0,                    //-4  12
    0,                    //-3  13
    isr_pendsv,           //-2  14
    isr_sysTick,          //-1  15 
    isr_spi0,             // 0  16 0x40 
    isr_spi1,             // 1  17 0x44 
    0,                    // 2  18 0x48 
    isr_uart0,            // 3  19 0x4C
    isr_uart1,            // 4  20 0x50
    isr_uart2,            // 5  21 0x54
    0,                    // 6  22 0x58
    isr_i2c1,             // 7  23 0x5C
    isr_i2c0,             // 8  24 0x60
    isr_sct,              // 9  25 0x64
    isr_mrt,              // 10 26 0x68
    isr_cmp,              // 11 27 0x6C
    isr_wdt,              // 12 28 0x70
    isr_bod,              // 13 29 0x74
    isr_flash,            // 14 30 0x78
    isr_wkt,              // 15 31 0x7C
    isr_adcseqa,          // 16 32 0x80
    isr_adcseqb,          // 17 32 0x80
    isr_adcthcmp,         // 18 32 0x80
    isr_adcovr,           // 19 32 0x80
    isr_dma,              // 20 32 0x80
    isr_i2c2,             // 21 32 0x80
    isr_i2c3,             // 22 32 0x80
    0,                    // 23 32 0x80
    isr_pinint0,          // 24 32 0x80
    isr_pinint1,          // 25 32 0x80
    isr_pinint2,          // 26 32 0x80
    isr_pinint3,          // 27 32 0x80
    isr_pinint4,          // 28 32 0x80
    isr_pinint5,          // 29 32 0x80
    isr_pinint6,          // 30 32 0x80
    isr_pinint8           // 31 32 0x80
};


void isr_default(void){
    while(TRUE){
    }
}

