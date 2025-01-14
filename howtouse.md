GPIO METHODS
============

    init()      -   Make initialization of the module. Always must be called first.
    getcfg()    -   Read current configuration of gpio.
    setcfg()    -   Write configuration to gpio.
    input()     -   Return current value of gpio.
    output()    -   Set output value.
    pullup()    -   Set pull-up/pull-down.


The available constants are:

    NAME        -   EQUALS TO
    ====            =========
    HIGH        ->      1
    LOW         ->      0
    INPUT       ->      0
    OUPTUT      ->      1
    PULLUP      ->      1
    PULLDOWN    ->      2


The gpio are named two ways:

    By port name: GPIOX, GPIOY, GPIOZ, etc.
    These can be imported from port module:

    >>> from pyGPIO2.gpio import port
    >>> dir(port)

    By connector name and pin number: gpio2p12, gpio3p8, lcdp18, uext1p3 and etc.
    These can be imported from connector module:

    >>> from pyGPIO2.gpio import connector
    >>> dir(connector)

Generally these constants are just an offset in the memory from the base GPIO address, so they can
be assigned to a number type variable.

    >>> led = port.GPIOX
    >>> print led
    226



I2C METHODS
===========

    init()      -   Make initialization of the module
    open()      -   Begin communication with slave device
    read()      -   Read from slave device
    write()     -   Write data to slave device
    close()     -   End communication with slave device


SPI METHODS
===========

    open()      -   Open SPI bus with given configuration
    read()      -   Read data from slave device without write
    write()     -   Write data to slave device without read
    xfer()      -   Do write and after that read
    close()     -   Close SPI bus



Examples
========

GPIO::

    #!/usr/bin/env python

    from pyGPIO2.gpio import gpio
    from pyGPIO2.gpio import port
    from pyGPIO2.gpio import connector

    gpio.init() #Initialize module. Always called first

    gpio.setcfg(port.GPIOX, gpio.OUTPUT)  #Configure LED1 as output
    gpio.setcfg(port.GPIOX, 1)    #This is the same as above

    gpio.setcfg(port.GPIOY, gpio.INPUT)   #Configure GPIOY as input
    gpio.setcfg(port.GPIOY, 0)   #Same as above

    gpio.pullup(port.GPIOY, 0)   #Clear pullups
    gpio.pullup(port.GPIOY, gpio.PULLDOWN)    #Enable pull-down
    gpio.pullup(port.GPIOY, gpio.PULLUP)  #Enable pull-up

    while True:
        if gpio.input(port.GPIOY) == 1:
            gpio.output(port.GPIOX, gpio.LOW)
            gpio.output(port.GPIOX, 0)
        else:
            gpio.output(port.GPIOX, gpio.HIGH)
            gpio.output(port.GPIOX, 1)


I2C::

    #!/usr/bin/env python

    from pyGPIO2 import i2c

    i2c.init("/dev/i2c-2")  #Initialize module to use /dev/i2c-2
    i2c.open(0x55)  #The slave device address is 0x55

    #If we want to write to some register
    i2c.write([0xAA, 0x20]) #Write 0x20 to register 0xAA
    i2c.write([0xAA, 0x10, 0x11, 0x12]) #Do continuous write with start address 0xAA

    #If we want to do write and read
    i2c.write([0xAA])   #Set address at 0xAA register
    value = i2c.read(1) #Read 1 byte with start address 0xAA

    i2c.close() #End communication with slave device


SPI::

    #!/usr/bin/env python

    from pyGPIO2 import spi

    spi.open("/dev/spidev2.0")
    #Open SPI device with default settings
    # mode : 0
    # speed : 100000kHz
    # delay : 0
    # bits-per-word: 8

    #Different ways to open device
    spi.open("/dev/spidev2.0", mode=1)
    spi.open("/dev/spidev2.0", mode=2, delay=0)
    spi.open("/dev/spidev2.0", mode=3, delay=0, bits_per_word=8)
    spi.open("/dev/spidev2.0", mode=0, delay=0, bits_per_word=8, speed=100000)

    spi.write([0x01, 0x02]) #Write 2 bytes to slave device
    spi.read(2) #Read 2 bytes from slave device
    spi.xfer([0x01, 0x02], 2)   #Write 2 byte and then read 2 bytes.

    spi.close() #Close SPI bus


It's important that you run your python script as root!
    

    
