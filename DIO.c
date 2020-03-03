/*
 * DIO.c
 *
 *  Created on:  MONDAY_03/02/2020_8:16 AM
 *      Author: ABBAS SALAH HATATA
 */
/*********************************#INCLUDE_LIBRARY_ATMEGA_32*************************************/
#include "DIO.h"

/**********************************#DEFINE_DIO.C*************************************************/
//static  DIO_CFG *CHANNEL_PTR = NULL_PTR ;

/************************************DIO_FUNCTION************************************************/
//DIO_SET_PORT_DIRECTION(PORT_ID PORT_NAME,DIO_DIRECTION DIRIO)
CHECK_ERROR DIO_SET_PORT_DIRECTION(PORT_ID PORT_NAME,DIO_DIRECTION DIRIO){
	 // Check For Errors
	 	CHECK_ERROR ERROR_STATE = NO_ERROR;
	 	if( (DIRIO != INPUT) && (DIRIO != OUTPUT) )
	 	{
	 		ERROR_STATE = ERROR;
	 	}
	 	else { /* Do Nothing */ }


       switch(PORT_NAME){

       case PORT_A:{
    	   DIRIO == OUTPUT ? (DDRA_REG=0xFF):(DDRA_REG=0x00) ;

       }break;
       case PORT_B:{
    	   DIRIO == OUTPUT ?(DDRB_REG=0xFF):(DDRB_REG=0x00) ;

             }break;
       case PORT_C:{
    	   DIRIO == OUTPUT ?(DDRC_REG=0xFF):(DDRC_REG=0x00) ;

       	   	 }break;
       case PORT_D:{
    	   DIRIO == OUTPUT ?(DDRD_REG=0xFF):(DDRD_REG=0x00) ;

             }break;
       default:{
       		ERROR_STATE = ERROR;
       }break;
       }
       return ERROR_STATE;
 }

//DIO_SET_PIN_DIRECTION(PORT_ID PORT_NAME,PIN_ID PIN_NUM,DIO_DIRECTION DIRIO)
 CHECK_ERROR DIO_SET_PIN_DIRECTION(PORT_ID PORT_NAME,PIN_ID PIN_NUM,DIO_DIRECTION DIRIO){

  //  CHANNEL_PTR= &ARRAY_OF_CFG[CHANNEL];
	  //Check For Errors
	  CHECK_ERROR ERROR_STATE = NO_ERROR;
	 	if((PIN_NUM)  > PIN_7 )

	 	{
	 		ERROR_STATE = ERROR;
	 	}
	 	else if( (DIRIO != INPUT) && (DIRIO != OUTPUT) )
	 	{
	 		ERROR_STATE = ERROR;
	 	}
	 	else { /* Do Nothing*/  }

	 	switch (PORT_NAME){
	 	 	case PORT_A:{

	 	 		DIRIO == OUTPUT ?SET_BIT(DDRA_REG,PIN_NUM):CLEAR_BIT(DDRA_REG,PIN_NUM) ;

	 	 	}break;

	 	 	case PORT_B:{

	 	 		DIRIO == OUTPUT ?SET_BIT(DDRB_REG,PIN_NUM):CLEAR_BIT(DDRB_REG,PIN_NUM) ;

	 	 	}break;

	 	 	case PORT_C:{

	 	 		DIRIO == OUTPUT ?SET_BIT(DDRC_REG,PIN_NUM):CLEAR_BIT(DDRC_REG,PIN_NUM) ;
	 	 	}break;

	 	 	case PORT_D:{

	 	 		DIRIO == OUTPUT ?SET_BIT(DDRD_REG,PIN_NUM):CLEAR_BIT(DDRD_REG,PIN_NUM) ;
	 	 	}break;

	 	 	default:

	 	 		ERROR_STATE = ERROR;

	 	 		break;
	 	 	}
	 	 return ERROR_STATE;
	 	 	}

// DIO_WRITE_PIN(PORT_ID PORT_NAME,PIN_ID PIN_NUM,DIO_VALUE VALUE)
 CHECK_ERROR DIO_WRITE_PIN(PORT_ID PORT_NAME,PIN_ID PIN_NUM,DIO_VALUE VALUE){
	 //ALLOW_POINTER_TO_POINT_AT_1ST ADRESS_IN_ARRAY_OF_STRUCT

	 	//	CHANNEL_PTR = &ARRAY_OF_CFG [CHANNEL];
	 // Check For Errors
	 	 	CHECK_ERROR ERROR_STATE = NO_ERROR;
	 	 	if( (PIN_NUM) > PIN_7 )
	 	 	{
	 	 		ERROR_STATE = ERROR;
	 	 	}
	 	 	else { /* Do Nothing */ }
	 switch(PORT_NAME){
	 case PORT_A:{
		 VALUE == SET?SET_BIT(PINA_REG,PIN_NUM):CLEAR_BIT(PINA_REG,PIN_NUM);
	 }break;
	 case PORT_B:{
	 	 VALUE == SET?SET_BIT(PINB_REG,PIN_NUM):CLEAR_BIT(PINB_REG,PIN_NUM);
	 	 }break;
	 case PORT_C:{
	 	VALUE == SET?SET_BIT(PINC_REG,PIN_NUM):CLEAR_BIT(PINC_REG,PIN_NUM);
	 	 }break;
	 case PORT_D:{
	 	VALUE == SET?SET_BIT(PIND_REG,PIN_NUM):CLEAR_BIT(PIND_REG,PIN_NUM);
	 	 }break;
	 default:{
		 ERROR_STATE=ERROR;
	 }break;
	 }
	 	 return ERROR_STATE;
 }

// DIO_GET_PORT(PORT_ID PORT_NAME )
 uint8 DIO_GET_PORT(PORT_ID PORT_NAME ){
	 uint8 GET_PORT=0X00;
	 	 switch (PORT_NAME){

	 	 case PORT_A:{
	 		 GET_PORT=PINA_REG;
	 	 }break;
	 	case PORT_B:{
	 		 		 GET_PORT=PINB_REG;
	 		 	 }break;
	 	case PORT_C:{
	 		 		 GET_PORT=PINC_REG;
	 		 	 }break;
	 	case PORT_D:{
	 		 		 GET_PORT=PIND_REG;
	 		 	 }break;
	 	default:{


	 	}break;

	 	 }

	 	 return GET_PORT ;
}

//DIO_GET_PIN(PIN_ID PIN_NUM)
 uint8 DIO_GET_PIN(PORT_ID PORT_NAME,PIN_ID PIN_NUM){
	 //RESULT IS HOLD DATA
	 uint8 RESULT=0x00;

		 switch(PORT_NAME){
		 case PORT_A:
		        {
		        	RESULT = (PINA_REG>>PIN_NUM)&0x01;
		        }break;
		 case PORT_B:
		 		 {
		 			RESULT = (PINB_REG>>PIN_NUM)&0x01;
		 		 }break;
		 case PORT_C:
		 		 {
		 			RESULT = (PINC_REG>>PIN_NUM)&0x01;
		 		 }break;
		 case PORT_D:
		 		 {
		 			RESULT = (PIND_REG>>PIN_NUM)&0x01;
		 		 }break;
		 default:
		 {

		 }break;
 }
		 	 return RESULT;
 }

//TOGGEL_PIN(PORT_ID PORT_NUM,PIN_ID PIN_NUM)
 void TOGGEL_PIN_ID(PORT_ID PORT_NAME,PIN_ID PIN_NUM)
 {
	 switch(PORT_NAME){
	 case PORT_A:{

		 TOGGLE_BIT(PORTA_REG,PIN_NUM);
	 }break;
	 case PORT_B:{

		 TOGGLE_BIT(PORTB_REG,PIN_NUM);
		 }break;
	 case PORT_C:{

		 TOGGLE_BIT(PORTC_REG,PIN_NUM);
		 }break;
	 case PORT_D:{

		 TOGGLE_BIT(PORTA_REG,PIN_NUM);
		 }break;
	 default:
		 break;
	 }

 }

 //TOGGEL_PORT
void TOGGEL_PORT_ID(PORT_ID PORT_NAME){

	switch(PORT_NAME){
	case PORT_A:
	{
		TOGGEL_PORT(PORTA_REG);
	}break;
	case PORT_B:
		{
			TOGGEL_PORT(PORTB_REG);
		}break;
	case PORT_C:
		{
			TOGGEL_PORT(PORTC_REG);
		}break;
	case PORT_D:
		{
			TOGGEL_PORT(PORTD_REG);
		}break;
	default:{

	}break;
	}
}
