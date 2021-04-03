/*
 * main.h
 *
 * Created: 31.03.2021 15:50:52
 *  Author: TOKA
 */ 


#ifndef MAIN_H_
#define MAIN_H_

#define SetPointEEPROMaddr	0x00
#include <avr/io.h>
#include <avr/interrupt.h>
#define F_CPU	1000000UL
#include <util/delay.h>
#include "indicator.h"
#include "buttons.h"
#include "adc.h"
#include <stdbool.h>
#include <avr/eeprom.h>

#endif /* MAIN_H_ */