/************************************************************************************/
/************** 	Author : Usef Elbedwehy              		*************************************/
/************** 	Layer : MCAL         				      		************************************/
/**************	 	SWC : WDT						            	***********************************/
/************** 	Version : V1         						   		**********************************/
/************** 	Date : Monday, September 11, 2023	*********************************/
/******************************************************************************/
void WDT_VoidSleep(u8 Copy_u8Period)
{
	/*Clear the Watchdog Timer Prescale Select bits*/
	WDT_WDTCR&=PRESCALE_CLR_MASK;
	/*Mask entered number to make sure it will no exceed three bits*/
	Copy_u8Period&=PRESCALE_SAFTY_MASK;
	/*Set the required Watchdog Timer Prescale */
	WDT_WDTCR|=Copy_u8Period;
}
void WDT_VoidEnable(void)
{
	/*Enable WatchDog Timer*/
	SetBit(WDT_WDTCR,WDTCR_WDE);
}
void WDT_VoidDisable(void)
{
	/*In the same operation, write a logic one to WDTOE and WDE*/
	WDT_WDTCR |= (1<<WDTCR_WDTOE) | (1<<WDTCR_WDE);
	/*Within the next four clock cycles, write a logic 0 to WDE*/
	WDT_WDTCR = LOW_PORT;
}
