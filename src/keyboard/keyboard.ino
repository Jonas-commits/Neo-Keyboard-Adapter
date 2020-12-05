// #include <usbhub.h>
#define NEO_DEBUG

#include "NeoReportParser.h"

USB     Usb;
//USBHub     Hub(&Usb);
HIDBoot<USB_HID_PROTOCOL_KEYBOARD>    HidKeyboard(&Usb);

NeoReportParser Prs;

void setup()
{
#ifdef NEO_DEBUG
	Serial.begin(115200);
	Serial.println("Started Keyboard");
#endif
	Keyboard.begin();


	if (Usb.Init() == -1){
#ifdef NEO_DEBUG
		Serial.println("OSC did not start.");
#endif
	}

	delay(200);

	HidKeyboard.SetReportParser(0, &Prs);
}

void loop()
{
  Usb.Task();
}
