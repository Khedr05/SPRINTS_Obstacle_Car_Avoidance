/*
 * ICU_cfg.h
 *
 * Created: 5/16/2023 8:25:29 PM
 *  Author: Mahmoud
 */ 


#ifndef ICU_CFG_H_
#define ICU_CFG_H_
/* ICU_cfg typedefs */

/* The 3 External Interrupts counted from 0 to 2 */
typedef enum {
	EXI_U8_INT0,
	EXI_U8_INT1,
	EXI_U8_INT2
}EN_ICU_usedExti_t;

/* Interrupts Sense Control */
typedef enum {
	EXI_U8_SENSE_LOW_LEVEL,
	EXI_U8_SENSE_LOGICAL_CHANGE,
	EXI_U8_SENSE_FALLING_EDGE,
	EXI_U8_SENSE_RISING_EDGE
}EN_ICU_senseControl_t;

/* Interrupts Sense Control */
typedef enum {
	ISR_DISABLED,
	ISR_ENABLED
}EN_ICU_timer1ISR_t;

typedef struct {
	EN_ICU_usedExti_t ICU_exti;
	EN_ICU_senseControl_t ICU_firstSenseControl;
	EN_ICU_senseControl_t ICU_secondSenseControl;
	EN_ICU_timer1ISR_t timer1_ISR;
}ST_ICU_g_Config_t;


#endif /* ICU_CFG_H_ */