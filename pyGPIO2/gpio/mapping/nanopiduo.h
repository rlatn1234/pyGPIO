/*
 *
 * This file is part of pyGPIO2.
 * mapping.h is python GPIO extension.
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
			        J1		  	 J2
(UART0_RX)		    |1| microUSB |1|	 5V	
(UART0_TX)		    |·|	 		 |·|	5V						
GND			        |·|	 		 |·|	3.3V
GPIO3 (TWI_SCL)		|·|			 |·|	GND	
GPIO2 (TWI_SDA)		|·|			 |·| 	GPIO4 (IR_RX)
GPIO23 (SPI1_CS)	|·|			 |·|	GPIO18 (IOG11)	
GPIO22 (SPI1_CLK)	|·|			 |·|	DM3 D-
GPIO27 (SPI1_MISO)	|·|			 |·|	DM3 D+
GPIO17 (SPI1_MOSI)	|·|			 |·|	DM2 D-	
GPIO15(UART1_RX)	|·|			 |·|	DM2 D+
GPIO14 (UART1_TX)	|·|			 |·|	RDN
(CVBS)			    |·|			 |·|	RDP	
(LINEOUT_L)		    |·|			 |·|	TXN
(LINEOUT_R)		    |·|			 |·|	TXP
(MICP)			    |·|			 |·|	LED-LINK
(MICN)			    |·|	microSD	 |·|	LED-SPD

*/  {"J1",
        {
            {   "GPIO3",  SUNXI_GPA(11),  4   },
            {   "GPIO2",  SUNXI_GPA(12),  5   },
            {   "GPIO23",  SUNXI_GPA(13),  6   },
            {   "GPIO22",  SUNXI_GPA(14),  7  },
            {   "GPIO27",  SUNXI_GPA(16),  8  },			
            {   "GPIO17",  SUNXI_GPA(15),  9  },
			{   "GPIO15",  SUNXI_GPG(6),  11  },
            {   "GPIO14",  SUNXI_GPG(7),  10  },
            {
                {   0,  0,  0}
            },
        }
    },
	{"J2",
        {
            {   "GPIO18",  SUNXI_GPL(11),  5   },            
			{   "GPIO4",  SUNXI_GPG(11),  6   },
            {
                {   0,  0,  0}
            },
        }
    },	

/*
    #define PIN_PG0		SUNXI_GPG(0)
*/  {"LED",
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
