/*
 * Controling_DC_Motor_Project.c
 *
 * Created: 11/11/2023 14:18:54
 * Author : Sergio Fink
 */ 

#include <avr/io.h>

#define   Motor   PB1

int main(void)
{
	DDRB |= (1<<Motor);  //PB1 output
	TCCR1B = (1<<CS10);  // Timer 1 is ON, prescaler is 1
	TCCR1A = (1<<WGM10) | (1<<WGM11) | (1<<COM1A1); //select PWM mode.
	
	ADCSRA = (1<<ADEN) | (1<<ADPS1) | (1<<ADPS2) | (1<<ADPS0); //Setting the ADC block
	ADMUX = (1<<REFS1) | (1<<REFS0) |(1<<MUX0) |(1<<MUX2);
	
	while(1)
	{
		unsigned int ADC_result; //In this variable we will keep conversion result
		ADCSRA |= (1<<ADSC);    //Start conversion
		
		do{} while (ADCSRA & (1<<ADSC));
		ADC_result = ADC;
		OCR1A = ADC_result;  //Here is stored the ADC value
	}
}