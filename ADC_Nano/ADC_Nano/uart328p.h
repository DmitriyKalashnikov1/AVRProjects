/*
 * UART328P.H
 *
 * Created: 16.08.2023 12:38:12
 *  Author: slagt
 */ 


#ifndef UART328P_H_

#define UART328P_H_

void USART_Init( unsigned int speed);
void USART_Transmit( unsigned char data );
void USART_Transmit_STR( const char *s);
void USART_Transmit_INT(unsigned int c);
unsigned char USART_Receive(void);

#endif /* UART328P_H_ */