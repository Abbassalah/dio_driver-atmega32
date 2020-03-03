/*
 * DIO.h
 *
 *  Created on:  MONDAY_03/02/2020_8:16 AM
 *      Author: ABBAS SALAH HATATA
 */

#ifndef DIO_DRIVER_ABBAS_DIO_H
#define DIO_DRIVER_ABBAS_DIO_H
/********************************************#INCLUDE_LIBERARY******************************************/
#include "STD.h"
#include "DIO_CFG.h"
/************************************TYPE_DEFINE_STRUCT_DIO*********************************************/
/*typedef struct{
	PORT_ID PORTID;
	PIN_ID  PINID;
	DIO_DIRECTION DIRIO;
	INIT_VALUE  INITI_VAL;
	PULL_UP_STATE PULL_STATE;
	}DIO_CFG;*/
/*****************************************EXTERN_DIO***************************************************/
 // DIO_CFG   ARRAY_OF_CFG [CHANNEL_NUM];
/*****************************************	proto_type_function****************************************/
//DIRECTOR_SPECIFIC_PORT		(1)

CHECK_ERROR DIO_SET_PORT_DIRECTION(PORT_ID PORT_NAME,DIO_DIRECTION DIRIO);

//DIRECTOR_SPECIFIC_PIN			(2)

CHECK_ERROR DIO_SET_PIN_DIRECTION(PORT_ID PORT_NAME,PIN_ID PIN_NUM,DIO_DIRECTION DIRIO);

//WRITE_SPECIFIC_PIN			(3)

CHECK_ERROR DIO_WRITE_PIN(PORT_ID PORT_NAME,PIN_ID PIN_NUM,DIO_VALUE VALUE);

//READ_SPECIFIC_PORT			(4)

uint8 DIO_GET_PORT(PORT_ID PORT_NAME );

//READ_SPECIFIC_PIN				(5)

uint8 DIO_GET_PIN(PORT_ID PORT_NAME,PIN_ID PIN_NUM);

//TOGGEL_SPECIFIC_NUM			(6)

void TOGGEL_PIN_ID(PORT_ID PORT_NAME,PIN_ID PIN_NUM);

//TOGGEL_SPECIFIC_PORT			(7)
void TOGGEL_PORT_ID(PORT_ID PORT_NAME);

#endif /* DIO_DRIVER_ABBAS_DIO_H */
