#ifndef __NVIC_H__
#define __NVIC_H__

#include <stdint.h>
#include "common.h"

typedef struct
{
	RO	volatile uint32_t ICTR;
	char RES00[0xF8];
	RW	volatile uint32_t ISER[8];
	char RES0[96];
	RW	volatile uint32_t ICER[8];
	char RES1[96];
	RW	volatile uint32_t ISPR[8];
	char RES2[96];
	RW	volatile uint32_t ICPR[8];
	char RES3[96];
	RO	volatile uint32_t IABR[8];
	char res4[96];
	RW	volatile uint32_t IPR[60];
} nvic_t;


typedef enum nvic_interrupt_id
{
	NVIC_IRQn_DMA0								 	 = 0u, /* DMA channel 0 transfer complete */
	NVIC_IRQn_DMA1								   = 1u,	/* DMA channel 1 transfer complete */
	NVIC_IRQn_DMA2								   = 2u, /* DMA channel 2 transfer complete */
	NVIC_IRQn_DMA3								   = 3u, /* DMA channel 3 transfer complete */
	NVIC_IRQn_DMA4								   = 4u, /* DMA channel 4 transfer complete */
	NVIC_IRQn_DMA5								   = 5u, /* DMA channel 5 transfer complete */
	NVIC_IRQn_DMA6								   = 6u, /* DMA channel 6 transfer complete */
	NVIC_IRQn_DMA7								   = 7u, /* DMA channel 7 transfer complete */
	NVIC_IRQn_DMA8								   = 8u, /* DMA channel 8 transfer complete */
	NVIC_IRQn_DMA9								   = 9u, /* DMA channel 9 transfer complete */
	NVIC_IRQn_DMA10								   = 10u, /* DMA channel 10 transfer complete */
	NVIC_IRQn_DMA11								   = 11u, /* DMA channel 11 transfer complete */
	NVIC_IRQn_DMA12								   = 12u, /* DMA channel 12 transfer complete */
	NVIC_IRQn_DMA13								   = 13u, /* DMA channel 13 transfer complete */
	NVIC_IRQn_DMA14								   = 14u, /* DMA channel 14 transfer complete */
	NVIC_IRQn_DMA15								   = 15u, /* DMA channel 15 transfer complete */
	NVIC_IRQn_DMA_ERROR						   = 16u, /* DMA error interrupt channels 0-15 */
	NVIC_IRQn_MCM									   = 17u, /* FPU sources */
	NVIC_IRQn_Command_Complete		   = 18u, /* FTFC Command complete */
	NVIC_IRQn_Read_collision			   = 19u, /* FTFC Read collision */
	NVIC_IRQn_PMC 								   = 20u, /* Low voltage detect interrupt */
	NVIC_IRQ_Double_Bit						   = 21u, /* FTFC Double bit */
	NVIC_IRQn_WDOG								   = 22u, /* interrupt request out before wdg reset out */
	NIVC_IRQn_EWM									   = 22u, /* EWM output as interrupt */
	NVIC_IRQn_RCM									   = 23u, /* RCM Asynchronous Interrupt */
	NVIC_IRQn_LPI2C0_Master				   = 24u, /* LPI2C Master Interrupt */
	NVIC_IRQ_LPI2C0_Slave					   = 25u, /* LPI2C Slave Interrupt */
	NVIC_IRQn_LPSPI0							   = 26u, /* LPSPI0 interrupt */
	NVIC_IRQn_LPSPI1							   = 27u, /* LPSPI1 intertupt */
	NVIC_IRQn_LPSPI2							   = 28u, /* LPSPI2 interrupt */
	NVIC_IRQn_LPI2C1_Master				   = 29u, /* LPI2C1 master interrupt */
	NVIC_IRQn_LPI2C1_Slave				   = 30u, /* LPI2C1 slave interrupt */
	NVIC_IRQn_LUART0_Transmit			   = 31u, /* LUART0 transmit interrupt */
	NVIC_IRQn_LUART0_Receive			   = 31u, /* LUART0 receive interrupt */
	NVIC_IRQn_LUART0_ERROR				   = 31u, /* LUART0 error interrupt */
	NVIC_IRQn_LUART0_Overrun			   = 31u, /* LUART0 overrun interrupt */
	NVIC_RES0											   = 32u, /* reserved */
	NVIC_IRQn_LUART1_Transmit			   = 33u, /* LUART1 transmit interrupt */
	NVIC_IRQn_LUART1_Receive			   = 33u, /* LUART1 receive interrupt */
	NVIC_IRQn_LUART1_ERROR				   = 33u, /* LUART1 error interrupt */
	NVIC_IRQn_LUART1_Overrun			   = 33u, /* LUART1 overrun interrupt */
	NVIC_RES1											   = 34u, /* reserved */
	NVIC_IRQn_LUART2_Transmit			   = 35u, /* LUAR2 transmit interrupt */
	NVIC_IRQn_LUART2_Receive			   = 35u, /* LUART2 receive interrupt */
	NVIC_IRQn_LUART2_ERROR				   = 35u, /* LUART2 error interrupt */
	NVIC_IRQn_LUART2_Overrun			   = 35u, /* LUART2 overrun interrupt */
	NVIC_RES2											   = 36u, /* reserved */
	NVIC_IRQn_ADC0								   = 39u, /* ADC interrupt request */
	NVIC_IRQn_ADC1								   = 40u, /* ADC interrupt request */
	NVIC_IRQn_CMP0								   = 41u, /* CMP0 interrupt request */
	NVIC_res3											   = 42u,
	NVIC_res4											   = 43u,
	NVIC_IRQn_ERM_single_bit			   = 44u, /* ERM single bit error correction */
	NVIC_IRQn_ERM_double_bit			   = 45u, /* ERM double bit error non-correctable */
	NVIC_IRQn_Alarm								   = 46u, /* RTC alarm interrupt */
	NVIC_IRQn_Second							   = 47u, /* RTC seconds interrupt */
	NVIC_IRQn_LPIT0_ch0						   = 48u, /* LPIT0 channel 0 overflow interrupt */
	NVIC_IRQn_LPIT0_ch1						   = 49u, /* LPIT0 channel 1 overflow interrupt */
	NVIC_IRQn_LPIT0_ch2						   = 50u, /* LPIT0 channel 2 overflow interrupt */ 
	NVIC_IRQn_LPIT0_ch3						   = 51u, /* LPIT0 channel 3 overflow interrupt */
	NVIC_IRQn_PDB0								   = 52u, /* PDB interrupt */
	NVIC_res5											   = 53u,
	NVIC_res6											   = 54u,
	NVIC_IRQn_SAI1_Transmit				   = 55u, /* Transmit Synchronous interupt (for interrupt controller) */
	NVIC_IRQn_SAI1_Receive				   = 56u, /* Receive Synchronous interupt (for interrupt controller) */
	NVIC_IRQn_SCG									   = 57u, /* SCG bus interrupt request */
	NVIC_IRQn_LPTIMER							   = 58u, /* Low power timer interrupt request */
	NVIC_IRQn_PORTA								   = 59u, /* PORTA pin detect interrupt */
	NVIC_IRQn_PORTB								   = 60u, /* PORTB pin detect interrupt */
	NVIC_IRQn_PORTC								   = 61u, /* PORTC pin detect interrupt */
	NVIC_IRQn_PORTD								   = 62u, /* PORTD pin detect interrupt */
	NVIC_IRQn_PORTE								   = 63u, /* PORTE pin detect interrupt */
	NVIC_IRQn_Software						   = 64u, /* software interrupt */
	NVIC_IRQn_QSPI								 	 = 65u, /* all interrupt ORED output */
	NVIC_IRQn_PDB1								   = 68u, /* PDB interrupt */
	NVIC_IRQn_FlexIO							 	 = 69u, /* FlexIO interrupt */
	NVIC_IRQn_SAI0_Transmit 			 	 = 70u, /* Transmit Synchronous interupt (for interrupt controller) */
	NVIC_IRQn_SAI0_Receive				   = 71u, /* Receive Synchronous interupt (for interrupt controller) */
	NVIC_IRQn_ENET_Timer					   = 72u, /* 1588 Timer Interrupt - synchronous */
	NVIC_IRQn_ENET_Even_Time				 = 72u, /* Period EventTimer Overflow */
	NVIC_IRQn_ENET_Time_Stamp			   = 72u, /* Time stamp available */
	NVIC_IRQn_ENET_Transfer				   = 73u, /* Data transfer done */
	NVIC_IRQn_ENET_Buffer					   = 73u, /* Transmit Buffer Done for Ring/Queue 0 */
	NVIC_IRQn_ENET_Frame					   = 73u, /* Transmit Frame Done for Ring/Queue 0 */
	NVIC_IRQn_ENET_Receive_Buffer		 = 74u, /* Receive Buffer Done for Ring/Queue 0 */
	NVIC_IRQn_ENET_Receive_Frame		 = 74u, /* Receive Frame Done for Ring/Queue 0 */
	NVIC_IRQn_ENET_Payload				   = 75u, /* Payload receive error */
	NVIC_IRQn_ENET_Collision			   = 75u, /* Collision retry limit reached */
	NVIC_IRQn_ENET_late_Collision	   = 75u, /* Late collision detected. */
	NVIC_IRQn_ENET_AXIbus					   = 75u, /* AXI Bus Error detected */
	NVIC_IRQn_ENET_Babling_Transmit  = 75u, /* Babbling transmit error */
	NVIC_IRQn_ENET_Babling_Receive   = 75u, /* Babbling receive error */
	NVIC_IRQn_ENET_FIFO						   = 75u, /* Transmit FIFO underrun */
	NVIC_IRQn_ENET_Graceful				   = 76u, /* Graceful stop */
	NVIC_IRQn_ENET_Wake_2_Sleep		   = 77u, /* Wake from sleep */
	NVIC_IRQn_CAN0_ORED						   = 78u, /* OR’ed [Bus Off OR Bus Off Done OR Transmit Warning OR Receive Warning] */
	NVIC_IRQn_CAN0_Transmit_Error		 = 78u, /* Interrupt indicating Transmit Error Counter transition from < 96 to >= 96 */
	NVIC_IRQn_CAN0_Receive_Error		 = 78u, /*Interrupt indicating Receive Error Counter transition from < 96 to >= 96 */
	NVIC_IRQn_CAN0_Bus_Error				 = 79u, /* Interrupt indicating that errors were detected on the CAN bus */
	NVIC_IRQn_CAN0_Fast_Bit_Error		 = 79u, /* Interrupt indicating that errors were detected on the CAN bus for FD messages in the Fast Bit Rate region */
	NVIC_IRQn_CAN0_Wake_up					 = 80u, /* Interrupt asserted when Pretended Networking operation is enabled, and a valid message matches the selected filter criteria during Low Power mode */
	NVIC_IRQn_CAN0_ORED_0_15				 = 81u, /* OR'ed Message buffer (0-15) */
	NVIC_IRQn_CAN0_ORED_16_31				 = 82u, /* OR'ed Message buffer (16-31) */
	NVIC_IRQn_CAN0_ORED_32_47				 = 83u, /* OR'ed Message buffer (32-47) */
	NVIC_IRQn_CAN0_ORED_48_63				 = 84u, /* OR'ed Message buffer (48-63) */
	NVIC_IRQn_CAN1_ORED_Transmit		 = 85u, /* OR’ed [Bus Off OR Bus Off Done OR Transmit Warning OR Receive Warning] */
	NVIC_IRQn_CAN1_Transmit_Error		 = 85u, /* Interrupt indicating Transmit Error Counter transition from < 96 to >= 96 */
	NVIC_IQRn_CAN1_Receive_Error		 = 85u, /* Interrupt indicating Receive Error Counter transition from < 96 to >= 96 */
	NVIC_IRQn_CAN1_Error						 = 86u, /* Interrupt indicating that errors were detected on the CAN bus for FD messages in the Fast Bit Rate region */
	NVIC_IRQn_CAN1_ORED_0_15				 = 88u, /* OR'ed Interrupt for Message buffer (0-15) */
	NVIC_IRQn_CAN1_ORED_16_31				 = 89u, /* OR'ed Interrupt for Message buffer (16-31) */
	NVIC_IRQn_CAN1_ORED_32_47				 = 90u, /* OR'ed Message buffer (32-47) */
	NVIC_IRQn_CAN1_ORED_48_63				 = 91u, /* OR'ed Message buffer (48-63) */
	NVIC_IRQn_CAN2_ORED							 = 92u, /* OR’ed [Bus Off OR Bus Off Done OR Transmit Warning OR Receive Warning] */
	NVIC_IRQn_CAN2_Transmit_Error		 = 92u, /* Interrupt indicating Transmit Error Counter transition from < 96 to >= 96 */
	NVIC_IRQn_CAN2_Receive_Error		 = 92u, /* Interrupt indicating Receive Error Counter transition from < 96 to >= 96 */
	NVIC_IRQn_CAN2_Error						 = 93u, /* Interrupt indicating that errors were detected on the CAN bus */
	NVIC_IRQn_CAN2_ORED_0_15				 = 95u, /* OR'ed Message buffer (0-15) */
	NVIC_IRQn_CAN2_ORED_16_31				 = 96u, /* OR'ed Message buffer (16-31) */
	NVIC_IRQn_FTM0_ch0_ch1					 = 99u, /* Channel 0 and 1 interrupt */
	NVIC_IRQn_FTM0_ch2_ch3					 = 100u, /* Channel 2 and 3 interrupt */
	NVIC_IRQn_FTM0_ch4_ch5					 = 101u, /* Channel 4 and 5 interrupt */
	NVIC_IRQn_FTM0_ch6_ch7					 = 102u, /* Channel 6 and 7 interrupt */
	NVIC_IRQn_FTM0_Fault						 = 103u, /* Fault interrupt */
	NVIC_IRQn_FTM0_Ovf_Reload				 = 104u, /* Counter overflow and Reload interrupt */
	NVIC_IRQn_FTM1_ch0_ch1					 = 105u, /* Channel 0 and 1 interrupt */
	NVIC_IRQn_FTM1_ch2_ch3					 = 106u, /* Channel 2 and 3 interrupt */
	NVIC_IRQn_FTM1_ch4_ch5					 = 107u, /* Channel 4 and 5 interrupt */
	NVIC_IRQn_FTM1_ch6_ch7					 = 108u, /* Channel 6 and 7 interrupt */
	NVIC_IRQn_FTM1_Fault						 = 109u, /* Fault interrupt */
	NVIC_IRQn_FTM1_Ovf_Reload				 = 110u, /* Counter overflow and Reload interrupt */
	NVIC_IRQn_FTM2_ch0_ch1					 = 111u, /* Channel 0 and 1 interrupt */
	NVIC_IRQn_FTM2_ch2_ch3					 = 112u, /*	Channel 2 and 3 interrupt */
	NVIC_IRQn_FTM2_ch4_ch5					 = 113u, /* Channel 4 and 5 interrupt */
	NVIC_IRQn_FTM2_ch6_ch7					 = 114u, /* Channel 6 and 7 interrupt */
	NVIC_IRQn_FTM2_Fault						 = 115u, /* Fault interrupt */
	NVIC_IRQn_FTM2_Ovf_Reload				 = 116u, /* Counter overflow and Reload interrupt */
	NVIC_IRQn_FTM3_ch0_ch1					 = 117u, /* Channel 0 and 1 interrupt */
	NVIC_IRQn_FTM3_ch2_ch3					 = 118u, /*	Channel 2 and 3 interrupt */
	NVIC_IRQn_FTM3_ch4_ch5					 = 119u, /* Channel 4 and 5 interrupt */
	NVIC_IRQn_FTM3_ch6_ch7					 = 120u, /* Channel 6 and 7 interrupt */
	NVIC_IRQn_FTM3_Fault						 = 121u, /* Fault interrupt */
	NVIC_IRQn_FTM3_Ovf_Reload				 = 122u, /* Counter overflow and Reload interrupt */
	NVIC_IRQn_FTM4_ch0_ch1					 = 123u, /* Channel 0 and 1 interrupt */
	NVIC_IRQn_FTM4_ch2_ch3					 = 124u, /*	Channel 2 and 3 interrupt */
	NVIC_IRQn_FTM4_ch4_ch5					 = 125u, /* Channel 4 and 5 interrupt */
	NVIC_IRQn_FTM4_ch6_ch7					 = 126u, /* Channel 6 and 7 interrupt */
	NVIC_IRQn_FTM4_Fault						 = 127u, /* Fault interrupt */
	NVIC_IRQn_FTM4_Ovf_Reload				 = 128u, /* Counter overflow and Reload interrupt */
	NVIC_IRQn_FTM5_ch0_ch1					 = 129u, /* Channel 0 and 1 interrupt */
	NVIC_IRQn_FTM5_ch2_ch3					 = 130u, /*	Channel 2 and 3 interrupt */
	NVIC_IRQn_FTM5_ch4_ch5					 = 131u, /* Channel 4 and 5 interrupt */
	NVIC_IRQn_FTM5_ch6_ch7					 = 132u, /* Channel 6 and 7 interrupt */
	NVIC_IRQn_FTM5_Fault						 = 133u, /* Fault interrupt */
	NVIC_IRQn_FTM5_Ovf_Reload				 = 134u, /* Counter overflow and Reload interrupt */
	NVIC_IRQn_FTM6_ch0_ch1					 = 135u, /* Channel 0 and 1 interrupt */
	NVIC_IRQn_FTM6_ch2_ch3					 = 136u, /*	Channel 2 and 3 interrupt */
	NVIC_IRQn_FTM6_ch4_ch5					 = 137u, /* Channel 4 and 5 interrupt */
	NVIC_IRQn_FTM6_ch6_ch7					 = 138u, /* Channel 6 and 7 interrupt */
	NVIC_IRQn_FTM6_Fault						 = 139u, /* Fault interrupt */
	NVIC_IRQn_FTM6_Ovf_Reload				 = 140u, /* Counter overflow and Reload interrupt */
	NVIC_IRQn_FTM7_ch0_ch1					 = 141u, /* Channel 0 and 1 interrupt */
	NVIC_IRQn_FTM7_ch2_ch3					 = 142u, /*	Channel 2 and 3 interrupt */
	NVIC_IRQn_FTM7_ch4_ch5					 = 143u, /* Channel 4 and 5 interrupt */
	NVIC_IRQn_FTM7_ch6_ch7					 = 144u, /* Channel 6 and 7 interrupt */
	NVIC_IRQn_FTM7_Fault						 = 145u, /* Fault interrupt */
	NVIC_IRQn_FTM7_Ovf_Reload				 = 146u, /* Counter overflow and Reload interrupt */
	NVIC_IRQn_EEERAM_ECC_ERR				 = 152u, /* EEERAM ECC error */
	NVIC_IRQn_MGATE_ECC_ERR					 = 153u /* Mgate ECC error */	
	
}nvic_interrupt_id_t;


#define NVIC_address_base						(0xE000E004)
#define NVIC												((nvic_t *) NVIC_address_base)

/* bit mask */
#define SET_BIT(reg, offset)		((reg) |= (1 << (offset)))
#define CLEAR_BIT(reg, offset)  ((reg) &= ~(1 << (offset)))

void set_enable_nvic_timer(void);
void clear_enable_nvic(void);
void set_pending_nvic(void);
void clear_pending_nvic(void);
void set_active_nvic(void);
void set_priority_nvic(void);
void set_enable_nvic_lpuart_transmit(void);
void set_enable_nvic_lpuart_receive(void);
	

void PORTD_IRQHandler(void);
void PORTC_IRQHandler(void);
void LPIT0_Ch0_IRQHandler(void);
void LPUART1_RxTx_IRQHandler(void);
#endif //__NVIC_H__
