#ifndef __HWDEF_GPIO_H
#define __HWDEF_GPIO_H

/*typedef struct{
    unsigned pin00   : 1;
    unsigned pin01   : 1;
    unsigned pin02   : 1;
    unsigned pin03   : 1;
    unsigned pin04   : 1;
    unsigned pin05   : 1;
    unsigned pin06   : 1;
    unsigned pin07   : 1;
    unsigned pin08   : 1;
    unsigned pin09   : 1;
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
*/


#define PORT0_DIR (*(volatile uint32_t *)(0x2009C000))
#define PORT1_DIR (*(volatile uint32_t *)(0x2009C020))
#define PORT2_DIR (*(volatile uint32_t *)(0x2009C040))
#define PORT3_DIR (*(volatile uint32_t *)(0x2009C060))
#define PORT4_DIR (*(volatile uint32_t *)(0x2009C080))

#define PORT0_SET (*(volatile uint32_t *)(0x2009C018))
#define PORT1_SET (*(volatile uint32_t *)(0x2009C038))
#define PORT2_SET (*(volatile uint32_t *)(0x2009C058))
#define PORT3_SET (*(volatile uint32_t *)(0x2009C078))
#define PORT4_SET (*(volatile uint32_t *)(0x2009C098))

#define PORT0_CLR (*(volatile uint32_t *)(0x2009C01C))
#define PORT1_CLR (*(volatile uint32_t *)(0x2009C03C))
#define PORT2_CLR (*(volatile uint32_t *)(0x2009C05C))
#define PORT3_CLR (*(volatile uint32_t *)(0x2009C07C))
#define PORT4_CLR (*(volatile uint32_t *)(0x2009C09C))

#define PORT0_VAL (*(volatile uint32_t *)(0x2009C014))
#define PORT1_VAL (*(volatile uint32_t *)(0x2009C034))
#define PORT2_VAL (*(volatile uint32_t *)(0x2009C054))
#define PORT3_VAL (*(volatile uint32_t *)(0x2009C074))
#define PORT4_VAL (*(volatile uint32_t *)(0x2009C094))

#define PORT0_MSK (*(volatile uint32_t *)(0x2009C010))
#define PORT1_MSK (*(volatile uint32_t *)(0x2009C030))
#define PORT2_MSK (*(volatile uint32_t *)(0x2009C050))
#define PORT3_MSK (*(volatile uint32_t *)(0x2009C070))
#define PORT4_MSK (*(volatile uint32_t *)(0x2009C090))

#endif //__HWDEF_GPIO_H
