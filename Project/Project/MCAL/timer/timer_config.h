/*
 * timer_cfg.h
 *
 * Created: 4/6/2023 5:33:09 AM
 *  Author: Mahmoud Mowafey
 */

#ifndef TMR_CONFIG_H_
#define TMR_CONFIG_H_

/*******************************************************************************************************************************************************************/
/* TMR Configurations' Definitions */


typedef enum {
    TMR_OVERFLOW_MODE,
    TMR_CTC_MODE,
    TMR_PWM_MODE,
    TMR_COUNTER_MODE,
    TMR_MAX_TIMERMODES
}TimerMode_t;

typedef enum
{
    TMR_INTERNAL,
    TMR_EXTERNAL
}TimerClockSource_t;
typedef enum {
    TMR_ENABLED,
    TMR_DISABLED
}TimerEnable_t;

typedef enum {
    TMR_ISR_ENABLED,
    TMR_ISR_DISABLED
}TimerISREnable_t;

typedef enum {
    TMR_MODULE_CLK,
    TMR_RISING_EDGE,
    TMR_FALLING_EDGE,
}TimerClockMode_t;

typedef enum {
    TMR_NORMAL_PORT_OPERATION_OC_PIN_DISCONNECTED,
    TMR_TOGGLE_OC_PIN_ON_COMPARE_MATCH,
    TMR_CLEAR_OC_PIN_ON_COMPARE_MATCH,
    TMR_SET_OC_PIN_ON_COMPARE_MATCH
}TimerCompMatchOutputMode_t;

typedef enum
{
	TIMER0,							/**< Timer 0*/
	TIMER1,							/**< Timer 1*/
	TIMER2,							/**< Timer 2*/
	MAX_TIMERS						/**< Timers on the microcontroller*/
}TimerChannel_t;

typedef enum
{
	TMR_NO_CLOCK_SOURCE_TIMER_COUNTER_ATOPPED,
	TMR_NO_PRESCALING,							
	TMR_CLK_8_FROM_PRESCALER,
    TMR_CLK_64_FROM_PRESCALER,
    TMR_CLK_256_FROM_PRESCALER,
    TMR_CLK_1024_FROM_PRESCALER,
    TMR_EXT_CLOCK_SOURCE_ON_T1_PIN_CLK_ON_FALLING_EDGE,
    TMR_EXT_CLOCK_SOURCE_ON_T1_PIN_CLK_ON_RISING_EDGE										
}TimerPrescaler_t;

typedef struct
{
    TimerChannel_t TimerChannel;
	TimerEnable_t TimerEnable;			/**< Timer Enable State*/
    TimerMode_t TimerMode;				/**< Up/Down Counter Mode, and OVF, CTC, PWM Timer mode Settings*/
	TimerCompMatchOutputMode_t TimerCtcMode;
    TimerClockSource_t ClockSource;			/**< Defines the clock source internal/external according to this it operates as timer or counter*/    
    TimerClockMode_t ClockMode;				/**< Clock Mode for counter rising, falling,......*/
    TimerPrescaler_t ClockPrescaler;		/**< Clock Prescaler for timer mode*/
	TimerISREnable_t ISREnable;				/**< ISR Enable State*/
}TimerConfig_t;
/******************************************************************************************
        Function Prototypes
*******************************************************************************************/
/*******************************************************************************************/
const TimerConfig_t* Tmr_ConfigGet(void);

/*******************************************************************************************************************************************************************/

#endif /* TMR_CONFIG_H_ */

/* End of file */