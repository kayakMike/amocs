#ifndef __SPISD_H
#define __SPISD_H
#include "micro_types.h"



void spisd_go_idle(void);
void spisd_send_if_cond(void);
void spisd_app_send_op_cond(void);
void spisd_read_ocr(void);
void spisd_read_card_identity(void);
void spisd_read_card_specific(void);
void spisd_read_single_block(uint8_t *block, uint32_t blk);
void spisd_initialize_card(void);


#endif //__SYSTEM_H

