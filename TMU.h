/*
 * TMC.h
 *
 *  Created on: Oct 12, 2019
 *      Author: free bytes
 */
#include "TMU_cnfg.h"

#ifndef TMU_H_
#define TMU_H_

//typedef enum {NOK,OK}EnmTMUError;
#define PERIODIC 1
#define ONE_SHOT 0

#define TIMER0   0
#define TIMER1   1
#define TIMER2   2

#define F_CPU   8000000
EnmTMUError TMU_dispatcher(void);
EnmTMUError TMU_stop(void (*pfn) (void));
void g_flag_increase(void);


#endif


