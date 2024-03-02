/*
 * main.c
 *
 * Created: 2/8/2024 1:01:06 PM
 *  Author: slagt
 */ 

#define F_CPU 16000000L
#include <avr/io.h>
#include <util/delay.h>
#include <avr/portpins.h>

int main(void)
{
	//init pin 3 arduino l, pin3 = pd0
	
	DDRD = (1 << PD0);
	PORTD = (0 << PD0);
	
	while(1)
	{
		_delay_ms(500);
		PORTD = (1 << PD0);
		_delay_ms(1500);
		PORTD = (0 << PD0);
		
	}
}