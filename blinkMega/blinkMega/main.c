/*
 * main.c
 *
 * Created: 2/8/2024 1:20:00 PM
 *  Author: slagt
 */ 

#define F_CPU 16000000L
#include <avr/io.h>
#include <util/delay.h>
#include <avr/portpins.h>

int main(void)
{
	//init pin 13 arduino nano, pin13 = pb5
	
	DDRB = (1 << PB7);
	PORTB = (0 << PB7);
	
	while(1)
	{
		_delay_ms(500);
		PORTB = (1 << PB7);
		_delay_ms(1500);
		PORTB = (0 << PB7);
		
	}
}