/*
 *
 * This file is part of pyA20.
 * mapping.h is python GPIO extension.
 *
 * Copyright (c) 2014 Stefan Mavrodiev @ OLIMEX LTD, <support@olimex.com>
 *
 * pyA20 is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 *
 * mapping.h from: https://github.com/wdmomoxx/orangepi_ZERO_gpio_pyH2
 *
 */

#ifndef __MAPPING_H
#define __MAPPING_H

#include "gpio_lib.h"

/**
Structure that describe all gpio
*/
typedef struct _pin {
	char name[10];          // The processor pin
	int offset;             // Memory offset for the pin
	int pin_number;         // Number on the connector
}pin_t;

typedef struct _gpio {
	char connector_name[10];
	pin_t pins[41];
}gpio_t;


gpio_t gpio[] = {

/*
Description of Pinheader, please don't change pinnumer to keep this library consistent! A 'RPi compatible'
pin header (26pin 'model A') looks like the following:

3.3V			|··|	5V
GPIO2 (I2C0_SDA)	|··|	5V
GPIO3 (I2C0_SCL)	|··|	GND
GPIO4 (GPIOG11)		|··|	GPIO14 (UART1_TX)
GND			|··|	GPIO15 (UART1_RX)
GPIO17 (UART2_TX)	|··|	GPIO18 (PMW)	
GPIO27 (UART2_RTS)	|··|	GND
GPIO22 (UART2_CTS)	|··|	GPIO23 (UART1_RTS)
3.3V			|··|	GPIO24 (UART1_CTS)
GPIO10 (SPI0_MOSI)	|··|	GND
GPIO9 (SPI0_MISO)	|··|	GPIO25 (UART2_RX)
GPIO11 (SPI0_CLK)	|··|	GPIO8 (SPI0_CS)
----------------------------------------------------------
GND		|··|	GPIO7	(not depoyed on 24 pin header)

replace XZ with the pin which is wired out on this position (e.g. PA10, PG11 etc.) 
*/  
	{"GPIO",
		{
			//'first row'
			{   "GPIO2",  SUNXI_GPA(12),  3   },
			{   "GPIO3",  SUNXI_GPA(11),  5   },
			{   "GPIO4",  SUNXI_GPG(11),  7   },
			{   "GPIO17",  SUNXI_GPA(4),  11   },
			{   "GPIO27",  SUNXI_GPA(2),  13   },
			{   "GPIO22",  SUNXI_GPA(3),  15   },
			{   "GPIO10",  SUNXI_GPC(0),  19  },
			{   "GPIO9",  SUNXI_GPC(1),  21  },
			{   "GPIO11",  SUNXI_GPC(2),  23  },
			//'second row'
			{   "GPIO14",  SUNXI_GPG(6),  8  },	
			{   "GPIO15",  SUNXI_GPG(7),  10  },
			{   "GPIO18",  SUNXI_GPA(5),  12  },
			{   "GPIO23",  SUNXI_GPG(8),  16  },
			{   "GPIO24",  SUNXI_GPG(9),  18  },
			{   "GPIO25",  SUNXI_GPa(5),  22  },
			{   "GPIO8",  SUNXI_GPC(3),  24  },
			{
				{   0,  0,  0}
			},
		}
		},
  /*
    #define PIN_PG0		SUNXI_GPG(0)
*/
	{"LED",
		{
			{   "POWER_LED",  SUNXI_GPL(10),  1   },
			{   "STATUS_LED",  SUNXI_GPA(10),  2  },
			{
				{   0,  0,  0}
			},
		}
	},
};



#endif
