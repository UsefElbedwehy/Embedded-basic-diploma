#ifndef	LM35_INTERFACE_H_
#define	LM35_INTERFACE_H_

u8 LM35_u8GetTemperature8Res(u8* Copy_u8pTempValue);
u8 LM35_u8GetTemperature10Res(u16* Copy_u8pTempValue);

#endif