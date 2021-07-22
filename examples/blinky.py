import os, sys

if not os.getegid() == 0:
	sys.exit('start script as root')
	
from pyGPIO2.gpio import gpio, port
from time import sleep

gpio.init()
gpio.setcfg(port.GPIO4, 1)  #gpio4 as output

n = 0
while n < 5:
	gpio.output(port.GPIO4, 1)
	sleep(1)
	gpio.output(port.GPIO4, 0)
	sleep(1)
	n +=1

sys.exit('finished ;-)')
