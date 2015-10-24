#ifndef __HWDEF_GPIO_H
#define __HWDEF_GPIO_H

typedef struct{
    unsigned pin0   : 1;
    unsigned pin1   : 1;
    unsigned pin2   : 1;
    unsigned pin3   : 1;
    unsigned pin4   : 1;
    unsigned pin5   : 1;
    unsigned pin6   : 1;
    unsigned pin7   : 1;
    unsigned        :24;
}FIO0Direction0;

#define FIO_0_DIR_0 (*(volatile GPIODirection0 *)(0x2009C000))
#define FIO_1_DIR_0 (*(volatile GPIODirection0 *)(0x2009C020))
#define FIO_2_DIR_0 (*(volatile GPIODirection0 *)(0x2009C040))
#define FIO_3_DIR_0 (*(volatile GPIODirection0 *)(0x2009C060))
#define FIO_4_DIR_0 (*(volatile GPIODirection0 *)(0x2009C080))


typedef struct{
    unsigned pin8   : 1;
    unsigned pin9   : 1;
    unsigned pin10  : 1;
    unsigned pin11  : 1;
    unsigned pin12  : 1;
    unsigned pin13  : 1;
    unsigned pin14  : 1;
    unsigned pin15  : 1;
    unsigned        :24;
}GPIODirection1;
/*
#define FIO_0_DIR_1 (*(volatile GPIODirection1 *)(0x2009C000))
#define FIO_1_DIR_1 (*(volatile GPIODirection1 *)(0x2009C020))
#define FIO_2_DIR_1 (*(volatile GPIODirection1 *)(0x2009C040))
#define FIO_3_DIR_1 (*(volatile GPIODirection1 *)(0x2009C060))
#define FIO_4_DIR_1 (*(volatile GPIODirection1 *)(0x2009C080))
*/
typedef struct{
    unsigned pin0   : 1;
    unsigned pin1   : 1;
    unsigned pin2   : 1;
    unsigned pin3   : 1;
    unsigned pin4   : 1;
    unsigned pin5   : 1;
    unsigned pin6   : 1;
    unsigned pin7   : 1;
    unsigned        :24;
}GPIOSet0;

#define FIO_0_SET_0 (*(volatile GPIOSet0 *)(0x2009C018))
#define FIO_1_SET_0 (*(volatile GPIOSet0 *)(0x2009C038))
#define FIO_2_SET_0 (*(volatile GPIOSet0 *)(0x2009C058))
#define FIO_3_SET_0 (*(volatile GPIOSet0 *)(0x2009C078))
#define FIO_4_SET_0 (*(volatile GPIOSet0 *)(0x2009C098))

typedef struct{
    unsigned pin0   : 1;
    unsigned pin1   : 1;
    unsigned pin2   : 1;
    unsigned pin3   : 1;
    unsigned pin4   : 1;
    unsigned pin5   : 1;
    unsigned pin6   : 1;
    unsigned pin7   : 1;
    unsigned        :24;
}GPIOClear0;

#define FIO_0_CLR_0 (*(volatile GPIOClear0 *)(0x2009C01C))
#define FIO_1_CLR_0 (*(volatile GPIOClear0 *)(0x2009C03C))
#define FIO_2_CLR_0 (*(volatile GPIOClear0 *)(0x2009C05C))
#define FIO_3_CLR_0 (*(volatile GPIOClear0 *)(0x2009C07C))
#define FIO_4_CLR_0 (*(volatile GPIOClear0 *)(0x2009C09C))

#endif //__HWDEF_GPIO_H
