#ifndef			ADC_REGISTER_H_
#define			ADC_REGISTER_H_

#define			ADC_ADMUX						*((volatile u8*)0x27)	  /*ADC Multiplexer selsection register*/
#define			ADMUX_MUX0					0									   /*Analog Channel and Gain Selection Bit0*/	
#define			ADMUX_MUX1					1									   /*Analog Channel and Gain Selection Bit1*/
#define			ADMUX_MUX2					2									   /*Analog Channel and Gain Selection Bit2*/	
#define			ADMUX_MUX3					3									   /*Analog Channel and Gain Selection Bit3*/	
#define			ADMUX_MUX4					4									   /*Analog Channel and Gain Selection Bit4*/
#define			ADMUX_ADLAR					5									   /*ADC left adjust result    */
#define			ADMUX_REFS0					6                                     /*Reference selection bit0*/
#define			ADMUX_REFS1					7                                     /*Reference selection bit1*/

#define			ADC_ADCSRA					*((volatile u8*)0x26)     /*ADC Control and Status Register A*/
#define			ADCSRA_ADPS0				0                                    /*prescaler bit0*/
#define			ADCSRA_ADPS1				1                                    /*prescaler bit1*/
#define			ADCSRA_ADPS2				2                                    /*prescaler bit2*/
#define			ADCSRA_ADIE					3                                    /*ADC Interrupt Enable*/
#define			ADCSRA_ADIF					4                                    /*ADC Interrupt Flag*/
#define			ADCSRA_ADATE				5                                    /*ADC Auto Trigger Enable*/
#define			ADCSRA_ADSC					6                                    /*ADC Start Conversion*/
#define			ADCSRA_ADEN					7                                    /*ADC enable*/

#define			ADC_SFIOR						*((volatile u8*)0x50)
#define			ADCSRA_ADTS0				5
#define			ADCSRA_ADTS1				6
#define			ADCSRA_ADTS2				7

#define			ADC_ADCH						*((volatile u8*)0x25)	  /*ADC high register*/
#define			ADC_ADCL						*((volatile u8*)0x24)	  /*ADC low register*/

#define   		ADC_FullRes					*((volatile u16*)0x24)

#endif
