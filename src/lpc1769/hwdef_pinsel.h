#ifndef __HWDEF_PINSEL_H
#define __HWDEF_PINSEL_H

typedef struct{
    unsigned p000  : 2;
    unsigned p001  : 2;
    unsigned p002  : 2;
    unsigned p003  : 2;
    unsigned p004  : 2;
    unsigned p005  : 2;
    unsigned p006  : 2;
    unsigned p007  : 2;
    unsigned p008  : 2;
    unsigned p009  : 2;
    unsigned p010  : 2;
    unsigned p011  : 2;
    unsigned       : 2;
    unsigned p015  : 2;
}PinRegister0;

#define PINSEL0   (*(volatile PinRegister0 *)(0x4002C000))
#define PINMODE0  (*(volatile PinRegister0 *)(0x4002C040))

typedef struct{
    unsigned p016  : 2;
    unsigned p017  : 2;
    unsigned p018  : 2;
    unsigned p019  : 2;
    unsigned p020  : 2;
    unsigned p021  : 2;
    unsigned p022  : 2;
    unsigned p023  : 2;
    unsigned p024  : 2;
    unsigned p025  : 2;
    unsigned p026  : 2;
    unsigned p027  : 2;
    unsigned p028  : 2;
    unsigned p029  : 2;
    unsigned p030  : 2;
    unsigned       : 2;
}PinRegister1;

#define PINSEL1  (*(volatile PinRegister1 *)(0x4002C004))
#define PINMODE1 (*(volatile PinRegister1 *)(0x4002C044))

typedef struct{
    unsigned p100  : 2;
    unsigned p101  : 2;
    unsigned       : 4;
    unsigned p104  : 2;
    unsigned       : 6;
    unsigned p108  : 2;
    unsigned p109  : 2;
    unsigned p110  : 2;
    unsigned       : 6;
    unsigned p114  : 2;
    unsigned p115  : 2;
}PinRegister2;

#define PINSEL2  (*(volatile PinRegister2 *)(0x4002C008))
#define PINMODE2 (*(volatile PinRegister2 *)(0x4002C048))


typedef struct{
    unsigned p116  : 2;
    unsigned p117  : 2;
    unsigned p118  : 2;
    unsigned p119  : 2;
    unsigned p120  : 2;
    unsigned p121  : 2;
    unsigned p122  : 2;
    unsigned p123  : 2;
    unsigned p124  : 2;
    unsigned p125  : 2;
    unsigned p126  : 2;
    unsigned p127  : 2;
    unsigned p128  : 2;
    unsigned p129  : 2;
    unsigned p130  : 2;
    unsigned p131  : 2;
}PinRegister3;

#define PINSEL3  (*(volatile PinRegister3 *)(0x4002C00C))
#define PINMODE3 (*(volatile PinRegister3 *)(0x4002C04C))


typedef struct{
    unsigned p200  : 2;
    unsigned p201  : 2;
    unsigned p202  : 2;
    unsigned p203  : 2;
    unsigned p204  : 2;
    unsigned p205  : 2;
    unsigned p206  : 2;
    unsigned p207  : 2;
    unsigned p208  : 2;
    unsigned p209  : 2;
    unsigned p210  : 2;
    unsigned p211  : 2;
    unsigned p212  : 2;
    unsigned p213  : 2;
    unsigned       : 4;
}PinRegister4;

#define PINSEL4  (*(volatile PinRegister4 *)(0x4002C010))
#define PINMODE4 (*(volatile PinRegister4 *)(0x4002C050))

typedef struct{
   unsigned      :18;
   unsigned p325 : 2;
   unsigned p326 : 2;
   unsigned      :10;
}PinRegister7;

#define PINSEL7  (*(volatile PinRegister7 *)(0x4002C01C))
#define PINMODE7 (*(volatile PinRegister7 *)(0x4002C05C))

typedef struct{
   unsigned      :18;
   unsigned p428 : 2;
   unsigned p429 : 2;
   unsigned      :10;
}PinRegister9;


#define PINSEL9  (*(volatile PinRegister9 *)(0x4002C024))
#define PINMODE9 (*(volatile PinRegister7 *)(0x4002C064))


#define PINODMODE0 (*(volatile uint32_t *)(0x4002C068))
#define PINODMODE1 (*(volatile uint32_t *)(0x4002C06C))
#define PINODMODE2 (*(volatile uint32_t *)(0x4002C070))
#define PINODMODE3 (*(volatile uint32_t *)(0x4002C074))
#define PINODMODE4 (*(volatile uint32_t *)(0x4002C078))

#define PINI2CCONFIG (*(volatile uint32_t *)(0x4002C07C))

#endif //__HWDEF_PINSEL_H
