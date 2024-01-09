#ifndef __PCC_H__
#define __PCC_H__

#include <stdint.h>
#include "common.h"

/* field lipit register */
typedef union
{
	uint32_t reg;
	struct
	{
		RO uint32_t RES0   : 24;
		RW uint32_t PCS    : 3;
		RO uint32_t RES1   : 3;
		RW uint32_t CGC    : 1;
		RO uint32_t PR  	 : 1;
	}PCC_LPIT_t;
}FIELD_PCC_LPIT_t;

/* field port register */
typedef union
{
	uint32_t REG_PCC_port;
	struct
	{
		RO uint32_t RES1 : 30;
		RW uint32_t CGC	 : 1;
		RO uint32_t PR	 : 1;
	} PCC_PORT;
}FIELD_PCC_PORT_t;

/* field lpuart register */
typedef union
{
	uint32_t REG;
	struct 
	{
		RO uint32_t RES0 : 24;
		RW uint32_t PCS  : 3;
		RO uint32_t RES1 : 3;
		RW uint32_t CGC  : 1;
		RO uint32_t PR	 : 1;
	}PCC_LPUART;
}FIELD_PCC_LPUART_t;

/* type of lpuart for user define */
typedef struct
{
	IO uint32_t							PCC_FTFC;
	IO uint32_t							PCC_DMAMUX;
	uint32_t								RES0[2];
	IO uint32_t							PCC_FlexCAN0;
	IO uint32_t							PCC_FlexCAN1;
	IO uint32_t							PCC_FTM3;
	IO uint32_t							PCC_ADC1;
	uint32_t								RES1[3];
	IO uint32_t							PCC_FlexCAN2;
	IO uint32_t							PCC_LPSPI0;
	IO uint32_t							PCC_LPSPI1;
	IO uint32_t							PCC_LPSPI2;
	uint32_t								RES2[2];
	IO uint32_t							PCC_PDB1;
	IO uint32_t							PCC_CRC;
	uint32_t								RES3[3];
	IO uint32_t							PCC_PDB0;
	IO FIELD_PCC_LPIT_t			PCC_LPIT;
	IO uint32_t							PCC_FTM0;
	IO uint32_t							PCC_FTM1;
	IO uint32_t							PCC_FTM2;
	IO uint32_t							PCC_ADC0;
	uint32_t								RES4;
	IO uint32_t							PCC_RTC;
	uint32_t								RES5[2];
	IO uint32_t							PCC_LPTMR0;
	uint32_t								RES6[8];
	IO FIELD_PCC_PORT_t			PCC_PORTA;
	IO FIELD_PCC_PORT_t			PCC_PORTB;
	IO FIELD_PCC_PORT_t			PCC_PORTC;
	IO FIELD_PCC_PORT_t			PCC_PORTD;
	IO FIELD_PCC_PORT_t			PCC_PORTE;
	uint32_t								RES7[6];
	IO uint32_t							PCC_SAI0;
	IO uint32_t							PCC_SAI1;
	uint32_t								RES8[4];
	IO uint32_t							PCC_FlexIO;
	uint32_t								RES9[6];
	IO uint32_t							PCC_EWM;
	uint32_t								RES10[4];
	IO uint32_t							PCC_LPI2C0;
	IO uint32_t							PCC_LPI2C1;
	uint32_t								RES11[2];
	IO FIELD_PCC_LPUART_t		PCC_LPUART0;
	IO FIELD_PCC_LPUART_t 	PCC_LPUART1;
	IO FIELD_PCC_LPUART_t 	PCC_LPUART2;
	uint32_t								RES12;
	IO uint32_t							PCC_FTM4;
	IO uint32_t							PCC_FTM5;
	IO uint32_t							PCC_FTM6;
	IO uint32_t							PCC_FTM7;
}PCC_Type_t;

/* define pcc base address  */
#define PCC_BASE								(0x40065080)

/* define pcc resgister */
#define PCC						((PCC_Type_t *) PCC_BASE)

/* peripheral clock source select */
typedef enum
{
	CLOCK_OFF			= 0U,
	CLOCK_OPTION1	= 1U,
	CLOCK_OPTION2	= 2U,
	CLOCK_OPTION3 = 3U,
	CLOCK_OPTION4	= 4U,
	CLOCK_OPTION5	= 5U,
	CLOCK_OPTION6	= 6U,
	CLOCK_OPTION7	= 7U
}CLOCK_SELECTION_t;

#endif
