/*
 * pwm_interface.h
 *
 * Created: 5/17/2023 4:56:39 PM
 *  Author: Sharpel
 */ 


#ifndef PWM_INTERFACE_H_
#define PWM_INTERFACE_H_




/*
Function    : TIMER0_init
Description : this function initializes timer0 with normal mode Also enable peripheral and Global interrupt.
Args        : void
return      : void 
*/
void TIMER0_init(void);


/*
Function    : TIMER0_start
Description : this function set three clock bits with chosen prescaller in config file (timer starts when we call this function)
Args        : void
return      : void
*/
void TIMER0_start(void);


/*
Function    : TIMER0_stop
Description : this function clear three clock bits (timer stops when we call this function)
Args        : void
return      : void
*/
void TIMER0_stop(void);

/*
Function    : TIMER0_initPWM
Description : this function initializes all pwm pins as outputs and set high on them, also calls TIMER0_init ....
Args        : void
return      : void
*/
void TIMER0_initPWM(void);

/*
Function    : TIMER0_setPwm
Description : this function calculates onTime and offTime , also calls TIMER0_start ....
Args        : DutyCycle (0--->100)
return      : void
*/
void TIMER0_setPwm(Uchar8_t u8_a_dutyCycle);




#endif /* PWM_INTERFACE_H_ */