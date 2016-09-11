#include "blink.h"
#include "gpio.h"


void blink_initializeOutput(uint8_t port, uint8_t pin){
    switch(port){
        case 0:
            PORT0_DIR=PORT0_DIR|(1<<pin);
            break;
        case 1:
            PORT1_DIR=PORT1_DIR|(1<<pin);
            break;
        case 2:
            PORT2_DIR=PORT2_DIR|(1<<pin);
            break;
        case 3:
            PORT3_DIR=PORT3_DIR|(1<<pin);
            break;
        case 4:
            PORT4_DIR=PORT4_DIR|(1<<pin);
            break;
        default:
            //error occured
            break;
    } 
}

void blink_setOutput(uint8_t port, uint8_t pin){
    switch(port){
        case 0:
            PORT0_SET=PORT0_SET|(1<<pin);
            break;
        case 1:
            PORT1_SET=PORT1_SET|(1<<pin);
            break;
        case 2:
            PORT2_SET=PORT2_SET|(1<<pin);
            break;
        case 3:
            PORT3_SET=PORT3_SET|(1<<pin);
            break;
        case 4:
            PORT4_SET=PORT4_SET|(1<<pin);
            break;
        default:
            //error occured
            break;
    } 
}

void blink_clearOutput(uint8_t port, uint8_t pin){
    switch(port){
        case 0:
            PORT0_CLR=PORT0_CLR|(1<<pin);
            break;
        case 1:
            PORT1_CLR=PORT1_CLR|(1<<pin);
            break;
        case 2:
            PORT2_CLR=PORT2_CLR|(1<<pin);
            break;
        case 3:
            PORT3_CLR=PORT3_CLR|(1<<pin);
            break;
        case 4:
            PORT4_CLR=PORT4_CLR|(1<<pin);
            break;
        default:
            //error occured
            break;
    } 
}

uint8_t blink_getOutputState(uint8_t port, uint8_t pin){
    switch(port){
        case 0:
            return ((PORT0_VAL>>pin)&1);
        case 1:
            return ((PORT1_VAL>>pin)&1);
        case 2:
            return ((PORT2_VAL>>pin)&1);
        case 3:
            return ((PORT3_VAL>>pin)&1);
        case 4:
            return ((PORT4_VAL>>pin)&1);
        default:
            return 0;
    }
    return 0;
}

void blink_toggleOutput(uint8_t port, uint8_t pin){

    if(blink_getOutputState(port,pin)==1){
        blink_clearOutput(port,pin); 
    }
    else{
        blink_setOutput(port,pin); 
    }
}


