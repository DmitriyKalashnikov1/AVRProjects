/*
 * main.c
 *
 * Created: 2/8/2024 11:53:45 AM
 *  Author: slagt
 */ 
#define F_CPU 16000000L

#include "avr/io.h"
#include <util/delay.h>
#include <avr/portpins.h>



int main(void)
{
   	//init pin 13 arduino uno, pin13 = pb5
   	
   	DDRB = (1 << PB5);
   	PORTB = (0 << PB5);
   	
   	while(1)
   	{
	   	_delay_ms(1000);
	   	PORTB = (1 << PB5);
	   	_delay_ms(1000);
	   	PORTB = (0 << PB5);
	   	
   	}
}