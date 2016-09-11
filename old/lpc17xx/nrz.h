#ifndef __NRZ_H
#define __NRZ_H
#include "micro_types.h"


//nrz for neopixels
void nrz_initialize(void);
void nrz_disable(void);
void nrz_enable(void);
void nrz_send_message(uint8_t *bytes, uint32_t len);





#endif //__NRZ_H
