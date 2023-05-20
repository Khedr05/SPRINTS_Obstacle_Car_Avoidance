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



Uchar8_t  u8_g_OnTime = 0 ;
Uchar8_t  u8_g_OffTime = 0 ;
VUchar8_t u8_g_on_off_state = 0 ;



extern ST_PWM_PINS_CONFIGS st_pwm_configs[PWM_PINS_NUMBER];

static void TIMER0_PWM_ExecutedFunction(void);

/*Timer0 Initialization*/
void TIMER0_init(void)
{
	
	/*Normal Mode Select*/
	CLEAR_BIT(TCCR0,WGM00);
	CLEAR_BIT(TCCR0,WGM01);
	/*Timer Overflow Interrupt Enable*/
	SET_BIT(TIMSK,TOIE0);
	/*TGlobal Interrupt Enable*/
	sei();
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


void TIMER0_initPWM(void)
{
	Uchar8_t u8_Loc_counter = 0;
	TIMER0_init();
	for(u8_Loc_counter = 0 ; u8_Loc_counter < PWM_PINS_NUMBER ; u8_Loc_counter++)
	{
		//DIO_s8SETPinDir(st_pwm_configs[u8_Loc_counter].pwm_pin,OUTPUT);
		//DIO_s8SETPinVal(st_pwm_configs[u8_Loc_counter].pwm_pin,HIGH);
		DIO_initpinn(st_pwm_configs[u8_Loc_counter].pwm_pin,OUTPUT);
		DIO_writepinn(st_pwm_configs[u8_Loc_counter].pwm_pin,HIGH);
		
	}
	
}
void TIMER0_setPwm(Uchar8_t u8_a_dutyCycle)
{
	
	u8_g_OnTime =  ((u8_a_dutyCycle * REG_SIZE)/100);
	u8_g_OffTime = (((100 -u8_a_dutyCycle) * REG_SIZE)/100);
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
			DIO_writepinn(st_pwm_configs[u8_Loc_counter].pwm_pin,LOW);
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
			DIO_writepinn(st_pwm_configs[u8_Loc_counter].pwm_pin,HIGH);
		}
		TCNT0 = REG_SIZE - u8_g_OnTime;
		u8_g_on_off_state=0;
	}
}


ISR(TIM0_OVF_INT)
{
	TIMER0_PWM_ExecutedFunction();
}
