#ifndef __SYSTEM_H
#define __SYSTEM_H
#include "system.h"
#include "micro_types.h"

void uart0_send(char *msg);
void uart0_send_message(uint8_t *msg, uint32_t len);

void send_message(uint8_t *message, uint32_t count);
void uart0_initialize(void);

void system_clock_initialize(void);
uint32_t system_core_clock(void);

void init_vtable(void);

void gpio_toggle(void);
void gpio_setup(void);
void gpio_on(void);
void gpio_off(void);

void Timer0_Handler(void);
void Timer0_Initialize(void);

void nrz0_disable(void);
void nrz0_enable(void);
void nrz0_send_message(uint8_t *bytes, uint32_t len);

void main00(void);
void main01(void);
void main02(void);
void main03(void);

void Default_Handler         (void);
void Reset_Handler           (void);
void NMI_Handler             (void);
void HardFault_Handler       (void);
void MemManage_Handler       (void);
void BusFault_Handler        (void);
void UsageFault_Handler      (void);
void SVC_Handler             (void);
void DebugMon_Handler        (void);
void PendSV_Handler          (void);
void SysTick_Handler         (void) __attribute__ ((interrupt,naked));
void WatchDog_Handler        (void);

extern uint32_t _stack_init;
extern uint32_t _text_end;
extern uint32_t _bss_start;
extern uint32_t _bss_end;
extern uint32_t _data_start;
extern uint32_t _data_end;
extern uint32_t _datai_start;
extern uint32_t _sidata;


#endif //__SYSTEM_H
