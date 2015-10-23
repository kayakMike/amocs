#ifndef __CRC_H
#define __CRC_H
#include "micro_types.h"

uint8_t compute_crc7(uint8_t crc, uint8_t *buffer, uint32_t len);
uint16_t compute_crc16(uint16_t crc, uint8_t *buffer, uint32_t len);

#endif //__CRC_H
