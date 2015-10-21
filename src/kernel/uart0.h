#ifndef __UART0_H
#define __UART0_H__
#include "micro_types.h"

void uart0_send(char *msg);
void send_message(uint8_t *message, uint32_t count);
#endif
