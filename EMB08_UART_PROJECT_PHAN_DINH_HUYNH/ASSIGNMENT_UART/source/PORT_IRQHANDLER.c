#include <stdint.h>
#include "port.h"
#include "gpio.h"
#include "common.h"
#include "nvic.h"
#include "lpit.h"
#include "lpuart.h"
#include "main.h"

volatile static uint32_t char_wrong = 0;

void LPUART1_RxTx_IRQHandler(void)
{
	/* check interrupt of received */
	if(LPUART1->LPUART_STAT.LPUART_STAT_t.LPUART_STAT_RDRF == BIT_SET)
	{
		char received = (char) LPUART1->LPUART_DATA.REG;
		/* check '0' -> '9', '+' '=' */
		if(!((received >= '0' && received <= '9') || received == '+' || received == '='))
		{
			char_wrong++;
		}			
		string_user[index] = received;
		if(string_user[index] == '=')
		{
			if(char_wrong == 0)
			{
				process = 1;
			}
			else if(char_wrong != 0)
			{
				process = 2;
			}
		}
		index++;
	}
}

