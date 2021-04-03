/*
 * adc.c
 *
 * Created: 02.04.2021 20:14:33
 *  Author: TOKA
 */ 

#include "main.h"
#include "adc.h"

float GetVoltage(){
	ADCSRA|=(1 << ADSC);
	while(ADCSRA & (1 << ADSC));
	unsigned int ADC_Code = (ADCL|(ADCH << 8));
	float Voltage = (5 * (float)ADC_Code) / 1024;
	return Voltage; 
}

float GetTemperature(){
	float voltage = GetVoltage();
	return (-0.2843 * (voltage * voltage) + 35.085 * voltage - 2.0869);
}

void ADC_Config(void){
	ADMUX |= (1 << MUX0)|(1 << MUX1)|(1 << MUX2)|(1 << REFS0);	//adc7
	ADCSRA |= (1 << ADPS0)|(1 << ADPS1)|(ADPS2)|(1 << ADEN);
}