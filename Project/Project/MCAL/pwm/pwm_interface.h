/*
 * pwm_interface.h
 *
 * Created: 5/17/2023 4:56:39 PM
 *  Author: Sharpel
 */ 


#ifndef PWM_INTERFACE_H_
#define PWM_INTERFACE_H_




/*Timer0 Initialization*/
void TIMER0_init(void);
/*Timer0 Start Counting (set prescaller)*/
void TIMER0_start(void);
/*Timer0 Stop Counting (clear prescaller)*/
void TIMER0_stop(void);


void TIMER0_initPWM(void);

void TIMER0_setPwm(Uchar8_t u8_a_dutyCycle);



#endif /* PWM_INTERFACE_H_ */