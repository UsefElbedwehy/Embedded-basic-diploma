#ifndef		ADC_INTERFACE_H_
#define		ADC_INTERFACE_H_

void ADC_VoidInit(void);
u8 ADC_u8GetChannelReading(u8 Copy_u8Channel);
u16 ADC_u16GetChannelReading(u8 Copy_u8Channel);
#endif
