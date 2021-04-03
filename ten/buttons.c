/*
 * buttons.c
 *
 * Created: 01.04.2021 17:18:56
 *  Author: TOKA
 */ 
#include "buttons.h"

uint8_t ButtonRead(){
	if (!(PIND & (1 << PIND7)))
	{
			return TENS;
	}
	else if (!(PIND & (1 << PIND6))){
		return OK;
	}
	else if (!(PIND & (1 << PIND5))){
		return ONES;
	}
	else return NAC;
}

