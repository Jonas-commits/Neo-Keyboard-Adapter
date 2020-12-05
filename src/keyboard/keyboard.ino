// #include <usbhub.h>
// #define DEBUG_NEO 1

#include "NeoReportParser.h"

USB     Usb;
//USBHub     Hub(&Usb);
HIDBoot<USB_HID_PROTOCOL_KEYBOARD>    HidKeyboard(&Usb);

NeoReportParser Prs;

void setup()
{
#ifdef DEBUG_NEO
	Serial.begin(115200);
	Serial.println("Start");
#endif
	Keyboard.begin();


	if (Usb.Init() == -1){
#ifdef DEBUG_NEO
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
