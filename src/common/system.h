#ifndef __SYSTEM_H
#define __SYSTEM_H
#include "micro_types.h"

uint32_t core_compute_main_clock(void);

//uart0 debug
void uart0_send(uint8_t *msg);
void uart0_send_message(uint8_t *msg, uint32_t len);
void uart0_initialize(void);

void uart2_send(uint8_t *msg);
void uart2_send_message(uint8_t *msg, uint32_t len);
void uart2_initialize(void);

//gpio stuff
void gpio_initialize(void);
void gpio_on(void);
void gpio_off(void);

void gpio_toggle027(void);
void gpio_toggle020(void);

//nrz for neopixels
void nrz0_initialize(void);
void nrz0_disable(void);
void nrz0_enable(void);
void nrz0_send_message(uint8_t *bytes, uint32_t len);

//(processes)
void main00(void);
void main01(void);
void main02(void);
void main03(void);

//systick
typedef struct SoftTimer{
    uint32_t period;
    uint32_t end;
    void *arg;
    void (*callback)(void *arg);
}SoftTimer;

void systick_initialize(void);
uint32_t systick_return_uptime(void);
void isr_systick(void) __attribute__((interrupt));
uint8_t systick_register_swtimer(SoftTimer *timer);
uint8_t systick_deregister_swtimer(SoftTimer *timer);
void systick_start_swtimer(SoftTimer *timer);

//spi
void spi_initialize(void);
void spi_select(void);
void spi_deselect(void);
uint8_t spi_xmit(uint8_t val);
void spi_send(uint8_t *msg, uint32_t len);
void spi_recv(uint8_t *msg, uint32_t len);

void spisd_go_idle(void);
void spisd_send_if_cond(void);
void spisd_app_send_op_cond(void);
void spisd_read_ocr(void);
void spisd_read_card_identity(void);
void spisd_read_card_specific(void);
void spisd_read_single_block(uint8_t *block, uint32_t blk);
void spisd_initialize_card(void);


#endif //__SYSTEM_H

