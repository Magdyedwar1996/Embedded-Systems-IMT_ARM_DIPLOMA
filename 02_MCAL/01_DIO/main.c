#include <util/delay.h>
#include "STD_TYPES.h"
#include "DIO_interface.h"

void main(void)
{
	// make the fist pin of the portA is output
	DIO_u8SetPortDirection(DIO_u8PORTA, DIO_u8PORT_HIGH);
		while(1)
		{

				// make this pin as high
			DIO_u8SetPinValue(DIO_u8PORTA, DIO_u8PIN0 ,DIO_u8PIN_HIGH);
			_delay_ms(1000);
			DIO_u8SetPinValue(DIO_u8PORTA, DIO_u8PIN0 ,DIO_u8PIN_LOW);


			DIO_u8SetPinValue(DIO_u8PORTA, DIO_u8PIN1 ,DIO_u8PIN_HIGH) ;
			_delay_ms(1000);
			DIO_u8SetPinValue(DIO_u8PORTA, DIO_u8PIN1 ,DIO_u8PIN_LOW);


			DIO_u8SetPinValue(DIO_u8PORTA, DIO_u8PIN2 ,DIO_u8PIN_HIGH) ;
			_delay_ms(1000);
			DIO_u8SetPinValue(DIO_u8PORTA, DIO_u8PIN2 ,DIO_u8PIN_LOW);


			DIO_u8SetPinValue(DIO_u8PORTA, DIO_u8PIN3 ,DIO_u8PIN_HIGH) ;
			_delay_ms(1000);
			DIO_u8SetPinValue(DIO_u8PORTA, DIO_u8PIN3 ,DIO_u8PIN_LOW);


			DIO_u8SetPinValue(DIO_u8PORTA, DIO_u8PIN4 ,DIO_u8PIN_HIGH) ;
			_delay_ms(1000);
			DIO_u8SetPinValue(DIO_u8PORTA, DIO_u8PIN4 ,DIO_u8PIN_LOW);


			DIO_u8SetPinValue(DIO_u8PORTA, DIO_u8PIN5 ,DIO_u8PIN_HIGH) ;
			_delay_ms(1000);
			DIO_u8SetPinValue(DIO_u8PORTA, DIO_u8PIN5 ,DIO_u8PIN_LOW);


	       DIO_u8SetPinValue(DIO_u8PORTA, DIO_u8PIN6 ,DIO_u8PIN_HIGH) ;
			_delay_ms(1000);
			DIO_u8SetPinValue(DIO_u8PORTA, DIO_u8PIN6 ,DIO_u8PIN_LOW);


		DIO_u8SetPinValue(DIO_u8PORTA, DIO_u8PIN7 ,DIO_u8PIN_HIGH) ;
		_delay_ms(1000);
		DIO_u8SetPinValue(DIO_u8PORTA, DIO_u8PIN7 ,DIO_u8PIN_LOW);















			/*
			DIO_u8SetPortValue(DIO_u8PORTA,DIO_u8PORT_HIGH);
			_delay_ms(1000);
			DIO_u8SetPortValue(DIO_u8PORTA,DIO_u8PORT_LOW);
			_delay_ms(1000);*/
		}



}



/*3- Test Get pin value

	}*/
