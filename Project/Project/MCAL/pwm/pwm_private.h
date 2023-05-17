/*
 * pwm_private.h
 *
 * Created: 5/17/2023 4:57:21 PM
 *  Author: Sharpel
 */ 


#ifndef PWM_PRIVATE_H_
#define PWM_PRIVATE_H_


#define TCCR0    (*(VUchar8_t*)(0x53))
#define TIMSK    (*(VUchar8_t*)(0x59))
#define TCNT0    (*(VUchar8_t*)(0x52))
#define OCR0     (*(VUchar8_t*)(0x5C))


// TCCR0 BITS NAMES

#define  FOC0     7
#define  WGM00    6
#define  COM01    5
#define  COM00    4
#define  WGM01    3
#define  CS02     2
#define  CS01     1
#define  CS00     0

// TIMSK BITS NAMES

#define  TOIE0     0
#define  OCIE0     1



#define FCPU                                      8
#define TIMER_STOPPED                             0
#define TIMER_NO_PRESCALER                        1
#define TIMER_8_PRESCALER                         2
#define TIMER_64_PRESCALER                        3
#define TIMER_256_PRESCALER                       4
#define TIMER_1024_PRESCALER                      5
#define TIMER_EXTERNAL_CLOCK_SOURCE_FALLING_EDGE  6
#define TIMER_EXTERNAL_CLOCK_SOURCE_RISING_EDGE   7



#define TIMER0_NORMAL_MODE                    1
#define TIMER0_CTC_MODE                       2
#define TIMER0_PHASECORRECT_PWM_MODE          3
#define TIMER0_FAST_PWM_MODE                  4

#define TIMER0_CTC_INTERRUPT_ENABLED		  0
#define TIMER0_CTC_INTERRUPT_DISABLED		  1


#define TIMER0_OC0_PIN_DISCONNECTED			  0
#define TIMER0_OC0_PIN_TOGGLE				  1
#define TIMER0_OC0_PIN_SET					  2
#define TIMER0_OC0_PIN_CLEAR                  3


#define TIMER0_NON_INVERTING_PWM              0
#define TIMER0_INVERTING_PWM                  1



#define  REG_SIZE        256
#define  HALF_REG_SIZE   128
#define  ERROR_HANDLER   15




#endif /* PWM_PRIVATE_H_ */