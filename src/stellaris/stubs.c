#include "system.h"

void system_clock_initialize(void){}
uint32_t system_core_clock(void){
    return 0xFFFFFFFF;
}
void gpio_setup(void){}
void gpio_toggle(void){}
void gpio_on(void){}
void gpio_off(void){}


void Timer0_Handler(void){}
void Timer0_Initialize(void){}

void nrz0_disable(void){}
void nrz0_enable(void){}
void nrz0_send_message(uint8_t *bytes, uint32_t len){}

