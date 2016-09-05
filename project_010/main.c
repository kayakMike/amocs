#include "types.h"

//from the lpc1769 data sheet
#define PORT4_DIR (*(volatile uint32_t *)(0x2009C080))
#define PORT4_SET (*(volatile uint32_t *)(0x2009C098))
#define PORT4_CLR (*(volatile uint32_t *)(0x2009C09C))
#define PORT4_VAL (*(volatile uint32_t *)(0x2009C094))
#define PIN28 (1<<28)

enum clock_select{
   IRC  = 0,
   XTAL = 1,
   RTC  = 2
}; 

void sclk_configure(uint8_t clk_select, uint16_t m_select, uint8_t n_select, uint8_t divider);
void xosc_enable(uint32_t frequency);
void pll0_enable(void);
void pll0_disable(void);
void pll0_connect(void);
void pll0_disconnect(void);

int main(int argc, char **argv)
{
    //sclk_configure(1, 14, 0, 2); 
    PORT4_DIR = PORT4_DIR | PIN28;
    //while(TRUE) {
    //    PORT4_CLR = PIN28;
    //    PORT4_SET = PIN28;
    //}
 
    asm volatile(
    "    ldr r2, .port4set        \n"
    "    ldr r3, .port4clr        \n"
    "    mov r1, #268435456       \n" 
    ".loop:                       \n"
    "    str r1, [r2]             \n"
    "    nop                      \n"
    "    nop                      \n"
    "    str r1, [r3]             \n"
    "    b .loop                  \n"
    ".port4set:                   \n"
	"    .word	537510044         \n"
    ".port4clr:                   \n"
	"    .word	537510040         \n"
    : : :
    );




    return 0;
}

// this is characteristic of the chip
#define IRC_FREQ  4000000

// these are characteristic of the dev board
#define XOS_FREQ 12000000
#define RTC_FREQ  32768

struct PLL0Status {
   unsigned m_select   :15;
   unsigned            : 1;
   unsigned n_select   : 8;
   unsigned enable     : 1;
   unsigned connect    : 1;
   unsigned lock       : 1;
   unsigned            : 5;
};
#define PLL0_STATUS (*(volatile struct PLL0Status *)(0x400FC088))
#define PLL0_CONFIG (*(volatile struct PLL0Status *)(0x400FC084))

struct PLL0Feed {
   unsigned feed      : 8;
   unsigned           :24;
};
//PLL0 FEED SEQUENCE:  0xAA 0x55
#define PLL0_FEED (*(volatile struct PLL0Feed *)(0x400FC08C))

struct XosControl {
   unsigned           : 4;
   unsigned range     : 1;
   unsigned enable    : 1;
   unsigned status    : 1;
   unsigned           :25;
};
#define XOS_CONTROL (*(volatile struct XosControl *)(0x400FC1A0))

struct PLL0ClockSelect {
   //0 internal IRC, 1 main osc, 2 real time clock; 
   unsigned source    : 2;   
   unsigned           :30;
};
#define PLL0_CLOCKSELECT (*(volatile struct PLL0ClockSelect *)(0x400FC10C))

struct PLL0Control {
   unsigned enable     : 1;  // 
   unsigned connect    : 1;
   unsigned            :30;
};
#define PLL0_CONTROL (*(volatile struct PLL0Control *)(0x400FC080))
    

void pll0_disconnect(void)
{
    //disconnect PLL0
    if(PLL0_STATUS.connect == 1) {
        PLL0_CONTROL.connect=0;
        PLL0_FEED.feed=0xAA;
        PLL0_FEED.feed=0x55;
    }
}

void pll0_connect(void)
{
    if(PLL0_STATUS.connect == 0) {
        PLL0_CONTROL.connect=1;
        PLL0_FEED.feed=0xAA;
        PLL0_FEED.feed=0x55;
    }
}

void pll0_disable(void)
{
    //enable PLL0
    if(PLL0_STATUS.enable == 1) {
        PLL0_CONTROL.enable=0;
        PLL0_FEED.feed=0xAA;
        PLL0_FEED.feed=0x55;
    }
}

void xosc_enable(uint32_t frequency)
{
    //enable XTAL
    if(XOS_CONTROL.enable == 0) {
        //manual says 1MHz to 20MHz range is 0
        //or 15MHz to 25MHz range is 1
        if(frequency < 15000000) {
            XOS_CONTROL.range = 0; 
        }
        else {
            XOS_CONTROL.range = 1; 
        }

        XOS_CONTROL.enable = 1;
        while(XOS_CONTROL.status == 0 ) {
            //NO OPERATION -- BLOCK
        }
    }
}

void pll0_enable(void)
{
    if(PLL0_STATUS.enable == 0) {
        PLL0_CONTROL.enable = 1;
        PLL0_FEED.feed = 0xAA;
        PLL0_FEED.feed = 0x55;
        while(PLL0_STATUS.lock == 0) {
            //NO OPERATION
        }
    }
}




//typedef struct{
//   unsigned value   : 8;
//   unsigned         :24;
//}CoreClockDivider;
//#define CORE_CLOCK_DIVIDER (*(volatile CoreClockDivider *)(0x400FC104))
#define CORE_CLOCK_DIVIDER (*(volatile uint8_t *)(0x400FC104))

/*   @@ see section 4.5.10 of UM1036.pdf
 *   Given that there is a 12MGHz Crystal 
 *     goal is 120MGHz CPU
 *     CORE_CLOCK=Fcco/div
 *     Fcco=(2*m*Fin)/n
 *     120=((2*15*12)/1)/3
 *     
 *     m=15    msel=14
 *     n=1     nsel=1
 *     div=3   divider=2
 *     TODO:  source, m, n, and div are input values
 */
void sclk_configure(uint8_t clk_select, uint16_t m_select, uint8_t n_select, uint8_t divider)
{

    pll0_disconnect();
    pll0_disable();
    if(clk_select == 1){
        xosc_enable(XOS_FREQ);
    }

    PLL0_CLOCKSELECT.source = 1;  // MAIN_OSCILLATOR

    PLL0_CONFIG.m_select = m_select;
    PLL0_FEED.feed = 0xAA;
    PLL0_FEED.feed = 0x55;
    PLL0_CONFIG.n_select = n_select; 
    PLL0_FEED.feed = 0xAA;
    PLL0_FEED.feed = 0x55;
    CORE_CLOCK_DIVIDER = divider;

    pll0_enable();
    pll0_connect();
}
