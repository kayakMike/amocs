#ifndef __BLINK_H
#define __BLINK_H
#include "micro_types.h"


void      blink_initializeOutput (uint8_t port, uint8_t pin);
void      blink_setOutput        (uint8_t port, uint8_t pin);
void      blink_clearOutput      (uint8_t port, uint8_t pin);
uint8_t   blink_getOutputState   (uint8_t port, uint8_t pin);
void      blink_toggleOutput     (uint8_t port, uint8_t pin);


#endif //__BLINK_H
