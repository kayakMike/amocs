#include "system.h"
#include "gpio.h"


void gpio_initialize(void){
    PORT0_DIR.pin20=1; //output 
    PORT0_DIR.pin00=1;  //output 
    PORT1_DIR.pin27=1;  //output 
}

void gpio_on(void){
    PORT0_SET.pin20=1;
    PORT0_SET.pin00=1;
}

void gpio_off(void){
    PORT0_CLR.pin20=1;
    PORT0_CLR.pin00=1;
}

void gpio_toggle020(void){
    if(PORT0_VAL.pin20==1){
        PORT0_CLR.pin20=1;
    }
    else{
        PORT0_SET.pin20=1;
    }
}

void gpio_toggle027(void){
    if(PORT1_VAL.pin27==1){
        PORT1_CLR.pin27=1;
    }
    else{
        PORT1_SET.pin27=1;
    }
}
