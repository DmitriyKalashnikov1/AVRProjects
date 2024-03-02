/*
 * main.c
 *
 * Created: 8/16/2023 12:05:41 PM
 *  Author: slagt
 */ 

#define F_CPU 16000000L

#include <xc.h>
#include "util/delay.h"
#include "uart328p.h"
#include <avr/interrupt.h>

#define BAUDRATE 9600
#define UBRR (F_CPU/(BAUDRATE<<4))-1


int main(void)
{
	DDRD |= (1 << PD1);//TX on output
	
	USART_Init(103); // 9600
	_delay_ms(1000);
	USART_Transmit_STR("Hello, this is serial echo example!\n ");
	USART_Transmit_INT(0);
	USART_Transmit('\n');
    while(1)
    {
		USART_Transmit(USART_Receive());
		//_delay_ms(500);
		
    }
}


ISR(USART_RXC_vect)

{
   // do something very useful ;)
	//int b;

	//b = UDR0;

}