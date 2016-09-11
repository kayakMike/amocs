#ifndef __MUTEX_H
#define __MUTEX_H
#include "micro_types.h"
volatile uint8_t mutex_lock(volatile uint8_t *lck);
void mutex_unlock(volatile uint8_t *lck);
void mutex_spinlock(volatile uint8_t *lck);

#endif //__MUTEX_H
