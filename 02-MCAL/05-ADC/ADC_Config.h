#ifndef		ADC_CONFIG_H_
#define		ADC_CONFIG_H_
/**********************************************/
/*Voltage Reference Selection,
 * OPTIONS:
 		1-AREF
 		2-AVCC
  		3-Internal_2Point56V	*/
#define	ADC_Voltage_Reference_Selection		AVCC
/**********************************************/
/*ADC Prescaler Selections,
 * OPTIONS:
 		1-PrescalerDivisionBy2
 		2-PrescalerDivisionBy4
  		3-PrescalerDivisionBy8
  		4-PrescalerDivisionBy16
  		5-PrescalerDivisionBy32
  		6-PrescalerDivisionBy64
  		7-PrescalerDivisionBy128	*/
#define	ADC_Prescaler_Selection		PrescalerDivisionBy128
/**********************************************/

#endif
