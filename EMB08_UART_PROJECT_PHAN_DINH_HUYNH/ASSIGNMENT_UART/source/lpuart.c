#include <stdint.h>
#include "lpuart.h"
#include <string.h>
#include "pcc.h"
#include "nvic.h"
#include "clock.h"
#include "port.h"

void init_lpuart(void)
{
	set_firc_sysclk();
	
	/* enable pcc portC clock gate */
	PCC->PCC_PORTC.PCC_PORT.CGC = BIT_SET;
	
	/* set mux alternative 2 (chip specific) for port C pcr */
	PORT_C->PORT_PCR6.PORT_PIN_t.MUX = ALTERNATIVE2;
	PORT_C->PORT_PCR7.PORT_PIN_t.MUX = ALTERNATIVE2;
	
	/* disable pcc lpuart clock */
	PCC->PCC_LPUART1.PCC_LPUART.CGC = BIT_CLEAR;
	
	/* set selection clock */
	PCC->PCC_LPUART1.PCC_LPUART.PCS = CLOCK_OPTION3;
	
	/* enable pcc lpuart clock gate */
	PCC->PCC_LPUART1.PCC_LPUART.CGC = BIT_SET;
	
	/* set modulo devide rate */
	LPUART1->LPUART_BAUD.LPUART_BAUD_t.LPUART_BAUD_SBR = (uint32_t) SBR;
	
	/* choose oversampling ratio */
	LPUART1->LPUART_BAUD.LPUART_BAUD_t.LPUART_BAUD_OSR = OVERSAMPLING_RATIO_11;
	
	/* stop bit number */
	LPUART1->LPUART_BAUD.LPUART_BAUD_t.LPUART_BAUD_SBNS = BIT_CLEAR;
	
	/* select transmitter data character */
	LPUART1->LPUART_CTRL.LPUART_CTRL_t.LPUART_CTRL_M = BIT_CLEAR;
	
	/* enable transmitter and reciver */
	LPUART1->LPUART_CTRL.LPUART_CTRL_t.LPUART_CTRL_TE = BIT_SET;
	LPUART1->LPUART_CTRL.LPUART_CTRL_t.LPUART_CTRL_RE = BIT_SET;
			
}

void intit_lpuart_interrupt(void)
{
	set_enable_nvic_lpuart_transmit();
	
	/* enable pcc portC clock gate */
	PCC->PCC_PORTC.PCC_PORT.CGC = BIT_SET;
	
	/* set mux alternative 2 (chip specific) for port C pcr */
	PORT_C->PORT_PCR6.PORT_PIN_t.MUX = ALTERNATIVE2;
	PORT_C->PORT_PCR7.PORT_PIN_t.MUX = ALTERNATIVE2;
	
	/* disable pcc lpuart clock */
	PCC->PCC_LPUART1.PCC_LPUART.CGC = BIT_CLEAR;
	
	/* set selection clock */
	PCC->PCC_LPUART1.PCC_LPUART.PCS = CLOCK_OPTION3;
	
	/* enable pcc lpuart clock gate */
	PCC->PCC_LPUART1.PCC_LPUART.CGC = BIT_SET;
	
	/* set modulo devide rate */
	LPUART1->LPUART_BAUD.LPUART_BAUD_t.LPUART_BAUD_SBR = (uint32_t) SBR;
	
	/* choose oversampling ratio */
	LPUART1->LPUART_BAUD.LPUART_BAUD_t.LPUART_BAUD_OSR = OVERSAMPLING_RATIO_11;
	
	/* stop bit number */
	LPUART1->LPUART_BAUD.LPUART_BAUD_t.LPUART_BAUD_SBNS = BIT_CLEAR	;
	
	/* select transmitter data charactor */
	LPUART1->LPUART_CTRL.LPUART_CTRL_t.LPUART_CTRL_M = BIT_CLEAR;
	
	/* receive interrupt enable */
	LPUART1->LPUART_CTRL.LPUART_CTRL_t.LPUART_CTRL_RIE = BIT_SET;
	
	/* enable transmitter and reciver */
	LPUART1->LPUART_CTRL.LPUART_CTRL_t.LPUART_CTRL_TE = BIT_SET;
	LPUART1->LPUART_CTRL.LPUART_CTRL_t.LPUART_CTRL_RE = BIT_SET;
	
}


void transmitter_1_character( char character)
{
	/* wait for transmit buffer to be empty  */
	while(LPUART1->LPUART_STAT.LPUART_STAT_t.LPUART_STAT_TDRE == 0){}
	
	/* send data */	
	LPUART1->LPUART_DATA.LPUART_DATA_t.LPUART_DATA_R1T1 = character;
}

void transmitter_1_string(char character[])
{
	/* wait for transmit buffer to be empty  */
	while(LPUART1->LPUART_STAT.LPUART_STAT_t.LPUART_STAT_TDRE == 0){}
	
	/* send data */	
	uint32_t i = 0;
	while(character[i] != NULL )
	{
		LPUART1->LPUART_DATA.LPUART_DATA_t.LPUART_DATA_R1T1 = character[i];
		i++;
	}
}

char receive_data(void)
{
	char receive;
	/* wait for buffer is full */
	while(LPUART1->LPUART_STAT.LPUART_STAT_t.LPUART_STAT_RDRF == 1){}
	
	/* receive data */	
	receive = LPUART1->LPUART_DATA.LPUART_DATA_t.LPUART_DATA_R1T1;

	return receive;
}

