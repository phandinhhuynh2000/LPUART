#ifndef __PORT_H__
#define __PORT_H__

#include <stdint.h>
#include "common.h"

typedef union
{
	uint32_t REG_PORT;
	struct
	{
		RW uint32_t PS		: 1;
		RW uint32_t PE 		: 1;
		RW uint32_t RES1  : 2;
		RW uint32_t PFE 	: 1;
		RW uint32_t RES2	: 1;
		RW uint32_t DSE		: 1;
		RO uint32_t RES3	: 1;
		RW uint32_t MUX		: 3;
		RO uint32_t RES4	: 4;
		RW uint32_t LK		: 1;
		RW uint32_t IRQC	: 4;
		RO uint32_t RES5	: 4;
		RW uint32_t ISF		: 1;
		RO uint32_t RES6	: 7;
	}PORT_PIN_t;
}PORT_PCRt;

typedef union
{
	uint32_t REG_PORT_GPCLR;
	struct
	{
		uint32_t GPWD : 16;
		uint32_t GPWE : 16;
	}PORT_GPCLR_t;
}PORT_GPCLRt;
	
typedef union
{
	uint32_t REG_PORT_GPCHR;
	struct
	{
		uint32_t GPWD : 16;
		uint32_t GPWE : 16;
	}PORT_GPCHR_t;
}PORT_GPCHRt;

typedef union
{
	uint32_t REG_PORT_GICLR;
	struct
	{
		uint32_t GIWE : 16;
		uint32_t GIWD : 16;
	}PORT_GICLR_t;
}PORT_GICLRt;

typedef union
{
	uint32_t REG_PORT_GICHR;
	struct
	{
		uint32_t GIWE : 16;
		uint32_t GIWD : 16;
	}PORT_GICHR_t;
}PORT_GICHRt;

typedef union
{
	uint32_t REG_PORT_ISFR;
	struct
	{
		RW	uint32_t ISF;
	}PORT_ISFR_t;
}PORT_ISFRt;

typedef union
{
	uint32_t REG_PORT_DFER;
	struct
	{
		RW uint32_t DFE;
	}PORT_DFER_t;
}PORT_DFERt;

typedef union
{
	uint32_t REG_PORT_DFCR;
	struct
	{
		RW uint32_t CS 	: 1;
		RO uint32_t res : 31;
	}PORT_DFCR_t;
}PORT_DFCRt;

typedef union
{
	uint32_t REG_PORT_DFWR;
	struct
	{
		RW uint32_t FILT : 5;
		RO uint32_t res	 : 27;
	}PORT_DFWR_t;
}PORT_DFWRt;

typedef struct
{
	IO	PORT_PCRt PORT_PCR0;
	IO	PORT_PCRt PORT_PCR1;
	IO	PORT_PCRt PORT_PCR2;
	IO	PORT_PCRt PORT_PCR3;
	IO	PORT_PCRt PORT_PCR4;
	IO	PORT_PCRt PORT_PCR5;
	IO	PORT_PCRt PORT_PCR6;
	IO	PORT_PCRt PORT_PCR7;
	IO	PORT_PCRt PORT_PCR8;
	IO	PORT_PCRt PORT_PCR9;
	IO	PORT_PCRt PORT_PCR10;
	IO	PORT_PCRt PORT_PCR11;
	IO	PORT_PCRt PORT_PCR12;
	IO	PORT_PCRt PORT_PCR13;
	IO	PORT_PCRt PORT_PCR14;
	IO	PORT_PCRt PORT_PCR15;
	IO	PORT_PCRt PORT_PCR16;
	IO	PORT_PCRt PORT_PCR17;
	IO	PORT_PCRt PORT_PCR18;
	IO	PORT_PCRt PORT_PCR19;
	IO	PORT_PCRt PORT_PCR20;
	IO	PORT_PCRt PORT_PCR21;
	IO	PORT_PCRt PORT_PCR22;
	IO	PORT_PCRt PORT_PCR23;
	IO	PORT_PCRt PORT_PCR24;
	IO	PORT_PCRt PORT_PCR25;
	IO	PORT_PCRt PORT_PCR26;
	IO	PORT_PCRt PORT_PCR27;
	IO	PORT_PCRt PORT_PCR28;
	IO	PORT_PCRt PORT_PCR29;
	IO	PORT_PCRt PORT_PCR30;
	IO	PORT_PCRt PORT_PCR31;
	IO	PORT_GPCLRt PORT_GPCLR;
	IO	PORT_GPCHRt	PORT_GPCHR;
	IO 	char res[16];
	IO	PORT_ISFRt PORT_ISFR;
			char RES2[28];
	IO	PORT_DFERt PORT_DFER;
	IO	PORT_DFCRt PORT_DFCR;
	IO	PORT_DFWRt PORT_DFWR;
	
}PORT_t;

//defie port base address
#define PORT_A_BASE						(0x40049000)
#define PORT_B_BASE						(0x4004A000)
#define	PORT_C_BASE						(0x4004B000)
#define PORT_D_BASE						(0x4004C000)
#define	PORT_E_BASE						(0x4004D000)

#define PORT_A								((PORT_t *) PORT_A_BASE)
#define PORT_B								((PORT_t *) PORT_B_BASE)
#define PORT_C								((PORT_t *) PORT_C_BASE)
#define PORT_D								((PORT_t *) PORT_D_BASE)
#define PORT_E								((PORT_t *) PORT_E_BASE)

typedef enum
{
	ALTERNATIVE0	= 0u, /* pin disable */
	ALTERNATIVE1	= 1u, /* GPIO */
	ALTERNATIVE2	= 2u, /* chip-specific */
	ALTERNATIVE3	= 3u, /* chip-specific */
	ALTERNATIVE4	= 4u, /* chip-specific */
	ALTERNATIVE5	= 5u, /* chip-specific */
	ALTERNATIVE6	= 6u, /* chip-specific */
	ALTERNATIVE7	= 7u	/* chip-specific */
}PIN_MUX_t;


/* define mode of interrupt */
#define RISING_EDGE						(0x9u)
#define FALLING_EDGE					(0xAu)

#endif //#define __PORT_H__

