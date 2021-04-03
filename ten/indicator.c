/*
 * indicator.c
 *
 * Created: 31.03.2021 14:59:19
 *  Author: TOKA
 */ 
#include "indicator.h"

void IndicatorOut(uint8_t Temp){
	PORTB = 0x00;
	PORTC = 0x00;
	PORTD &= ~((1 << PORTD0)|(1 << PORTD1)|(1 << PORTD2));
	if (Temp > 99){//Indicator Overflow Error Report
		PORTB |= (1 << PORTB0)|(1 << PORTB6)|(1 << PORTB7);
		PORTC |= (1 << PORTC0)|(1 << PORTC1)|(1 << PORTC2)|
		(1 << PORTC3);
		PORTD |= (1 << PORTD0)|(1 << PORTD1)|(1 << PORTD2);
		return;
	}
	uint8_t SegmentB = 0;
	uint8_t SegmentA = 0;
	if (Temp < 10)
	{
		SegmentA = Temp;
		SegmentB = 0xFF;
	} 
	else
	{
		SegmentA = (uint8_t)(Temp / 10);
		SegmentB = (uint8_t)(Temp % 10);
	}
	
	switch(SegmentA){
		case 0: { 
			PORTB |= (1 << PORTB0)|(1 << PORTB1)|
					 (1 << PORTB2)|(1 << PORTB6)|
				     (1 << PORTB7);
			PORTC |= (1 << PORTC0);
			break;
		}
		case 1: { 
			PORTB |= (1 << PORTB1)|(1 << PORTB2);
			break;
		}
		case 2: { 
			PORTB |= (1 << PORTB0)|(1 << PORTB1)|
					 (1 << PORTB6)|(1 << PORTB7);
			PORTC |= (1 << PORTC1);
			break;
		}
		case 3: { 
			PORTB |= (1 << PORTB0)|(1 << PORTB1)|
					 (1 << PORTB2)|(1 << PORTB6);
			PORTC |= (1 << PORTC1);
			break;
		}
		case 4: { 
			PORTB |= (1 << PORTB1)|(1 << PORTB2);
			PORTC |= (1 << PORTC0)|(1 << PORTC1);
			break;
		}
		case 5: { 
			PORTB |= (1 << PORTB0)|(1 << PORTB2)|
					 (1 << PORTB6);
			PORTC |= (1 << PORTC0)|(1 << PORTC1);
			break;
		}
		case 6: {
			PORTB |= (1 << PORTB0)|(1 << PORTB2)|
					 (1 << PORTB6)|(1 << PORTB7);
			PORTC |= (1 << PORTC0)|(1 << PORTC1);
			break;
		}
		case 7: { 
			PORTB |= (1 << PORTB0)|(1 << PORTB1)|
			(1 << PORTB2);
			break;
		}
		case 8: { 
			PORTB |= (1 << PORTB0)|(1 << PORTB1)|
					  (1 << PORTB2)|(1 << PORTB6)|
					  (1 << PORTB7);
			PORTC |= (1 << PORTC0)|(1 << PORTC1);
			break;
		}
		case 9: {
			PORTB |= (1 << PORTB0)|(1 << PORTB1)|
					 (1 << PORTB2)|(1 << PORTB6);
			PORTC |= (1 << PORTC0)|(1 << PORTC1);
			break;
		}
		default: break; 
	}
	
	switch(SegmentB){
		case 0: {
			PORTC |= (1 << PORTC2)|(1 << PORTC3)|
					 (1 << PORTC4)|(1 << PORTC5);
			PORTD |= (1 << PORTD0)|(1 << PORTD1);
			break;
		}
		case 1: {
			PORTC |= (1 << PORTC3)|(1 << PORTC4);
			break;
		}
		case 2: {
			PORTC |= (1 << PORTC2)|(1 << PORTC3)|
					 (1 << PORTC5);
			PORTD |= (1 << PORTD0)|(1 << PORTD2);
			break;
		}
		case 3: {
			PORTC |= (1 << PORTC2)|(1 << PORTC3)|
					 (1 << PORTC4)|(1 << PORTC5);
			PORTD |= (1 << PORTD2);
			break;
		}
		case 4: {
			PORTC |= (1 << PORTC3)|(1 << PORTC4);
			PORTD |= (1 << PORTD1)|(1 << PORTD2);
			break;
		}
		case 5: {
			PORTC |= (1 << PORTC2)|(1 << PORTC4)|
					 (1 << PORTC5);
			PORTD |= (1 << PORTD1)|(1 << PORTD2);
			break;
		}
		case 6: {
			PORTC |= (1 << PORTC2)|(1 << PORTC4)|
			(1 << PORTC5);
			PORTD |= (1 << PORTD0)|(1 << PORTD1)|
					 (1 << PORTD2);
			break;
		}
		case 7: {
			PORTC |= (1 << PORTC2)|(1 << PORTC3)|
					 (1 << PORTC4);
			break;
		}
		case 8: {
			PORTC |= (1 << PORTC2)|(1 << PORTC3)|
					 (1 << PORTC4)|(1 << PORTC5);
			PORTD |= (1 << PORTD0)|(1 << PORTD1)|
					 (1 << PORTD2);
			break;
		}
		case 9: {
			PORTC |= (1 << PORTC2)|(1 << PORTC3)|
			(1 << PORTC4)|(1 << PORTC5);
			PORTD |= (1 << PORTD1)|(1 << PORTD2);
			break;
		}
		default: break;
	}
	
}