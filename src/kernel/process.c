#include "system.h"

volatile uint32_t proc[4];
volatile uint32_t proc_index=0;
volatile uint32_t stack=0;

void exit(void){
    while(true){

    }
}

void init_stack(uint32_t bot, uint32_t entry){
    uint32_t *stack=(uint32_t *)bot;
    stack[16]=0x01000000;
    stack[15]=(uint32_t)entry;
    stack[14]=(uint32_t)exit;
    stack[ 8]=0xFFFFFFF9;
}

void sysinit_stacks(void){
    //proc[0]=0x20010000;
    //notsureaboutthis....
    proc[1]=0x20003000-0x10; //4k stack space
    init_stack(0x20003000-0x10,(uint32_t)main01);
    proc[2]=0x20002000-0x10; //4k stack space
    init_stack(0x20002000-0x10,(uint32_t)main02);
    proc[3]=0x20001000-0x10; //4k stack space
    init_stack(0x20001000-0x10,(uint32_t)main03);
} 


