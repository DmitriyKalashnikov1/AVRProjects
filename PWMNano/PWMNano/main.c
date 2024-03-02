/*
 * main.c
 *
 * Created: 8/16/2023 11:19:38 AM
 *  Author: slagt
 */ 
#define F_CPU 16000000L

#include <avr/io.h> // регистры
#include <util/delay.h> // _delay_ms
#include <avr/portpins.h> // наименование портов


int main(void)
{	
	 
	//pin6 uno
	   DDRD |= (1 << PD6);

	   // PD6 as output
	   OCR0A = 0;
	   // set PWM for 50% duty cycle at 10bit
	   TCCR0A |= (1 << COM1A1) | (1 << COM1B1);
	   // set non-inverting mode
	   TCCR0A |= (1 << WGM21) | (1 << WGM20);
	   // set 8bit fast PWM Mode
	   
	   TCCR0B |= (1 << CS11);
	   // set prescaler to 8 and starts PWM
    while(1)
    {
        OCR0A = 127;
		_delay_ms(600);
		OCR0A = 51;
		_delay_ms(400);
    }
}