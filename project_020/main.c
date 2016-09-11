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
void blink_loop(void);
void simple_sleep(uint32_t loops);
void simple_blink(uint32_t *dir, uint32_t *set, uint32_t *clr);
void initialize_hd44780(void);

//bit band for GPIO port4 pin 28
#define P4_28DIR *((volatile uint32_t *)((0x9C080*0x20) + (4*28) + 0x22000000))
#define P4_28SET *((volatile uint32_t *)((0x9C098*0x20) + (4*28) + 0x22000000))
#define P4_28CLR *((volatile uint32_t *)((0x9C09C*0x20) + (4*28) + 0x22000000))

#define B428DIR  (uint32_t *)((0x9C080*0x20) + (4*28) + 0x22000000) 
#define B428SET  (uint32_t *)((0x9C098*0x20) + (4*28) + 0x22000000) 
#define B428CLR  (uint32_t *)((0x9C09C*0x20) + (4*28) + 0x22000000) 

#define B429DIR  (uint32_t *)((0x9C080*0x20) + (4*29) + 0x22000000) 
#define B429SET  (uint32_t *)((0x9C098*0x20) + (4*29) + 0x22000000) 
#define B429CLR  (uint32_t *)((0x9C09C*0x20) + (4*29) + 0x22000000) 

#define B325DIR  (uint32_t *)((0x9C060*0x20) + (4*25) + 0x22000000) 
#define B325SET  (uint32_t *)((0x9C078*0x20) + (4*25) + 0x22000000) 
#define B325CLR  (uint32_t *)((0x9C07C*0x20) + (4*25) + 0x22000000) 

#define B127DIR  (uint32_t *)((0x9C020*0x20) + (4*27) + 0x22000000) 
#define B127SET  (uint32_t *)((0x9C038*0x20) + (4*27) + 0x22000000) 
#define B127CLR  (uint32_t *)((0x9C03C*0x20) + (4*27) + 0x22000000) 

#define B124DIR  (uint32_t *)((0x9C020*0x20) + (4*24) + 0x22000000) 
#define B124SET  (uint32_t *)((0x9C038*0x20) + (4*24) + 0x22000000) 
#define B124CLR  (uint32_t *)((0x9C03C*0x20) + (4*24) + 0x22000000) 

#define B121DIR  (uint32_t *)((0x9C020*0x20) + (4*21) + 0x22000000) 
#define B121SET  (uint32_t *)((0x9C038*0x20) + (4*21) + 0x22000000) 
#define B121CLR  (uint32_t *)((0x9C03C*0x20) + (4*21) + 0x22000000) 

#define B118DIR  (uint32_t *)((0x9C020*0x20) + (4*18) + 0x22000000) 
#define B118SET  (uint32_t *)((0x9C038*0x20) + (4*18) + 0x22000000) 
#define B118CLR  (uint32_t *)((0x9C03C*0x20) + (4*18) + 0x22000000) 

#define B019DIR  (uint32_t *)((0x9C000*0x20) + (4*19) + 0x22000000) 
#define B019SET  (uint32_t *)((0x9C018*0x20) + (4*19) + 0x22000000) 
#define B019CLR  (uint32_t *)((0x9C01C*0x20) + (4*19) + 0x22000000) 

#define B326DIR  (uint32_t *)((0x9C060*0x20) + (4*26) + 0x22000000) 
#define B326SET  (uint32_t *)((0x9C078*0x20) + (4*26) + 0x22000000) 
#define B326CLR  (uint32_t *)((0x9C07C*0x20) + (4*26) + 0x22000000) 

#define B123DIR  (uint32_t *)((0x9C020*0x20) + (4*23) + 0x22000000) 
#define B123SET  (uint32_t *)((0x9C038*0x20) + (4*23) + 0x22000000) 
#define B123CLR  (uint32_t *)((0x9C03C*0x20) + (4*23) + 0x22000000) 

#define B120DIR  (uint32_t *)((0x9C020*0x20) + (4*20) + 0x22000000) 
#define B120SET  (uint32_t *)((0x9C038*0x20) + (4*20) + 0x22000000) 
#define B120CLR  (uint32_t *)((0x9C03C*0x20) + (4*20) + 0x22000000) 


void initialize_hd44780(void)
{
    *B429DIR = 1; //7
    *B325DIR = 1; //6
    *B127DIR = 1; //5 
    *B124DIR = 1; //4 
    *B121DIR = 1; //3 
    *B118DIR = 1; //2
    *B019DIR = 1; //1
    *B326DIR = 1; //0
    *B123DIR = 1; //en
    *B120DIR = 1; //rs

    *B326SET = 1;
    *B123SET = 1;
    simple_sleep(6000000);
    *B123CLR = 1;  
    simple_sleep(6000000);
    *B326CLR = 1;

    *B326SET = 1;
    *B019SET = 1;
    *B118SET = 1;
    *B123SET = 1;
    simple_sleep(6000000);
    *B123CLR = 1;  
    simple_sleep(6000000);
    *B326SET = 0;
    *B019SET = 0;
    *B118SET = 0;
}

int main(int argc, char **argv)
{
    sclk_configure(1, 14, 0, 2); 
    initialize_hd44780();
    simple_blink(B428DIR, B428SET, B428CLR);
//    P4_28DIR = 1;
//    while(TRUE){
//        P4_28CLR = 1;
//        simple_sleep(40000);
//        P4_28SET = 1;
//        simple_sleep(40000);
//    }
    return 0;
}

void simple_blink(uint32_t *dir, uint32_t *set, uint32_t *clr)
{
    *dir = 1;
    while(TRUE){
        *clr = 1;
        simple_sleep(6000000);
        *set = 1;
        simple_sleep(6000000);
    }
}

void simple_sleep(volatile uint32_t loops)
{
    while(loops > 0){
        loops--;
    }
}

void blink_loop(void)
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
    "    mov r1, #268435456       \n"  // (1<28) 
    ".loop:                       \n"
    "    str r1, [r2]             \n"
    "    nop                      \n"
    "    nop                      \n"
    "    str r1, [r3]             \n"
    "    b .loop                  \n"
    ".port4set:                   \n"
	"    .word	537510044         \n" // memory locations 0x209C098 
    ".port4clr:                   \n"
	"    .word	537510040         \n" // memory locations 0x209C09C
    : : :
    );

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
