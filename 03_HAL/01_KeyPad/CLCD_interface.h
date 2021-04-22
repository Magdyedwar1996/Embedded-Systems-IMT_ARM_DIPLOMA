/*******************************************************************/
/*******************************************************************/
/***************************     Author:Adel Magdy     *************/
/***************************     Layer:CLCD            *************/
/***************************     SWC:CLCD               *************/
/***************************     Version:1.00          *************/
/***************************     Data:25-8-2020        *************/
/*******************************************************************/
/*******************************************************************/

#ifndef CLCD_INTERFACE_H_
#define CLCD_INTERFACE_H_

void CLCD_voidSendCommend(u8 Copy_u8Commend);
void CLCD_voidSendData(u8 Copy_u8Data);
void CLCD_voidInit(void);
void CLCD_voidSendString(const char* Copy_pchString);
void CLCD_voidGoToXY(u8 Copy_u8XPos,u8 Copy_u8YPos);
void CLCD_voidWriteSpecialCharacter(u8* Copy_pu8Pattern,u8 Copy_u8PatternNumber,u8 Copy_u8XPos,u8 Copy_u8YPos);
void CLCD_voidWriteNumber(u32 Number);
void CLCD_voidSimpleCalculator(void );

#endif 
