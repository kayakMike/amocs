#ifndef __STRING_H
#define __STRING_H

#include "micro_types.h"

#define BIN      2
#define OCTAL    8
#define DECIMAL 10
#define HEX     16


uint8_t uint_to_string(uint32_t convert, uint8_t base, uint8_t max, uint8_t *bytes);



uint8_t uint_to_decimal_string(uint32_t in, uint8_t *out);
uint8_t uint_to_hex_string(uint32_t in, uint8_t *out);

#endif
