#ifndef __NEOPIX_H_
#define __NEOPIX_H_

#include "micro_types.h"


void Timer0_Handler(void);
/**
 *  @brief: initializes the necessary neopixel structures and libraries
 *  Neopixel uses the lpc timers to implement a non-return to zero serial
 *  each neopixel gets 3 bytes
 *   
 *  Uses timer0:  
 *
 *
 */
void neopix_initializeDemo(void);

/**
 *  @brief: each change to the string of pixes is a frame.
 *  a frame contains a list of numbers representative of appropriate reload values
 *  for timer0
 *  
 *
 */
void neopix_computeFrame(void);

/**
 *  @brief: use this function to set single pixel in a single frame
 *  Red/Green/Blue 
 *
 */
void neopix_setPixelRgb(uint32_t pixIndex, uint8_t grn, uint8_t red, uint8_t blu);

/**
 *  @brief: use this function to set single pixel in a single frame
 *  (hue/value/saturation) 
 *
 */
void neopix_setPixelHsv(uint32_t pixIndex, uint32_t hue, float sat, float val);

/*
 * @brief basic control to start timer0 to initiate the communication with the neopixels
 *
 */

void neopix_startDemo(void);

//void NEOPIX_dump(void);

void neopix_changePixels(void);

#endif /* __NEOPIX_DEMO_H_ */
