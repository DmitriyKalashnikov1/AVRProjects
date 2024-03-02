#include <xc.h>
#include "uart328p.h"
#include "avr/portpins.h"


void USART_Init( unsigned int speed)//Инициализация модуля USART

{

	 UBRR0 = speed;
	 
	// 9600-8-E-1
	// That is, baudrate of 9600bps
	// 8 databits
	// Even parity
	// 1 stopbit
	UCSR0B = (1 << TXEN0) | (1 << RXEN0) | (1 << RXCIE0); // And enable interrupts
	UCSR0C = (1 << UPM01) | (1 << UCSZ01) | (1 << UCSZ00);

}

void USART_Transmit(unsigned char data)
{
	/* Wait for empty transmit buffer */
	while (!(UCSR0A & (1<<UDRE0)))
	;
	/* Put data into buffer, sends the data */
	UDR0 = data;
}

void USART_Transmit_STR(const char *s)
{
	while (*s != 0) {USART_Transmit(*s++);}
}

void USART_Transmit_INT(unsigned int c)//	Отправка числа от 0000 до 9999
{
	unsigned char temp;
	c=c%10000;
	temp=c/100;
	USART_Transmit(temp/10+'0');
	USART_Transmit(temp%10+'0');
	temp=c%100;;
	USART_Transmit(temp/10+'0');
	USART_Transmit(temp%10+'0');
}
unsigned char USART_Receive(void)
{
	/* Wait for data to be received */
	while (!(UCSR0A & (1<<RXC0)))
	;
	/* Get and return received data from buffer */
	return UDR0;
}

