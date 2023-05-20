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
}EN_TimerMode_t;

typedef enum
{
    TMR_INTERNAL,
    TMR_EXTERNAL
}EN_TimerClockSource_t;
typedef enum {
    TMR_ENABLED,
    TMR_DISABLED
}EN_TimerEnable_t;

typedef enum {
    TMR_ISR_ENABLED,
    TMR_ISR_DISABLED
}EN_TimerISREnable_t;

typedef enum {
    TMR_MODULE_CLK,
    TMR_RISING_EDGE,
    TMR_FALLING_EDGE,
}EN_TimerClockMode_t;

typedef enum {
    TMR_NORMAL_PORT_OPERATION_OC_PIN_DISCONNECTED,
    TMR_TOGGLE_OC_PIN_ON_COMPARE_MATCH,
    TMR_CLEAR_OC_PIN_ON_COMPARE_MATCH,
    TMR_SET_OC_PIN_ON_COMPARE_MATCH
}EN_TimerCompMatchOutputMode_t;

typedef enum
{
	TIMER0,							/**< Timer 0*/
	TIMER1,							/**< Timer 1*/
	TIMER2,							/**< Timer 2*/
	MAX_TIMERS						/**< Timers on the microcontroller*/
}EN_TimerChannel_t;

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
}EN_TimerPrescaler_t;

typedef struct
{
    EN_TimerChannel_t TimerChannel;
	EN_TimerEnable_t TimerEnable;			/**< Timer Enable en_g_state*/
    EN_TimerMode_t TimerMode;				/**< Up/Down Counter Mode, and OVF, CTC, PWM Timer mode Settings*/
	EN_TimerCompMatchOutputMode_t TimerCtcMode;
    EN_TimerClockSource_t ClockSource;			/**< Defines the clock source internal/external according to this it operates as timer or counter*/    
    EN_TimerClockMode_t ClockMode;				/**< Clock Mode for counter rising, falling,......*/
    EN_TimerPrescaler_t ClockPrescaler;		/**< Clock Prescaler for timer mode*/
	EN_TimerISREnable_t ISREnable;				/**< ISR Enable en_g_state*/
}ST_TimerConfig_t;
/******************************************************************************************
        Function Prototypes
*******************************************************************************************/
/*******************************************************************************************/
const ST_TimerConfig_t* Tmr_ConfigGet(void);

/*******************************************************************************************************************************************************************/

#endif /* TMR_CONFIG_H_ */

/* End of file */