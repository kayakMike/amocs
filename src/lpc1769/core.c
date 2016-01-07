#include "system.h"
#include "clock.h"

#define IRC_OSCILLATOR  4000000
#define MAIN_OSCILLATOR 12000000
#define RTC_OSCILLATOR  32768


extern uint32_t _text_end;
extern uint32_t _bss_start;
extern uint32_t _bss_end;
extern uint32_t _data_start;
extern uint32_t _data_end;
extern uint32_t _datai_start;
extern uint32_t _sidata;


void sysinit_memory(void);
void system_clock_initialize(void);

//Reset ISR, the main entry point!
void Reset_ISR(void){
    sysinit_memory();
    system_clock_initialize();

    gpio_initialize();
    nrz0_initialize();
    uart0_initialize();
    initialize_stacks();
    initialize_systick();
    
    main00();
} 

static inline void main_pll_feed(void){
    PLL0_FEED.feed=0xAA;
    PLL0_FEED.feed=0x55;
}

/*
 *   12MGHz Crystal 
 *     goal is 120MGHz CPU
 *     CORE_CLOCK=Fcco/div
 *     Fcco=(2*m*Fin)/n
 *     120=((2*15*12)/1)/3
 *
 *     m=15    msel=14
 *     n=1     nsel=1
 *     div=3   divider=2
 */
void system_clock_initialize(void){

    //disconnect PLL0
    if(PLL0_STATUS.connected){
        PLL0_CTL.connect=0;
        main_pll_feed();
    }
    
    //enable PLL0
    if(PLL0_STATUS.enabled){
        PLL0_CTL.enable=0;
        main_pll_feed();
    }

    //enable XTAL
    if(!XTAL_OSCILLATOR.enable){
        XTAL_OSCILLATOR.range=0;  //12MHz Crystal
        XTAL_OSCILLATOR.enable=1;
        while(XTAL_OSCILLATOR.status==0){}
    }
    CORE_CLOCK_OUTPUT.divider=2;

    PLL0_SELECT.source=1;

    PLL0_CONFIG.msel=14;
    main_pll_feed();

    PLL0_CONFIG.nsel=0; 
    main_pll_feed();

    PLL0_CTL.enable=1;
    main_pll_feed();

    while(PLL0_STATUS.locked==0){}
    
    CORE_CLOCK_OUTPUT.divider=2;

    PLL0_CTL_VALUE=0x03;; //enable and connect
    main_pll_feed();
}

uint32_t system_core_clock(void){
    uint32_t clk_speed=0;
    if(PLL0_STATUS.connected==1){
        uint32_t m=PLL0_STATUS.msel+1;
        uint32_t n=PLL0_STATUS.nsel+1;
        uint32_t div=CORE_CLOCK_OUTPUT.divider+1;
        switch(PLL0_SELECT.source){
            case 0:
                clk_speed=(2*m*IRC_OSCILLATOR)/(n*div);
                break;
            case 1:
                clk_speed=(2*m*MAIN_OSCILLATOR)/(n*div);
                break;
            case 2:
                clk_speed=(2*m*RTC_OSCILLATOR)/(n*div);
                break;
            default:
                clk_speed=0;
                break;
        }
    }
    else{
        clk_speed=IRC_OSCILLATOR;
    }
    return clk_speed; 
}

//MemCopy Stuff. Note  that the buffers are 4 Byte Alligned
void sysinit_memory(void){
    uint32_t *data_begin   = &_data_start;
    uint32_t *data_end     = &_data_end;
    uint32_t *datai_begin  = &_sidata;
    uint32_t *bss_ptr      = &_bss_start;
    //INIT DATA:  copies data section from flash to ram
    while(data_begin < data_end){
        *data_begin = *datai_begin;
        data_begin++;
        datai_begin++;
    }
    //INIT BSS: loads a bunch of zeroes to bss section
    while (bss_ptr < &_bss_end){
        *bss_ptr++ = 0;
    }
}
