#ifndef __CRC_H
#define __CRC_H
#include "micro_types.h"

uint8_t  crc_compute_crc7(uint8_t   crc, uint8_t *data, uint32_t len);
uint16_t crc_compute_ccitt(uint16_t crc, uint8_t *data, uint32_t len);

#endif //__CRC_H
