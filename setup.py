from distutils.core import setup
from distutils.core import Extension
from distutils.command.build_ext import build_ext as _build_ext

import sys, shutil


supported_processors = ["sun6i", "sun7i", "sun8i", "Allwinner sun8i Family", "Allwinner sun6i (A31) Family" ]

try:
	input = raw_input
except NameError:
	pass

def print_green(text):
	"""
	Print text in yellow :)
	:param text: String to be colored
	:return: Colored text
	"""

	return '\033[0;32m' + text + '\033[0m'	

def print_yellow(text):
	"""
	Print text in yellow :)
	:param text: String to be colored
	:return: Colored text
	"""

	return '\033[0;33m' + text + '\033[0m'

def print_red(text):
	"""
	Print text in yellow :)
	:param text: String to be colored
	:return: Colored text
	"""

	return '\033[0;31m' + text + '\033[0m'

def print_warning_processor():
	"""
	Print confirmation dialog
	:return:
	"""
	print (print_yellow("Warning! ") + "Detected and target processor mismatch. ")


	var2 = input("Do you want to continue [Y/n]? ")
	if var2 == 'Y' or var2 == 'y':
		return
	else:
		print ("Abort.")
		sys.exit(1)

def print_warning_board():
	"""
	Print confirmation dialog
	:return:
	"""
	print (print_yellow("Warning! ") + "Detected and target boards mismatch.")

	var3 = input("Do you want to use the mapping of a supported boards [Y/n]? ")
	if var3 == 'Y' or var3 == 'y':
		shutil.copy2('pyGPIO2/gpio/mapping/micro.h', 'pyGPIO2/gpio/mapping.h')
		return
	else:
		print ("Abort.")
		sys.exit(1)

def print_correct():
	"""
	Print confirmation dialog
	:return:
	"""

	var4 = input("Correct? [Y/n] ")
	if var4 == 'Y' or var4 == 'y':
		return
	else:
		manual_board_assignment()

def manual_board_assignment():
	print ("Automatic board detection failed or your board is not supported (yet). \nYou can use a pin mapping from one of our supported boards or abort the \ninstallation. " + print_red("This is only recommended for experienced users! ") + "\nPin mapping might be " + print_red("false") + " and the library " + print_red("does not work") +" as expected!")
	print ("[1]  OrangePi Zero")
	print ("[2]  OrangePi Pc Plus")
	print ("[3]  OrangePi Plus 2E")
	print ("[4]  OrangePi Lite")
	print ("[5]  A20-OLinuXino-MICRO")
	print ("[6]  A20-OLinuXIno-LIME")
	print ("[7]  A20-OLinuXIno-LIME2")
	print ("[8]  NanoPi Duo")
	print ("[9]  NanoPi Neo")
	print ("[10] pcDuino3")
	print ("[11] BananaPi M2")
	print ("[12] BananaPi M2 Zero")
	print ("[13] Tritium")
	print ("[99] Abort")
	var5 = input("")
	
	if var5 == '1' or var5 == '[1]':
		shutil.copy2('pyGPIO2/gpio/mapping/orangepizero.h', 'pyGPIO2/gpio/mapping.h')
		return
		
	elif var5 == '2' or var5 == '[2]':
		shutil.copy2('pyGPIO2/gpio/mapping/orangepipcplus.h', 'pyGPIO2/gpio/mapping.h')
		return
	elif var5 == '3' or var5 == '[3]':
		shutil.copy2('pyGPIO2/gpio/mapping/orangepiplus2e.h', 'pyGPIO2/gpio/mapping.h')
		return
		
	elif var5 == '4' or var5 == '[4]':
		shutil.copy2('pyGPIO2/gpio/mapping/orangepilite.h', 'pyGPIO2/gpio/mapping.h')
		return
		
	elif var5 == '5' or var5 == '[5]':
		shutil.copy2('pyGPIO2/gpio/mapping/micro.h', 'pyGPIO2/gpio/mapping.h')
		return
		
	elif var5 == '6' or var5 == '[6]':
		shutil.copy2('pyGPIO2/gpio/mapping/lime.h', 'pyGPIO2/gpio/mapping.h')
		return
		
	elif var5 == '7' or var5 == '[7]':
		shutil.copy2('pyGPIO2/gpio/mapping/lime2.h', 'pyGPIO2/gpio/mapping.h')
		return
		
	elif var5 == '8' or var5 == '[8]':
		var6 = input("Do you want to use your NanoPi Duo with [1] or without minishield [2]\n(mapping & naming in connector mode is incorrect, no changes by using port)?)")
		if var6 == '2' or var6 == '[2]':				
			shutil.copy2('pyGPIO2/gpio/mapping/nanopiduo.h', 'pyGPIO2/gpio/mapping.h')
		elif var6 == '1' or var6 == '[1]':
			shutil.copy2('pyGPIO2/gpio/mapping/nanopiduo_minishield.h', 'pyGPIO2/gpio/mapping.h')
		else:
			print ("Abort.")
			sys.exit(1)
			
	elif var5 == '9' or var5 == '[9]':
		shutil.copy2('pyGPIO2/gpio/mapping/nanopiduo.h', 'pyGPIO2/gpio/mapping.h')
		return
		
	elif var5 == '10' or var5 == '[10]':
		shutil.copy2('pyGPIO2/gpio/mapping/pcduino3.h', 'pyGPIO2/gpio/mapping.h')
		return
    
	elif var5 == '11' or var5 == '[11]':
		shutil.copy2('pyGPIO2/gpio/mapping/bananapim2.h', 'pyGPIO2/gpio/mapping.h')
		return

	elif var5 == '12' or var5 == '[12]':
		shutil.copy2('pyGPIO2/gpio/mapping/bananapim2zero.h', 'pyGPIO2/gpio/mapping.h')
		return
	
	elif var5 == '13' or var5 == '[13]':
		shutil.copy2('pyGPIO2/gpio/mapping/tritium.h', 'pyGPIO2/gpio/mapping.h')
		return
	
	elif var5 == '99' or var5 == '[99]':
		print ("Abort.")
		sys.exit(1)
		
	else:
		print ("Abort.")
		sys.exit(1)
		
def print_annotation_olimex():
	print ("Pin naming differs from other boards when using port method!")

def check_processor():
	"""
	Detect processor type
	:return:
	"""
	cpuinfo = open("/proc/cpuinfo", 'r')
	for line in cpuinfo:
		if "Hardware" in line:
			processor = line.split(": ")[1].rstrip()

			if "sun4i" in processor:
				print ("Detected processor: " + print_yellow(processor) + " (Probably Allwinner A10)")

			elif "sun5i" in processor:
				print ("Detected processor: " + print_yellow(processor) + " (Probably Allwinner A13)")
            
			elif "sun6i" in processor:
				print ("Detected processor: " + print_yellow(processor) + " (Probably Allwinner A31s)")

			elif "sun7i" in processor:
				print ("Detected processor: " + print_yellow(processor) + " (Probably Allwinner A20)")

			elif "sun8i" in processor:
				print ("Detected processor: " + print_yellow(processor) + " (Probably Allwinner H2+/H3)")

			else:
				print ("Detected processor: " + print_yellow("unknown"))


			if processor not in supported_processors:
				print_warning_processor()

			return

	print ("No processor detected")
	print_warning_processor()

def check_board():
	"""
	Detect board type (added by chwe17)
	"""
	boardinfo = open("/etc/armbian-release", 'r')
	for line in boardinfo:
		if "BOARD" in line:
			board = line.split("=")[1].rstrip()
			#OrangePi Boards
			if "orangepizero" == board:
				print ("Detected board: " + print_green("OrangePi Zero"))
				print_correct()
				shutil.copy2('pyGPIO2/gpio/mapping/orangepizero.h', 'pyGPIO2/gpio/mapping.h')

			elif "orangepipcplus" == board:
				print ("Detected board: " + print_green("OrangePi Pc Plus"))
				print_correct()
				shutil.copy2('pyGPIO2/gpio/mapping/orangepipcplus.h', 'pyGPIO2/gpio/mapping.h')
				
			elif "orangepiplus2e" == board:
				print ("Detected board: " + print_green("OrangePi Plus 2E"))
				print_correct()
				shutil.copy2('pyGPIO2/gpio/mapping/orangepiplus2e.h', 'pyGPIO2/gpio/mapping.h')
				
			elif "orangepilite" == board:
				print ("Detected board: " + print_green("OrangePi Lite"))
				print_correct()
				shutil.copy2('pyGPIO2/gpio/mapping/orangepilite.h', 'pyGPIO2/gpio/mapping.h')

			#Olimex Boards
			elif "micro" == board:
				print ("Detected board: " + print_green("A20-OLinuXino-MICRO"))
				print_correct()
				shutil.copy2('pyGPIO2/gpio/mapping/micro.h', 'pyGPIO2/gpio/mapping.h')
				print_annotation_olimex()
				
			elif "lime" == board:
				print ("Detected board: " + print_green("A20-OLinuXIno-LIME"))
				print_correct()
				shutil.copy2('pyGPIO2/gpio/mapping/lime.h', 'pyGPIO2/gpio/mapping.h')
				print_annotation_olimex()

			elif "lime2" == board:
				print ("Detected board: " + print_green("A20-OLinuXIno-LIME2"))
				print_correct()
				shutil.copy2('pyGPIO2/gpio/mapping/lime2.h', 'pyGPIO2/gpio/mapping.h')
				print_annotation_olimex()

			#FriendlyArm Boards
			elif "nanopiduo" == board:
				print ("Detected board: " + print_green("NanoPi Duo"))
				print_correct()
				var6 = input("Do you want to use your NanoPi Duo with [1] ore without minishield [2]\n(mapping & naming in connector mode is incorrect, no changes by using port)?)")
				if var6 == '2' or var6 == '[2]':				
					shutil.copy2('pyGPIO2/gpio/mapping/nanopiduo.h', 'pyGPIO2/gpio/mapping.h')
				elif var6 == '1' or var6 == '[1]':
					shutil.copy2('pyGPIO2/gpio/mapping/nanopiduo_minishield.h', 'pyGPIO2/gpio/mapping.h')
				else:
					print ("Abort.")
					sys.exit(1)

			elif "nanopineo" == board:
				print ("Detected board: NanoPi Neo")
				print_correct()
				shutil.copy2('pyGPIO2/gpio/mapping/nanopineo.h', 'pyGPIO2/gpio/mapping.h')

			#LinkSprite Boards
			elif "pcduino3" == board:
				print ("Detected board: pcDuino3")
				print_correct()
				shutil.copy2('pyGPIO2/gpio/mapping/pcduino3.h', 'pyGPIO2/gpio/mapping.h')		
			
			#Sinovoip Boards
			elif "bananapim2" == board:
				print ("Detected board: " + print_green("Bananapi M2"))
				print_correct()
				shutil.copy2('pyGPIO2/gpio/mapping/bananapim2.h', 'pyGPIO2/gpio/mapping.h')

			elif "bananapim2zero" == board:
				print ("Detected board: " + print_green("Bananapi M2 Zero"))
				print_correct()
				shutil.copy2('pyGPIO2/gpio/mapping/bananapim2zero.h', 'pyGPIO2/gpio/mapping.h')

			#Libre Computer Boards
			elif board in ("tritium-h3", "tritium-h5"):
				print ("Detected board: " + print_green("Tritium"))
				print_correct()
				shutil.copy2('pyGPIO2/gpio/mapping/tritium.h', 'pyGPIO2/gpio/mapping.h')			
				
			else:
				print ("Unknown board")
				manual_board_assignment()
				

			return

	print ("Unknown Board")
	print_warning_board()


class build_ext(_build_ext):
	def run(self):
		check_processor()
		check_board()
		_build_ext.run(self)


modules = [
	Extension('pyGPIO2.gpio.gpio', sources=['pyGPIO2/gpio/gpio_lib.c', 'pyGPIO2/gpio/gpio.c']),
	Extension('pyGPIO2.i2c', sources=['pyGPIO2/i2c/i2c_lib.c', 'pyGPIO2/i2c/i2c.c']),
	Extension('pyGPIO2.spi', sources=['pyGPIO2/spi/spi_lib.c', 'pyGPIO2/spi/spi.c']),
	Extension('pyGPIO2.gpio.connector', sources=['pyGPIO2/gpio/connector/connector.c']),
	Extension('pyGPIO2.gpio.port', sources=['pyGPIO2/gpio/port/port.c']),

]

setup(
	name='pyGPIO2',
	version='0.2.2',
	author='Kim Su',
	author_email='qnrwhr01@gmail.com',
	url='https://github.com/rlatn1234/pyGPIO2',
	license='GPL',
	packages=['pyGPIO2', 'pyGPIO2.gpio'],
	description='Control GPIO, I2C and SPI',
	long_description=open('readme.md').read() + open('howtouse.md').read(),
	classifiers=['Development Status :: 3 - Alpha',
				'Environment :: Console',
				'Intended Audience :: Developers',
				'Intended Audience :: Education',
				'License :: OSI Approved :: GNU General Public License v3 (GPLv3)',
				'Operating System :: POSIX :: Linux',
				'Programming Language :: Python',
				'Topic :: Home Automation',
				'Topic :: Software Development :: Embedded Systems'
	],
	ext_modules=modules,
	cmdclass={'build_ext': build_ext}
)
