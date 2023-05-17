/*
 * pwm_program.c
 *
 * Created: 5/17/2023 4:56:05 PM
 *  Author: Sharpel
 */ 


#include "../../COMMON/std_types.h"
#include "../../COMMON/bit_math.h"
#include "../../COMMON/vect_table.h"
#include "../dio/dio.h"
#include "pwm_private.h"
#include "pwm_config.h"
#include "pwm_interface.h"


Uint32_t u32_g_NumOfOVFs = 0 ;

Uchar8_t  u8_g_OnTime = 0 ;
Uchar8_t  u8_g_OffTime = 0 ;
VUchar8_t u8_g_on_off_state = 0 ;



extern ST_PWM_PINS_CONFIGS st_pwm_configs[PWM_PINS_NUMBER];

static void TIMER0_PWM_ExecutedFunction(void);
/*Timer0 Initialization*/
void TIMER0_init(void)
{
	
	/*Mode Select*/
	
	#if TIMER0_SET_MODE == TIMER0_NORMAL_MODE
	CLEAR_BIT(TCCR0,WGM00);
	CLEAR_BIT(TCCR0,WGM01);
	/*Timer Overflow Interrupt Enable*/
	SET_BIT(TIMSK,TOIE0);
	sei();

	#elif TIMER0_SET_MODE == TIMER0_CTC_MODE
	CLEAR_BIT(TCCR0,WGM00);
	SET_BIT(TCCR0,WGM01);
	
	#if TIMER0_SET_CTC_INTERRUPT == TIMER0_CTC_INTERRUPT_ENABLED
	SET_BIT(TIMSK,OCIE0);
	#elif TIMER0_SET_CTC_INTERRUPT == TIMER0_CTC_INTERRUPT_DISABLED
	CLEAR_BIT(TIMSK,OCIE0);
	#endif
	
	#if TIMER0_SET_OC0_PIN_MODE == TIMER0_OC0_PIN_DISCONNECTED
	CLEAR_BIT(TCCR0,COM01);
	CLEAR_BIT(TCCR0,COM00);
	#elif TIMER0_SET_OC0_PIN_MODE == TIMER0_OC0_PIN_TOGGLE
	CLEAR_BIT(TCCR0,COM01);
	SET_BIT(TCCR0,COM00);
	#elif TIMER0_SET_OC0_PIN_MODE == TIMER0_OC0_PIN_SET
	SET_BIT(TCCR0,COM01);
	SET_BIT(TCCR0,COM00);
	#elif TIMER0_SET_OC0_PIN_MODE == TIMER0_OC0_PIN_CLEAR
	SET_BIT(TCCR0,COM01);
	CLEAR_BIT(TCCR0,COM00);
	
	#endif
	
	#elif TIMER0_SET_MODE == TIMER0_PHASECORRECT_PWM_MODE
	SET_BIT(TCCR0,WGM00);
	CLEAR_BIT(TCCR0,WGM01);
	#if TIMER0_SET_PWM_MODE == TIMER0_NON_INVERTING_PWM
	SET_BIT(TCCR0,COM01);
	CLEAR_BIT(TCCR0,COM00);
	
	#elif TIMER0_SET_PWM_MODE == TIMER0_INVERTING_PWM
	SET_BIT(TCCR0,COM01);
	SET_BIT(TCCR0,COM00);
	
	#endif
	
	#elif TIMER0_SET_MODE == TIMER0_FAST_PWM_MODE
	SET_BIT(TCCR0,WGM00);
	SET_BIT(TCCR0,WGM01);
	#if TIMER0_SET_PWM_MODE == TIMER0_NON_INVERTING_PWM
	SET_BIT(TCCR0,COM01);
	CLEAR_BIT(TCCR0,COM00);
	
	#elif TIMER0_SET_PWM_MODE == TIMER0_INVERTING_PWM
	SET_BIT(TCCR0,COM01);
	SET_BIT(TCCR0,COM00);

	#endif
	
	
	#endif

}


/*Timer0 Start Counting (set prescaller)*/
void TIMER0_start(void)
{
	/*Clear Three Clock Select Bits */
	TCCR0 &=0xF8;
	/*Set Selected Prescaller */
	TCCR0|=TIMER_SET_PRESCALER;
}
/*Timer0 Stop Counting (clear prescaller)*/
void TIMER0_stop(void)
{
	/*Clear Three Clock Select Bits */
	TCCR0 &=0xF8;
}


void TIMER0_setDelay(Uint32_t u32_a_delayMs)
{
	float32_t f32_loc_tickTime;
	Uint32_t  u32_loc_totalTicks;
	Uchar8_t  u8_loc_initValue;
	
	f32_loc_tickTime = (float32_t)TIMER_SET_PRESCALER/FCPU ;
	u32_loc_totalTicks = (u32_a_delayMs * 1000)/f32_loc_tickTime;
	u32_g_NumOfOVFs = u32_loc_totalTicks / 256 ;
	
	u8_loc_initValue = 256 - (u32_loc_totalTicks % 256);
	
	TCNT0 = u8_loc_initValue;
	u32_g_NumOfOVFs++;
	
}


void TIMER0_initPWM(void)
{
	Uchar8_t u8_Loc_counter = 0;
	TIMER0_init();
	for(u8_Loc_counter = 0 ; u8_Loc_counter < PWM_PINS_NUMBER ; u8_Loc_counter++)
	{
		//DIO_s8SETPinDir(st_pwm_configs[u8_Loc_counter].pwm_pin,OUTPUT);
		//DIO_s8SETPinVal(st_pwm_configs[u8_Loc_counter].pwm_pin,HIGH);
		DIO_Initpin(&st_pwm_configs[u8_Loc_counter].pwm_pin);
	}
	
}
void TIMER0_setPwm(Uchar8_t u8_a_dutyCycle)
{
	
	u8_g_OnTime =  ((u8_a_dutyCycle * HALF_REG_SIZE)/100)-ERROR_HANDLER;
	u8_g_OffTime = (((100 -u8_a_dutyCycle) * HALF_REG_SIZE)/100)-ERROR_HANDLER;
	TCNT0 = REG_SIZE - u8_g_OnTime ;
	TIMER0_start();
	
}

static void TIMER0_PWM_ExecutedFunction(void)
{
	Uchar8_t u8_Loc_counter = 0;
	if(u8_g_on_off_state == 0)
	{
		// switch level of cycle to LOW
		for(u8_Loc_counter = 0 ; u8_Loc_counter < PWM_PINS_NUMBER ; u8_Loc_counter++)
		{
			//DIO_s8SETPinVal(st_pwm_configs[u8_Loc_counter].pwm_pin,LOW);
			DIO_WritePin(st_pwm_configs[u8_Loc_counter].pwm_pin.dio_port,st_pwm_configs[u8_Loc_counter].pwm_pin.dio_pin,DIO_LOW);
		}
		TCNT0 = REG_SIZE - u8_g_OffTime;
		u8_g_on_off_state=1;
	}
	else
	{
		// switch level of cycle to HIGH
		for(u8_Loc_counter = 0 ; u8_Loc_counter < PWM_PINS_NUMBER ; u8_Loc_counter++)
		{
			//DIO_s8SETPinVal(st_pwm_configs[u8_Loc_counter].pwm_pin,HIGH);
			DIO_WritePin(st_pwm_configs[u8_Loc_counter].pwm_pin.dio_port,st_pwm_configs[u8_Loc_counter].pwm_pin.dio_pin,DIO_HIGH);
		}
		TCNT0 = REG_SIZE - u8_g_OnTime;
		u8_g_on_off_state=0;
	}
}


ISR(TIM0_OVF_INT)
{
	TIMER0_PWM_ExecutedFunction();
}
