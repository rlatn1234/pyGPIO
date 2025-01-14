/*
 *
 * This file is part of pyGPIO2.
 * mapping.h is python GPIO extension.
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

3.3V			    |··|	5V
GPIO2 	I2C0_SDA	|··|	5V
GPIO3	I2C_SCL		|··|	GND
GPIO4			    |··|	GPIO14	UART1_TX
GND			        |··|	GPIO15	UART1_RX
GPIO17	SPI1_MOSI	|··|	GPIO18	
GPIO27	SPI1_MISO	|··|	GND	
GPIO22	SPI1_CLK	|··|	GPIO23	SPI1_CS
3.3V			    |··|	NC (on mini shield)
----------------------------------------------------
GPIO10			    |··|	GND		(not depoyed on mini shield)
GPIO9			    |··|	GPIO25
GPIO11			    |··|	GPIO8
GND			        |··|	GPIO7	

*/  
	{"GPIO",
		{
			//'first row'
			{   "GPIO2",  SUNXI_GPA(12),  2   },
			{   "GPIO3",  SUNXI_GPA(11),  3   },
			{   "GPIO4",  SUNXI_GPG(11),  4   },
			{   "GPIO17",  SUNXI_GPA(15),  6   },
			{   "GPIO27",  SUNXI_GPA(16),  7   },
			{   "GPIO22",  SUNXI_GPA(14),  8   },
			//'second row'
			{   "GPIO14",  SUNXI_GPG(7),  4  },	
			{   "GPIO15",  SUNXI_GPG(6),  5  },
			{   "GPIO18",  SUNXI_GPL(11),  6  },
			{   "GPIO23",  SUNXI_GPA(13),  8  },
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
