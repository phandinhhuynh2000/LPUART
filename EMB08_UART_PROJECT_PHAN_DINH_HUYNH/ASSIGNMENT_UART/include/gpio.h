#ifndef __S32K144_GPIO_H__
#define __S32K144_GPIO_H__

#include <stdint.h>
#include "common.h"

typedef union
{
	uint32_t REG_GPIO;
	struct
	{
		RW uint32_t P0 : 1;
		RW uint32_t P1  : 1;
		RW uint32_t P2  : 1;
		RW uint32_t P3  : 1;
		RW uint32_t P4  : 1;
		RW uint32_t P5  : 1;
		RW uint32_t P6  : 1;
		RW uint32_t P7  : 1;
		RW uint32_t P8  : 1;
		RW uint32_t P9  : 1;
		RW uint32_t P10 : 1;
		RW uint32_t P11 : 1;
		RW uint32_t P12 : 1;
		RW uint32_t P13 : 1;
		RW uint32_t p14 : 1;
		RW uint32_t P15 : 1;
		RW uint32_t P16 : 1;
		RW uint32_t P17 : 1;
		RW uint32_t RES :14;
	} FIELD;
} S32K144_GPIO_PIN_t;

typedef struct
{
	IO			S32K144_GPIO_PIN_t	PDOR;
	IO			S32K144_GPIO_PIN_t	PSOR;
	IO			S32K144_GPIO_PIN_t	PCOR;
	IO			S32K144_GPIO_PIN_t	PTOR;
	IO			S32K144_GPIO_PIN_t	PDIR;
	IO			S32K144_GPIO_PIN_t	PDDR;
	IO			S32K144_GPIO_PIN_t	PIDR;
} GPIO_t;

#define GPIO_A_BASE									(0x400FF000)
#define GPIO_B_BASE									(0x400FF040)
#define	GPIO_C_BASE									(0x400FF080)
#define	GPIO_D_BASE									(0x400FF0C0)
#define GPIO_E_BASE									(0x400FF100)

#define	GPIO_A											((GPIO_t *) GPIO_A_BASE)
#define GPIO_B											((GPIO_t *) GPIO_B_BASE)
#define	GPIO_C											((GPIO_t *) GPIO_C_BASE)
#define	GPIO_D											((GPIO_t *) GPIO_D_BASE)
#define GPIO_E											((GPIO_t *) GPIO_E_BASE)
		
#endif //! #ifndef __S32K144_GPIO_H_
