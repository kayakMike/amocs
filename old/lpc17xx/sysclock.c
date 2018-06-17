#include "clock.h"
#include "sysclock.h"


static inline void main_pll_feed(void){
    PLL0_FEED.feed = 0xAA;
    PLL0_FEED.feed = 0x55;
}

/*   @@ see section 4.5.10 of UM1036.pdf
 *   Given that there is a 12MGHz Crystal 
 *     goal is 120MGHz CPU
 *     CORE_CLOCK=Fcco/div
 *     Fcco=(2*m*Fin)/n
 *     120=((2*15*12)/1)/3
 *     
 *     m   = 15    msel    = 14
 *     n   = 1     nsel    = 1
 *     div = 3     divider = 2
 */
void sysclock_setMainClock120MHZ(void){
    
    //disconnect PLL0
    if(PLL0_STATUS.connected){
        PLL0_CTL.connect = 0;
        main_pll_feed();
    }

    //enable PLL0
    if(PLL0_STATUS.enabled){
        PLL0_CTL.enable = 0;
        main_pll_feed();
    }

    //enable XTAL
    if(!XTAL_OSCILLATOR.enable){
        XTAL_OSCILLATOR.range  = 0;  //12MHz Crystal
        XTAL_OSCILLATOR.enable = 1;
        while(XTAL_OSCILLATOR.status == 0){
           //spin on this	
	}
    }

    CORE_CLOCK_OUTPUT.divider =  2;
    PLL0_SELECT.source        =  1;
    PLL0_CONFIG.msel          = 14;
    main_pll_feed();         
    PLL0_CONFIG.nsel          =  0; 
    main_pll_feed();         
    PLL0_CTL.enable           =  1;
    main_pll_feed();

    //wait for PLL to lock
    while(PLL0_STATUS.locked == 0){
        //spin here 
    }

    CORE_CLOCK_OUTPUT.divider = 2;
    //enable and connect!
    PLL0_CTL_VALUE = 0x03;
    main_pll_feed();
}

/* use the values in the main PLL settings to determine the core clock
*/
uint32_t sysclock_computeMainClock(void){
    uint32_t clk_speed = 0;
    if(PLL0_STATUS.connected == 1){
        uint32_t m   = PLL0_STATUS.msel + 1;
        uint32_t n   = PLL0_STATUS.nsel + 1;
        uint32_t div =CORE_CLOCK_OUTPUT.divider+1;
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
