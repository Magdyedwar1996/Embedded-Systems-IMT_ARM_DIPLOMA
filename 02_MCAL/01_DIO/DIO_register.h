/*****************************************************************/
/*****************************************************************/
/***************		Author: Magdy Edwar	******************/
/***************		Layer: MCAL				******************/
/***************		SWC: DIO				******************/
/***************		Date: 24-8-2020			******************/
/***************		Version: 1.00			******************/
/*****************************************************************/
/*****************************************************************/

/*Preprocessor file guard*/
#ifndef DIO_REGISTER_H_
#define DIO_REGISTER_H_

// these are the registers of the first port [PORTA]
// PORTA : is the register that control the Output of the port
// DDRA : is the register that control the direction of the data
//PINA : is the register that determine and control the input
#define PORTA	 	*((volatile u8*)0x3B)	 
#define DDRA 	 	*((volatile u8*)0x3A)    
#define PINA 	 	*((volatile u8*)0x39)    



// these are the registers of the first port [PORTA]
// PORTB : is the register that control the Output of the port
// DDRB : is the register that control the direction of the data
//PINB: is the register that determine and control the input
#define PORTB		*((volatile u8*)0x38)    
#define DDRB 		*((volatile u8*)0x37)    
#define PINB 		*((volatile u8*)0x36)    


// these are the registers of the first port [PORTC]
// PORTC : is the register that control the Output of the port
// DDRC: is the register that control the direction of the data
//PINC : is the register that determine and control the input

#define PORTC		*((volatile u8*)0x35)    
#define DDRC 		*((volatile u8*)0x34)    
#define PINC 		*((volatile u8*)0x33)    



// these are the registers of the first port [PORTD]
// PORTD : is the register that control the Output of the port
// DDRD: is the register that control the direction of the data
//PIND: is the register that determine and control the input
#define PORTD		*((volatile u8*)0x32)    
#define DDRD 		*((volatile u8*)0x31)    
#define PIND 		*((volatile u8*)0x30)    


#endif  /*   DIO_REGISTER_H_ */
