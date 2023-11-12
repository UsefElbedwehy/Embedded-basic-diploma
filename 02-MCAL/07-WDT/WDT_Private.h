/************************************************************************************/
/************** 	Author : Usef Elbedwehy              		*************************************/
/************** 	Layer : MCAL         				      		************************************/
/**************	 	SWC : WDT						            	***********************************/
/************** 	Version : V1         						   		**********************************/
/************** 	Date : Monday, September 11, 2023	*********************************/
/******************************************************************************/
#ifndef 		WDT_PRIVATE_H_
#define 	WDT_PRIVATE_H_

/*Watchdog Timer Prescale Select*/
#define SIXTEENp3_MILLISEC					0
#define THISTY_TWOp5_MILLISEC				1
#define SIXTY_FIVE_MILLISEC					2
#define ZEROp13_SEC								3
#define ZEROp26_SEC								4
#define ZEROp52_SEC								5
#define ONE_SEC										6
#define TWOpONE_SEC								7
/*MACROS*/
#define		LOW_PORT								 0x00
#define		LOW_PIN							 	     0

#define     PRESCALE_CLR_MASK				b11111000
#define     PRESCALE_SAFTY_MASK			0b00000111

#endif