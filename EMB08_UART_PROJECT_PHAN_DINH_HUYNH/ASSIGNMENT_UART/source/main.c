#include <stdint.h>
#include "lpuart.h"
#include "clock.h"
#include "common.h"
#include "nvic.h"
#include "main.h"
#include "port.h"
#include "pcc.h"
#include "gpio.h"
#include <string.h>
#include <stdio.h>

char string_user[256];
volatile uint32_t index = 0;
volatile uint32_t process = 0;


int main(void)
{
	set_firc_sysclk();
	init_lpuart();
	
	while(1)
	{
		char string1[30];
		char string2[30];
		char res[60];
		unsigned long int sum;
		uint32_t num1;
		uint32_t num2;
		
		if(LPUART1->LPUART_DATA.LPUART_DATA_t.LPUART_DATA_IDLINE == BIT_SET)
		{
			if(process == 1)
			{
				process = 0;
				uint32_t plus_sign = 0;
				index = 0;
				uint32_t num1index = 0;
				uint32_t num2index = 0;
				
				/* duyet tung ky tu co trong chuoi */
				for(uint32_t i = 0; i < strlen(string_user); i++)
				{
					char current_string = string_user[i];
					/* kiem ky tu hien tai la so hay khong  */
					if(current_string >= '0' && current_string <= '9')
					{
						if(plus_sign == 0)
						{
							string1[num1index] = current_string;
							num1index++;
						}
						else if(plus_sign == 1)
						{
							string2[num2index] = current_string;
							num2index++;
						}
					}
					else if(current_string == '+')
					{
						if(current_string >= '0' && current_string <= '9')
						{
							plus_sign = 1;
						}
						else
						{
							/* exit loop */
							break;
						}
					}
				}
				/* convert string to number */
				sscanf(string1, "%u", &num1);
				sscanf(string2, "%u", &num2);
				sum = num1 + num2;
				/* convert number to string */
				sprintf(res, "%lu", sum);
				
				transmitter_1_string(res);
				transmitter_1_character('\n');
				
				/* reset value */
				process = 0;
				memset(string1, 0 , sizeof(string1));
				memset(string2, 0 , sizeof(string2));
				memset(string_user, 0, sizeof(string_user));
				memset(res, 0 , sizeof(res));
			}
			
			else if(process == 2)
			{
				transmitter_1_string("wrong format\n");
				/* reset value */
				process = 0;
				memset(string_user, 0 , sizeof(string_user));
			}
		}
	}
}
