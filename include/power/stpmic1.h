/* SPDX-License-Identifier: GPL-2.0+ OR BSD-3-Clause */
/*
 * Copyright (C) 2018, STMicroelectronics - All Rights Reserved
 */

#ifndef __PMIC_STPMIC1_H_
#define __PMIC_STPMIC1_H_

#define STPMIC1_MAIN_CR			0x10
#define STPMIC1_BUCKS_MRST_CR		0x18
#define STPMIC1_LDOS_MRST_CR		0x1a
#define STPMIC1_BUCKX_MAIN_CR(buck)	(0x20 + (buck))
#define STPMIC1_REFDDR_MAIN_CR		0x24
#define STPMIC1_LDOX_MAIN_CR(ldo)	(0x25 + (ldo))
#define STPMIC1_BST_SW_CR		0x40
#define STPMIC1_NVM_SR			0xb8
#define STPMIC1_NVM_CR			0xb9

/* Main PMIC Control Register (MAIN_CR) */
#define STPMIC1_SWOFF			BIT(0)
#define STPMIC1_RREQ_EN			BIT(1)

/* BUCKS_MRST_CR */
#define STPMIC1_MRST_BUCK(buck)		BIT(buck)
#define STPMIC1_MRST_BUCK_ALL		GENMASK(3, 0)

/* LDOS_MRST_CR */
#define STPMIC1_MRST_LDO(ldo)		BIT(ldo)
#define STPMIC1_MRST_LDO_ALL		GENMASK(6, 0)

/* BUCKx_MAIN_CR (x=1...4) */
#define STPMIC1_BUCK_ENA		BIT(0)
#define STPMIC1_BUCK_PREG_MODE		BIT(1)
#define STPMIC1_BUCK_VOUT_MASK		GENMASK(7, 2)
#define STPMIC1_BUCK_VOUT_SHIFT		2
#define STPMIC1_BUCK_VOUT(sel)		(sel << STPMIC1_BUCK_VOUT_SHIFT)

#define STPMIC1_BUCK2_1200000V		STPMIC1_BUCK_VOUT(24)
#define STPMIC1_BUCK2_1350000V		STPMIC1_BUCK_VOUT(30)

#define STPMIC1_BUCK3_1800000V		STPMIC1_BUCK_VOUT(39)

/* REFDDR_MAIN_CR */
#define STPMIC1_VREF_ENA		BIT(0)

/* LDOX_MAIN_CR */
#define STPMIC1_LDO_ENA			BIT(0)
#define STPMIC1_LDO12356_VOUT_MASK	GENMASK(6, 2)
#define STPMIC1_LDO12356_VOUT_SHIFT	2
#define STPMIC1_LDO_VOUT(sel)		(sel << STPMIC1_LDO12356_VOUT_SHIFT)

#define STPMIC1_LDO3_MODE		BIT(7)
#define STPMIC1_LDO3_DDR_SEL		31
#define STPMIC1_LDO3_1800000		STPMIC1_LDO_VOUT(9)

#define STPMIC1_LDO4_UV			3300000

/* BST_SW_CR */
#define STPMIC1_BST_ON			BIT(0)
#define STPMIC1_VBUSOTG_ON		BIT(1)
#define STPMIC1_SWOUT_ON		BIT(2)
#define STPMIC1_PWR_SW_ON		(STPMIC1_VBUSOTG_ON | STPMIC1_SWOUT_ON)

/* NVM_SR */
#define STPMIC1_NVM_BUSY		BIT(0)

/* NVM_CR */
#define STPMIC1_NVM_CMD_PROGRAM		1
#define STPMIC1_NVM_CMD_READ		2

/* Timeout */
#define STPMIC1_DEFAULT_START_UP_DELAY_MS	1
#define STPMIC1_DEFAULT_STOP_DELAY_MS		5
#define STPMIC1_USB_BOOST_START_UP_DELAY_MS	10

enum {
	STPMIC1_BUCK1,
	STPMIC1_BUCK2,
	STPMIC1_BUCK3,
	STPMIC1_BUCK4,
	STPMIC1_MAX_BUCK,
};

enum {
	STPMIC1_PREG_MODE_HP,
	STPMIC1_PREG_MODE_LP,
};

enum {
	STPMIC1_LDO1,
	STPMIC1_LDO2,
	STPMIC1_LDO3,
	STPMIC1_LDO4,
	STPMIC1_LDO5,
	STPMIC1_LDO6,
	STPMIC1_MAX_LDO,
};

enum {
	STPMIC1_LDO_MODE_NORMAL,
	STPMIC1_LDO_MODE_BYPASS,
	STPMIC1_LDO_MODE_SINK_SOURCE,
};

enum {
	STPMIC1_PWR_SW1,
	STPMIC1_PWR_SW2,
	STPMIC1_MAX_PWR_SW,
};

int stpmic1_shadow_read_byte(u8 addr, u8 *buf);
int stpmic1_shadow_write_byte(u8 addr, u8 *buf);
int stpmic1_nvm_read_byte(u8 addr, u8 *buf);
int stpmic1_nvm_write_byte(u8 addr, u8 *buf);
int stpmic1_nvm_read_all(u8 *buf, int buf_len);
int stpmic1_nvm_write_all(u8 *buf, int buf_len);
#endif
