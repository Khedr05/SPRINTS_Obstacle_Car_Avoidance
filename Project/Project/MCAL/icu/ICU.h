/*
 * ICU.h
 *
 * Created: 5/16/2023 8:25:05 PM
 *         Author: Mahmoud Mowafey - https://github.com/Mahmoud-Mowafy
 *  Description: This file contains all Direct Current Motor (DCM) functions' implementation.
 *		MCU Datasheet: AVR ATmega32
 *                  https://ww1.microchip.com/downloads/en/DeviceDoc/Atmega32A-DataSheet-Complete-DS40002072A.pdf
 */ 


#ifndef ICU_H_
#define ICU_H_


#include "ICU_cfg.h"
#include "icu_private.h"
#include "../TIMER/timer_private.h"
extern ST_ICU_g_Config_t ST_g_softwareICU[1];

typedef enum {
	RISING,
	FALLING
	}EN_icuEdgeFlag;


void ICU_RisingEdgeCapture(void);
void ICU_getValue(u32 *var);
/*void ICU_FallingEdgeCapture(void);*/
EN_TIMER_ERROR_T TIMER_tmr1NormalModeInit(EN_TIMER_INTERRPUT_T en_a_interrputEnable);
void TIMER_tmr1CleareCompMatInit(void);
EN_TIMER_ERROR_T TIMER_tmr1Start(u16 u16_a_prescaler);
void TIMER_tmr1Stop(void);

#endif /* ICU_H_ */