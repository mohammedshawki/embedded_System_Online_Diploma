/*
 * Platform_Types.h
 *
 *  Created on: Sep 22, 2023
 *      Author: smartypc
 */

#ifndef PLATFORM_TYPES_H_
#define PLATFORM_TYPES_H_

#ifndef _bool
#define _bool unsigned char
#endif

#ifndef FALSE
#define FALSE				(boolean)false
#endif

#ifndef TRUE
#define TRUE				(boolean)true
#endif

#define CPU_TYPE 			CPU_TYPE_32
#define CPU_BIT_ORDER		MSB_FIRST
#define CPU_BYTE_ORDER 	    HIGH_BYTE_FIRST

typedef _Bool               boolean;
typedef signed char         sint8_t;
typedef unsigned char       uint8_t;
typedef char                char_t;
typedef signed short        sint16_t;
typedef unsigned short      uint16_t;
typedef signed int          sint32_t;
typedef unsigned int        uint32_t;
typedef signed long long    sint64_t;
typedef unsigned long long  uint64_t;
typedef float               float32_t;
typedef double              float64_t;

typedef volatile signed char         vsint8_t;
typedef volatile unsigned char       vuint8_t;
typedef volatile char                vchar_t;
typedef volatile signed short        vint16_t;
typedef volatile unsigned short      vuint16_t;
typedef volatile signed int          vint32_t;
typedef volatile unsigned int        vuint32_t;
typedef volatile signed long long    vint64_t;
typedef volatile unsigned long long  vuint64_t;
#endif /* PLATFORM_TYPES_H_ */
