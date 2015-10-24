#include "hwdef_clock.h"
#include "hwdef_gpio.h"
#include "system.h"

static inline void main_pll_feed(void){
        PLL0_FEED.feed=0xAA;
        PLL0_FEED.feed=0x55;
}


void system_clock_initialize(void){

    if(PLL0_STATUS.connected){
        PLL0_CTL.connect=0;
        main_pll_feed();
    }

    if(PLL0_STATUS.enabled){
        PLL0_CTL.enable=0;
        main_pll_feed();
    }

    if(!XTAL_OSCILLATOR.enable){
        XTAL_OSCILLATOR.range=0;  //12MHz Crystal
        XTAL_OSCILLATOR.enable=1;
    }

    while(!XTAL_OSCILLATOR.status){
    }

    CORE_CLOCK_OUTPUT.divider=0;
    PLL0_SOURCE_SELECT.source=1;
    main_pll_feed(); 

    PLL0_CONFIG.m=19;
    main_pll_feed();
    PLL0_CONFIG.n=3; 
    main_pll_feed();
    PLL0_CTL.enable=1;
    main_pll_feed();

    CORE_CLOCK_OUTPUT.divider=0;
    while(!PLL0_STATUS.locked){}
    
    PLL0_CTL.connect=1;
    main_pll_feed();
} 

void gpio_setup(void){
    

}

void gpio_toggle(void){

}

