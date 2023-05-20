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


#endif /* PWM_PRIVATE_H_ */