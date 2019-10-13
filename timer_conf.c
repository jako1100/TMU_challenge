/*
 * sprint_timer_conf.c
 *
 *  Created on: 20 Sep 2019
 *      Author: RGB
 */

#include "timer.h"

	/* Timers configrations */

 TIMER_cnfg_t TIMER_cnfg_arr [MAX_NUM_OF_TIMERS] =
	{
		/* Timer 0 */
		{
			USED,
			NORMAL_T0_T2,
			NORMAL_OPERATION_T0_T2 ,
			YES,
			INTERRPUT_OVF_T0,
			NP,
			NP,
			NP,
			NP
		},
		/* Timer 1 */
		{

			NOT_USED,
			FAST_PWM_T1_OCR1,
			NORMAL_OPERATION_T1,
			NO,
			NP,
			NP,
			OC1A,
			NP
		},
		/* Timer 2 */
		{


			NOT_USED,
			NP,
			NP,
			NP,
			NP,

			NP,

			NP,
			NP
		}
	};





