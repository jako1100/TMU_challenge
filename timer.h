/*
 * sprint_timer.h
 *
 *  Created on: 20 Sep 2019
 *      Author: RGB
 */

#ifndef TIMER_H_
#define TIMER_H_


#include "timer_conf.h"



#define OK  1
#define NOK 0

/* MODE FOR TIMER 0 AND TIMER 2 */
#define NORMAL_T0_T2	      0
#define COMPER_T0_T2          8
#define FAST_PWM_T0_T2        72
#define PHASE_CORRECT_T0_T2   64

/* MODE FOR TIMER 1 */

#define NORMAL_T1	          				1
#define COMPER_T1_OCR1        			 	2  /*OCRA1*/
#define FAST_PWM_T1_OCR1      				3  /*OCRA1*/
#define FAST_PWM_T1_ICR1      				4  /*OCRA1*/
#define PHASE_CORRECT_T1_OCR1 				5  /*OCRA1*/
#define PHASE_CORRECT_T1_ICR1 			 	6  /*OCRA1*/
#define PHASE_CORRECT_T1_8BIT			 	7  /*OCRA1*/
#define PHASE_CORRECT_T1_9BIT  				8  /*OCRA1*/
#define PHASE_CORRECT_T1_10BIT  			9  /*OCRA1*/
#define PHASE_CORRECT_FREQ_CORRECT_ICR1  	10  /*OCRA1*/
#define PHASE_CORRECT_FREQ_CORRECT_OCR1  	11  /*OCRA1*/
#define FAST_PWM_T1_8BIT       				12  /*OCRA1*/
#define FAST_PWM_T1_9BIT       				13  /*OCRA1*/
#define FAST_PWM_T1_10BIT      				14  /*OCRA1*/
#define COMPER_T1_ICR1        				15  /*OCRA1*/


/******************************************/

/* COM pins operation FOR TIMER 0 AND TIMER 2 */

#define  NORMAL_OPERATION_T0_T2    0
#define  TOGGLE_T0_T2			   16
#define  CLEAR_ON_CMP_T0_T2	       32
#define  SET_ON_CMP_T0_T2		   48

/*******************************************/

/* COM pins operation FOR TIMER 1  */

#define  NORMAL_OPERATION_T1    0
#define  TOGGLE_T1		  	   80
#define  CLEAR_ON_CMP_T1       160
#define  SET_ON_CMP_T1		   240

/*******************************************/

/*ICU_Edge*/

#define YES   10
#define NO    11

/****************/

#define RISING_EDGE   64
#define FALING_EDGE   0

/*******************************************/
#define INTERRPUT_T0_OFF               0
#define INTERRPUT_OVF_T0               1
#define INTERRPUT_CMP_T0       	       2
#define INTERRPUT_CMP_OVF_T0           3
#define INTERRPUT_CMP_T2       	       128
#define INTERRPUT_OVF_T2           	   64
#define INTERRPUT_CMP_OVF_T2           192
#define INTERRPUT_OVF_T1      		   4
#define INTERRPUT_CMP_CHANELA_T1       16
#define INTERRPUT_CMP_CHANELB_T1	   8
#define INTERRPUT_ICU_T1       		   32



#define NOT_USED  20
#define USED      21


#define OC0       30
#define OC2       31
#define OC1A      32
#define OC1B      33
#define OC1AB     34


#define prescaler_1_T0_T1      1
#define prescaler_8_T0_T1      2
#define prescaler_64_T0_T1     3
#define prescaler_256_T0_T1    4
#define prescaler_1024_T0_T1   5

#define prescaler_1_T2      1
#define prescaler_8_T2      2
#define prescaler_32_T2     3
#define prescaler_64_T2     4
#define prescaler_128_T2    5
#define prescaler_256_T2    6
#define prescaler_1024_T2   7

#define TIMER0        0
#define TIMER1        1
#define TIMER2        2

#define prescaler_mask  7
#define NP   0xff

#define NULL_ptr     ((void*)0)

/*APIS*/
uint8_t Timer_init(uint8_t prescalar,uint16_t  OCR_val);
uint8_t Timer_SetPreLoad(uint8_t Preload_Val, uint8_t TimerId);
uint8_t Timer_SetCompareVal(uint8_t cmp_Val, uint8_t TimerId);
uint8_t Timer_PWM(uint8_t TimerId ,uint8_t duty_cycle);
void flags_Set_Call_Back(	void  (*ptrfn) (void));


#endif /* TIMER_H_ */
