#ifndef _I8042_X86IA64IO_H
#define _I8042_X86IA64IO_H

/*
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License version 2 as published by
 * the Free Software Foundation.
 */

#ifdef CONFIG_X86
#include <asm/x86_init.h>
#endif


#define I8042_KBD_PHYS_DESC "isa0060/serio0"
#define I8042_AUX_PHYS_DESC "isa0060/serio1"
#define I8042_MUX_PHYS_DESC "isa0060/serio%d"


#if defined(__ia64__)
# define I8042_MAP_IRQ(x)	isa_irq_to_vector((x))
#else
# define I8042_MAP_IRQ(x)	(x)
#endif

#define I8042_KBD_IRQ	i8042_kbd_irq
#define I8042_AUX_IRQ	i8042_aux_irq

static int i8042_kbd_irq;
static int i8042_aux_irq;


#define I8042_COMMAND_REG	i8042_command_reg
#define I8042_STATUS_REG	i8042_command_reg
#define I8042_DATA_REG		i8042_data_reg

static int i8042_command_reg = 0x64;
static int i8042_data_reg = 0x60;


static inline int i8042_read_data(void)
{
	return inb(I8042_DATA_REG);
}

static inline int i8042_read_status(void)
{
	return inb(I8042_STATUS_REG);
}

static inline void i8042_write_data(int val)
{
	outb(val, I8042_DATA_REG);
}

static inline void i8042_write_command(int val)
{
	outb(val, I8042_COMMAND_REG);
}

#ifdef CONFIG_X86

#include <linux/dmi.h>

static const struct dmi_system_id __initconst i8042_dmi_noloop_table[] = {
	{
		.matches = {
			DMI_MATCH(DMI_BOARD_VENDOR, "RIOWORKS"),
			DMI_MATCH(DMI_BOARD_NAME, "HDAMB"),
			DMI_MATCH(DMI_BOARD_VERSION, "Rev E"),
		},
	},
	{
		
		.matches = {
			DMI_MATCH(DMI_BOARD_VENDOR, "ASUSTeK Computer Inc."),
			DMI_MATCH(DMI_BOARD_NAME, "G1S"),
			DMI_MATCH(DMI_BOARD_VERSION, "1.0"),
		},
	},
	{
		
		.matches = {
			DMI_MATCH(DMI_BOARD_VENDOR, "ASUSTeK Computer INC."),
			DMI_MATCH(DMI_BOARD_NAME, "P/I-P65UP5"),
			DMI_MATCH(DMI_BOARD_VERSION, "REV 2.X"),
		},
	},
	{
		.matches = {
			DMI_MATCH(DMI_SYS_VENDOR, "Compaq"),
			DMI_MATCH(DMI_PRODUCT_NAME , "ProLiant"),
			DMI_MATCH(DMI_PRODUCT_VERSION, "8500"),
		},
	},
	{
		.matches = {
			DMI_MATCH(DMI_SYS_VENDOR, "Compaq"),
			DMI_MATCH(DMI_PRODUCT_NAME , "ProLiant"),
			DMI_MATCH(DMI_PRODUCT_VERSION, "DL760"),
		},
	},
	{
		
		.matches = {
			DMI_MATCH(DMI_SYS_VENDOR, "OQO"),
			DMI_MATCH(DMI_PRODUCT_NAME, "ZEPTO"),
			DMI_MATCH(DMI_PRODUCT_VERSION, "00"),
		},
	},
	{
		
		.matches = {
			DMI_MATCH(DMI_SYS_VENDOR, "ULI"),
			DMI_MATCH(DMI_PRODUCT_NAME, "EV4873"),
			DMI_MATCH(DMI_PRODUCT_VERSION, "5a"),
		},
	},
	{
		
		.matches = {
			DMI_MATCH(DMI_SYS_VENDOR, "Microsoft Corporation"),
			DMI_MATCH(DMI_PRODUCT_NAME, "Virtual Machine"),
			DMI_MATCH(DMI_PRODUCT_VERSION, "VS2005R2"),
		},
	},
	{
		
		.matches = {
			DMI_MATCH(DMI_SYS_VENDOR, "Notebook"),
			DMI_MATCH(DMI_PRODUCT_NAME, "MAM 2070"),
			DMI_MATCH(DMI_PRODUCT_VERSION, "5a"),
		},
	},
	{
		
		.matches = {
			DMI_MATCH(DMI_SYS_VENDOR, "blue"),
			DMI_MATCH(DMI_PRODUCT_NAME, "FB5601"),
			DMI_MATCH(DMI_PRODUCT_VERSION, "M606"),
		},
	},
	{
		
		.matches = {
			DMI_MATCH(DMI_SYS_VENDOR, "GIGABYTE"),
			DMI_MATCH(DMI_PRODUCT_NAME, "M912"),
			DMI_MATCH(DMI_PRODUCT_VERSION, "01"),
		},
	},
	{
		
		.matches = {
			DMI_MATCH(DMI_BOARD_VENDOR, "Gigabyte Technology Co.,Ltd."),
			DMI_MATCH(DMI_BOARD_NAME, "M1022E"),
			DMI_MATCH(DMI_BOARD_VERSION, "1.02"),
		},
	},
	{
		
		.matches = {
			DMI_MATCH(DMI_SYS_VENDOR, "GIGABYTE"),
			DMI_MATCH(DMI_PRODUCT_NAME, "Spring Peak"),
		},
	},
	{
		/* Gigabyte T1005 - defines wrong chassis type ("Other") */
		.matches = {
			DMI_MATCH(DMI_SYS_VENDOR, "GIGABYTE"),
			DMI_MATCH(DMI_PRODUCT_NAME, "T1005"),
		},
	},
	{
		/* Gigabyte T1005M/P - defines wrong chassis type ("Other") */
		.matches = {
			DMI_MATCH(DMI_SYS_VENDOR, "GIGABYTE"),
			DMI_MATCH(DMI_PRODUCT_NAME, "T1005M/P"),
		},
	},
	{
		.matches = {
			DMI_MATCH(DMI_SYS_VENDOR, "Hewlett-Packard"),
			DMI_MATCH(DMI_PRODUCT_NAME, "HP Pavilion dv9700"),
			DMI_MATCH(DMI_PRODUCT_VERSION, "Rev 1"),
		},
	},
	{ }
};

static const struct dmi_system_id __initconst i8042_dmi_nomux_table[] = {
	{
		
		.matches = {
			DMI_MATCH(DMI_SYS_VENDOR, "FUJITSU"),
			DMI_MATCH(DMI_PRODUCT_NAME, "P7010"),
		},
	},
	{
		
		.matches = {
			DMI_MATCH(DMI_SYS_VENDOR, "FUJITSU SIEMENS"),
			DMI_MATCH(DMI_PRODUCT_NAME, "0000000000"),
		},
	},
	{
		
		.matches = {
			DMI_MATCH(DMI_SYS_VENDOR, "FUJITSU"),
			DMI_MATCH(DMI_PRODUCT_NAME, "LifeBook P Series"),
		},
	},
	{
		
		.matches = {
			DMI_MATCH(DMI_SYS_VENDOR, "FUJITSU"),
			DMI_MATCH(DMI_PRODUCT_NAME, "LifeBook S Series"),
		},
	},
	{
		
		.matches = {
			DMI_MATCH(DMI_SYS_VENDOR, "FUJITSU"),
			DMI_MATCH(DMI_PRODUCT_NAME, "LifeBook S6230"),
		},
	},
	{
		
		.matches = {
			DMI_MATCH(DMI_SYS_VENDOR, "FUJITSU"),
			DMI_MATCH(DMI_PRODUCT_NAME, "FMVLT70H"),
		},
	},
	{
		
		.matches = {
			DMI_MATCH(DMI_SYS_VENDOR, "FUJITSU SIEMENS"),
			DMI_MATCH(DMI_PRODUCT_NAME, "LIFEBOOK T3010"),
		},
	},
	{
		
		.matches = {
			DMI_MATCH(DMI_SYS_VENDOR, "FUJITSU SIEMENS"),
			DMI_MATCH(DMI_PRODUCT_NAME, "LIFEBOOK E4010"),
		},
	},
	{
		
		.matches = {
			DMI_MATCH(DMI_SYS_VENDOR, "FUJITSU SIEMENS"),
			DMI_MATCH(DMI_PRODUCT_NAME, "AMILO Pro V2010"),
		},
	},
	{
		
		.matches = {
			DMI_MATCH(DMI_SYS_VENDOR, "FUJITSU SIEMENS"),
			DMI_MATCH(DMI_PRODUCT_NAME, "AMILO PRO V2030"),
		},
	},
	{
		
		.matches = {
			DMI_MATCH(DMI_SYS_VENDOR, "Matsushita"),
			DMI_MATCH(DMI_PRODUCT_NAME, "CF-29"),
		},
	},
	{
		.matches = {
			DMI_MATCH(DMI_SYS_VENDOR, "Hewlett-Packard"),
			DMI_MATCH(DMI_PRODUCT_NAME, "Pavilion dv4000 (EA032EA#ABF)"),
		},
	},
	{
		.matches = {
			DMI_MATCH(DMI_SYS_VENDOR, "Hewlett-Packard"),
			DMI_MATCH(DMI_PRODUCT_NAME, "HP Pavilion Notebook PC"),
			DMI_MATCH(DMI_PRODUCT_VERSION, "HP Pavilion Notebook ZT1000"),
		},
	},
	{
		.matches = {
			DMI_MATCH(DMI_SYS_VENDOR, "Hewlett-Packard"),
			DMI_MATCH(DMI_PRODUCT_NAME, "Pavilion dv4000 (EH476UA#ABL)"),
		},
	},
	{
		.matches = {
			DMI_MATCH(DMI_SYS_VENDOR, "TOSHIBA"),
			DMI_MATCH(DMI_PRODUCT_NAME, "Satellite P10"),
		},
	},
	{
		.matches = {
			DMI_MATCH(DMI_SYS_VENDOR, "TOSHIBA"),
			DMI_MATCH(DMI_PRODUCT_NAME, "EQUIUM A110"),
		},
	},
	{
		.matches = {
			DMI_MATCH(DMI_SYS_VENDOR, "ALIENWARE"),
			DMI_MATCH(DMI_PRODUCT_NAME, "Sentia"),
		},
	},
	{
		
		.matches = {
			DMI_MATCH(DMI_SYS_VENDOR, "SHARP"),
			DMI_MATCH(DMI_PRODUCT_NAME, "PC-MM20 Series"),
		},
	},
	{
		
		.matches = {
			DMI_MATCH(DMI_SYS_VENDOR, "Sony Corporation"),
			DMI_MATCH(DMI_PRODUCT_NAME, "VGN-FS115B"),
		},
	},
	{
		.matches = {
			DMI_MATCH(DMI_SYS_VENDOR, "Sony Corporation"),
			DMI_MATCH(DMI_PRODUCT_NAME, "VGN-FZ240E"),
		},
	},
	{
		.matches = {
			DMI_MATCH(DMI_SYS_VENDOR, "Sony Corporation"),
			DMI_MATCH(DMI_BOARD_NAME, "VAIO"),
		},
	},
	{
		
		.matches = {
			DMI_MATCH(DMI_SYS_VENDOR, "Amoi Electronics CO.,LTD."),
			DMI_MATCH(DMI_PRODUCT_NAME, "M636/A737 platform"),
		},
	},
	{
		
		.matches = {
			DMI_MATCH(DMI_SYS_VENDOR, "LENOVO"),
			DMI_MATCH(DMI_PRODUCT_NAME, "076804U"),
		},
	},
	{
		.matches = {
			DMI_MATCH(DMI_SYS_VENDOR, "Acer"),
			DMI_MATCH(DMI_PRODUCT_NAME, "Aspire 1360"),
		},
	},
	{
		
		.matches = {
			DMI_MATCH(DMI_SYS_VENDOR, "Gericom"),
			DMI_MATCH(DMI_PRODUCT_NAME, "N34AS6"),
		},
	},
	{
		
		.matches = {
			DMI_MATCH(DMI_SYS_VENDOR, "IBM"),
			DMI_MATCH(DMI_PRODUCT_NAME, "2656"),
		},
	},
	{
		
		.matches = {
			DMI_MATCH(DMI_SYS_VENDOR, "Dell Inc."),
			DMI_MATCH(DMI_PRODUCT_NAME, "XPS M1530"),
		},
	},
	{
		
		.matches = {
			DMI_MATCH(DMI_SYS_VENDOR, "COMPAL"),
			DMI_MATCH(DMI_PRODUCT_NAME, "HEL80I"),
		},
	},
	{
		
		.matches = {
			DMI_MATCH(DMI_SYS_VENDOR, "Dell Inc."),
			DMI_MATCH(DMI_PRODUCT_NAME, "Vostro1510"),
		},
	},
	{
		
		.matches = {
			DMI_MATCH(DMI_SYS_VENDOR, "Acer"),
			DMI_MATCH(DMI_PRODUCT_NAME, "Aspire 5536"),
			DMI_MATCH(DMI_PRODUCT_VERSION, "0100"),
		},
	},
	{
		
		.matches = {
			DMI_MATCH(DMI_SYS_VENDOR, "Dell Inc."),
			DMI_MATCH(DMI_PRODUCT_NAME, "Vostro V13"),
		},
	},
	{
		
		.matches = {
			DMI_MATCH(DMI_SYS_VENDOR, "Hewlett-Packard"),
			DMI_MATCH(DMI_PRODUCT_NAME, "HP Pavilion dv4 Notebook PC"),
		},
	},
	{ }
};

static const struct dmi_system_id __initconst i8042_dmi_reset_table[] = {
	{
		
		.matches = {
			DMI_MATCH(DMI_BOARD_NAME, "U-100"),
			DMI_MATCH(DMI_BOARD_VENDOR, "MICRO-STAR INTERNATIONAL CO., LTD"),
		},
	},
	{
		
		.matches = {
			DMI_MATCH(DMI_BOARD_NAME, "X110"),
			DMI_MATCH(DMI_BOARD_VENDOR, "LG Electronics Inc."),
		},
	},
	{
		
		.matches = {
			DMI_MATCH(DMI_SYS_VENDOR, "Acer"),
			DMI_MATCH(DMI_PRODUCT_NAME, "AOA150"),
		},
	},
	{
		
		.matches = {
			DMI_MATCH(DMI_SYS_VENDOR, "DIXONSXP"),
			DMI_MATCH(DMI_PRODUCT_NAME, "Advent 4211"),
		},
	},
	{
		
		.matches = {
			DMI_MATCH(DMI_SYS_VENDOR, "MEDION"),
			DMI_MATCH(DMI_PRODUCT_NAME, "E1210"),
		},
	},
	{
		
		.matches = {
			DMI_MATCH(DMI_SYS_VENDOR, "MEDION"),
			DMI_MATCH(DMI_PRODUCT_NAME, "E122X"),
		},
	},
	{
		
		.matches = {
			DMI_MATCH(DMI_SYS_VENDOR, "VIOOO"),
			DMI_MATCH(DMI_PRODUCT_NAME, "N10"),
		},
	},
	{
		
		.matches = {
			DMI_MATCH(DMI_SYS_VENDOR, "Dell Inc."),
			DMI_MATCH(DMI_PRODUCT_NAME, "Vostro 1320"),
		},
	},
	{
		
		.matches = {
			DMI_MATCH(DMI_SYS_VENDOR, "Dell Inc."),
			DMI_MATCH(DMI_PRODUCT_NAME, "Vostro 1520"),
		},
	},
	{
		
		.matches = {
			DMI_MATCH(DMI_SYS_VENDOR, "Dell Inc."),
			DMI_MATCH(DMI_PRODUCT_NAME, "Vostro 1720"),
		},
	},
	{
		
		.matches = {
			DMI_MATCH(DMI_SYS_VENDOR, "LENOVO"),
			DMI_MATCH(DMI_PRODUCT_NAME, "20046"),
		},
	},
	{ }
};

#ifdef CONFIG_PNP
static const struct dmi_system_id __initconst i8042_dmi_nopnp_table[] = {
	{
		
		.matches = {
			DMI_MATCH(DMI_BOARD_NAME, "D845PESV"),
			DMI_MATCH(DMI_BOARD_VENDOR, "Intel Corporation"),
		},
	},
	{
		
		.matches = {
			DMI_MATCH(DMI_BOARD_NAME, "U-100"),
			DMI_MATCH(DMI_BOARD_VENDOR, "MICRO-STAR INTERNATIONAL CO., LTD"),
		},
	},
	{ }
};

static const struct dmi_system_id __initconst i8042_dmi_laptop_table[] = {
	{
		.matches = {
			DMI_MATCH(DMI_CHASSIS_TYPE, "8"), 
		},
	},
	{
		.matches = {
			DMI_MATCH(DMI_CHASSIS_TYPE, "9"), 
		},
	},
	{
		.matches = {
			DMI_MATCH(DMI_CHASSIS_TYPE, "10"), 
		},
	},
	{
		.matches = {
			DMI_MATCH(DMI_CHASSIS_TYPE, "14"), 
		},
	},
	{ }
};
#endif

static const struct dmi_system_id __initconst i8042_dmi_notimeout_table[] = {
	{
		
		.matches = {
			DMI_MATCH(DMI_SYS_VENDOR, "Dell Inc."),
			DMI_MATCH(DMI_PRODUCT_NAME, "Vostro V13"),
		},
	},
	{
		
		.matches = {
			DMI_MATCH(DMI_SYS_VENDOR, "Hewlett-Packard"),
			DMI_MATCH(DMI_PRODUCT_NAME, "HP Pavilion dv4 Notebook PC"),
		},
	},
	{ }
};

static const struct dmi_system_id __initconst i8042_dmi_dritek_table[] = {
	{
		
		.matches = {
			DMI_MATCH(DMI_SYS_VENDOR, "Acer"),
			DMI_MATCH(DMI_PRODUCT_NAME, "Aspire 5100"),
		},
	},
	{
		
		.matches = {
			DMI_MATCH(DMI_SYS_VENDOR, "Acer"),
			DMI_MATCH(DMI_PRODUCT_NAME, "Aspire 5610"),
		},
	},
	{
		
		.matches = {
			DMI_MATCH(DMI_SYS_VENDOR, "Acer"),
			DMI_MATCH(DMI_PRODUCT_NAME, "Aspire 5630"),
		},
	},
	{
		
		.matches = {
			DMI_MATCH(DMI_SYS_VENDOR, "Acer"),
			DMI_MATCH(DMI_PRODUCT_NAME, "Aspire 5650"),
		},
	},
	{
		
		.matches = {
			DMI_MATCH(DMI_SYS_VENDOR, "Acer"),
			DMI_MATCH(DMI_PRODUCT_NAME, "Aspire 5680"),
		},
	},
	{
		
		.matches = {
			DMI_MATCH(DMI_SYS_VENDOR, "Acer"),
			DMI_MATCH(DMI_PRODUCT_NAME, "Aspire 5720"),
		},
	},
	{
		
		.matches = {
			DMI_MATCH(DMI_SYS_VENDOR, "Acer"),
			DMI_MATCH(DMI_PRODUCT_NAME, "Aspire 9110"),
		},
	},
	{
		
		.matches = {
			DMI_MATCH(DMI_SYS_VENDOR, "Acer"),
			DMI_MATCH(DMI_PRODUCT_NAME, "TravelMate 660"),
		},
	},
	{
		
		.matches = {
			DMI_MATCH(DMI_SYS_VENDOR, "Acer"),
			DMI_MATCH(DMI_PRODUCT_NAME, "TravelMate 2490"),
		},
	},
	{
		
		.matches = {
			DMI_MATCH(DMI_SYS_VENDOR, "Acer"),
			DMI_MATCH(DMI_PRODUCT_NAME, "TravelMate 4280"),
		},
	},
	{ }
};

#endif 

#ifdef CONFIG_PNP
#include <linux/pnp.h>

static bool i8042_pnp_kbd_registered;
static unsigned int i8042_pnp_kbd_devices;
static bool i8042_pnp_aux_registered;
static unsigned int i8042_pnp_aux_devices;

static int i8042_pnp_command_reg;
static int i8042_pnp_data_reg;
static int i8042_pnp_kbd_irq;
static int i8042_pnp_aux_irq;

static char i8042_pnp_kbd_name[32];
static char i8042_pnp_aux_name[32];

static int i8042_pnp_kbd_probe(struct pnp_dev *dev, const struct pnp_device_id *did)
{
	if (pnp_port_valid(dev, 0) && pnp_port_len(dev, 0) == 1)
		i8042_pnp_data_reg = pnp_port_start(dev,0);

	if (pnp_port_valid(dev, 1) && pnp_port_len(dev, 1) == 1)
		i8042_pnp_command_reg = pnp_port_start(dev, 1);

	if (pnp_irq_valid(dev,0))
		i8042_pnp_kbd_irq = pnp_irq(dev, 0);

	strlcpy(i8042_pnp_kbd_name, did->id, sizeof(i8042_pnp_kbd_name));
	if (strlen(pnp_dev_name(dev))) {
		strlcat(i8042_pnp_kbd_name, ":", sizeof(i8042_pnp_kbd_name));
		strlcat(i8042_pnp_kbd_name, pnp_dev_name(dev), sizeof(i8042_pnp_kbd_name));
	}

	
	device_set_wakeup_enable(&dev->dev, true);

	i8042_pnp_kbd_devices++;
	return 0;
}

static int i8042_pnp_aux_probe(struct pnp_dev *dev, const struct pnp_device_id *did)
{
	if (pnp_port_valid(dev, 0) && pnp_port_len(dev, 0) == 1)
		i8042_pnp_data_reg = pnp_port_start(dev,0);

	if (pnp_port_valid(dev, 1) && pnp_port_len(dev, 1) == 1)
		i8042_pnp_command_reg = pnp_port_start(dev, 1);

	if (pnp_irq_valid(dev, 0))
		i8042_pnp_aux_irq = pnp_irq(dev, 0);

	strlcpy(i8042_pnp_aux_name, did->id, sizeof(i8042_pnp_aux_name));
	if (strlen(pnp_dev_name(dev))) {
		strlcat(i8042_pnp_aux_name, ":", sizeof(i8042_pnp_aux_name));
		strlcat(i8042_pnp_aux_name, pnp_dev_name(dev), sizeof(i8042_pnp_aux_name));
	}

	i8042_pnp_aux_devices++;
	return 0;
}

static struct pnp_device_id pnp_kbd_devids[] = {
	{ .id = "PNP0300", .driver_data = 0 },
	{ .id = "PNP0301", .driver_data = 0 },
	{ .id = "PNP0302", .driver_data = 0 },
	{ .id = "PNP0303", .driver_data = 0 },
	{ .id = "PNP0304", .driver_data = 0 },
	{ .id = "PNP0305", .driver_data = 0 },
	{ .id = "PNP0306", .driver_data = 0 },
	{ .id = "PNP0309", .driver_data = 0 },
	{ .id = "PNP030a", .driver_data = 0 },
	{ .id = "PNP030b", .driver_data = 0 },
	{ .id = "PNP0320", .driver_data = 0 },
	{ .id = "PNP0343", .driver_data = 0 },
	{ .id = "PNP0344", .driver_data = 0 },
	{ .id = "PNP0345", .driver_data = 0 },
	{ .id = "CPQA0D7", .driver_data = 0 },
	{ .id = "", },
};

static struct pnp_driver i8042_pnp_kbd_driver = {
	.name           = "i8042 kbd",
	.id_table       = pnp_kbd_devids,
	.probe          = i8042_pnp_kbd_probe,
};

static struct pnp_device_id pnp_aux_devids[] = {
	{ .id = "AUI0200", .driver_data = 0 },
	{ .id = "FJC6000", .driver_data = 0 },
	{ .id = "FJC6001", .driver_data = 0 },
	{ .id = "PNP0f03", .driver_data = 0 },
	{ .id = "PNP0f0b", .driver_data = 0 },
	{ .id = "PNP0f0e", .driver_data = 0 },
	{ .id = "PNP0f12", .driver_data = 0 },
	{ .id = "PNP0f13", .driver_data = 0 },
	{ .id = "PNP0f19", .driver_data = 0 },
	{ .id = "PNP0f1c", .driver_data = 0 },
	{ .id = "SYN0801", .driver_data = 0 },
	{ .id = "", },
};

static struct pnp_driver i8042_pnp_aux_driver = {
	.name           = "i8042 aux",
	.id_table       = pnp_aux_devids,
	.probe          = i8042_pnp_aux_probe,
};

static void i8042_pnp_exit(void)
{
	if (i8042_pnp_kbd_registered) {
		i8042_pnp_kbd_registered = false;
		pnp_unregister_driver(&i8042_pnp_kbd_driver);
	}

	if (i8042_pnp_aux_registered) {
		i8042_pnp_aux_registered = false;
		pnp_unregister_driver(&i8042_pnp_aux_driver);
	}
}

static int __init i8042_pnp_init(void)
{
	char kbd_irq_str[4] = { 0 }, aux_irq_str[4] = { 0 };
	bool pnp_data_busted = false;
	int err;

#ifdef CONFIG_X86
	if (dmi_check_system(i8042_dmi_nopnp_table))
		i8042_nopnp = true;
#endif

	if (i8042_nopnp) {
		pr_info("PNP detection disabled\n");
		return 0;
	}

	err = pnp_register_driver(&i8042_pnp_kbd_driver);
	if (!err)
		i8042_pnp_kbd_registered = true;

	err = pnp_register_driver(&i8042_pnp_aux_driver);
	if (!err)
		i8042_pnp_aux_registered = true;

	if (!i8042_pnp_kbd_devices && !i8042_pnp_aux_devices) {
		i8042_pnp_exit();
#if defined(__ia64__)
		return -ENODEV;
#else
		pr_info("PNP: No PS/2 controller found. Probing ports directly.\n");
		return 0;
#endif
	}

	if (i8042_pnp_kbd_devices)
		snprintf(kbd_irq_str, sizeof(kbd_irq_str),
			"%d", i8042_pnp_kbd_irq);
	if (i8042_pnp_aux_devices)
		snprintf(aux_irq_str, sizeof(aux_irq_str),
			"%d", i8042_pnp_aux_irq);

	pr_info("PNP: PS/2 Controller [%s%s%s] at %#x,%#x irq %s%s%s\n",
		i8042_pnp_kbd_name, (i8042_pnp_kbd_devices && i8042_pnp_aux_devices) ? "," : "",
		i8042_pnp_aux_name,
		i8042_pnp_data_reg, i8042_pnp_command_reg,
		kbd_irq_str, (i8042_pnp_kbd_devices && i8042_pnp_aux_devices) ? "," : "",
		aux_irq_str);

#if defined(__ia64__)
	if (!i8042_pnp_kbd_devices)
		i8042_nokbd = true;
	if (!i8042_pnp_aux_devices)
		i8042_noaux = true;
#endif

	if (((i8042_pnp_data_reg & ~0xf) == (i8042_data_reg & ~0xf) &&
	      i8042_pnp_data_reg != i8042_data_reg) ||
	    !i8042_pnp_data_reg) {
		pr_warn("PNP: PS/2 controller has invalid data port %#x; using default %#x\n",
			i8042_pnp_data_reg, i8042_data_reg);
		i8042_pnp_data_reg = i8042_data_reg;
		pnp_data_busted = true;
	}

	if (((i8042_pnp_command_reg & ~0xf) == (i8042_command_reg & ~0xf) &&
	      i8042_pnp_command_reg != i8042_command_reg) ||
	    !i8042_pnp_command_reg) {
		pr_warn("PNP: PS/2 controller has invalid command port %#x; using default %#x\n",
			i8042_pnp_command_reg, i8042_command_reg);
		i8042_pnp_command_reg = i8042_command_reg;
		pnp_data_busted = true;
	}

	if (!i8042_nokbd && !i8042_pnp_kbd_irq) {
		pr_warn("PNP: PS/2 controller doesn't have KBD irq; using default %d\n",
			i8042_kbd_irq);
		i8042_pnp_kbd_irq = i8042_kbd_irq;
		pnp_data_busted = true;
	}

	if (!i8042_noaux && !i8042_pnp_aux_irq) {
		if (!pnp_data_busted && i8042_pnp_kbd_irq) {
			pr_warn("PNP: PS/2 appears to have AUX port disabled, "
				"if this is incorrect please boot with i8042.nopnp\n");
			i8042_noaux = true;
		} else {
			pr_warn("PNP: PS/2 controller doesn't have AUX irq; using default %d\n",
				i8042_aux_irq);
			i8042_pnp_aux_irq = i8042_aux_irq;
		}
	}

	i8042_data_reg = i8042_pnp_data_reg;
	i8042_command_reg = i8042_pnp_command_reg;
	i8042_kbd_irq = i8042_pnp_kbd_irq;
	i8042_aux_irq = i8042_pnp_aux_irq;

#ifdef CONFIG_X86
	i8042_bypass_aux_irq_test = !pnp_data_busted &&
				    dmi_check_system(i8042_dmi_laptop_table);
#endif

	return 0;
}

#else
static inline int i8042_pnp_init(void) { return 0; }
static inline void i8042_pnp_exit(void) { }
#endif

static int __init i8042_platform_init(void)
{
	int retval;

#ifdef CONFIG_X86
	
	if (!x86_platform.i8042_detect())
		return -ENODEV;
#endif


	i8042_kbd_irq = I8042_MAP_IRQ(1);
	i8042_aux_irq = I8042_MAP_IRQ(12);

	retval = i8042_pnp_init();
	if (retval)
		return retval;

#if defined(__ia64__)
        i8042_reset = true;
#endif

#ifdef CONFIG_X86
	if (dmi_check_system(i8042_dmi_reset_table))
		i8042_reset = true;

	if (dmi_check_system(i8042_dmi_noloop_table))
		i8042_noloop = true;

	if (dmi_check_system(i8042_dmi_nomux_table))
		i8042_nomux = true;

	if (dmi_check_system(i8042_dmi_notimeout_table))
		i8042_notimeout = true;

	if (dmi_check_system(i8042_dmi_dritek_table))
		i8042_dritek = true;
#endif 

	return retval;
}

static inline void i8042_platform_exit(void)
{
	i8042_pnp_exit();
}

#endif 
