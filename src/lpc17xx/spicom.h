#ifndef __SPICOM_H
#define __SPICOM_H


//spi
void    spicom_initialize  (void);
void    spicom_select      (void);
void    spicom_deselect    (void);
uint8_t spicom_xmit        (uint8_t val);
void    spicom_send        (uint8_t *msg, uint32_t len);
void    spicom_recv        (uint8_t *msg, uint32_t len);


#endif //__SPICOM_H
