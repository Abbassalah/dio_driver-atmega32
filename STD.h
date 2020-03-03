/*
 * STD.h
 *
 *  Created on: MONDAY_03/02/2020_8:16 AM
 *      Author: ABBAS SALAH HATATA
 */
/**********************************************#DEFINE_STD_H*********************************/
#ifndef DIO_DRIVER_ABBAS_STD_H
#define DIO_DRIVER_ABBAS_STD_H
/***********************************************#INCLUDE_LIBERARY****************************/
#include "DIO_REGS.h"

/**********************************************SET_BIT_MACROS********************************/
#define SET_BIT(REG,BIT_NUM)       (REG|=(0X01<<BIT_NUM))

/**********************************************CLEAR_BIT_MACROS******************************/
#define CLEAR_BIT(REG,BIT_NUM)     (REG&=~(0X01<<BIT_NUM))

/**********************************************TOGGLE_BIT_MACROS*****************************/
#define TOGGLE_BIT(REG,BIT_NUM)	   (REG^=(0X01<<BIT_NUM))

/**********************************************GET_BIT_MACROS********************************/
#define GET_BIT (REG,BIT_NUM)		((REG>>BIT_NUM)&0X01)

#define GET_BIT_1 (REG,BIT_NUM) 	(!!((REG) & (0X01<<(BIT_NUM))))
/**********************************************SET_PORT_MACROS*******************************/
#define SET_PORT (REG)				(REG|=0XFF)

/**********************************************CLEAR_PORT_MACROS*****************************/
#define CLEAR_PORT(REG)             (REG&=0X00)

/***************************************TOGGLE_PORT_MACROS**********************************/
#define TOGGEL_PORT(REG)			(REG^=0XFF)

/****************************typedef_PORT_ID************************************************/

typedef enum {PORT_A,PORT_B,PORT_C,PORT_D}PORT_ID;
/****************************typedef_PIN_ID**********************************************/

typedef enum {PIN_0,PIN_1,PIN_2,PIN_3,PIN_4,PIN_5,PIN_6,PIN_7}PIN_ID;
/****************************typedef_DDR_ID**********************************************/

typedef enum {INPUT,OUTPUT}DIO_DIRECTION;
/****************************TYPEDEF_INIT_VALUE******************************************/

typedef enum {STD_LOW,STD_HIGH,NOT_CHANGE}INIT_VALUE;
/****************************TYPEDEF_PULLUP**********************************************/

typedef enum {DISPULL_UP,PULL_UP,DONT_CARE}PULL_UP_STATE;
/****************************TYPEDEF_CHANNEL_PIN******************************************/

typedef enum {LED0,LED1,LED2,SWITCH0,SWITCH1}CHANNEL_ID;
/****************************TYPEDEF_VALUE_PIN*******************************************/

typedef enum{RESET,SET}DIO_VALUE;
/****************************TYPEDEF_CHECK_ERROR******************************************/

typedef enum{NO_ERROR,ERROR}CHECK_ERROR;

/*********************************DELAY_FUNCTION******************************************/
#define clock   8000000
// 1MHz clock means 1000000 cycles per second.
// So 1 cycle equals 1/1000000 seconds or 1us.
// To get 1 second delay, you need 1000000 cycles of 1us,
// so it means that you have to DELAY_FUN(1000) which mean number of cycles (1000000/1000)*1000 =1000000 cycles = 1 sec
// the "NOP" takes 1 Cycle only
#define error_ratio 30
 uint32  Delay_Count;

#define DELAY_FUN(ARG) \
		for( Delay_Count = ((clock/1000)*ARG/error_ratio); Delay_Count >0; Delay_Count--)\
			{\
				__asm("NOP");\
			}
 /******************************CONC_HELPER*************************************************/

#endif /* DIO_DRIVER_ABBAS_STD_H */
