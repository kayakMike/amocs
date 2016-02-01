#ifndef __pincfg_defs_h
#define __pincfg_defs_h

#include "system_types.h"

//NOTE:  HIGHSPEED pins use EXACTLY the same bits as Normal Drive pins!
//
/**
 * @brief Table 189. Pin configuration registers for normal-drive pins (SFS, address 0x4008 6000 (SPSP0_0) to 0x4008 67AC (SFSPF_11)) bit description
 */
struct PinConfigNormalDrive{
    unsigned functionSelect    : 3;   //!< pinmode
    unsigned pulldownEnable    : 1;   //!< enable pulldown
    unsigned pullupDisable     : 1;   //!< disable pullup
    unsigned highSpeedEnable   : 1;   //!< slew rate something
    unsigned inputEnable       : 1;   //!< input buffer
    unsigned glitchDisable     : 1;   //!< glitch filter enable
    unsigned                   :24;   //!< reserved
};


/**
 * @brief Table 190. Pin configuration registers for high-drive pins (SFS, address 0x4008 60C4
 * (SFSP1_17) to 0x4008 650C (SFSPA_3) bit description
 */
struct PinConfigHighDrive{
    unsigned functionSelect      : 3;   //!< pinmode
    unsigned pulldownEnable      : 1;   //!< enable pulldown
    unsigned pullupDisable       : 1;   //!< disable pullup         
    unsigned                     : 1;   //!< slew rate something
    unsigned inputEnable         : 1;   //!< input buffer
    unsigned glitchDisable       : 1;   //!< glitch filter enable  
    unsigned driveStrengthSelect : 2;   //!< drive strength select values
    unsigned                     :21;
};

#define P1_0  (*(volatile struct PinConfigNormalDrive *)(0x40086080))
#define P1_1  (*(volatile struct PinConfigNormalDrive *)(0x40086084))
#define P1_2  (*(volatile struct PinConfigNormalDrive *)(0x40086088))
#define P1_3  (*(volatile struct PinConfigNormalDrive *)(0x4008608C))
#define P1_4  (*(volatile struct PinConfigNormalDrive *)(0x40086090))
#define P1_5  (*(volatile struct PinConfigNormalDrive *)(0x40086094))
#define P1_6  (*(volatile struct PinConfigNormalDrive *)(0x40086098))
#define P1_7  (*(volatile struct PinConfigNormalDrive *)(0x4008609C))
#define P1_8  (*(volatile struct PinConfigNormalDrive *)(0x400860A0))
#define P1_9  (*(volatile struct PinConfigNormalDrive *)(0x400860A4))
#define P1_10 (*(volatile struct PinConfigNormalDrive *)(0x400860A8))
#define P1_11 (*(volatile struct PinConfigNormalDrive *)(0x400860AC))
#define P1_12 (*(volatile struct PinConfigNormalDrive *)(0x400860B0))
#define P1_13 (*(volatile struct PinConfigNormalDrive *)(0x400860B4))
#define P1_14 (*(volatile struct PinConfigNormalDrive *)(0x400860B8))
#define P1_15 (*(volatile struct PinConfigNormalDrive *)(0x400860BC))
#define P1_16 (*(volatile struct PinConfigNormalDrive *)(0x400860C0))
#define P1_17 (*(volatile struct PinConfigNormalDrive *)(0x400860C4))
#define P1_18 (*(volatile struct PinConfigNormalDrive *)(0x400860C8))
#define P1_19 (*(volatile struct PinConfigNormalDrive *)(0x400860CC))
#define P1_20 (*(volatile struct PinConfigNormalDrive *)(0x400860D0))

#define P2_0  (*(volatile struct PinConfigNormalDrive *)(0x40086100))
#define P2_1  (*(volatile struct PinConfigNormalDrive *)(0x40086104))
#define P2_2  (*(volatile struct PinConfigNormalDrive *)(0x40086108))
#define P2_3  (*(volatile struct PinConfigHighDrive   *)(0x4008610C))
#define P2_4  (*(volatile struct PinConfigHighDrive   *)(0x40086110))
#define P2_5  (*(volatile struct PinConfigHighDrive   *)(0x40086114))
#define P2_6  (*(volatile struct PinConfigNormalDrive *)(0x40086118))
#define P2_7  (*(volatile struct PinConfigNormalDrive *)(0x4008611C))
#define P2_8  (*(volatile struct PinConfigNormalDrive *)(0x40086120))
#define P2_9  (*(volatile struct PinConfigNormalDrive *)(0x40086124))
#define P2_10 (*(volatile struct PinConfigNormalDrive *)(0x40086128))
#define P2_11 (*(volatile struct PinConfigNormalDrive *)(0x4008612C))
#define P2_12 (*(volatile struct PinConfigNormalDrive *)(0x40086130))
#define P2_13 (*(volatile struct PinConfigNormalDrive *)(0x40086134))

#define P3_0  (*(volatile struct PinConfigNormalDrive *)(0x40086180))
#define P3_1  (*(volatile struct PinConfigNormalDrive *)(0x40086184))
#define P3_2  (*(volatile struct PinConfigNormalDrive *)(0x40086188))
#define P3_3  (*(volatile struct PinConfigNormalDrive *)(0x4008618C))
#define P3_4  (*(volatile struct PinConfigNormalDrive *)(0x40086190))
#define P3_5  (*(volatile struct PinConfigNormalDrive *)(0x40086194))
#define P3_6  (*(volatile struct PinConfigNormalDrive *)(0x40086198))
#define P3_7  (*(volatile struct PinConfigNormalDrive *)(0x4008619C))
#define P3_8  (*(volatile struct PinConfigNormalDrive *)(0x400861A0))

#define P4_0  (*(volatile struct PinConfigNormalDrive *)(0x40086200))
#define P4_1  (*(volatile struct PinConfigNormalDrive *)(0x40086204))
#define P4_2  (*(volatile struct PinConfigNormalDrive *)(0x40086208))
#define P4_3  (*(volatile struct PinConfigNormalDrive *)(0x4008620C))
#define P4_4  (*(volatile struct PinConfigNormalDrive *)(0x40086210))
#define P4_5  (*(volatile struct PinConfigNormalDrive *)(0x40086214))
#define P4_6  (*(volatile struct PinConfigNormalDrive *)(0x40086218))
#define P4_7  (*(volatile struct PinConfigNormalDrive *)(0x4008621C))
#define P4_8  (*(volatile struct PinConfigNormalDrive *)(0x40086220))
#define P4_9  (*(volatile struct PinConfigNormalDrive *)(0x40086224))
#define P4_10 (*(volatile struct PinConfigNormalDrive *)(0x40086228))

#define P5_0  (*(volatile struct PinConfigNormalDrive *)(0x40086280))
#define P5_1  (*(volatile struct PinConfigNormalDrive *)(0x40086284))
#define P5_2  (*(volatile struct PinConfigNormalDrive *)(0x40086288))
#define P5_3  (*(volatile struct PinConfigNormalDrive *)(0x4008628C))
#define P5_4  (*(volatile struct PinConfigNormalDrive *)(0x40086290))
#define P5_5  (*(volatile struct PinConfigNormalDrive *)(0x40086294))
#define P5_6  (*(volatile struct PinConfigNormalDrive *)(0x40086298))
#define P5_7  (*(volatile struct PinConfigNormalDrive *)(0x4008629C))

#define P6_0  (*(volatile struct PinConfigNormalDrive *)(0x40086300))
#define P6_1  (*(volatile struct PinConfigNormalDrive *)(0x40086304))
#define P6_2  (*(volatile struct PinConfigNormalDrive *)(0x40086308))
#define P6_3  (*(volatile struct PinConfigNormalDrive *)(0x4008630C))
#define P6_4  (*(volatile struct PinConfigNormalDrive *)(0x40086310))
#define P6_5  (*(volatile struct PinConfigNormalDrive *)(0x40086314))
#define P6_6  (*(volatile struct PinConfigNormalDrive *)(0x40086318))
#define P6_7  (*(volatile struct PinConfigNormalDrive *)(0x4008631C))
#define P6_8  (*(volatile struct PinConfigNormalDrive *)(0x40086320))
#define P6_9  (*(volatile struct PinConfigNormalDrive *)(0x40086324))
#define P6_10 (*(volatile struct PinConfigNormalDrive *)(0x40086328))

#define P7_0  (*(volatile struct PinConfigNormalDrive *)(0x40086380))
#define P7_1  (*(volatile struct PinConfigNormalDrive *)(0x40086384))
#define P7_2  (*(volatile struct PinConfigNormalDrive *)(0x40086388))
#define P7_3  (*(volatile struct PinConfigNormalDrive *)(0x4008638C))
#define P7_4  (*(volatile struct PinConfigNormalDrive *)(0x40086390))
#define P7_5  (*(volatile struct PinConfigNormalDrive *)(0x40086394))
#define P7_6  (*(volatile struct PinConfigNormalDrive *)(0x40086398))
#define P7_7  (*(volatile struct PinConfigNormalDrive *)(0x4008639C))






#endif  // __pincfg_defs_h
