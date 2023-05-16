

#include "EXT_INTERRUPT_Config.h"

extern void callone(void);
extern void calltwo(void);
extern void callthree(void);



const ST_EXT_INTERRUPTS_CFG A_interruptConfig[EXT_INTERRUPT_PINS] =
{
		{callone,EXT0_INTERRUPTS,RISING_EDGE_SENSE_CONTROL},
		{calltwo,EXT1_INTERRUPTS,LOW_LEVEL_SENSE_CONTROL},
 		{callthree,EXT2_INTERRUPTS,FALLING_EDGE_SENSE_CONTROL}
};

