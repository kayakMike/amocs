#ifndef __COLOR_H
#define __COLOR_H
#include "micro_types.h"


typedef struct{
    uint8_t red;
    uint8_t grn;
    uint8_t blu;
}RGBColor;


RGBColor hsvtorgb(uint8_t hue, uint8_t sat, uint8_t val);


void color_test_rainbow(uint8_t *pixarray, uint8_t index);






#endif //__COLOR_H
