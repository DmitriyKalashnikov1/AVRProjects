/*
 * adc.c
 *
 * Created: 23.08.2023 17:44:50
 *  Author: slagt
 */ 
#include "adc.h"
#include "avr/io.h"

void ADC_Init(){
	ADCSRA |= (1<<ADEN) // Turn on ADC

	|(1<<ADPS2)|(1<<ADPS1)|(1<<ADPS0);//Prescaller 128 = 64 kH
	ADMUX |= (1<<REFS1)|(1<<REFS0); //internal voltage source 2,56v, input ADC0
}
void ADC_Set_ADC0(){
	ADMUX = 0;
	ADMUX |= (1<<REFS1)|(1<<REFS0);
}

void ADC_Set_ADC1(){
	ADMUX = 0;
	ADMUX |= (1<<REFS1)|(1<<REFS0)|(1<<MUX0);
}

void ADC_Set_ADC2(){
	ADMUX = 0;
	ADMUX |= (1<<REFS1)|(1<<REFS0)|(1<<MUX1);
}

void ADC_Set_ADC3(){
	ADMUX = 0;
	ADMUX |= (1<<REFS1)|(1<<REFS0)|(1<<MUX1)|(1<<MUX0);
}

//To do: add all adc channels

unsigned int get_ADC_val(){
	 ADCSRA |= (1<<ADSC); //start converting
	 while((ADCSRA & (1<<ADSC))); //wait while convertint will be end
	 return (unsigned int)ADC;
}


	


