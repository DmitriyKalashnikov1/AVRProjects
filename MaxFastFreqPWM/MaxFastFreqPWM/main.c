/*
 * main.c
 *
 * Created: 9/1/2023 3:21:56 PM
 *  Author: slagt
 */ 

/*
 * main.c
 *
 * Created: 8/16/2023 11:19:38 AM
 *  Author: slagt
 */ 
#define F_CPU 16000000L

#include <xc.h>
#include "util/delay.h"
#include <avr/portpins.h>

int main(void)
{	
	 _delay_ms(1000);
	 int speed = 1;
	//pin3&pin4&pin5&pin6&pin9&pin10 uno
	   DDRD |= (1 << DDD3);
	   DDRD |= (1 << DDD4);
	   DDRD |= (1 << DDD6);
	   DDRD |= (1 << DDD5);
	   DDRB |= (1 << DDB1);
	   DDRB |= (1 << DDB2);
	   // PD3&PD4&PD6&PD5&PB1&PB2 as output
	   
	   //zum pin to out
	   DDRB |= (1 << DDB0);
	   
	   //beep
	   PORTB |= (1 << PB0);
	   _delay_ms(50);
	   PORTB &= ~(1 << PB0);
	   
	   // set motor dir
	   PORTD |= (1 << PD3);
	   PORTD &= ~(1 << PD4);
	   
	   PORTB |= (1 << PB2);
	   PORTB &= ~(1 << PD1);
	   
	   OCR0A = 100;
	   OCR0B = 40;
	   // set PWM for 50% duty cycle at 10bit
	   TCCR0A |= (1 << COM0A1) | (1 << COM0B1);
	   // set non-inverting mode
	   TCCR0A |= (1 << WGM02) |  (1 << WGM00);
	   // set 8bit phase correct PWM Mode
	   
	   TCCR0B |= (1 << CS00);
	   // set prescaler to 0 and starts PWM
    
	while(1)
    {
        OCR0A += speed;
        
        if (OCR0A > 254){
	        speed = -1;
        }
        if (OCR0A < 1){
	        speed = 1;
        }
        _delay_ms(10);
        
		
    }
}