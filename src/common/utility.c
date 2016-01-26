#include "utility.h"
#include "string.h"

void util_sleep(uint32_t msec){
    uint32_t i=1200*msec;
    while(i--){
        //noop??
    }
}

void output_system_stats(void){
    uint32_t core_clock_speed=core_compute_main_clock();
    uint8_t str[]="\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0";
    uart0_send("BASIC SYSTEM STATS! \n\r");
    uart0_send("    System CPU Clock:  ");
    uint_to_decimal_string(core_clock_speed,str);
    uart0_send(str);
    uart0_send(" ");
    uint_to_hex_string(core_clock_speed,str);
    uart0_send(str);
    uart0_send("\n\r");
}

