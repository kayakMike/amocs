#ifndef __HWDEF_CLOCK_H
#define __HWDEF_CLOCK_H

#include "micro_types.h"


typedef struct{
   unsigned source    : 2;   
   //0 internal IRC, 1 main osc, 2 real time clock; 
   unsigned           :30;
}PLL0SourceSelect;
#define PLL0_SOURCE_SELECT (*(volatile PLL0SourceSelect *)(0x400FC10C))

typedef struct{
   unsigned enable     : 1;
   unsigned connect    : 1;
   unsigned            :30;
}PLL0Control;
#define PLL0_CTL (*(volatile PLL0Control *)(0x400FC080))

typedef struct{
   unsigned m          :15;
   unsigned            : 1;
   unsigned n          : 8;
   unsigned            : 8;
}PLL0Config;
#define PLL0_CONFIG (*(volatile PLL0Config *)(0x400FC084))

typedef struct{
   unsigned m          :15;
   unsigned            : 1;
   unsigned n          : 8;
   unsigned enabled    : 1;
   unsigned connected  : 1;
   unsigned locked     : 1;
   unsigned            : 5;
}PLL0Status;
#define PLL0_STATUS (*(volatile PLL0Status *)(0x400FC088))

typedef struct{
   unsigned feed      : 8;
   unsigned           :24;
}PLL0Feed;
//PLL0 FEED SEQUENCE:  0xAA 0x55
#define PLL0_FEED (*(volatile PLL0Feed *)(0x400FC08C))

typedef struct{
   unsigned           : 4;
   unsigned range     : 1;
   unsigned enable    : 1;
   unsigned status    : 1;
   unsigned           :25;
}XtalOscillator;
#define XTAL_OSCILLATOR (*(volatile XtalOscillator *)(0x400FC1A0))

typedef struct{
   unsigned divider   : 8;
   unsigned           :24;
}CoreClockOutput;
#define CORE_CLOCK_OUTPUT (*(volatile CoreClockOutput *)(0x400FC014))


#endif //__HWDEF_CLOCK_H
