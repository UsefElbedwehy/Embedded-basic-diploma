#ifndef EXTI_INTERFACE_H_
#define EXTI_INTERFACE_H_

void EXTI_VoidInt0Init(void);
void EXTI_VoidInt1Init(void);
void EXTI_VoidInt2Init(void);
/*
 Describtion: a function used to set the sense control of int0 using postbuild configuration
 Input:sense control of int0 , options:
								       1-LOW_LEVEL
								       2-ON_CHANGE
								       3-FALLING_EDGE
								       4-RISING_EDGE
 Output: error state with type u8							*/
u8 EXTI_u8Int0SenseControl(u8 Copy_u8Sense);
/*
 Describtion: a function used to set the sense control of int1 using postbuild configuration
 Input:sense control of int0 , options:
								       1-LOW_LEVEL
								       2-ON_CHANGE
								       3-FALLING_EDGE
								       4-RISING_EDGE
 Output: error state with type u8							*/
u8 EXTI_u8Int1SenseControl(u8 Copy_u8Sense);
/*
 Describtion: a function used to set the sense control of int2 using postbuild configuration
 Input:sense control of int0 , options:
								       1-LOW_LEVEL
								       2-ON_CHANGE
								       3-FALLING_EDGE
								       4-RISING_EDGE
 Output: error state with type u8							*/
u8 EXTI_u8Int2SenseControl(u8 Copy_u8Sense);
/*
 Describtion: a function used to set the enable state of int using postbuild configuration
 Input:INTno , options:
						    1-EXIT_INT_0
						    2-EXIT_INT_1
						    3-EXIT_INT_3
 Output: error state with type u8							*/
u8 EXTI_u8IntEnable(u8 Copy_u8Int);
u8 EXTI_u8IntDisable(u8 Copy_u8Int);
/**************CALL BACK FUNCTION***************/
/*A FUNCTION THAT RECEIVE THE SENT FUNCTION(OF ISR) ADDRESS */
u8 EXTI_u8INT0CallBackFunc(void (*Copy_INT0)(void));
u8 EXTI_u8INT1CallBackFunc(void (*Copy_INT1)(void));
u8 EXTI_u8INT2CallBackFunc(void (*Copy_INT2)(void));
#endif
