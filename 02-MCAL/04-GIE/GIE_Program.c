/***********************************************************************************/
/************** 	Author : Usef Elbedwehy              		************************************/
/**************	 	Layer : MCAL 						           	***********************************/
/**************	 	SWC : GIE 						           		**********************************/
/************** 	Version : V1         						   		*********************************/
/************** 	Date : Sunday, August 27, 2023		    ********************************/
/*****************************************************************************/
#include "STDTYPES.h"
#include "BITMATH.h"
#include "GIE_Inteface.h"
#include "GIE_Register.h"


void GIE_VoidEnable(void)
{
	SetBit(GIE_SREG,SREG_I);
}
void GIE_VoidDisable(void)
{
	CLRBit(GIE_SREG,SREG_I);
}