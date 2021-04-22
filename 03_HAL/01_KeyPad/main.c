/*
 * main.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: First
 */


#include "STD_TYPES.h"
#include "DIO_interface.h"
#include "CLCD_interface.h"
#include <util/delay.h>
#include "PORT_interface.h"
#include "KPD_interface.h"


	int main()
	{
    PORT_voidInit();
    CLCD_voidInit();

//Keypad_voidComplateCalculator();
    while(1)
    {
    	/*Local_u8Number=KPD_U8GetPressedKey();
    	while (Local_u8Number==0xff)
    	{
    		Local_u8Number=KPD_U8GetPressedKey();
    	}*/
    	//Keypad_voidComplateCalculator();
    	Keypad_voidTimer();

    }

    }

