#ifndef __HWDEF_GPIO_H
#define __HWDEF_GPIO_H

typedef struct{
    unsigned pin0    : 1;
    unsigned pin1    : 1;
    unsigned pin2    : 1;
    unsigned pin3    : 1;
    unsigned pin4    : 1;
    unsigned pin5    : 1;
    unsigned pin6    : 1;
    unsigned pin7    : 1;
    unsigned pin8    : 1;
    unsigned pin9    : 1;
    unsigned pin10   : 1;
    unsigned pin11   : 1;
    unsigned pin12   : 1;
    unsigned pin13   : 1;
    unsigned pin14   : 1;
    unsigned pin15   : 1;
    unsigned pin16   : 1;
    unsigned pin17   : 1;
    unsigned pin18   : 1;
    unsigned pin19   : 1;
    unsigned pin20   : 1;
    unsigned pin21   : 1;
    unsigned pin22   : 1;
    unsigned pin23   : 1;
    unsigned pin24   : 1;
    unsigned pin25   : 1;
    unsigned pin26   : 1;
    unsigned pin27   : 1;
    unsigned pin28   : 1;
    unsigned pin29   : 1;
    unsigned pin30   : 1;
    unsigned pin31   : 1;
}GPIOPort;

#define FIO0DIR (*(volatile GPIOPort *)(0x2009C000))
#define FIO1DIR (*(volatile GPIOPort *)(0x2009C020))
#define FIO2DIR (*(volatile GPIOPort *)(0x2009C040))
#define FIO3DIR (*(volatile GPIOPort *)(0x2009C060))
#define FIO4DIR (*(volatile GPIOPort *)(0x2009C080))

#define FIO0SET (*(volatile GPIOPort *)(0x2009C018))
#define FIO1SET (*(volatile GPIOPort *)(0x2009C038))
#define FIO2SET (*(volatile GPIOPort *)(0x2009C058))
#define FIO3SET (*(volatile GPIOPort *)(0x2009C078))
#define FIO4SET (*(volatile GPIOPort *)(0x2009C098))

#define FIO0CLR (*(volatile GPIOPort *)(0x2009C01C))
#define FIO1CLR (*(volatile GPIOPort *)(0x2009C03C))
#define FIO2CLR (*(volatile GPIOPort *)(0x2009C05C))
#define FIO3CLR (*(volatile GPIOPort *)(0x2009C07C))
#define FIO4CLR (*(volatile GPIOPort *)(0x2009C09C))

#define FIO0VAL (*(volatile GPIOPort *)(0x2009C014))
#define FIO1VAL (*(volatile GPIOPort *)(0x2009C034))
#define FIO2VAL (*(volatile GPIOPort *)(0x2009C054))
#define FIO3VAL (*(volatile GPIOPort *)(0x2009C074))
#define FIO4VAL (*(volatile GPIOPort *)(0x2009C094))

#define FIO0MSK (*(volatile GPIOPort *)(0x2009C010))
#define FIO1MSK (*(volatile GPIOPort *)(0x2009C030))
#define FIO2MSK (*(volatile GPIOPort *)(0x2009C050))
#define FIO3MSK (*(volatile GPIOPort *)(0x2009C070))
#define FIO4MSK (*(volatile GPIOPort *)(0x2009C090))

#endif //__HWDEF_GPIO_H
