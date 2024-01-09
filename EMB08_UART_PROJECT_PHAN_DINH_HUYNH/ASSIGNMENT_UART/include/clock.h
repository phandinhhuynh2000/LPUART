#ifndef __CLOCK_H__
#define __CLOCK_H__

#include <stdint.h>
#include "common.h"

typedef union FIELD_SCG_CCR
{
	uint32_t REG;
	struct SCG_CCR
	{
		RW	uint32_t DIVSLOW   : 4;
		RW	uint32_t DIVBUS	   : 4;
		RO	uint32_t RES1		   : 8;
		RW	uint32_t DIVCORE   : 4;
		RO	uint32_t RES2		   : 4;
		RW	uint32_t SCS		   : 4;
		RO  uint32_t RES3		   : 4;
	}SCG_CCR_t;
}FIELD_SCG_CCR_t;

typedef struct SCG_CCR_TYPE_
{
	IO FIELD_SCG_CCR_t RCCR;
	IO FIELD_SCG_CCR_t VCCR;
	IO FIELD_SCG_CCR_t HCCR;
	
}SCG_CCR_TYPE_t;


typedef union FIELD_SCG_CLKOUTCNFG
{
	uint32_t REG;
	struct SCG_CLKOUTCNFG
	{
		RO uint32_t RES1		   : 24;
		RW uint32_t CLKOUTSEL  : 4;
		RO uint32_t RES2		   : 4;	
	}SCG_CLKOUTCNFG_t;
}FIELD_SCG_CLKOUTCNFG_t;

/* field sosc control */
typedef union FIELD_SCG_SOSCCSR
{
	uint32_t REG;
	struct SCG_SOSCCSR
	{
		RW uint32_t SOSCEN     : 1;
		RW uint32_t RES1		   : 15;
		RW uint32_t SOSCCM	   : 1;
		RW uint32_t SOSCCMRE   : 1;
		RO uint32_t RES2		   : 5;
		RW uint32_t LK			   : 1;
		RO uint32_t SOSCVLD    : 1;
		RO uint32_t SOSCSEL	   : 1;
		RW uint32_t SOSCERR    : 1;
		RO uint32_t RES3		   : 5;
	}SCG_SOSCCSR_t;
}FIELD_SCG_SOSCCSR_t;

/* field sosc devide */
typedef union FIELD_SCG_SOSCDIV
{
	
	struct SCG_SOSCDIV
	{
		RW uint32_t SOSCDIV1   : 3;
		RO uint32_t RES1		   : 5;
		RW uint32_t SOSCDIV2 	 : 3;
		RO uint32_t RES2		 	 : 21;
	}SCG_SOSCDIV_t;
}FIELD_SCG_SOSCDIV_t;

/* field sosc configure */
typedef union FIELD_SCG_SOSCCFG
{
	uint32_t REG;
	struct SCG_SOSCCFG
	{
		RO uint32_t RES1		   : 2;
		RW uint32_t ERRES		   : 1;
		RW uint32_t HIGH_GAIN  : 1;
		RW uint32_t RANGE			 : 2;
		RW uint32_t RES2			 : 26;
	}SCG_SOSCCFG_t;
}FIELD_SCG_SOSCCFG_t;

typedef struct SCG_SOSC
{
	IO FIELD_SCG_SOSCCSR_t SOSC_CSR;
	IO FIELD_SCG_SOSCDIV_t SOSC_DIV;
	IO FIELD_SCG_SOSCCFG_t SOSC_CFG;
}SCG_SOSC_t;

/* field sirc control */
typedef union FIELD_SCG_SIRCCSR
{
	uint32_t REG;
	struct SCG_SIRCCSR
	{
		RW uint32_t SIRCEN		 : 1;
		RW uint32_t SIRCSTEN	 : 1;
		RW uint32_t SIRCLPEN	 : 1;
		RO uint32_t RES1			 : 20;
		RW uint32_t LK				 : 1;
		RO uint32_t SIRCVLD		 : 1;
		RO uint32_t SIRCSEL		 : 1;
		RO uint32_t RES2			 : 6;
	}SCG_SIRCCSR_t;
}FIELD_SCG_SIRCCSR_t;

/* field sirc devide */
typedef union FIELD_SCG_SIRCDIV
{
	uint32_t REG;
	struct SCG_SIRCDIV
	{
		RW uint32_t SIRCDIV1	 : 3;
		RO uint32_t RES1			 : 5;
		RW uint32_t SIRCDIV2	 : 3;
		RO uint32_t RES2			 : 21;
	}SCG_SIRCDIV_t;
}FIELD_SCG_SIRCDIV_t;

/* field sirc configure */
typedef union FIELD_SCG_SIRCCFG
{
	uint32_t REG;
	struct SCG_SIRCCFG
	{
		RW uint32_t RANGE			 : 1;
		RO uint32_t RES1			 : 31;
	}SCG_SIRCCFG_t;
}FIELD_SCG_SIRCCFG_t;

typedef struct SCG_SIRC
{
	IO FIELD_SCG_SIRCCSR_t SIRC_CSR;
	IO FIELD_SCG_SIRCDIV_t SIRC_DIV;
	IO FIELD_SCG_SIRCCFG_t SIRC_CFG;
}SCG_SIRC_t;

/* field firc control */
typedef union FIELD_SCG_FIRCCSR
{
	uint32_t REG;
	struct SCG_FIRCCSR
	{
		RW uint32_t FIRCEN	 	 : 1;
		RW uint32_t RES1		   : 2;
		RW uint32_t FIRCREGOFF : 1;
		RW uint32_t RES2			 : 19;
		RW uint32_t LK				 : 1;
		RO uint32_t FIRCVLD		 : 1;
		RO uint32_t FIRCSEL		 : 1;
		RW uint32_t FIRCERR		 : 1;
		RO uint32_t RES3			 : 5;
	}SCG_FIRCCSR_t;
}FIELD_SCG_FIRCCSR_t;

/* field firc divide */
typedef union FIELD_SCG_FIRCDIV
{
	struct SCG_FIRCDIV
	{
		RW uint32_t FIRCDIV1	 : 3;
		RO uint32_t RES1			 : 5;
		RW uint32_t FIRCDIV2	 : 3;
		RO uint32_t RES2			 : 21;
	}SCG_FIRCDIV_t;
}FIELD_SCG_FIRCDIV_t;

/* field firc configure */
typedef union FIELD_SCG_FIRCCFG
{
	uint32_t REG;
	struct SCG_FIRCCFG
	{
		RW uint32_t RANGE			 : 1;
		RO uint32_t RES1			 : 31;
	}SCG_FIRCCFG_t;
}FIELD_SCG_FIRCCFG_t;

typedef struct SCG_FIRC
{
	IO FIELD_SCG_FIRCCSR_t FIRC_CSR;
	IO FIELD_SCG_FIRCDIV_t FIRC_DIV;
	IO FIELD_SCG_FIRCCFG_t FIRC_CFG;
}SCG_FIRC_t;
	
/* field spll control */
typedef union FIELD_SCG_SPLLCSR
{
	uint32_t REG;
	struct SCG_SPLLCSR
	{
		RW uint32_t SPLLEN	 	 : 1;
		RW uint32_t RES1		   : 15;
		RW uint32_t SPLLCM		 : 1;
		RW uint32_t SPLLCMRE	 : 1;
		RW uint32_t RES2			 : 5;
		RW uint32_t LK				 : 1;
		RO uint32_t SPLLCVLD	 : 1;
		RO uint32_t SPLLSEL 	 : 1;
		RW uint32_t SILLERR		 : 1;
		RO uint32_t RES3			 : 5;
	}SCG_SPLLCSR_t;
}FIELD_SCG_SPLLCSR_t;

/* field spll divide */
typedef union FIELD_SCG_SPLLDIV
{
	uint32_t REG;
	struct SCG_SPLLDIV
	{
		RW uint32_t SIRCDIV1		: 3;
		RO uint32_t RES1				: 5;
		RW uint32_t SIRCDIV2		: 3;
		RO uint32_t RES2				: 21;
	}SCG_SPLLDIV_t;
}FIELD_SCG_SPLLDIV_t;

/* field spll configure */
typedef union FIELD_SCG_SPLLCFG
{
	uint32_t REG;
	struct SCG_SPLLCFG
	{
		RW uint32_t SOURCE 			: 1;
		RO uint32_t RES1				: 7;
		RW uint32_t PREDIV			: 3;
		RO uint32_t RES2				: 5;
		RW uint32_t MULT				: 5;
		RO uint32_t RES3				: 11;
	}SCG_SPLLCFG_t;
}FIELD_SCG_SPLLCFG_t;

typedef struct SCG_SPLL
{
	IO FIELD_SCG_SPLLCSR_t SPLL_CSR;
	IO FIELD_SCG_SPLLDIV_t SPLL_DIV;
	IO FIELD_SCG_SPLLCFG_t SPLL_CFG;
}SCG_SPLL_t;

typedef enum scg_ccr_divslow
{
	SCG_DIVSLOW1							= 0u,
	SCG_DIVSLOW2							= 1u,
	SCG_DIVSLOW3							= 2u,
	SCG_DIVSLOW4							= 3u,
	SCG_DIVSLOW5							= 4u,
	SCG_DIVSLOW6							= 5u,
	SCG_DIVSLOW7							= 6u,
	SCG_DIVSLOW8							= 7u
}scg_ccr_divslow_t;

typedef enum scg_ccr_divbus
{
	SCG_DIVBUS1								= 0u,
	SCG_DIVBUS2								= 1u,
	SCG_DIVBUS3								= 2u,
	SCG_DIVBUS4								= 3u,
	SCG_DIVBUS5								= 4u,
	SCG_DIVBUS6								= 5u,
	SCG_DIVBUS7								= 6u,
	SCG_DIVBUS8								= 7u,
	SCG_DIVBUS9								= 8u,
	SCG_DIVBUS10							= 9u,
	SCG_DIVBUS11							= 10u,
	SCG_DIVBUS12							= 11u,
	SCG_DIVBUS13							= 12u,
	SCG_DIVBUS14							= 13u,
	SCG_DIVBUS15							= 14u,
	SCG_DIVBUS16							= 15u
}scg_ccr_divbus_t;

typedef enum scg_ccr_divcore
{
	SCG_DIVCORE1							= 0u,
	SCG_DIVCORE2							= 1u,
	SCG_DIVCORE3							= 2u,
	SCG_DIVCORE4							= 3u,
	SCG_DIVCORE5							= 4u,
	SCG_DIVCORE6							= 5u,
	SCG_DIVCORE7							= 6u,
	SCG_DIVCORE8							= 7u,
	SCG_DIVCORE9							= 8u,
	SCG_DIVCORE10							= 9u,
	SCG_DIVCORE11							= 10u,
	SCG_DIVCORE12							= 11u,
	SCG_DIVCORE13							= 12u,
	SCG_DIVCORE14							= 13u,
	SCG_DIVCORE15							= 14u,
	SCG_DIVCORE16							= 15u
}scg_ccr_divcore_t;

typedef enum scg_rccr_scs
{
	SCG_SOSC_CLK							= 1u,
	SCG_SIRC_CLK							= 2u,
	SCG_FIRC_CLK							= 3u,
	SCG_SPLL_CLK							= 6u
}scg_rccr_scs_t;

typedef enum scg_clkout_cnfg
{
	SCG_CLKOUT_SLOW_CLK				= 0u,
	SCG_CLKOUT_SOSC_CLK				= 1u,
	SCG_CLKOUT_SIRC_CLK				= 2u,
	SCG_CLKOUT_FIRC_CLK				= 3u,
	SCG_CLKOUT_SPLL_CLK				= 6u
}scg_clkout_cnfg_t;

typedef enum scg_sosc_en
{
	SCG_SOSCEN_DIS						= 0u,
	SCG_SOSCEN_ENA						= 1u
}scg_sosc_en_t;

typedef enum scg_sosc_cm
{
	SCG_SOSCCM_DIS						= 0u,
	SCG_SOSCCM_ENA						= 1u
}scg_sosc_cm_t;

typedef enum scg_sosc_cmre
{
	SCG_SOSC_CMRE_interrupt		= 0u,
	SCG_SOSC_CMRE_reset				= 1u
}scg_sosc_cmre_t;

typedef enum scg_sosc_lk
{
	SCG_LK_clear							= 0u,
	SCG_LK_set								= 1u
}scg_lk_t;

typedef enum scg_sosc_err
{
	SCG_SOSC_ERR_DIS					= 0u,
	SCG_SOSC_ERR_ENA 					= 1u
}scg_sosc_err_t;

typedef enum scg_sirc_en
{
	SCG_SIRC_EN_DIS						= 0u,
	SCG_SIRC_EN_ENA						= 1u,
}scg_sirc_en_t;

typedef enum scg_sirc_sten
{
	SCG_SIRC_STEN_DIS					= 0u,
	SCG_SIRC_STEN_ENA					= 1u
}scg_sirc_sten_t;

typedef enum scg_sirc_lpen
{
	SCG_SIRC_LPEN_DIS					= 0u,
	SCG_SIRC_LPEN_ENA					= 1u
}scg_sirc_lpen_t;

typedef enum scg_firc_en
{
	SCG_FIRC_EN_DIS						= 0u,
	SCG_FIRC_EN_ENA						= 1u
}scg_firc_en_t;

typedef enum scg_firc_regoff
{
	SCG_FIRC_REGOFF_ENA				= 0u,
	SCG_FIRC_REGOFF_DIS				= 1u,
}scg_firc_regoff_t;

typedef enum scg_firc_err
{
	SCG_FIRC_ERR_not_detected = 0u,
	SCG_FIRC_ERR_detected			= 1u
}scg_firc_err_t;

typedef enum scg_spll_en
{
	SCG_SPLL_EN_DIS						= 0u,
	SCG_SPLL_EN_ENA 					= 1u
}scg_spll_en_t;

typedef enum scg_spll_cm
{
	SCG_SPLL_CM_DIS						= 0u,
	SCG_SPLL_CM_ENA 					= 1u
}scg_spll_cm_t;

typedef enum scg_spll_cmre
{
	SCG_SPLL_SMRE_interrupt		= 0u,
	SCG_SPLL_SMRE_reset				= 1u
}scg_spll_cmre_t;

typedef enum scg_spll_err
{
	SCG_SPLL_ERR_DIS					= 0u,
	SCG_SPLL_ERR_ENA					= 1u
}scg_spll_err_t;

typedef enum 
{
	SCG_DIV0_DIS							= 0u,
	SCG_DIV1									= 1u,
	SCG_DIV2									= 2u,
	SCG_DIV4									= 3u,
	SCG_DIV8									= 4u,
	SCG_DIV16									= 5u,
	SCG_DIV32									= 6u,
	SCG_DIV64									= 7u
}scg_div;

typedef enum scg_sosc_erefs
{
	SCG_EXTERNAL_REFERENCE		= 0u,
	SCG_INTERNAL_CRYTAL				= 1u
}scg_sosc_erefs_t;

typedef enum scg_sosc_hgo
{
	SCG_LOW_GAIN							= 0u,
	SCG_HIGH_GAIN							= 1u
}scg_sosc_hgo_t;

typedef enum scg_sosc_range
{
	SCG_SOSC_LOW_RANGE				= 1u,
	SCG_SOSC_MEDIUM_RANGE			= 2u,
	SCG_SOSC_HIGH_RANGE				= 3u
}scg_sosc_range_t;

typedef enum scg_sirc_range
{
	SCG_SIRC_LOW_RANGE				= 0u,
	SCG_SIRC_HIGH_RANGE 			= 1u
}scg_sirc_range_t;

typedef enum scg_spll_source
{
	SCG_SPLL_SOSC							= 0u,
	SCG_SPLL_FIRC							= 1u
}scg_spll_source_t;

typedef enum scg_spll_prediv
{
	SCG_SPLL_PREDIV0					= 1u,
	SCG_SPLL_PREDIV1					= 2u,
	SCG_SPLL_PREDIV2					= 3u,
	SCG_SPLL_PREDIV3					= 4u,
	SCG_SPLL_PREDIV4					= 5u,
	SCG_SPLL_PREDIV5					= 6u,
	SCG_SPLL_PREDIV6					= 7u,
	SCG_SPLL_PREDIV7					= 8u
}scg_spll_prediv_t;

typedef enum scg_spll_mult
{
	SCG_SPLL_MULT0						= 16u,
	SCG_SPLL_MULT1						= 17u,
	SCG_SPLL_MULT2						= 18u,
	SCG_SPLL_MULT3						= 19u,
	SCG_SPLL_MULT4						= 20u,
	SCG_SPLL_MULT5						= 21u,
	SCG_SPLL_MULT6						= 22u,
	SCG_SPLL_MULT7						= 23u,
	SCG_SPLL_MULT8						= 24u,
	SCG_SPLL_MULT9						= 25u,
	SCG_SPLL_MULT10						= 26u,
	SCG_SPLL_MULT11						= 27u,
	SCG_SPLL_MULT12						= 28u,
	SCG_SPLL_MULT13						= 29u,
	SCG_SPLL_MULT14						= 30u,
	SCG_SPLL_MULT15						= 31u,
	SCG_SPLL_MULT16						= 32u,
	SCG_SPLL_MULT17						= 33u,
	SCG_SPLL_MULT18						= 34u,
	SCG_SPLL_MULT19						= 35u,
	SCG_SPLL_MULT20						= 36u,
	SCG_SPLL_MULT21						= 37u,
	SCG_SPLL_MULT22						= 38u,
	SCG_SPLL_MULT23						= 39u,
	SCG_SPLL_MULT24						= 40u,
	SCG_SPLL_MULT25						= 41u,
	SCG_SPLL_MULT26						= 42u,
	SCG_SPLL_MULT27						= 43u,
	SCG_SPLL_MULT28						= 44u,
	SCG_SPLL_MULT29						= 45u,
	SCG_SPLL_MULT30						= 46u,
	SCG_SPLL_MULT31						= 47u
	
}scg_spll_mult_t;

typedef struct scg_ccr
{
	scg_ccr_divslow_t DIVSLOW;
	scg_ccr_divbus_t	DIVBUS;
	scg_ccr_divcore_t	DIVCORE;
	scg_rccr_scs_t		RCCR_SCS;
}scg_ccr_t;

typedef struct scg_clkout
{
	scg_clkout_cnfg_t CLKOUTSEL;
}scg_clkout_t;


typedef struct scg_csr
{
	scg_sosc_en_t 		SOSC_EN;
	scg_sosc_cm_t 		SOSC_CM;
	scg_sosc_cmre_t 	SOSC_CMRE;
	scg_sosc_err_t		SOSC_ERR;
	
	scg_lk_t					LK;
	
	scg_sirc_en_t			SIRC_EN;
	scg_sirc_sten_t 	SIRC_STEN;
	scg_sirc_lpen_t 	SIRC_LPEN;
	
	scg_firc_en_t			FIRC_EN;
	scg_firc_regoff_t	FIRC_REGOFF;
	scg_firc_err_t		FIRC_ERR;
	
	scg_spll_en_t			SPLL_EN;
	scg_spll_cm_t			SPLL_CM;
	scg_spll_cmre_t		SPLL_CMRE;
	scg_spll_err_t		SPLL_ERR;
	
}scg_csr_t;


typedef struct scg_sosc_div
{
	scg_div 					DIV1;
	scg_div 					DIV2;
}scg_div_t;

typedef struct scg_cfg
{
	scg_sosc_erefs_t 	EREFS;
	scg_sosc_hgo_t	 	HGO;
	scg_sosc_range_t 	SOSC_RANGE;
	
	scg_sirc_range_t 	SIRC_RANGE;
	
	scg_spll_source_t SOURCE;
	scg_spll_prediv_t PREDIV;
	scg_spll_mult_t		MULT ;
}scg_cfg_t;

/* define base address */
#define  SCG_RCCR_BASE					(0x40064014)
#define	 SCG_VCCR_BASE					(0x40064018)
#define  SCG_HCCR_BASE					(0x4006401C)

#define  SCG_SOSC_BASE					(0x40064100)
#define	 SCG_SIRC_BASE					(0x40064200)
#define  SCG_FIRC_BASE					(0x40064300)
#define  SCG_SPLL_BASE					(0x40064600)

/* define scr base */
#define	SCG_RCCR							((SCG_CCR_TYPE_t *) SCG_RCCR_BASE)
#define SCG_VCCR							((SCG_CCR_TYPE_t *) SCG_VCCR_BASE)
#define SCG_HCCR							((SCG_CCR_TYPE_t *) SCG_HCCR_BASE)
#define SCG_SOSC							((SCG_SOSC_t *) SCG_SOSC_BASE)
#define SCG_SIRC							((SCG_SIRC_t *) SCG_SIRC_BASE)
#define SCG_FIRC							((SCG_FIRC_t *) SCG_FIRC_BASE)
#define SCG_SPLL							((SCG_SPLL_t *) SCG_SPLL_BASE)

/* function prototype */
void set_firc_sysclk(void);
void set_sirc_sysclk(void);
void set_sosc_sysclk(void);
void set_spll_sysclk(void);

#endif /* !__CLOCCK_H__ */
