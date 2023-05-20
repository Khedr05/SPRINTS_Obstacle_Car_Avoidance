/*
 * pwm_config.h
 *
 * Created: 5/17/2023 4:56:57 PM
 *  Author: Sharpel
 */ 


#ifndef PWM_CONFIG_H_
#define PWM_CONFIG_H_


#define TIMER_STOPPED                             0
#define TIMER_NO_PRESCALER                        1
#define TIMER_8_PRESCALER                         2
#define TIMER_64_PRESCALER                        3
#define TIMER_256_PRESCALER                       4
#define TIMER_1024_PRESCALER                      5
#define TIMER_EXTERNAL_CLOCK_SOURCE_FALLING_EDGE  6
#define TIMER_EXTERNAL_CLOCK_SOURCE_RISING_EDGE   7





/*Timer Prescaler Options:
 * 0- TIMER_STOPPED
 * 1- TIMER_NO_PRESCALER
 * 2- TIMER_8_PRESCALER
 * 3- TIMER_64_PRESCALER
 * 4- TIMER_256_PRESCALER
 * 5- TIMER_1024_PRESCALER
 * 6- TIMER_EXTERNAL_CLOCK_SOURCE_FALLING_EDGE
 * 7- TIMER_EXTERNAL_CLOCK_SOURCE_RISING_EDGE
 */
#define TIMER_SET_PRESCALER   TIMER_1024_PRESCALER

#define  REG_SIZE                                 256

/*configuration of pwm pins*/
#define PWM_PINS_NUMBER     2


typedef struct ST_PWM_PINS_CONFIGS{
	
	DIO_Pin_type pwm_pin ;
	
}ST_PWM_PINS_CONFIGS;


#endif /* PWM_CONFIG_H_ */