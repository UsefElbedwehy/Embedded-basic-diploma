#include "STDTYPES.h"
#include "BITMATH.h"
#include "ADC_Register.h"
#include "ADC_Config.h"
#include "ADC_Private.h"
#include "ADC_Interface.h"



void ADC_VoidInit(void)
{
	/*AVCC as Voltage Reference Selection*/
	SetBit(ADC_ADMUX,ADMUX_REFS0);
	CLRBit(ADC_ADMUX,ADMUX_REFS1);
	/*Activate the left adjust result*/
	SetBit(ADC_ADMUX,ADMUX_ADLAR);
	/*Prescaler selection to 128*/
	SetBit(ADC_ADCSRA,ADCSRA_ADPS0);
	SetBit(ADC_ADCSRA,ADCSRA_ADPS1);
	SetBit(ADC_ADCSRA,ADCSRA_ADPS2);
	/*Enable peripheral*/
	SetBit(ADC_ADCSRA,ADCSRA_ADEN);
}
u8 ADC_u8GetChannelReading(u8 Copy_u8Channel)
{
	/*clear MUX bits in ADMUX Register*/
	ADC_ADMUX&=0b11100000;
	/*Set the required channel into ADC_ADMUX*/
	ADC_ADMUX|=Copy_u8Channel;
	/*start conversion*/
	SetBit(ADC_ADCSRA,ADCSRA_ADSC);
	/*pulling busy waiting until the conversion complete flag is set*/
	while(GetBit(ADC_ADCSRA,ADCSRA_ADIF)==0);
	/*Clear the conversion complete flag*/
	SetBit(ADC_ADCSRA,ADCSRA_ADIF);
	/*return the reading*/

	return ADC_ADCH;
}
u16 ADC_u16GetChannelReading(u8 Copy_u8Channel)
{
	/*clear MUX bits in ADMUX Register*/
	ADC_ADMUX&=0b11100000;
	/*Set the required channel into ADC_ADMUX*/
	ADC_ADMUX|=Copy_u8Channel;
	/*start conversion*/
	SetBit(ADC_ADCSRA,ADCSRA_ADSC);
	/*pulling busy waiting until the conversion complete flag is set*/
	while(GetBit(ADC_ADCSRA,ADCSRA_ADIF)==0);
	/*Clear the conversion complete flag*/
	SetBit(ADC_ADCSRA,ADCSRA_ADIF);
	/*return the reading*/
	return ADC_FullRes;
}
