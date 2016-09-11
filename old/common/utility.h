#ifndef __UTILITY_H
#define __UTILITY_H
#include "micro_types.h"

uint32_t util_sleep(uint32_t msec)__attribute__((optimize("O0")));
void output_system_stats(void);

#endif //__UTILITY_H
