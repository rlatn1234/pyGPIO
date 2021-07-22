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
pin header (40pin) looks like the following:
  3.3V    |··|	5V
  GPIO2   |··|	5V
  GPIO3   |··|	GND
  GPIO4   |··|	GPIO14
  GND     |··|	GPIO15
  GPIO17  |··|	GPIO18
  GPIO27  |··|	GND
  GPIO22  |··|	GPIO23
  3.3V    |··|	GPIO24
  GPIO10  |··|	GND
  GPIO9   |··|	GPIO25
  GPIO11  |··|	GPIO8
  GND     |··|	GPIO7	
  GPIO28* |··|	GPIO29*
  GPIO5   |··|	GND
  GPIO6   |··|	GPIO12
  GPIO13  |··|	GND
  GPIO19  |··|	GPIO16
  GPIO26  |··|	GPIO20
  GND     |··|	GPIO21
(*) on the RPi those two pins are used for official HATS (read out eeprom), since this is never depoyed 
on SUNXI boards we can use this GPIOs too. ;)
replace XZ with the pin which is wired out on this position (e.g. PA10, PG11 etc.) 
*/  
	{"GPIO",
		{
			//'first row'
			{   "GPIO2",  SUNXI_GPA(12),  3   },
			{   "GPIO3",  SUNXI_GPA(11),  5   },
			{   "GPIO4",  SUNXI_GPA(2),  7   },
			{   "GPIO17",  SUNXI_GPA(1),  11   },
			{   "GPIO27",  SUNXI_GPA(0),  13   },
			{   "GPIO22",  SUNXI_GPA(3),  15   },
			{   "GPIO10",  SUNXI_GPC(0),  19  },
			{   "GPIO9",  SUNXI_GPC(1),  21  },
			{   "GPIO11",  SUNXI_GPC(2),  23  },
			{   "GPIO28",  SUNXI_GPA(19),  27   },
			{   "GPIO5",  SUNXI_GPA(20),  29   },
			{   "GPIO6",  SUNXI_GPA(21),  31  },
			{   "GPIO13",  SUNXI_GPA(6),  33  },
			{   "GPIO19",  SUNXI_GPG(10),  35  },
			{   "GPIO26",  SUNXI_GPA(16),  37  },			
			//'second row'
			{   "GPIO14",  SUNXI_GPG(6),  8  },	
			{   "GPIO15",  SUNXI_GPG(7),  10  },
			{   "GPIO18",  SUNXI_GPG(11),  12  },
			{   "GPIO23",  SUNXI_GPG(9),  16  },
			{   "GPIO24",  SUNXI_GPG(8),  18  },
			{   "GPIO25",  SUNXI_GPA(14),  22  },
			{   "GPIO8",  SUNXI_GPC(3),  24  },
			{   "GPIO7",  SUNXI_GPA(17),  26   },
			{   "GPIO29",  SUNXI_GPA(18),  28  },
			{   "GPIO12",  SUNXI_GPA(13),  32  },
			{   "GPIO16",  SUNXI_GPA(15),  36  },
			{   "GPIO20",  SUNXI_GPG(13),  38  },
			{   "GPIO21",  SUNXI_GPG(12),  40  },
			
			{
				{   0,  0,  0}
			},
		}
	},
  /*
    #define PIN_PG0		SUNXI_GPG(0)

	{"LED",
		{
			{   "POWER_LED",  SUNXI_GPL(10),  1   },
			{   "STATUS_LED",  SUNXI_GPA(17),  2   },
			{
				{   0,  0,  0}
			},
		}
	},
*/
};

#endif
