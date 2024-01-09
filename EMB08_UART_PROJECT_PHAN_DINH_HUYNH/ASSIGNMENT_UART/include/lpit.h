#ifndef __LPIT_H__
#define __LPIT_H__

#include <stdint.h>
#include "common.h"

/* field control register */
typedef union
{
	uint32_t REG;
	struct
	{
		RW uint32_t M_CEN		: 1;
		RW uint32_t SW_RST	: 1;
		RW uint32_t DOZE_EN	: 1;
		RW uint32_t DBG_EN	: 1;
		uint32_t RES0				: 28;
	}LPIT_MCR_t;
}FIELD_LPIT_MCR_t;

/* field status register */
typedef union
{
	uint32_t REG;
	struct
	{
		W1C uint32_t TIF0		: 1;
		W1C uint32_t TIF1		: 1;
		W1C uint32_t TIF2		: 1;
		W1C uint32_t TIF3		: 1;
		uint32_t RES0				: 28;
	}LPIT_MSR_t;
	
}FIELD_LPIT_MSR_t;

/* field interrupt enable register */
typedef union
{
	uint32_t REG;
	struct
	{
		RW uint32_t TIE0		: 1;
		RW uint32_t TIE1		: 1;
		RW uint32_t TIE2		: 1;
		RW uint32_t TIE3		: 1;
		uint32_t RES0				: 28;
	}LPIT_MIER_t;
}FIELD_LPIT_MIER_t;

/* field set timer enable register */
typedef union
{
	uint32_t REG;
	struct
	{
		RW uint32_t SET_T_EN_0	: 1;
		RW uint32_t SET_T_EN_1	: 1;
		RW uint32_t SET_T_EN_2	: 1;
		RW uint32_t SET_T_EN_3	: 1;
		uint32_t RES0						: 28;
		
	}LPIT_SETTEN_t;
}FIELD_LPIT_SETTEN_t;

/* field clear time enable register */
typedef union
{
	uint32_t REG;
	struct
	{
		RW uint32_t CLR_T_EN_0	: 1;
		RW uint32_t CLR_T_EN_1	: 1;
		RW uint32_t CLR_T_EN_2	: 1;
		RW uint32_t CLR_T_EN_3	: 1;
		uint32_t RES0						: 28;
	}LPIT_CLRTEN_t;
}FIELD_LPIT_CLRTEN_t;

/* field timer value register */
typedef union
{
	uint32_t REG;
	struct
	{
		RW uint32_t TMR_VAL;
	}LPIT_TAVLn_t;
}FIELD_LPIT_TAVLn_t;

/* field current timer value */
typedef union
{
	uint32_t REG;
	struct
	{
		RO uint32_t TMR_CUR_VAL;
	}LPIT_CVALn_t;
}FIELD_LPIT_CVALn_t;

/* field timer control register */
typedef union
{
	uint32_t REG;
	struct
	{
		RW uint32_t T_EN		: 1;
		RW uint32_t CHAIN		: 1;
		RW uint32_t MODE		: 2;
		uint32_t RES0				: 12;
		RW uint32_t TSOT		: 1;
		RW uint32_t TSOI		: 1;
		RW uint32_t TROT		: 1;
		uint32_t RES1				: 4;
		RW uint32_t TRG_SRC	: 1;
		RW uint32_t TRG_SEL	: 4;
		uint32_t RES2 			: 4;
	}LPIT_TCTRLn_t;
}FIELD_LPIT_TCTRLn_t;

typedef struct
{
	IO uint32_t							VERID;
	IO uint32_t 						PARAM;
	IO FIELD_LPIT_MCR_t			MCR;
	IO FIELD_LPIT_MSR_t			MSR;
	IO FIELD_LPIT_MIER_t		MIER;
	IO FIELD_LPIT_SETTEN_t	SETTEN;
	IO FIELD_LPIT_CLRTEN_t	CLRTEN;
	uint32_t								RES0;
	IO FIELD_LPIT_TAVLn_t		TAVL0;
	IO FIELD_LPIT_CVALn_t		CAVL0;
	IO FIELD_LPIT_TCTRLn_t	TCTRL0;
	uint32_t 								RES1;
	IO FIELD_LPIT_TAVLn_t		TAVL1;
	IO FIELD_LPIT_CVALn_t		CAVL1;
	IO FIELD_LPIT_TCTRLn_t	TCTRL1;
	uint32_t 								RES2;
	IO FIELD_LPIT_TAVLn_t		TAVL2;
	IO FIELD_LPIT_CVALn_t		CAVL2;
	IO FIELD_LPIT_TCTRLn_t	TCTRL2;
	uint32_t 								RES3;
	IO FIELD_LPIT_TAVLn_t		TAVL3;
	IO FIELD_LPIT_CVALn_t		CAVL3;
	IO FIELD_LPIT_TCTRLn_t	TCTRL3;
	
}LPIT_Type_t;

/* define lpit address base */
#define LPIT_BASE					(0x40037000)

/* define lpit register */
#define LPIT							((LPIT_Type_t *) LPIT_BASE)


/* timer operation mode */
typedef enum
{
	A_32_bit_periodic_counter				= 0u,
	B_dual_16_bit_periodic_counter	= 1u,
	C_32_bit_trigger_accumulator		= 2u,
	D_32_bit_trigger_input_capter		= 3u
}OPERATION_MODE_t;



#define BUS_CLK	24000000

/* function prototype */
/* timer mode is 32-bits periodic counter */
void timer_32_bit(void);
/* timer mode is 32-bits periodic counter with interrupt */
void timer_32_bit_interrupt(void);
/* timer mode is dual 16-bit periodic counter */
void timer_dual_16_bit(void);
/* timer mode is dual 16-bit periodic */
void timer_dual_16_bit_interrupt(void);


#endif 
