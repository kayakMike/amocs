#ifndef __HWDEF_SPI_H
#define __HWDEF_SPI_H


//SPI_CONTROL   0x40020000
//SPI_STATUS    0x40020004
//SPI_DATA      0x40020008
//SPI_CLOCK     0x4002000C
//SPI_INTERUPT  0X4002001C

typedef struct{
    unsigned              : 2;
    unsigned bits_enable  : 1;
    unsigned clk_phase    : 1;
    unsigned clk_polarity : 1;
    unsigned master_sel   : 1;
    unsigned byte_order   : 1;
    unsigned irq_enable   : 1;
    unsigned bit_count    : 4;
    unsigned              :20;
}SpiControl;
#define SPI_CTL (*(volatile SpiControl)(0x40020000))

typedef struct{
    unsigned                : 3;
    unsigned  slave_abort   : 1;
    unsigned  mode_fault    : 1;
    unsigned  read_overrun  : 1;
    unsigned  write_collide : 1;
    unsigned  xmit_complete : 1;
    unsigned                :24;
}SpiStatus;
#define SPI_STATUS (*(volatile SpiStatus)(0x40020004))

typedef struct{
    unsigned  low           : 8;
    unsigned  high          : 8;
    unsigned                :16;
}SpiData;
#define SPI_DATA    (*(volatile SpiData)(0x40020008))

typedef struct{
    unsigned  clk_countu    : 8;
    unsigned                :24;
}SpiClock;
#define SPI_CLOCK   (*(volatile SpiClock)(0x4002000C))

typedef struct{
    unsigned test       : 1;
    unsigned            :31;
}SpiTestControl;
#define SPI_TEST_CTL     (*(volatile SpiTestControl)(0x4002010))
#define SPI_TEST_STATUS  (*(volatile SpiStatus)(0x40020014))

typedef struct{
    unsigned irq_flag       : 1;
    unsigned                : 7;
    unsigned                :24;
}SpiInterrupt;
#define SPI_INTERRUPT   (*(volatile SpiClock)(0x4002001C))

#endif //__HWDEF_H
