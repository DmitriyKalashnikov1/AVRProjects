/*
 * main.c
 *
 * Created: 3/27/2024 12:41:20 PM
 *  Author: slagt
 */ 
#define F_CPU  4000000L

#include "avr/io.h"
#include "util/delay.h"
#include "avr/portpins.h"
#include  "avr/interrupt.h"


int main(void)
{
	// pins PA0 PC4 -> output
	DDRA |= (1 << PA0);
	DDRC |= (1 << PC4);
	// PC4 PA0 -> high
	PORTC |= (1 << PC4);
	PORTA |= (1 << PA0);
	
	// turn on interrupt on INT0 INT1
	GICR |= (1 << INT0);
	GICR |= (1 << INT1);
	// setup interrupts front -> FALLING
	// INT0
	MCUCR |= (1 << ISC01);
	MCUCR &= ~(1 << ISC00);
	//INT1
	MCUCR |= (1 << ISC11);
	MCUCR &= ~(1 << ISC10);
	// enable interrupts
	asm("sei");

    while(1)
    {
        //TODO:: DO NOTHING! 
    }
}

//handle for INT0
ISR(INT0_vect){
	// blink 1x 1s
	PORTA &= ~(1 << PA0);
	_delay_ms(1000);
	PORTA |= (1 << PA0);
}

//handle for INT1
ISR(INT1_vect){
	// blink 3x 0.5s
	for(int f = 0; f <3; f++){
	PORTA &= ~(1 << PA0);
	_delay_ms(500);
	PORTA |= (1 << PA0);
	_delay_ms(500);
	}
}