#include <stdint.h>
#include "lpit.h"
#include "pcc.h"
#include "clock.h"
#include "nvic.h"

/* timer mode is 32-bits periodic counter */
void timer_32_bit(void)
{
	set_firc_sysclk();
	
	/* disable pcc cgc lpit */
	PCC->PCC_LPIT.PCC_LPIT_t.CGC = BIT_CLEAR;
	
	/* selection clock */
	PCC->PCC_LPIT.PCC_LPIT_t.PCS = CLOCK_OPTION3;
	
	/* enable pcc cgc lpit */
	PCC->PCC_LPIT.PCC_LPIT_t.CGC = BIT_SET;
	
	/* enable control lpit */
	LPIT->MCR.LPIT_MCR_t.M_CEN = BIT_SET;
	
	/* set stop timer when in debug mode */
	LPIT->MCR.LPIT_MCR_t.DBG_EN = BIT_SET;
	
	/* timer value */
	LPIT->TAVL0.LPIT_TAVLn_t.TMR_VAL = 10000000;
	
	/* select mode timer operation */
	LPIT->TCTRL0.LPIT_TCTRLn_t.MODE = A_32_bit_periodic_counter;
	
	/* enable timer channel */
	LPIT->TCTRL0.LPIT_TCTRLn_t.T_EN = BIT_SET;
}

/* timer mode is 32-bits periodic counter */
void timer_32_bit_interrupt(void)
{
	set_firc_sysclk();
	
	/* set enable nvic */
	set_enable_nvic_timer();
	
	/* disable pcc cgc lpit */
	PCC->PCC_LPIT.PCC_LPIT_t.CGC = BIT_CLEAR;
	
	/* selection clock */
	PCC->PCC_LPIT.PCC_LPIT_t.PCS = CLOCK_OPTION3;
	
	/* enable pcc cgc lpit clock gate */
	PCC->PCC_LPIT.PCC_LPIT_t.CGC = BIT_SET;
	
	/* enable control lpit */
	LPIT->MCR.LPIT_MCR_t.M_CEN = BIT_SET;
	
	/* set stop timer when in debug mode */
	LPIT->MCR.LPIT_MCR_t.DBG_EN = BIT_SET;
	
	/* enable channel timer interrupt */
	LPIT->MIER.LPIT_MIER_t.TIE0 = BIT_SET;
	
	/* set timer value start */
	LPIT->TAVL0.REG = BUS_CLK;
	
	/* disable timer */
	LPIT->TCTRL0.LPIT_TCTRLn_t.T_EN = BIT_CLEAR;
	
	/* select timer mode */
	LPIT->TCTRL0.LPIT_TCTRLn_t.MODE = A_32_bit_periodic_counter;
	
	/* enable timer */
	LPIT->TCTRL0.LPIT_TCTRLn_t.T_EN = BIT_SET;
}
	
void timer_dual_16_bit(void)
{
	set_firc_sysclk();
	
	/* disable pcc lpit clock */
	PCC->PCC_LPIT.PCC_LPIT_t.CGC = BIT_CLEAR;
	
	/* select clock option */
	PCC->PCC_LPIT.PCC_LPIT_t.PCS = CLOCK_OPTION3;
	
	/* enable pcc lpit clock */
	PCC->PCC_LPIT.PCC_LPIT_t.CGC = BIT_SET;
	
	/* enable control lpit */
	LPIT->MCR.LPIT_MCR_t.M_CEN = BIT_SET;
	
	/* set stop timer when in dubug mode */
	LPIT->MCR.LPIT_MCR_t.DBG_EN = BIT_SET;
	
	/* set timer value start */
	LPIT->TAVL0.LPIT_TAVLn_t.TMR_VAL = BUS_CLK;
	
	/* disable timer */
	LPIT->TCTRL0.LPIT_TCTRLn_t.T_EN = BIT_CLEAR;
	
	
	/* select timer mode */
	LPIT->TCTRL0.LPIT_TCTRLn_t.MODE = B_dual_16_bit_periodic_counter;
	
	/* enable timer mode */
	LPIT->TCTRL0.LPIT_TCTRLn_t.T_EN = BIT_SET;
}

void timer_dual_16_bit_interrupt(void)
{
	set_firc_sysclk();
	
	set_enable_nvic_timer();

	/* disable pcc lpit clock */
	PCC->PCC_LPIT.PCC_LPIT_t.CGC = BIT_CLEAR;
	
	/* select clock option */
	PCC->PCC_LPIT.PCC_LPIT_t.PCS = CLOCK_OPTION3;
	
	/* enable pcc lpit clock */
	PCC->PCC_LPIT.PCC_LPIT_t.CGC = BIT_SET;
	
	/* enable control lpit */
	LPIT->MCR.LPIT_MCR_t.M_CEN = BIT_SET;
	
	/* set stop timer when in dubug mode */
	LPIT->MCR.LPIT_MCR_t.DBG_EN = BIT_SET;
	
	/* enable channel timer interrupt */
	LPIT->MIER.LPIT_MIER_t.TIE0 = BIT_SET;
	
	/* set timer value start */
	LPIT->TAVL0.REG |= (60000u << 0) | (60000u << 16);
	
	/* disable timer */
	LPIT->TCTRL0.LPIT_TCTRLn_t.T_EN = BIT_CLEAR;
	
	/* select timer mode */
	LPIT->TCTRL0.LPIT_TCTRLn_t.MODE = B_dual_16_bit_periodic_counter;
	
	/* enable timer mode */
	LPIT->TCTRL0.LPIT_TCTRLn_t.T_EN = BIT_SET;
}
