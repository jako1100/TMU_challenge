/*
 * TMU_cnfg.h
 *
 *  Created on: Oct 12, 2019
 *      Author: free bytes
 */




#ifndef TMU_CNFG_H_
#define TMU_CNFG_H_

#define NUM_OF_FNs 3


#include "std_types.h"

typedef struct
{
	uint_16 period;
	uint8_t status;
	uint8_t repeatation;
	void  (*ptrfn) (void) ;

}TMU_cnfg;

typedef struct
{
	uint8_t timer_id;
	uint8_t resolution;

}TMU_cnfg_init;

extern TMU_cnfg_init TMU_cnfg_init_str;

extern TMU_cnfg TMU_cnfg_arr[NUM_OF_FNs];





#endif /* DIO_CNFG_H_ */
