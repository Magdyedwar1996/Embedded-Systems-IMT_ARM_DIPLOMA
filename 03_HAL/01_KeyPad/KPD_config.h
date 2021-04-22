/*******************************************************************/
/*******************************************************************/
/***************************     Author:Adel Magdy     *************/
/***************************     Layer:HALL            *************/
/***************************     SWC:KPD               *************/
/***************************     Version:1.00          *************/
/***************************     Data:1-9-2020        *************/
/*******************************************************************/
/*******************************************************************/

#ifndef KPD_CONFIG_H
#define KPD_CONFIG_H
#define KPD_BUTTONS_VAL    {{1,2,3,4},{5,6,7,8},{9,0,'+','-'},{'*','/','=','.'}}

#define KPD_PORT     DIO_u8PORTD

#define COLLUM_PIN0  DIO_u8PIN0
#define COLLUM_PIN1  DIO_u8PIN1
#define COLLUM_PIN2  DIO_u8PIN2
#define COLLUM_PIN3  DIO_u8PIN3

#define ROW_PIN0  DIO_u8PIN4
#define ROW_PIN1  DIO_u8PIN5
#define ROW_PIN2  DIO_u8PIN6
#define ROW_PIN3  DIO_u8PIN7

#define NO_PRESSED_KEY  0xff

#endif
