/*
 * TMU.c
 *
 *  Created on: Oct 12, 2019
 *      Author: free bytes
 */

#include "timer.h"
#include "TMU.h"

uint_16 g_flag[NUM_OF_FNs];
uint16_t end_of_active= NUM_OF_FNs;
uint8_t retval=OK;

EnmTMUError TMU_init(const TMU_cnfg_init * ConfigPtr )
{
	uint8_t retval=OK;

	uint8_t error=0;
	uint_16 pre_value=0;
	uint_16 OCR_value=0;
	uint8_t prescalar=0;
	flags_Set_Call_Back(g_flag_increase);

	switch(ConfigPtr->timer_id)
	{
	case TIMER0:

		pre_value = (ConfigPtr->resolution*F_CPU)/(256*1000);

		if(pre_value>1 && pre_value<8)
		{
			pre_value=8;
			prescalar=prescaler_8_T0_T1;

		}
		else if (pre_value>8 && pre_value<64)
		{
			pre_value=64;
			prescalar=prescaler_64_T0_T1;
		}
		else if (pre_value>64 && pre_value<256)
		{
			pre_value=256;
			prescalar=prescaler_256_T0_T1;
		}
		else if (pre_value>256 && pre_value<1024)
		{
			pre_value=1024;
			prescalar=prescaler_1024_T0_T1;
		}
		else
		{
			retval=NOK;
		}
		break;
	case TIMER1:

		if(pre_value>1 && pre_value<8)
		{
			pre_value=8;
			prescalar=prescaler_8_T0_T1;

		}
		else if (pre_value>8 && pre_value<64)
		{
			pre_value=64;
			prescalar=prescaler_64_T0_T1;
		}
		else if (pre_value>64 && pre_value<256)
		{
			pre_value=256;
			prescalar=prescaler_256_T0_T1;
		}
		else if (pre_value>256 && pre_value<1024)
		{
			pre_value=1024;
			prescalar=prescaler_1024_T0_T1;
		}
		else
		{
			retval=NOK;

		}
		break;
	case TIMER2:
		pre_value = (ConfigPtr->resolution*F_CPU)/(256*1000);

		if(pre_value>1 && pre_value<8)
		{
			pre_value=8;
			prescalar=prescaler_8_T2;

		}
		else if (pre_value>8 && pre_value<32)
		{
			pre_value=32;
			prescalar=prescaler_32_T2;
		}
		else if (pre_value>32 && pre_value<64)
		{
			pre_value=64;
			prescalar=prescaler_64_T2;
		}
		else if (pre_value>64 && pre_value<128)
		{
			pre_value=128;
			prescalar=prescaler_128_T2;
		}
		else if (pre_value>128 && pre_value<256)
		{
			pre_value=256;
			prescalar=prescaler_256_T2;
		}
		else if (pre_value>256 && pre_value<1024)
		{
			pre_value=1024;
			prescalar=prescaler_1024_T2;
		}
		else
		{
			retval=NOK;
		}
		break;

	}



	OCR_value=(ConfigPtr->resolution*F_CPU)/(pre_value*1000);
	Timer_init(prescalar,OCR_value);
	return retval;
}



EnmTMUError TMU_start(void  (*pfn) (void) ,uint8_t repeatation_val,uint_16 period_val)
{
	uint8_t loop_index=0;

	uint8_t retval=OK;


	for(loop_index=0;loop_index<end_of_active;loop_index++)
	{
		if(TMU_cnfg_arr[loop_index].status==0)
		{
			TMU_cnfg_arr[loop_index].ptrfn=pfn;
			TMU_cnfg_arr[loop_index].period=period_val;
			TMU_cnfg_arr[loop_index].repeatation=repeatation_val;
			TMU_cnfg_arr[loop_index].status=1;

		}
		else
		{
			retval=NOK;

		}

	}

	return retval;

}

EnmTMUError TMU_dispatcher(void)
{
	uint8_t retval=OK;

	uint8_t loop_index=0;

	for(loop_index=0;loop_index<NUM_OF_FNs;loop_index++)
	{
		if(g_flag[loop_index]==TMU_cnfg_arr[loop_index].period)
		{
			g_flag[loop_index]=0;
			(*TMU_cnfg_arr[loop_index].ptrfn)();
		}
		else
		{
			retval=NOK;

		}
	}

}

EnmTMUError TMU_stop(void (*pfn) (void))
{
	uint8_t retval=OK;

	uint8_t loop_index=0;

	for(loop_index=0;loop_index<end_of_active;loop_index++)
	{
		if(TMU_cnfg_arr[loop_index].ptrfn==pfn)
		{
			TMU_cnfg_arr[loop_index]=TMU_cnfg_arr[end_of_active-1];
			g_flag[loop_index]=g_flag[end_of_active-1];
			end_of_active--;
		}
		else
		{
			retval=NOK;

		}
	}
	return retval;

}

void g_flag_increase(void)
{
	uint8_t loop_index=0;

	for(loop_index=0;loop_index<end_of_active;loop_index++)
	{
		g_flag[loop_index]++;
	}
}


