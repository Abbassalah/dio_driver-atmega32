/*
 * compiler.h
 *
 * Created on:  MONDAY_03/02/2020_8:16 AM
 *      Author: ABBAS SALAH HATATA
 */

#ifndef DIO_DRIVER_ABBAS_COMPILER_H
#define DIO_DRIVER_ABBAS_COMPILER_H

/* The memory class is used for the declaration of local pointers */
#define AUTOMATIC

/* The memory class is used within type definitions, where no memory
   qualifier can be specified */
#define TYPEDEF

/* This is used to define the void pointer to zero definition */
#define NULL_PTR          ((void *)0)

/* This is used to define the abstraction of compiler keyword inline */
#define INLINE            inline

/* This is used to define the local in line function */
#define LOCAL_INLINE      static inline

/* This is used to define the abstraction of compiler keyword static */
#define STATIC            static


#endif /* DIO_DRIVER_ABBAS_COMPILER_H */
