#ifndef __SYSTEM_H
#define __SYSTEM_H
#include "micro_types.h"

uint32_t system_core_clock(void);

//uart0 debug
void uart0_send(char *msg);
void uart0_send_message(uint8_t *msg, uint32_t len);
void uart0_initialize(void);

//gpio stuff
void gpio_initialize(void);
void gpio_toggle(void);
void gpio_on(void);
void gpio_off(void);

//nrz for neopixels
void nrz0_initialize(void);
void nrz0_disable(void);
void nrz0_enable(void);
void nrz0_send_message(uint8_t *bytes, uint32_t len);

//threads
void main00(void);
void main01(void);
void main02(void);
void main03(void);
void exit(void);


#endif //__SYSTEM_H
