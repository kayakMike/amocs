#include "utility.h"
#include "sysclock.h"
#include "string.h"
#include "ucom.h"

void util_sleep(uint32_t msec){
    uint32_t i=1200*msec;
    while(i--){
        //noop??
    }
}


void util_outputNumber(uint32_t num){
    uint8_t str[10];
    uint_to_decimal_string(num,str);
    ucom_sendString(UART0,str);
    ucom_sendString(UART0,"\n\r");
} 

void util_outputSystemStats(void){
    uint32_t cpu_clock=sysclock_computeMainClock();
    ucom_sendString(UART0,"BASIC STATS: \n\r");
    ucom_sendString(UART0,"\tCPU CLOCK: \n\r");
    util_outputNumber(cpu_clock);
}


