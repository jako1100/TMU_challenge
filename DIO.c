/*
 * DIO.c
 *
 *  Created on: 9 ,24, 2019
 *      Author: Ya3koob
 */
#include "DIO.h"


uint8_t DIO_init (void)
{
	uint8_t retval = OK;
	uint8_t loop_index = 0;
	if (NUM_OF_PINS>MAX_NUM_OF_PINS) return retval=NOK;

	for(loop_index = 0;loop_index<NUM_OF_PINS;loop_index++)
	{

	if(DIO_cnfg_arr[loop_index].DIR == OUTPUT)

	{
		switch(DIO_cnfg_arr[loop_index].PORT)

		{
		case PORT_A:
			set_bit(DDRA_REG,DIO_cnfg_arr[loop_index].PIN);
			break;

		case PORT_B:
			set_bit(DDRB_REG,DIO_cnfg_arr[loop_index].PIN);
			break;

		case PORT_C:
			set_bit(DDRC_REG,DIO_cnfg_arr[loop_index].PIN);
			break;

		case PORT_D:
			set_bit(DDRD_REG,DIO_cnfg_arr[loop_index].PIN);
			break;
		default :
			retval =NOK;

		}

	}
	else if (DIO_cnfg_arr[loop_index].DIR == INPUT)
	{



		switch(DIO_cnfg_arr[loop_index].PORT)

		{
		case PORT_A:
			clr_bit(DDRA_REG,DIO_cnfg_arr[loop_index].PIN);
			if (DIO_cnfg_arr[loop_index].RES == PULLUP)
				set_bit(PORTA_REG,DIO_cnfg_arr[loop_index].PIN);
			else if (DIO_cnfg_arr[loop_index].RES == EXTRES)
				clr_bit(PORTA_REG,DIO_cnfg_arr[loop_index].PIN);
			else {
				return retval=NOK;
			}


			break;

		case PORT_B:
			clr_bit(DDRB_REG,DIO_cnfg_arr[loop_index].PIN);
			if (DIO_cnfg_arr[loop_index].RES == PULLUP)
				set_bit(PORTA_REG,DIO_cnfg_arr[loop_index].PIN);
			else if (DIO_cnfg_arr[loop_index].RES == EXTRES)
				clr_bit(PORTA_REG,DIO_cnfg_arr[loop_index].PIN);
			else {
				return retval=NOK;
			}			break;

		case PORT_C:
			clr_bit(DDRC_REG,DIO_cnfg_arr[loop_index].PIN);
			if (DIO_cnfg_arr[loop_index].RES == PULLUP)
				set_bit(PORTA_REG,DIO_cnfg_arr[loop_index].PIN);
			else if (DIO_cnfg_arr[loop_index].RES == EXTRES)
				clr_bit(PORTA_REG,DIO_cnfg_arr[loop_index].PIN);
			else {
				return retval=NOK;
			}			break;

		case PORT_D:
			clr_bit(DDRD_REG,DIO_cnfg_arr[loop_index].PIN);
			if (DIO_cnfg_arr[loop_index].RES == PULLUP)
				set_bit(PORTA_REG,DIO_cnfg_arr[loop_index].PIN);
			else if (DIO_cnfg_arr[loop_index].RES == EXTRES)
				clr_bit(PORTA_REG,DIO_cnfg_arr[loop_index].PIN);
			else {
				return retval=NOK;
			}			break;
		default :
			retval =NOK;


		}
	}
	else
	{
		retval =NOK;
	}



	if(DIO_cnfg_arr[loop_index].OUT == HIGH)
	{switch(DIO_cnfg_arr[loop_index].PORT)

	{
	case PORT_A:
		set_bit(PORTA_REG,DIO_cnfg_arr[loop_index].PIN);
		break;

	case PORT_B:
		set_bit(PORTB_REG,DIO_cnfg_arr[loop_index].PIN);
		break;

	case PORT_C:
		set_bit(PORTC_REG,DIO_cnfg_arr[loop_index].PIN);
		break;

	case PORT_D:
		set_bit(PORTD_REG,DIO_cnfg_arr[loop_index].PIN);
		break;
	default :
		retval =NOK;


	}

	}
	else if (DIO_cnfg_arr[loop_index].OUT==LOW)
	{
		switch(DIO_cnfg_arr[loop_index].PORT)

		{
		case PORT_A:
			clr_bit(PORTA_REG,DIO_cnfg_arr[loop_index].PIN);


			break;

		case PORT_B:
			clr_bit(PORTB_REG,DIO_cnfg_arr[loop_index].PIN);

			break;

		case PORT_C:
			clr_bit(PORTC_REG,DIO_cnfg_arr[loop_index].PIN);


			break;

		case PORT_D:
			clr_bit(PORTD_REG,DIO_cnfg_arr[loop_index].PIN);


			break;
		default :
			retval =NOK;


		}

	}
	else
	{
		retval =NOK;


	}
	}
	return retval;
}

uint8_t DIO_set_pin_direction(uint8_t port_id,uint8_t pin_number,uint8_t direction)
{


	uint8_t retval = OK;

	if( !(pin_number>=PIN0 && pin_number<=PIN7) )

		return retval=NOK;



	if(direction==OUTPUT)
	{


		switch (port_id)
		{
		case PORT_A:
			set_bit(DDRA_REG,pin_number);
			break;

		case PORT_B:
			set_bit(DDRB_REG,pin_number);
			break;

		case PORT_C:
			set_bit(DDRC_REG,pin_number);
			break;

		case PORT_D:
			set_bit(DDRD_REG,pin_number);
			break;
		default :
			retval =NOK;

		}

	}
	else if (direction ==INPUT)
	{
		switch (port_id)
		{
		case PORT_A:
			clr_bit(DDRA_REG,pin_number);
			break;

		case PORT_B:
			clr_bit(DDRB_REG,pin_number);
			break;

		case PORT_C:
			clr_bit(DDRC_REG,pin_number);
			break;

		case PORT_D:
			clr_bit(DDRD_REG,pin_number);
			break;
		default :
			retval =NOK;

		}

	}
	else
	{
		retval =NOK;
	}
	return retval;

}

uint8_t DIO_write_pin_value(uint8_t port_id,uint8_t pin_number,uint8_t value)
{

	uint8_t retval = OK;

	if( !(pin_number>=PIN0 && pin_number<=PIN7) )

		return retval=NOK;


	if( value==HIGH )
	{

		switch (port_id)
		{
		case PORT_A:

			set_bit(PORTA_REG,pin_number);


			break;

		case PORT_B:
			set_bit(PORTB_REG,pin_number);
			break;

		case PORT_C:
			set_bit(PORTC_REG,pin_number);
			break;

		case PORT_D:
			set_bit(PORTD_REG,pin_number);
			break;
		default :
			retval =NOK;

		}
	}


	else if (value==LOW)
	{

		switch (port_id)
		{
		case PORT_A:
			clr_bit(PORTA_REG,pin_number);
			break;

		case PORT_B:
			clr_bit(PORTB_REG,pin_number);
			break;

		case PORT_C:
			clr_bit(PORTC_REG,pin_number);
			break;

		case PORT_D:
			clr_bit(PORTD_REG,pin_number);
			break;
		default :
			retval =NOK;

		}

	}
	else
	{
		retval =NOK;

	}
	return retval;
}

uint8_t  DIO_read_pin_value(uint8_t port_id,uint8_t pin_number,uint8_t* got)
{
	uint8_t retval = OK;

	if(! (pin_number>=PIN0 && pin_number<=PIN7) )

		return retval=NOK;



	switch (port_id)
	{
	case PORT_A:
		*got=get_bit(PINA_REG,pin_number);
		break;

	case PORT_B:
		*got=get_bit(PINB_REG,pin_number);
		break;

	case PORT_C:
		*got=get_bit(PINC_REG,pin_number);
		break;

	case PORT_D:
		*got=get_bit(PIND_REG,pin_number);
		break;
	default :
		retval=NOK;
	}
	return retval;

}
uint8_t DIO_set_port_direction(uint8_t port_id,uint8_t value)
{
	uint8_t retval = OK;


	if(! (value>=0 && value<=255) )

		return retval=NOK;

	switch (port_id)
	{
	case PORT_A:
		DDRA_REG=value;
		break;

	case PORT_B:
		DDRB_REG=value;
		break;

	case PORT_C:
		DDRC_REG=value;
		break;

	case PORT_D:
		DDRD_REG=value;
		break;
	default:
		retval=NOK;
	}
	return retval;

}
uint8_t DIO_write_port_value(uint8_t port_id,uint8_t value)
{
	uint8_t retval = OK;


	if(! (value>=0 && value<=255) )

		return retval=NOK;

	switch (port_id)
	{
	case PORT_A:
		PORTA_REG=value;
		break;

	case PORT_B:
		PORTB_REG=value;
		break;

	case PORT_C:
		PORTC_REG=value;
		break;

	case PORT_D:
		PORTD_REG=value;
		break;
	default:
		retval=NOK;
	}
	return retval;
}


uint8_t DIO_read_port_value(uint8_t port_id,uint8_t* got)

{
	uint8_t retval = OK;

	switch (port_id)
	{
	case PORT_A:
		*got=PINA_REG;
		break;

	case PORT_B:
		*got=PINB_REG;
		break;

	case PORT_C:
		*got=PINC_REG;
		break;

	case PORT_D:
		*got=PIND_REG;
		break;
	default:
		retval=NOK;
	}

	return retval;


}





