#include <stdint.h>
#include "common.h"
#include "clock.h"
#include "lpuart.h"

void set_firc_sysclk(void)
{
	/* wait till LK is 0	*/
	//while(SCG_FIRC->FIRC_CSR.SCG_FIRCCSR_t.LK == BIT_SET){}
	SCG_FIRC->FIRC_CSR.SCG_FIRCCSR_t.LK = BIT_CLEAR;
		
	SCG_FIRC->FIRC_CSR.SCG_FIRCCSR_t.FIRCEN = BIT_CLEAR;

	/* enable peripheral firc div2 */	
	SCG_FIRC->FIRC_DIV.SCG_FIRCDIV_t.FIRCDIV2 = SCG_DIV2;
	
	/* enable firc and waiting till it is stable */
	SCG_FIRC->FIRC_CSR.SCG_FIRCCSR_t.FIRCEN = BIT_SET;
	while(SCG_FIRC->FIRC_CSR.SCG_FIRCCSR_t.FIRCVLD == BIT_CLEAR){}
	
	/* select clock source for RCCR */	
	SCG_RCCR->RCCR.SCG_CCR_t.SCS = SCG_FIRC_CLK;
		
	/* enable clock divcore from firc */
	SCG_RCCR->RCCR.SCG_CCR_t.DIVCORE = SCG_DIVCORE1;
		
	/* enable clock divbus from firc */	
	SCG_RCCR->RCCR.SCG_CCR_t.DIVBUS = SCG_DIVBUS1;
		
	while(SCG_RCCR->RCCR.REG != SCG_FIRC->FIRC_CSR.REG){}

}


void set_sirc_sysclk (void)
{
	/* wait till LK is */
	while(SCG_SIRC->SIRC_CSR.SCG_SIRCCSR_t.LK == BIT_SET){}
	
	/* check sirc is enable, if the sirc is enable, disable sirc */
	if(SCG_SIRC->SIRC_CSR.SCG_SIRCCSR_t.SIRCEN == BIT_SET)
	{
		SCG_SIRC->SIRC_CSR.SCG_SIRCCSR_t.SIRCEN = BIT_CLEAR;
	}
	else{/* do not something */}
	
	/* set frequency range for sirc */
	SCG_SIRC->SIRC_CFG.SCG_SIRCCFG_t.RANGE = BIT_SET;
	
	/* enable peripheral sirc div2 */
	SCG_SIRC->SIRC_DIV.SCG_SIRCDIV_t.SIRCDIV2 = SCG_DIV2;
	
	/* enable sirc and waiting till it is stable */
	SCG_SIRC->SIRC_CSR.SCG_SIRCCSR_t.SIRCEN = BIT_SET;
	while(SCG_SIRC->SIRC_CSR.SCG_SIRCCSR_t.SIRCVLD == BIT_SET){}
		
	/* select clock source from sirc */
	SCG_RCCR->RCCR.SCG_CCR_t.SCS = SCG_SIRC_CLK;
		
	/* enable clock divcore */		
	SCG_RCCR->RCCR.SCG_CCR_t.DIVCORE = SCG_DIVCORE1;
		
	/* enable clock divbus */
	SCG_RCCR->RCCR.SCG_CCR_t.DIVBUS = SCG_DIVBUS2;	
		
	while(SCG_RCCR->RCCR.REG != SCG_SIRC->SIRC_CSR.REG){}	
}

void set_sosc_sysclk(void)
{
	/* wait till lk is 0 */
	while(SCG_SOSC->SOSC_CSR.SCG_SOSCCSR_t.LK == BIT_SET){}
	
	/* check sirc is enable and disable */
	if(SCG_SOSC->SOSC_CSR.SCG_SOSCCSR_t.SOSCEN == BIT_SET)
	{
		SCG_SOSC->SOSC_CSR.SCG_SOSCCSR_t.SOSCEN = BIT_CLEAR;
	}
	else{/* DO NOT SOMETHING */}
	
	/* SET EREFS FOR SOSC */
	SCG_SOSC->SOSC_CFG.SCG_SOSCCFG_t.ERRES = SCG_INTERNAL_CRYTAL;
	
	/* SET HIGH GAIN FOR SOSC */
	SCG_SOSC->SOSC_CFG.SCG_SOSCCFG_t.HIGH_GAIN = SCG_HIGH_GAIN;
	
	/* SET RANGE FOR THE SOSC */
	SCG_SOSC->SOSC_CFG.SCG_SOSCCFG_t.RANGE = SCG_SOSC_MEDIUM_RANGE;
	
	/* enable peripheral sosc div2 */
	SCG_SOSC->SOSC_DIV.SCG_SOSCDIV_t.SOSCDIV2 = SCG_DIV2;
	
	/* enable sosc and waiting it is till stable */
	SCG_SOSC->SOSC_CSR.SCG_SOSCCSR_t.SOSCEN = BIT_SET;
	while(SCG_SOSC->SOSC_CSR.SCG_SOSCCSR_t.SOSCVLD == BIT_SET){}
		
	/* enable clock source from sosc */	
	SCG_RCCR->RCCR.SCG_CCR_t.SCS = SCG_SOSC_CLK;
		
	/* enable clock divcore */	
	SCG_RCCR->RCCR.SCG_CCR_t.DIVCORE = SCG_DIVCORE1;
		
	/* enable clock divbus */	
	SCG_RCCR->RCCR.SCG_CCR_t.DIVBUS = SCG_DIVBUS2;
		
	while(SCG_RCCR->RCCR.REG != SCG_SOSC->SOSC_CSR.REG){}
		
}

void set_spll_sysclk(void)
{
	/* wait till lk is 0 */
	while(SCG_SPLL->SPLL_CSR.SCG_SPLLCSR_t.LK == BIT_SET){}
		
	/* check spll is enable and disable its*/
	if(SCG_SPLL->SPLL_CSR.SCG_SPLLCSR_t.SPLLEN == BIT_SET)
	{
		SCG_SPLL->SPLL_CSR.SCG_SPLLCSR_t.SPLLEN = BIT_CLEAR;
	}
	else{/* do not something */}
	
	SCG_SPLL->SPLL_CFG.SCG_SPLLCFG_t.SOURCE = BIT_SET;
	
	/* set prediv for SPLL */
	SCG_SPLL->SPLL_CFG.SCG_SPLLCFG_t.PREDIV = SCG_SPLL_PREDIV1;
	
	/* set multiply for SPLL */
	SCG_SPLL->SPLL_CFG.SCG_SPLLCFG_t.MULT = SCG_SPLL_MULT1;
	
	/* enable divcore */	
	SCG_RCCR->RCCR.SCG_CCR_t.DIVCORE = SCG_DIVCORE1;
	
	/* enable clock divbus */
	SCG_RCCR->RCCR.SCG_CCR_t.DIVBUS = SCG_DIVBUS2;
	
	/* enable SPLL and waiting it is till stable */
	SCG_SPLL->SPLL_CSR.SCG_SPLLCSR_t.SPLLEN = BIT_SET;
	while(SCG_SPLL->SPLL_CSR.SCG_SPLLCSR_t.SPLLCVLD == BIT_SET){}
		
	/* enable clock source rccr */
	SCG_RCCR->RCCR.SCG_CCR_t.SCS = SCG_SPLL_CLK;
		
	
}



