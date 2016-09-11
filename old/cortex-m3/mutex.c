#include "mutex.h"


// attempt to claim the lock
// return 1 if lock obtained
// return 0 if lock not obtained
volatile uint8_t mutex_lock(volatile uint8_t *lck){
    //r0 contains the value of the lock pointer, by convention
    uint8_t res=1;
    uint8_t tst=1;
    asm volatile(
        "ldrexb    %[res], [%[lck]]            \n" // load lock value from memory
        "cmp       %[res], #0                  \n" // lock is free if it is zero 
        "ittte     eq                          \n" //  
        "strexbeq  %[res], %[tst], [%[lck]]    \n" // THEN store the value 1 to the lock address
        "cmpeq     %[res], #0                  \n" // THEN check if this succeeded (zero in res)
        "dmbeq                                 \n" // THEN data memory barrier
        "movne     %[res], #1                  \n" // ELSE (lock was already taken)
        "cmp       %[res], #0                  \n" // FLIP result to match expected output 
        "ite       ne                          \n" // IF result is not zero  
        "movne     %[res], #0                  \n" // THEN switch it to zero
        "moveq     %[res], #1                  \n" // ELSE switch it to one
        : [res] "+r" (res)                         // output only
        : [lck] "r"  (lck), [tst] "r" (tst)        // address of the lock
        :
    );
    return res;
}

void mutex_spinlock(volatile uint8_t *lck){
    while(mutex_lock(lck)==0){};
}

void mutex_unlock(volatile uint8_t *lck){
   *lck=0;
}
