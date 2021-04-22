/*******************************************************************/
/*******************************************************************/
/***************************     Author:Adel Magdy     *************/
/***************************     Layer:CLCD            *************/
/***************************     SWC:CLCD               *************/
/***************************     Version:1.00          *************/
/***************************     Data:25-8-2020        *************/
/*******************************************************************/
/*******************************************************************/

#include "STD_TYPES.h"
#include "DIO_interface.h"
#include "CLCD_interface.h"
#include "CLCD_config.h"
#include "CLCD_private.h"
#include <util/delay.h>

void CLCD_voidSendCommend(u8 Copy_u8Commend)
{
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_RS_PIN,DIO_u8PIN_LOW);
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_RW_PIN,DIO_u8PIN_LOW);
	DIO_u8SetPortValue(CLCD_DATA_PORT,Copy_u8Commend);
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_E_PIN,DIO_u8PIN_HIGH);
	_delay_ms(2);
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_E_PIN,DIO_u8PIN_LOW);

}
void CLCD_voidSendData(u8 Copy_u8Data)
{
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_RS_PIN,DIO_u8PIN_HIGH);
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_RW_PIN,DIO_u8PIN_LOW);
	DIO_u8SetPortValue(CLCD_DATA_PORT,Copy_u8Data);
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_E_PIN,DIO_u8PIN_HIGH);
	_delay_ms(2);
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_E_PIN,DIO_u8PIN_LOW);

}
void CLCD_voidInit(void)
{
	_delay_ms(40);
	CLCD_voidSendCommend(0b00111000);

	CLCD_voidSendCommend(0b00001100);

	CLCD_voidSendCommend(0b00000001);




}

void CLCD_voidSendString(const char* Copy_pchString)
{
	u8 Local_u8Counter=0;
	while(Copy_pchString[Local_u8Counter]!='\0')
	{
		CLCD_voidSendData(Copy_pchString[Local_u8Counter]);
		Local_u8Counter++;
	}
}

void CLCD_voidGoToXY(u8 Copy_u8XPos,u8 Copy_u8YPos)
{
	u8 Local_u8DDRAMAddress;
	if(Copy_u8YPos==0)
	{
		Local_u8DDRAMAddress=Copy_u8XPos;
	}
	else if(Copy_u8YPos==1)
	{
		Local_u8DDRAMAddress=0x40+Copy_u8XPos;
	}

	CLCD_voidSendCommend(Local_u8DDRAMAddress+128);
}

void CLCD_voidWriteSpecialCharacter(u8* Copy_pu8Pattern,u8 Copy_u8PatternNumber,u8 Copy_u8XPos,u8 Copy_u8YPos)
{
	u8 Local_u8CGRAMAddress,Local_u8Counter;
	Local_u8CGRAMAddress=Copy_u8PatternNumber*8;
	CLCD_voidSendCommend(Local_u8CGRAMAddress+64);
	for(Local_u8Counter=0;Local_u8Counter<8;Local_u8Counter++)
	{
		CLCD_voidSendData(Copy_pu8Pattern[Local_u8Counter]);
	}
	CLCD_voidGoToXY(Copy_u8XPos,Copy_u8YPos);
	CLCD_voidSendData(Copy_u8PatternNumber);
}

void CLCD_voidWriteNumber(u32 Number)
{
	u32 Local_u32Number=0;
	u32 Local_u32DigitNumber;
	u32 Local_u32Counter1=0;
	u32 Local_u32Counter2=0;
	u32 Local_u32Iterms;
	u32 Local_u32Flag=0;



	while(Number!=0)
	{
		Local_u32Number=(Local_u32Number*10)+(Number%10);
		Number/=10;
		Local_u32Counter1++;
		Local_u32Flag=1;
	}

	while(Local_u32Number!=0)
	{


		Local_u32DigitNumber=Local_u32Number % 10;


		CLCD_voidSendData(Local_u32DigitNumber+'0');


		Local_u32Number/=10;
		Local_u32Counter2++;


	}
	if(Local_u32Flag==0){

		for(Local_u32Iterms=0;Local_u32Iterms<=Local_u32Counter1-Local_u32Counter2;Local_u32Iterms++)
		{
			CLCD_voidSendData('0');

		}
	}
	else{
		for(Local_u32Iterms=0;Local_u32Iterms<Local_u32Counter1-Local_u32Counter2;Local_u32Iterms++)
		{
			CLCD_voidSendData('0');

		}
	}
}

void CLCD_voidSimpleCalculator()
{
	u8 Local_u8Pattern[8]={0b00000100,0b00000100,0b00001110,0b00010101,0b00010101,0b00000100,0b00000100,0};
	u8 Local_u8Pattern1[8]={0};
	u8 pu8Value;
	u8 pu8Value1;
	u8 pu8Value2;
	u32 Local_counter=1;
	u32 Local_Mark=1;
	u32 Local_counter2=1;
	u8 Local_u8XPos=0;
	u8 Local_u8YPos=0;
	CLCD_voidGoToXY(0,0);
	CLCD_voidWriteNumber(Local_counter);
	CLCD_voidGoToXY(1,0);
	CLCD_voidSendData('+');
	CLCD_voidGoToXY(2,0);
	CLCD_voidWriteNumber(Local_counter);



	while(Local_u8XPos==0)
	{
		CLCD_voidWriteSpecialCharacter(Local_u8Pattern,0,0,1);
		CLCD_voidGoToXY(Local_u8XPos,Local_u8YPos);
		DIO_u8GetPinValue(DIO_u8PORTD,DIO_u8PIN0,&pu8Value1);
		if(pu8Value1==0   )
		{
			Local_counter++;
			if(Local_counter==10)
			{
				Local_counter=0;
			}
			_delay_ms(250);

		}
		CLCD_voidGoToXY(0,0);
		CLCD_voidWriteNumber(Local_counter);
		DIO_u8GetPinValue(DIO_u8PORTD,DIO_u8PIN1,&pu8Value2);
		if(pu8Value2==0   )
		{
			Local_counter--;
			if(Local_counter==0)
			{
				Local_counter=9;
			}
			_delay_ms(250);


		}
		CLCD_voidGoToXY(0,0);
		CLCD_voidWriteNumber(Local_counter);
		DIO_u8GetPinValue(DIO_u8PORTD,DIO_u8PIN2,&pu8Value);
		if(pu8Value==0)
		{

			Local_u8XPos=Local_u8XPos+1;
		}

	}
	_delay_ms(250);
	CLCD_voidWriteSpecialCharacter(Local_u8Pattern1,1,0,1);
	while(Local_u8XPos==1)
	{
		CLCD_voidWriteSpecialCharacter(Local_u8Pattern,0,1,1);
		CLCD_voidGoToXY(Local_u8XPos,Local_u8YPos);
		DIO_u8GetPinValue(DIO_u8PORTD,DIO_u8PIN0,&pu8Value1);
		if(pu8Value1==0   )
		{
			Local_Mark++;
			if(Local_Mark==5)
			{
				Local_Mark=1;
			}
			_delay_ms(250);

		}
		DIO_u8GetPinValue(DIO_u8PORTD,DIO_u8PIN1,&pu8Value2);
		if(pu8Value2==0 )
		{
			Local_Mark--;
			if( Local_Mark<1)
			{
				Local_Mark=4;
			}
			_delay_ms(250);


		}
		switch (Local_Mark)
		{
		case 1 :CLCD_voidSendData('+');break;
		case 2 :CLCD_voidSendData('-');break;
		case 3 :CLCD_voidSendData('*');break;
		case 4 :CLCD_voidSendData('/');break;

		}
		DIO_u8GetPinValue(DIO_u8PORTD,DIO_u8PIN2,&pu8Value);
		if(pu8Value==0)
		{
			Local_u8XPos=Local_u8XPos+1;
		}

	}
	_delay_ms(250);
	CLCD_voidWriteSpecialCharacter(Local_u8Pattern1,1,1,1);
	while(Local_u8XPos==2)
	{

		CLCD_voidWriteSpecialCharacter(Local_u8Pattern,0,2,1);
		CLCD_voidGoToXY(Local_u8XPos,Local_u8YPos);
		DIO_u8GetPinValue(DIO_u8PORTD,DIO_u8PIN0,&pu8Value1);
		if(pu8Value1==0   )
		{
			Local_counter2++;
			if(Local_counter2==10)
			{
				Local_counter2=0;
			}
			_delay_ms(250);

		}
		CLCD_voidGoToXY(2,0);
		CLCD_voidWriteNumber(Local_counter2);
		DIO_u8GetPinValue(DIO_u8PORTD,DIO_u8PIN1,&pu8Value2);
		if(pu8Value2==0   )
		{
			Local_counter2--;
			if(Local_counter2==0)
			{
				Local_counter2=9;
			}
			_delay_ms(250);


		}
		CLCD_voidGoToXY(2,0);
		CLCD_voidWriteNumber(Local_counter2);
		DIO_u8GetPinValue(DIO_u8PORTD,DIO_u8PIN2,&pu8Value);
		if(pu8Value==0)
		{
			Local_u8XPos=Local_u8XPos+1;
		}
	}
	_delay_ms(250);
	CLCD_voidWriteSpecialCharacter(Local_u8Pattern1,1,2,1);
	while(Local_u8XPos==3)
	{

		CLCD_voidWriteSpecialCharacter(Local_u8Pattern,0,4,1);
		CLCD_voidGoToXY(Local_u8XPos,Local_u8YPos);
		CLCD_voidSendData('=');
		CLCD_voidGoToXY(Local_u8XPos+1,Local_u8YPos);
		switch(Local_Mark)
		{
		case 1 :CLCD_voidGoToXY(4,0);
			CLCD_voidWriteNumber(Local_counter + Local_counter2);break ;
		case 2 :if(Local_counter>Local_counter2){
			CLCD_voidGoToXY(4,0);
			CLCD_voidWriteNumber(Local_counter - Local_counter2);
		}
		else
		{
			CLCD_voidGoToXY(Local_u8XPos+1,Local_u8YPos);
			CLCD_voidSendData('-');
			CLCD_voidGoToXY(5,0);
			CLCD_voidWriteNumber(Local_counter2 - Local_counter);
		}
			break ;
		case 3 :CLCD_voidGoToXY(4,0);
			CLCD_voidWriteNumber(Local_counter * Local_counter2);break ;
		case 4 :   if(Local_counter2!=0){
			f32 Local_u32FloatNumber=((f32)Local_counter /(f32) Local_counter2)-(Local_counter / Local_counter2);
			CLCD_voidGoToXY(4,0);
			CLCD_voidWriteNumber(Local_counter / Local_counter2);
			CLCD_voidSendData('.');
			Local_u32FloatNumber=Local_u32FloatNumber*100;
			CLCD_voidWriteNumber(Local_u32FloatNumber);
		}
		else{

			CLCD_voidSendString("Infinity");
		}
		break ;


		}
		DIO_u8GetPinValue(DIO_u8PORTD,DIO_u8PIN2,&pu8Value);
		if(pu8Value==0)
		{
			Local_u8XPos=Local_u8XPos+1;
		}
		_delay_ms(250);

	}
	_delay_ms(250);

	CLCD_voidWriteSpecialCharacter(Local_u8Pattern1,1,4,1);
	CLCD_voidSendCommend(1);
}


