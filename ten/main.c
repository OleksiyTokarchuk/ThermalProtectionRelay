/*
 * ten.c
 *
 * Created: 31.03.2021 14:43:08
 * Author : TOKA
 */ 

#include "main.h"

volatile uint8_t SetPoint	 = 0; 
volatile uint8_t Temperature = 0;

int main(void)
{
	if (eeprom_read_byte((uint8_t*)SetPointEEPROMaddr) != 0xFF){
		SetPoint = eeprom_read_byte((uint8_t*)SetPointEEPROMaddr);
	}
	DDRB = 0xFF;
	DDRC = 0xFF;
	DDRD |= (1 << DDB0)|(1 << DDB1)|(1 << DDB2)|(1 << DDB3)|(1 << DDB4);
	DDRD &= ~((1 << DDB5)|(1 << DDB6)|(1 << DDB7));
	PORTD |= (1 << PORTD5)|(1 << PORTD6)|(1 << PORTD7);
	TCCR0 |= (1 << CS00)|(1 << CS02);	//timer prescaller 1024
	TIMSK |= (1 << TOIE0);
	ADC_Config();
    /* Replace with your application code */
	PORTD |= (1 << PORTD3);
	IndicatorOut(100);
	_delay_ms(500);
	sei();
	while (1) 
    {
		Temperature = (uint8_t)GetTemperature();
		if (Temperature >= SetPoint){
			PORTD &= ~(1 << PORTD3);
		}
	}
}

ISR(TIMER0_OVF_vect){
	cli();
	if (ButtonRead() == TENS)
	{
		if (SetPoint < 90)
		{
			SetPoint += 10;
			eeprom_write_byte((uint8_t*)SetPointEEPROMaddr, SetPoint);
			IndicatorOut(SetPoint);
		}
		else if (SetPoint == 90)
		{
			SetPoint += 9;
			eeprom_write_byte((uint8_t*)SetPointEEPROMaddr, SetPoint);
			IndicatorOut(SetPoint);
		}
		else
		{
			eeprom_write_byte((uint8_t*)SetPointEEPROMaddr, SetPoint);
			SetPoint = 0;
		}
	}
	if (ButtonRead() == OK)
	{
		PORTD |= (1 << PORTD3);
		IndicatorOut(SetPoint);
	}
	if (ButtonRead() == ONES)
	{
		if (SetPoint < 99)
		{
			++SetPoint;
			if ((SetPoint % 10) == 0)
			{
				SetPoint -= 10;
				eeprom_write_byte((uint8_t*)SetPointEEPROMaddr, SetPoint);
				IndicatorOut(SetPoint);
			} 
			else
			{
				eeprom_write_byte((uint8_t*)SetPointEEPROMaddr, SetPoint);
				IndicatorOut(SetPoint);
			}
			
		}
		else
		{
			SetPoint = 0;
			eeprom_write_byte((uint8_t*)SetPointEEPROMaddr, SetPoint);
			IndicatorOut(SetPoint);
		}
	}
	if (ButtonRead() == NAC)
	{
		_delay_ms(500);
		IndicatorOut((uint8_t)Temperature);
	}
	sei();
}