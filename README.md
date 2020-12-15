# Neo Layout Hardware Adapter
This project implements a hardware driver for the [Neo-Layout](https://neo-layout.org/). It works by using an Arduino Mirco. The Arduino registers as BootKeyboard Human Interface Device to the Host using the [HID-Project Library](https://github.com/NicoHood/HID) on the one side. On the other side, we attach a USB Host Shield to the Arduino to make it act as a USB Host for a BootKeyboard itself, using the BootKeyboard Library from the [USB Host Shield Project](https://github.com/felis/USB_Host_Shield_2.0/). Then we run the inputs through a transformation Matrix to map it to the according to Input on the normal German Keyboard layout.

Why all this? For Linux, the Linux build-in Layout works well what I can tell from my experience, but for Windows, there are countless issues with both the software drives. One reason being additional modifiers added and lock Keys (Num-lock, CAPS-Lock) having a non-standard implementation. That confuses windows, so we have not always the behavior we want in all apps. Key-Combinations do not work and Remote-Desktop applications and Screen sharing behave differently every time. With this hardware solution, our layout stays transparent for Windows and when we press Mod3-J, we just send Shift-8 to the host for an open left bracket. No application will ever know we modified our layout. Especially with desktop sharing and VPN connections, that puts a lot of relief in productional use. You can even have two keyboards connected to the PC, where you are using neo-layout and the other person is using the german layout (not sure if this is real use case)

This project can also be modified for other Keyboard-transforming applications, like passing through everything, but playing macro sequences for some key-presses or having any layout you want.

## Setup Project
### Setup Hardware
* Arduino Pro Micro 3.3V (**not 5V**) [Ebay](https://www.ebay.de/itm/Eckstein-Pro-micro-3-3V-8MHz-Arduino-mini-Leonardo-compatible-board-QITA/353159955592?epid=2235734612&hash=item5239f94488:g:0tsAAOSwVgdfpTbY)
* Arduino Micro Host Shield [Ebay](https://www.ebay.de/itm/Mini-USB-Host-Shield-Support-Google-ADK-Android-For-Arduino-UNO-MEGA-Duemilanove/264728254334?ssPageName=STRK%3AMEBIDX%3AIT&_trksid=p2060353.m2749.l2649)

### Arduino Pro Micro:
* Download Arduino IDE https://www.arduino.cc/en/software
* **Do not** attempt to flash a sketch by selecting the "Arduino Pro Micro" in the List. It will work, but soft-brick the device for further programming.
* Download Additional Bootloader for 3.3V/8Mhz Variant at Sparkfun https://codeload.github.com/sparkfun/SF32u4_boards/zip/master
* Copy Bootloader SF32u4_boards-master.zip/SF32u4_boards-master/sparkfun/avr/bootloaders/caterina/Caterina-promicro8.hex to *Arduino-Install-dir*/hardware/arduino/avr/bootloaders/caterina
* Edit *Arduino-Install-dir*/hardware/arduino/avr/boards.txt by adding the contents from [hardware/boards.txt](hardware/boards.txt)
* Sketches can now be uploaded by selecting the respective COM-Port and selecting the device "Arduino Pro Mirco 3.3V"
	
### Mirco USB Host Shield:
* USB runs with 5V, but the board is 3.3V only and therefore has a design flaw and has to be fixed
* Furthermore, the reset pin of the shield (**Not** the reset pin of the Arduino) has to be connected to 3.3V. Unfortunately, this pin is GND in Arduino, so we cannot just set the Pin to HIGH. I went straight after following setup: https://geekhack.org/index.php?topic=80421.0
	
### Software 
* The USB Host Shield Library has to be installed in the Arduino Library Manager
* The HID-Project Library has to be installed in the Arduino Library Manager, standard Keyboard Library is insufficient.
* After uploading the [example](https://github.com/felis/USB_Host_Shield_2.0/blob/master/examples/HID/USBHIDBootKbd/USBHIDBootKbd.ino) to the board I can see the board working in the serial port monitor. 

## Controlling the driver
The Left Windows-Key is configured to interact with the driver. Following (under windows anyhow unused combinations) are therefore used to interact with the driver and are not passed to the Host-PC. To reach this behavior, the left Windows-Key behaves differently in that way. Therefore it does not appear in a pressed-State to the Host before another non-used combination is pressed or the Key is released without pressing a key. In practical use, you will not notice this difference. Please note, that only the left Windows-Key is configured for this use, not the right one. The settings are not stored to EEPROM and therefore reset after each power-reset from the Arduino. This behavior is intended.

### Combinations:
#### Toggle Mapping:

* **WIN + F12**: Toggle between Neo-Mapping and transparent pass-through mode. (Default: Neo-Layout)

#### Toggle Unicode Input:

* **WIN + F9**: Unicode will be entered in decimal for Windows. (Default)
* **WIN + F10**: Unicode will be entered in hexadecimal for Windows. (Requires setup)
* **WIN + SHIFT + F10**: The registry entry for hexadecimal input in Windows is created. (Requires reboot)
* **WIN + F11**: Unicode will be entered in hexadecimal for Linux.

General note for Unicode on Windows: The decimal method only works in some apps (mainly MS Office) for all Unicode characters. For non-supported apps, only some of the Unicode Keys work. Hexadecimal setup does not require admin rights, but a reboot. It works with most apps, but apparently not with those where the decimal input is fully supported. So you have to toggle the Unicode method in respective to the app you are using. Linux is according to the specification I found, but untested. 

## Open issues (worked on):
* Making the LEDs light on the Keyboard does not work (reading in the state and acting according to it works though)
* only basic dead-key support and no compose
* Mod4-Lock not supported yet.
* Media-Keys not supported

## General issues:
* No universal working in all applications Unicode input method which does not require additional software available for windows.
