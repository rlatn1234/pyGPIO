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

3.3V	|··|	5V
GPIO2	|··|	5V
GPIO3	|··|	GND
GPIO4	|··|	GPIO14
GND	    |··|	GPIO15
GPIO17	|··|	GPIO18
GPIO27	|··|	GND
GPIO22	|··|	GPIO23
3.3V	|··|	GPIO24
GPIO10	|··|	GND
GPIO9	|··|	GPIO25
GPIO11	|··|	GPIO8
GND	    |··|	GPIO7	
GPIO28*	|··|	GPIO29*
GPIO5	|··|	GND
GPIO6	|··|	GPIO12
GPIO13	|··|	GND
GPIO19	|··|	GPIO16
GPIO26	|··|	GPIO20
GND	    |··|	GPIO21
(*) on the RPi those two pins are used for official HATS (read out eeprom), since this is never depoyed 
on SUNXI boards we can use this GPIOs too. ;)

replace XZ with the pin which is wired out on this position (e.g. PA10, PG11 etc.) 
*/  
	{"GPIO",
		{
			//'first row'
			{   "GPIO2",  SUNXI_GPA(12),  3   },
			{   "GPIO3",  SUNXI_GPA(11),  5   },
			{   "GPIO4",  SUNXI_GPA(6),  7   },
			{   "GPIO17",  SUNXI_GPA(1),  11   },
			{   "GPIO27",  SUNXI_GPA(0),  13   },
			{   "GPIO22",  SUNXI_GPA(3),  15   },
			{   "GPIO10",  SUNXI_GPC(0),  19  },
			{   "GPIO9",  SUNXI_GPC(1),  21  },
			{   "GPIO11",  SUNXI_GPC(2),  23  },
			{   "GPIO28",  SUNXI_GPA(19),  27   },
			{   "GPIO5",  SUNXI_GPA(7),  29   },
			{   "GPIO6",  SUNXI_GPA(8),  31  },
			{   "GPIO13",  SUNXI_GPA(9),  33  },
			{   "GPIO19",  SUNXI_GPA(10),  35  },
			{   "GPIO26",  SUNXI_GPA(17),  37  },			
			//'second row'
			{   "GPIO14",  SUNXI_GPA(13),  8  },	
			{   "GPIO15",  SUNXI_GPA(14),  10  },
			{   "GPIO18",  SUNXI_GPA(16),  12  },
			{   "GPIO23",  SUNXI_GPA(15),  16  },
			{   "GPIO24",  SUNXI_GPC(4),  18  },
			{   "GPIO25",  SUNXI_GPA(2),  22  },
			{   "GPIO8",  SUNXI_GPC(3),  24  },
			{   "GPIO7",  SUNXI_GPC(7),  26   },
			{   "GPIO29",  SUNXI_GPA(18),  28  },
			{   "GPIO12",  SUNXI_GPL(2),  32  },
			{   "GPIO16",  SUNXI_GPL(4),  36  },
			{   "GPIO20",  SUNXI_GPA(21),  38  },
			{   "GPIO21",  SUNXI_GPA(20),  40  },
			
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
			{   "STATUS_LED",  SUNXI_GPA(17),  2   },
			{
				{   0,  0,  0}
			},
		}
	},
};

#endif