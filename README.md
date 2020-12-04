# Neo Layout Hardware Adatper

## Required Hardware
* Arduino Pro Micro 3.3V (**not 5V**) [Ebay](https://www.ebay.de/itm/Eckstein-Pro-micro-3-3V-8MHz-Arduino-mini-Leonardo-compatible-board-QITA/353159955592?epid=2235734612&hash=item5239f94488:g:0tsAAOSwVgdfpTbY)
* Arduino Micro Host Shield [Ebay](https://www.ebay.de/itm/Mini-USB-Host-Shield-Support-Google-ADK-Android-For-Arduino-UNO-MEGA-Duemilanove/264728254334?ssPageName=STRK%3AMEBIDX%3AIT&_trksid=p2060353.m2749.l2649)
	
## Setup Hardware

### Arduino Pro Micro:
* Download Arduino IDE https://www.arduino.cc/en/software
* **Do not** attempt to flash a sketch by selecting the "Arduino Pro Micro" in the List. It will work, but soft-brick the device for further programming.
* Download Additional Bootloader for 3.3V/8Mhz Variant at Sparkfun https://codeload.github.com/sparkfun/SF32u4_boards/zip/master
* Copy Bootloader SF32u4_boards-master.zipiSF32u4_boards-master/sparkfun/avr/bootloaders/caterina/Caterina-promicro8.hex to *Arduino-Install-dir*/hardware/arduino/avr/bootloaders/caterina
* Edit *Arduino-Install-dir*/hardware/arduino/avr/boards.txt by adding the contents from [hardware/boards.txt](hardware/boards.txt)
* Sketches can now be uploaded by selecting the respective COM-Port and selecting the device "Arduino Pro Mirco 3.3V"
	
### Mirco Usb Host Shield:
* USB runs with 5V, but the board is 3.3V only and therefore has a design flaw and has to be fixed
* Furthermore the reset pin of the shield (**Not** the reset pin of the Arduino) has to be connected to 3.3V. Unfortunately this pin is GND in Arduino, so we cannot just set the Pin to HIGH. I went straight after following setup: https://geekhack.org/index.php?topic=80421.0
	
### Software 
* The USB Host Shield Library has to be installed in the Arduino Library Manager
* After uploading the [example] https://github.com/felis/USB_Host_Shield_2.0/blob/master/examples/HID/USBHIDBootKbd/USBHIDBootKbd.ino to the board I can see the board working in the serial port monitor. 
* I did not fully understand how you need to plug it in to make it work, my guess is, first arduino to PC, then open port monitor, then plug in keyboard. Have to be worked out in more detail. 
	
