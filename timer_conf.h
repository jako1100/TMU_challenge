/*
 * sprint_timer_conf.h
 *
 *  Created on: 20 Sep 2019
 *      Author: RGB
 */

#ifndef TIMER_CONF_H_
#define TIMER_CONF_H_

#include "std_types.h"


#define MAX_NUM_OF_TIMERS	(uint8_t)3

typedef struct Timer_Str
	{
	uint8_t used ; /*USED/NOTUSED*/
	uint8_t mode;  /*NORMAL/COMPER/FAST_PWM/PHASE_CORRECT*/
	uint8_t com_mode ;/*COMPER PINS OPERATION*/
	uint8_t	Interrupt; /*YES/NO*/
	uint_16	Preload_Val	;/*0-65535*/
	//uint_16 Compare_Val	;/*0-65535*/
	uint_16 ICR1_val ; /*0-65535*/
	//uint8_t prescaler;/*prescaler_1-prescaler_1024*/
	uint8_t PWM_Pin_output; /*OC0/OC2/OC1A/OC1B/OC1AB/NOT_USED*/
	uint8_t ICU_Edge ; /*Falling/Rising*/


	}TIMER_cnfg_t;
extern  TIMER_cnfg_t TIMER_cnfg_arr [MAX_NUM_OF_TIMERS] ;

#endif /* TIMER_CONF_H_ */
