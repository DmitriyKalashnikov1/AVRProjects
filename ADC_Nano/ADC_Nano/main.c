/*
 * main.c
 *
 * Created: 8/23/2023 5:36:13 PM
 *  Author: slagt
 */ 

#define F_CPU 16000000L

#include <xc.h>
#include "util/delay.h"
#include "uart328p.h"
#include "adc.h"
#include <avr/interrupt.h>


int main(void)
{
	// init serial ;)
	DDRD |= (1 << PD1);//TX on output
	USART_Init(103); // 9600
	_delay_ms(1000);
	// init adc
	ADC_Init();
	USART_Transmit_STR("ADC init ok \n");
    while(1)
    {
		ADC_Set_ADC2();
		unsigned int valA2 = get_ADC_val();
		USART_Transmit_STR("A2 val: ");
		USART_Transmit_INT(valA2);
		USART_Transmit('\n');
		
		ADC_Set_ADC3();
		unsigned int valA3 = get_ADC_val();
		USART_Transmit_STR("A3 val: ");
		USART_Transmit_INT(valA3);
		USART_Transmit('\n');
		
        //TODO:: Please write your application code 
    }
}