#ifndef REGISTERS_H_
#define REGISTERS_H_
#include "std_types.h"
#define DDRA_REG  *(volatile uint8_t *)0x3A
#define DDRB_REG  *(volatile uint8_t *)0x37
#define DDRC_REG  *(volatile uint8_t *)0x34
#define DDRD_REG  *(volatile uint8_t *)0x31


#define PORTA_REG  *(volatile uint8_t *)0x3B
#define PORTB_REG  *(volatile uint8_t *)0x38
#define PORTC_REG  *(volatile uint8_t *)0x35
#define PORTD_REG  *(volatile uint8_t *)0x32

#define PINA_REG  *(volatile uint8_t *)0x39
#define PINB_REG  *(volatile uint8_t *)0x36
#define PINC_REG  *(volatile uint8_t *)0x33
#define PIND_REG  *(volatile uint8_t *)0x30

#define TIMER_TCCR0_REGISTER *(volatile uint8_t *)0x53
#define TIMER_TCNT0_REGISTER *(volatile uint8_t *)0x52
#define TIMER_OCR0_REGISTER *(volatile uint8_t *)0x5C
#define TIMER_TIMSK_REGISTER *(volatile uint8_t *)0x59
#define TIMER_TIFR_REGISTER *(volatile uint8_t *)0x58

#define TIMER_TCCR1A_REGISTER *(volatile uint8_t *)0x4F
#define TIMER_TCCR1B_REGISTER *(volatile uint8_t *)0x4E
#define TIMER_TCNT1H_REGISTER *(volatile uint8_t *)0x4D
#define TIMER_TCNT1L_REGISTER *(volatile uint8_t *)0x4C
#define TIMER_OCR1AH_REGISTER *(volatile uint8_t *)0x4B
#define TIMER_OCR1AL_REGISTER *(volatile uint8_t *)0x4A
#define TIMER_OCR1BH_REGISTER *(volatile uint8_t *)0x49
#define TIMER_OCR1BL_REGISTER *(volatile uint8_t *)0x48
#define TIMER_ICR1H_REGISTER *(volatile uint8_t *)0x47
#define TIMER_ICR1L_REGISTER *(volatile uint8_t *)0x46

#define TIMER_TCCR2_REGISTER *(volatile uint8_t *)0x45
#define TIMER_TCNT2_REGISTER *(volatile uint8_t *)0x44
#define TIMER_OCR2_REGISTER *(volatile uint8_t *)0x43

#define Interrupt_SREG_REGISTER *(volatile uint8_t *)0x5F


#endif
