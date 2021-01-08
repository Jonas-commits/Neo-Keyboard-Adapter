// #include <usbhub.h>

#include "NeoReportParser.h"

USB     Usb;
//USBHub     Hub(&Usb);
HIDBoot<USB_HID_PROTOCOL_KEYBOARD>    HidKeyboard(&Usb);

NeoReportParser Prs;

void setup()
{
	BootKeyboard.begin();
	Consumer.begin();

	// Flash LED rapidly in case USB Shield could not be initialized
	if (Usb.Init() == -1) {
		while (true) {
			RXLED0;
			delay(100);
			RXLED1;
			delay(100);
		}
	}
	
	//The USB needs some time
	delay(200);

	HidKeyboard.SetReportParser(0, &Prs);
}

void loop()
{
  Usb.Task();
}
