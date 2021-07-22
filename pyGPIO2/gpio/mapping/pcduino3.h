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
						(J11)			(J12)
GPIO0 (UART2_RX)		|·|				|·|	 A0**
GPIO1 (UART2_TX)		|·|				|·|	 A1**
GPIO2					|·|				|·|  A2**
GPIO3					|·|				|·|  A3**
GPIO4					|·|				|·|  A4**
GPIO5					|·|				|·|  A5**
GPIO6					|·|				(J9)
GPIO7					|·|				|·|  5V
						(J8)			|·|  GND
GPIO8					|1|				|·|  GND
GPIO9					|·|				|·|  5V
GPIO10 (SPI_CS)			|·|				|·|	 3.3V
GPIO11 (SPI0_MOSI)		|·|				|·|  RESET
GPIO12 (SPI0_MISO)		|·|				|·|  IOREF
GPIO13 (SPI0_CLK)		|·|				|·|  NC
GND						|·|				
AREF					|·|				
GPIO18* (TWI2_SDA)		|·|				
GPIO19* (TWI2_SCL)		|10|	

		(P10)	
GPIO15	|·||1|	GPIO14
GPIO17  |4||·|	GPIO16


* Pins are not defined as GPIOs, but from schematics, those pins can also be used as GPIOs
** The library can not read analog inputs, therefore those pins are not defined!
	
*/	

  {"J11",
        {
            {   "GPIO0",  SUNXI_GPI(19),  1   },
            {   "GPIO1",  SUNXI_GPI(18),  2   },
            {   "GPIO2",  SUNXI_GPH(7),  3   },
            {   "GPIO3",  SUNXI_GPH(6),  4  },
            {   "GPIO4",  SUNXI_GPH(8),  5  },			
            {   "GPIO5",  SUNXI_GPB(2),  6  },
			{   "GPIO6",  SUNXI_GPI(3),  7  },
            {   "GPIO7",  SUNXI_GPH(9),  8  },
            {
                {   0,  0,  0}
            },
        }
    },

  {"J8",
        {
            {   "GPIO8",  SUNXI_GPH(10),  1   },
            {   "GPIO9",  SUNXI_GPH(5),  2   },
            {   "GPIO10",  SUNXI_GPI(10),  3   },
            {   "GPIO11",  SUNXI_GPI(12),  4  },
            {   "GPIO12",  SUNXI_GPI(13),  5  },			
            {   "GPIO13",  SUNXI_GPI(11),  6  },
			{   "GPIO18",  SUNXI_GPB(21),  9  },
            {   "GPIO19",  SUNXI_GPB(20),  10  },
            {
                {   0,  0,  0}
            },
        }
    },	
	
  {"P10",
        {
            {   "GPIO14",  SUNXI_GPH(11),  1   },
            {   "GPIO15",  SUNXI_GPH(13),  2   },
            {   "GPIO16",  SUNXI_GPH(12),  3   },
			{   "GPIO17",  SUNXI_GPH(14),  4   },
            {
                {   0,  0,  0}
            },
        }
    },	

  {"BUTTON",
        {
            {   "SW5",  SUNXI_GPH(19),  1   },
            {   "SW4",  SUNXI_GPH(18),  2   },
            {   "SW3",  SUNXI_GPH(17),  3   },
            {
                {   0,  0,  0}
            },
        }
    },
	
};

#endif
	