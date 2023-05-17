/*
 * ICU_cfg.c
 *
 * Created: 5/16/2023 8:24:24 PM
 *  Author: Mahmoud
 */ 

#include "ICU_cfg.h"
ST_ICU_g_Config_t ST_g_softwareICU[1] =
{
	{ EXI_U8_INT0 ,  EXI_U8_SENSE_RISING_EDGE , EXI_U8_SENSE_FALLING_EDGE, ISR_ENABLED}
};
