/*
 * sprint_Timer.c
 *
 *  Created on: 20 Sep 2019
 *      Author: RGB
 */
#include "timer.h"
#include "REG.h"
#include "avr/Interrupt.h"
static volatile void  (*global_ptr_flags) (void) = NULL_ptr;





uint8_t  prescaler(uint8_t timer , uint8_t pre_scaler) ;
uint8_t mode_fnc (uint8_t timer , uint8_t Mode) ;
uint8_t options(uint8_t timer);
uint8_t Timer0_Timer2_option(uint8_t timer,uint8_t Com_Mode);
uint8_t Timer1_option (uint8_t timer,uint8_t Com_Mode,uint8_t icu_edge);
uint8_t set_preload (uint8_t timer,uint_16 Pre_Load);
uint8_t set_OCR (uint8_t timer,uint_16 cmp_value);
uint8_t set_ICR (uint8_t timer,uint_16 ICR);
uint8_t Timer_interrupt_init(uint8_t timer,uint8_t interrupt);






uint8_t retvalue = OK ;

uint8_t Timer_init(uint8_t const prescalar,uint16_t const OCR_val)
{
	uint8_t loop_index = 0;

	for(loop_index=0;loop_index<MAX_NUM_OF_TIMERS;loop_index++)
	{

			if(TIMER_cnfg_arr[loop_index].used==USED)
			{
				retvalue = prescaler(loop_index,prescalar);
				retvalue = mode_fnc(loop_index,TIMER_cnfg_arr[loop_index].mode);
				retvalue = options(loop_index);
				retvalue =Timer_interrupt_init(loop_index,TIMER_cnfg_arr[loop_index].Interrupt);
				retvalue = set_preload (loop_index,TIMER_cnfg_arr[loop_index].Preload_Val);
				retvalue = set_OCR (loop_index,OCR_val);
				retvalue = set_ICR (loop_index,TIMER_cnfg_arr[loop_index].ICR1_val);
			}
			else if(TIMER_cnfg_arr[loop_index].used==NOT_USED)
			{
				loop_index++;
			}
			else
			{
				retvalue=NOK;
			}

		}











	return retvalue ;
}


uint8_t prescaler(uint8_t timer , uint8_t pre_scaler)
{
	switch (timer)
	{
	case 0 :
		TIMER_TCCR0_REGISTER &=0XF8;/*andding reg with 11111000*/
		TIMER_TCCR0_REGISTER |= pre_scaler ;
		break ;
	case 1 :
		TIMER_TCCR1B_REGISTER &=0XF8;
		TIMER_TCCR1B_REGISTER |= pre_scaler ;
		break ;
	case 2 :
		TIMER_TCCR2_REGISTER &=0XF8;
		TIMER_TCCR2_REGISTER |= pre_scaler ;
		break ;

	default :
		retvalue = NOK;
		break ;
	}
	return retvalue ;
}


uint8_t mode_fnc (uint8_t timer , uint8_t Mode)
{
	switch (timer)
	{

	case 0 :
		TIMER_TCCR0_REGISTER &=0XB7; /*andding reg with 101101111*/
		TIMER_TCCR0_REGISTER |= Mode ; /*orring reg with Mode check timer.h*/
		break ;
	case 1 :
		switch(Mode)
		{
		case NORMAL_T1 :

			TIMER_TCCR1A_REGISTER &=0xFC; /*andding reg with 11111100*/
			TIMER_TCCR1A_REGISTER |=0;
			TIMER_TCCR1B_REGISTER  &=0xE7;/*andding reg with 11100111*/
			TIMER_TCCR1B_REGISTER |=0;

			break ;

		case COMPER_T1_OCR1 :

			TIMER_TCCR1A_REGISTER &=0xFC;
			TIMER_TCCR1A_REGISTER |=0;
			TIMER_TCCR1B_REGISTER  &=0xE7;
			TIMER_TCCR1B_REGISTER |=8;

			break ;

		case FAST_PWM_T1_OCR1 :

			TIMER_TCCR1A_REGISTER &=0xFC; /*andding reg with 11111100*/
			TIMER_TCCR1A_REGISTER |=3;
			TIMER_TCCR1B_REGISTER  &=0xE7;/*andding reg with 11100111*/
			TIMER_TCCR1B_REGISTER |=24;

			break ;

		case PHASE_CORRECT_T1_OCR1 :

			TIMER_TCCR1A_REGISTER &=0xFC; /*andding reg with 11111100*/
			TIMER_TCCR1A_REGISTER |=3;
			TIMER_TCCR1B_REGISTER  &=0xE7;/*andding reg with 11100111*/
			TIMER_TCCR1B_REGISTER |=16;

			break ;

		case FAST_PWM_T1_ICR1 :
			TIMER_TCCR1A_REGISTER &=0xFC;
			TIMER_TCCR1A_REGISTER |=2;
			TIMER_TCCR1B_REGISTER  &=0xE7;
			TIMER_TCCR1B_REGISTER |=24;
			break ;
		case FAST_PWM_T1_8BIT :
			TIMER_TCCR1A_REGISTER &=0xFC;
			TIMER_TCCR1A_REGISTER |=1;
			TIMER_TCCR1B_REGISTER  &=0xE7;
			TIMER_TCCR1B_REGISTER |=8;
			break ;
		case FAST_PWM_T1_9BIT :
			TIMER_TCCR1A_REGISTER &=0xFC;
			TIMER_TCCR1A_REGISTER |=2;
			TIMER_TCCR1B_REGISTER  &=0xE7;
			TIMER_TCCR1B_REGISTER |=8;
			break ;
		case FAST_PWM_T1_10BIT :
			TIMER_TCCR1A_REGISTER &=0xFC;
			TIMER_TCCR1A_REGISTER |=3;
			TIMER_TCCR1B_REGISTER  &=0xE7;
			TIMER_TCCR1B_REGISTER |=8;
			break ;
		case PHASE_CORRECT_T1_ICR1 :
			TIMER_TCCR1A_REGISTER &=0xFC;
			TIMER_TCCR1A_REGISTER |=2;
			TIMER_TCCR1B_REGISTER  &=0xE7;
			TIMER_TCCR1B_REGISTER |=24;
			break ;

		case PHASE_CORRECT_T1_8BIT :
			TIMER_TCCR1A_REGISTER &=0xFC;
			TIMER_TCCR1A_REGISTER |=1;
			TIMER_TCCR1B_REGISTER  &=0xE7;
			TIMER_TCCR1B_REGISTER |=0;
			break ;
		case PHASE_CORRECT_T1_9BIT :
			TIMER_TCCR1A_REGISTER &=0xFC;
			TIMER_TCCR1A_REGISTER |=2;
			TIMER_TCCR1B_REGISTER  &=0xE7;
			TIMER_TCCR1B_REGISTER |=0;
			break ;
		case PHASE_CORRECT_T1_10BIT :
			TIMER_TCCR1A_REGISTER &=0xFC;
			TIMER_TCCR1A_REGISTER |=3;
			TIMER_TCCR1B_REGISTER  &=0xE7;
			TIMER_TCCR1B_REGISTER |=0;
			break ;
		case PHASE_CORRECT_FREQ_CORRECT_ICR1 :
			TIMER_TCCR1A_REGISTER &=0xFC;
			TIMER_TCCR1A_REGISTER |=0;
			TIMER_TCCR1B_REGISTER  &=0xE7;
			TIMER_TCCR1B_REGISTER |=16;
			break ;
		case PHASE_CORRECT_FREQ_CORRECT_OCR1 :
			TIMER_TCCR1A_REGISTER &=0xFC;
			TIMER_TCCR1A_REGISTER |=1;
			TIMER_TCCR1B_REGISTER  &=0xE7;
			TIMER_TCCR1B_REGISTER |=16;
			break ;
		case COMPER_T1_ICR1 :
			TIMER_TCCR1A_REGISTER &=0xFC;
			TIMER_TCCR1A_REGISTER |=0;
			TIMER_TCCR1B_REGISTER  &=0xE7;
			TIMER_TCCR1B_REGISTER |=24;
			break ;


		default :

			retvalue = NOK;
			break ;
		}

		break ;
		case 2 :
			TIMER_TCCR2_REGISTER &=0XB7;
			TIMER_TCCR2_REGISTER |= Mode ;
			break ;


		default :
			retvalue = NOK;
			break ;
	}
	return retvalue ;


}

uint8_t Timer0_Timer2_option (uint8_t timer,uint8_t Com_Mode)
{
	switch(timer)
	{
	case 0 :
		TIMER_TCCR0_REGISTER &=0xCF;/*andding with 11001111*/
		TIMER_TCCR0_REGISTER |=Com_Mode ;
		break ;
	case 2 :
		TIMER_TCCR2_REGISTER &=0xCF;/*andding with 11001111*/
		TIMER_TCCR2_REGISTER |=Com_Mode ;
		break;
	default :
		retvalue = NOK;
		break ;
	}
	return retvalue ;
}

uint8_t Timer1_option (uint8_t timer,uint8_t Com_Mode,uint8_t icu_edge)
{
	if (timer ==1)
	{
		TIMER_TCCR1A_REGISTER &=0x0F;/*andding with 00001111*/
		TIMER_TCCR1A_REGISTER |= Com_Mode ;
		TIMER_TCCR1B_REGISTER &=0XBF;/*adding 10111111*/
		TIMER_TCCR1B_REGISTER |=icu_edge;

	}

	else
	{
		retvalue = NOK;
	}
	return retvalue ;

}

uint8_t options(uint8_t timer)
{
	switch(timer)
	{
	case 0 :
		retvalue = Timer0_Timer2_option( timer,TIMER_cnfg_arr[timer].com_mode);
		break;
	case 1 :
		retvalue = Timer1_option (timer,TIMER_cnfg_arr[timer].com_mode,TIMER_cnfg_arr[timer].ICU_Edge);
		break ;
	case 2 :
		retvalue = Timer0_Timer2_option( timer,TIMER_cnfg_arr[timer].com_mode);
		break;
	default :
		retvalue = NOK;
		break ;

	}
	return retvalue ;
}

uint8_t set_preload (uint8_t timer,uint_16 Pre_Load)
{
	switch(timer)
	{
	case 0 :
		TIMER_TCNT0_REGISTER= Pre_Load ;
		break ;
	case 1 :
		TIMER_TCNT1H_REGISTER= (Pre_Load&0xF0);
		TIMER_TCNT1L_REGISTER=(Pre_Load&0x0F);
		break;
	case 2 :
		TIMER_TCNT2_REGISTER= Pre_Load ;
		break ;

	default :
		retvalue = NOK;
		break ;
	}
	return retvalue ;

}

uint8_t set_OCR (uint8_t timer,uint_16 cmp_value)
{
	switch(timer)
	{
	case 0 :
		TIMER_OCR0_REGISTER= cmp_value ;
		break ;
	case 1 :
		TIMER_OCR1AH_REGISTER= (cmp_value&0xF0);
		TIMER_OCR1AL_REGISTER=(cmp_value&0x0F);
		break;
	case 2 :
		TIMER_OCR2_REGISTER= cmp_value ;
		break ;

	default :
		retvalue = NOK;
		break ;
	}
	return retvalue ;

}


uint8_t set_ICR (uint8_t timer,uint_16 ICR)
{
	if (timer ==1)
	{
		TIMER_ICR1H_REGISTER =(ICR&0xF0);
		TIMER_ICR1L_REGISTER =(ICR&0x0F);

	}

	else
	{
		retvalue = NOK;
	}
	return retvalue ;
}

uint8_t Timer_interrupt_init(uint8_t timer,uint8_t interrupt )
{
	switch(timer)
	{
	case 0 :
		TIMER_TIMSK_REGISTER &=0xFC;     /*andding reg with 11111100*/
		TIMER_TIMSK_REGISTER |=interrupt;
		break;
	case 1 :
		TIMER_TIMSK_REGISTER &=0xC3;     /*andding reg with 11111100*/
		TIMER_TIMSK_REGISTER |=interrupt;
		break ;
	case 2 :
		TIMER_TIMSK_REGISTER &=0x3F;     /*andding reg with 11111100*/
		TIMER_TIMSK_REGISTER |=interrupt;
		break;
	default :
		retvalue = NOK;
		break ;

	}
	return retvalue ;

}


void flags_Set_Call_Back(	void  (*ptrfn) (void))
{
 	global_ptr_flags=ptrfn;
}


ISR(TIMER0_COMP_vect)
{
if(global_ptr_flags!=NULL_ptr)
{
	global_ptr_flags();
}
}

