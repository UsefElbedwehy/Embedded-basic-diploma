
u16 LDR_u16GetValue(u8 Copy_u8Channel)
{
	u16	Local_u16Digital=0;
	u16	Local_u16Analog=0;
	u16	Local_u16LightIntenisty=0;

	Local_u16Digital=ADC_u8GetChannelReading(Copy_u8Channel);
	Local_u16Analog=((u32)Local_u16Digital*5000UL)/256;
	Local_u16LightIntenisty=Local_u16Analog*2;
	return Local_u16LightIntenisty;
}