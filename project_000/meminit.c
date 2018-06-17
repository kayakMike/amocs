#include "meminit.h"


/*
 * copies data section from flash to appropriate spot in the SRAM
 * data section is the 
 * NOTE:  This is global data that will change as the program progresses
void init_data(uint32_t *start, uint32_t *end, uint32_t *mem)
{
    while(start < end)
    {
        *start = *mem;
        start++;
        mem++;
    }
}
*/

/* function zeroes out a section of RAM 
 *
void init_bss(uint32_t *start, uint32_t *end)
{
    while (start < end)
    {
        *start++ = 0;
    }
}
 */


/*  copy n bytes from the source pointer to the destination pointer
 *  return a copy of the destination pointer
 *  
*/
void *memcpy(void *dest, const void *src, size_t n)
{
    //size_t is the number of bytes
    size_t index = 0;

    /* Possible  optimization?  PREMATURE OPTMIZATION is bad
     *  Good for 4 byte aligned performance
     *  some jitter on non-4byte aligned sections.
    for(index = 0; index < n/4; index++)
    {
        ((uint32_t *)dest)[index] = ((uint32_t *)src)[index];
    }
    index = index*4
    */
    for( ; index < n; index++)
    {
        ((uint8_t *)dest)[index] = ((uint8_t *)src)[index];
    }

    return dest;
}

/*
 * function fills the first n bytes of the memory area
 *      pointed to by s with the constant byte c.
 * returns funtion pointed to the memory that was just set.
 */
void *memset(void *s, int8_t c, size_t n)
{
    size_t index = 0;

    /* Possible IF def optimization?  PREMATURE OPTMIZATION is bad
    int8_t bucket[] = { c, c, c, c };
    for(index = 0; index < n/4; index++)
    {
        ((uint32_t *)s)[index] = ((uint32_t *)bucket)[0];
    }
    index = index*4
    */
    for( ; index < n; index++)
    {
        ((uint8_t *)s)[index] = 0; 
    }
    return s;
}





