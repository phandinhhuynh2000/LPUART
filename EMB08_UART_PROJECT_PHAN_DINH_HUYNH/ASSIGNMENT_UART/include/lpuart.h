#ifndef  __LUART_H__
#define  __LUART_H__

#include <stdint.h>
#include "common.h"

typedef union FIELD_LPUART_CFG
{
	uint32_t reg;
	struct LPUART_CFG
	{
		uint32_t LPUART_CFG_TRGSEL 	: 2;  // trigger select
		uint32_t RES0				: 30;
	}LPUART_CFG_t;
}FIELD_LPUART_CFG_t;

typedef union FIELD_LPUART_BAUD
{
	uint32_t REG;
	struct LPUART_BAUD
	{
		uint32_t LPUART_BAUD_SBR				: 13; //baud rate modulo divisor
		uint32_t LPUART_BAUD_SBNS				: 1;	//stop bit number select
		uint32_t LPUART_BAUD_RXEDGIE		: 1;	//RX input active edge interrupt enable
		uint32_t LPUART_BAUD_LBKDIE			: 1;	//lin break detect interrupt enable
		uint32_t LPUART_BAUD_RESYNCDIS	: 1;	//resynchronization disable
		uint32_t LPUART_BAUD_BOTHEDGE		: 1;	//both edge sampling
		uint32_t LPUART_BAUD_MATCFG			: 2;	//macth configuration
		uint32_t LPUART_BAUD_RIDMAE			: 1;	//receiver idle DMA enable
		uint32_t LPUART_BAUD_RDMAE			: 1;	//receiver full DMA enable
		uint32_t LPUART_BAUD_RES0				: 1;	
		uint32_t LPUART_BAUD_TDMAE			: 1;	//transmitter DMA enable
		uint32_t LPUART_BAUD_OSR				: 5;	//oversampling ratio
		uint32_t LPUART_BAUD_M10				: 1;	//10-bit mode select
		uint32_t LPUART_BAUD_MAEN2			: 1;	//match address mode enable 1
		uint32_t LPUART_BAUD_MAEN1			: 1;		
	}LPUART_BAUD_t;
}FIELD_LPUART_BAUD_t;	

typedef union FIELD_LPUART_STAT
{
	uint32_t REG;
	struct LPUART_STAT
	{
		uint32_t RES0									: 14;		
		uint32_t LPUART_STAT_MA2F			: 1;		//match 1 flag
		uint32_t LPUART_STAT_MA1F			: 1;		//match 2 flag
		uint32_t LPUART_STAT_PF				: 1;		//parity error flag
		uint32_t LPUART_STAT_FE				: 1;		//framing error flag
		uint32_t LPUART_STAT_NF				: 1;		//noise flag
		uint32_t LPUART_STAT_OR				: 1;		//receiver overrun flag
		uint32_t LPUART_STAT_IDLE			: 1;		//idle line flag
		uint32_t LPUART_STAT_RDRF			: 1;		//receive data register full flag
		uint32_t LPUART_STAT_TC				: 1;		//transmission complete flag 
		uint32_t LPUART_STAT_TDRE			: 1;		//transmit data register empty flag
		uint32_t LPUART_STAT_RAF			: 1;		//receiver active flag
		uint32_t LPUART_STAT_LBKDE		: 1;		//lin break detection enable
		uint32_t LPUART_STAT_BRK13		: 1;		//break character generation length
		uint32_t LPUART_STAT_RWUID		: 1;		//receive wake up idle detect
		uint32_t LPUART_STAT_RXINV		: 1;		//receive data inversion
		uint32_t LPUART_STAT_MSBF			: 1;		//MSB first
		uint32_t LPUART_STAT_RXEDGIF	: 1;		//RXD pin active edge interrupt flag
		uint32_t LPUART_STAT_LBKDIF		: 1;		//lin break detect interrupt flag
	}LPUART_STAT_t;
}FIELD_LPUART_STAT_t;
	
typedef union FIELD_LPUART_CTRL
{
	uint32_t REG;
	struct LPUART_CTRL
	{
		uint32_t LPUART_CTRL_PT				: 1; //parity type
		uint32_t LPUART_CTRL_PE				: 1; //parity enable
		uint32_t LPUART_CTRL_ILT			: 1; //idle line type select
		uint32_t LPUART_CTRL_WAKE			: 1; //receiver wakeup method select
		uint32_t LPUART_CTRL_M				: 1; //9-bit or 8-bit mode select
		uint32_t LPUART_CTRL_RSRC			: 1; //receiver source select
		uint32_t LPUART_CTRL_DOZEEN		: 1; //doze enable
		uint32_t LPUART_CTRL_LOOPS		: 1; //loop mode select
		uint32_t LPUART_CTRL_IDLECFG	: 3; //idle configuration
		uint32_t LPUART_CTRL_M7				: 1; //7-bit mode select
		uint32_t RES0									: 2;
		uint32_t LPUART_CTRL_MA2IE		: 1; //match 2 interrupt enable
		uint32_t LPUART_CTRL_MA1IE		: 1; //match 1 interrupt enable
		uint32_t LPUART_CTRL_SBK			: 1; //send break
		uint32_t LPUART_CTRL_RWU			: 1; //receiver wakeup control
		uint32_t LPUART_CTRL_RE				: 1; //receiver enable
		uint32_t LPUART_CTRL_TE				: 1; //transmitter enable
		uint32_t LPUART_CTRL_ILIE			: 1; //idle line interrupt enable
		uint32_t LPUART_CTRL_RIE			: 1; //receiver interrupt enable
		uint32_t LPUART_CTRL_TCIE			: 1; //transmission complete interrupt enable
		uint32_t LPUART_CTRL_TIE			: 1; //transmit interrupt enable
		uint32_t LPUART_CTRL_PEIE			: 1; //parity error interrup enable
		uint32_t LPUART_CTRL_FEIF			: 1; //framing error interrupt enable
		uint32_t LPUART_CTRL_NEIE			: 1; //noise error interrupt enable
		uint32_t LPUART_CTRL_ORIE			: 1; //overrun interrupt enable
		uint32_t LPUART_CTRL_TXINV		: 1; //transmit data inversion
		uint32_t LPUART_CTRL_TXDIR		: 1; //TXD pin direction in single-wire mode
		uint32_t LPUART_CTRL_R9T8			: 1; //receive bit 9/ transmit bit 8
		uint32_t LPUART_CTRL_R8T9			: 1; //receive bit 8/ transmit bit 9
	}LPUART_CTRL_t;
}FIELD_LPUART_CTRL_t;

typedef union FIELD_LPUART_DATA
{
	uint32_t REG;
	struct LPUART_DATA
	{
		uint32_t LPUART_DATA_R0T0			: 1; //read receive data buffer 0 or write transmit data buffer 0
		uint32_t LPUART_DATA_R1T1			: 1;
		uint32_t LPUART_DATA_R2T2			: 1;
		uint32_t LPUART_DATA_R3T3			: 1;
		uint32_t LPUART_DATA_R4T4			: 1;
		uint32_t LPUART_DATA_R5T5			: 1;
		uint32_t LPUART_DATA_R6T6			: 1;
		uint32_t LPUART_DATA_R7T7			: 1;
		uint32_t LPUART_DATA_R8T8			: 1;
		uint32_t LPUART_DATA_R9T9			:	1;
		uint32_t RES0									: 1;
		uint32_t LPUART_DATA_IDLINE		: 1; //idle line
		uint32_t LPUART_DATA_RXEMPT		: 1; //receive buffer empty
		uint32_t LPUART_DATA_PRETSC		: 1; //frame error/ transmit special character
		uint32_t LPUART_DATA_PARITYE	: 1;
		uint32_t LPUART_DATA_NOISY		: 1;
		uint32_t LPUART_DATA_RES1			: 16;
		
	}LPUART_DATA_t;
}FIELD_LPUART_DATA_t;

/* lpuart type */
typedef struct
{
	IO RO uint32_t 						LPUART_VERID;
	IO RO uint32_t 						LPUART_PARAM;
	IO RW uint32_t 						LPUART_GLOBAL;
	IO RW FIELD_LPUART_CFG_t	LPUART_PIN_CFG;
	IO RW FIELD_LPUART_BAUD_t	LPUART_BAUD;
	IO RW FIELD_LPUART_STAT_t	LPUART_STAT;
	IO RW FIELD_LPUART_CTRL_t	LPUART_CTRL;
	IO RW FIELD_LPUART_DATA_t	LPUART_DATA;
	IO RW uint32_t						LPUART_MATCH;
	IO RW uint32_t						LPUART_MODIR;
	IO RW uint32_t						LPUART_FIFO;
	IO RW uint32_t						LPUART_WATER;
	
}LPUART_type_t;
	
/* define lpuart1 base address */
#define LPUART0_BASE						(0x4006A000)
#define LPUART1_BASE						(0x4006B000)
#define LPUART2_BASE						(0x4006C000)

/* define lpuart0 base */
#define LPUART1								((LPUART_type_t *) LPUART1_BASE)


typedef enum
{
	OVERSAMPLING_RATIO_8  = 7,
	OVERSAMPLING_RATIO_9  = 8,
	OVERSAMPLING_RATIO_10 = 9,
	OVERSAMPLING_RATIO_11 = 10,
	OVERSAMPLING_RATIO_12 = 11,
	OVERSAMPLING_RATIO_13 = 12,
	OVERSAMPLING_RATIO_14 = 13,
	OVERSAMPLING_RATIO_15 = 14,
	OVERSAMPLING_RATIO_16 = 15,
	OVERSAMPLING_RATIO_17 = 16,
	OVERSAMPLING_RATIO_18 = 17,
	OVERSAMPLING_RATIO_19 = 18,
	OVERSAMPLING_RATIO_20 = 19,
	OVERSAMPLING_RATIO_21 = 20,
	OVERSAMPLING_RATIO_22 = 21,
	OVERSAMPLING_RATIO_23 = 22,
	OVERSAMPLING_RATIO_24 = 23,
	OVERSAMPLING_RATIO_25 = 24,
	OVERSAMPLING_RATIO_26 = 25,
	OVERSAMPLING_RATIO_27 = 26,
	OVERSAMPLING_RATIO_28 = 27,
	OVERSAMPLING_RATIO_29 = 28,
	OVERSAMPLING_RATIO_30 = 29,
	OVERSAMPLING_RATIO_31 = 30,
	OVERSAMPLING_RATIO_32 = 31
	
}osr_t;

typedef struct
{
	osr_t	OVERSAMPLING_RATIO;
}ost_type_t;

#define  SBR  ((24*10E6) / (192000 * OVERSAMPLING_RATIO_11))
	
/*function prototype*/
/* initialize lpuart */
void init_lpuart(void);
/* initialize lpuart with intrerrupt*/
void intit_lpuart_interrupt(void);


/* send a character */
void transmitter_1_character(char character);
/* send a string */
void transmitter_1_string(char character[]);
/* receive data */
char receive_data(void);
/* receive string */
void receive_string(void);
#endif /* __LUART_H__*/
