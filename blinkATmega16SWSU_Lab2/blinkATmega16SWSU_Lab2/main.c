/*
 * main.c
 *
 * Created: 3/1/2024 12:57:52 PM
 *  Author: slagt
 */ 
#define F_CPU 4000000L

#include <avr/io.h>
#include <util/delay.h>
#include <avr/portpins.h>


int main(void)
{
	// pin 39, 40 -> output
	DDRA |= (1 << PA0); 
	DDRA |= (1 << PA1); 
	 // pin 39, 40 -> low, high
	PORTA |= (1 << PA0);
	
    while(1)
    {
	 
	 PORTA |= (1 << PA1);
	 _delay_ms(1000);
	 PORTA &= ~(1 << PA1);
	 _delay_ms(1000);
    }
}