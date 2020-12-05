#include "NeoReportParser.h"

void NeoReportParser::PrintKey(uint8_t m, uint8_t key)
{
	MODIFIERKEYS mod;
	*((uint8_t*)&mod) = m;
	Serial.print((mod.bmLeftCtrl   == 1) ? "C" : " ");
	Serial.print((mod.bmLeftShift  == 1) ? "S" : " ");
	Serial.print((mod.bmLeftAlt    == 1) ? "A" : " ");
	Serial.print((mod.bmLeftGUI    == 1) ? "G" : " ");

	Serial.print(" >");
	//PrintHex<uint8_t>(key, 0x80);
	Serial.print(key, HEX);
	Serial.print("< ");

	Serial.print((mod.bmRightCtrl   == 1) ? "C" : " ");
	Serial.print((mod.bmRightShift  == 1) ? "S" : " ");
	Serial.print((mod.bmRightAlt    == 1) ? "A" : " ");
	Serial.println((mod.bmRightGUI    == 1) ? "G" : " ");
};

void NeoReportParser::OnKeyDown(uint8_t mod, uint8_t key)
{
	Keyboard.press(KeyboardKeycode(key));
	Serial.print("DN ");
	PrintKey(mod, key);
}

void NeoReportParser::OnControlKeysChanged(uint8_t before, uint8_t after) {

	MODIFIERKEYS beforeMod;
	*((uint8_t*)&beforeMod) = before;

	MODIFIERKEYS afterMod;
	*((uint8_t*)&afterMod) = after;

	if (beforeMod.bmLeftCtrl != afterMod.bmLeftCtrl) {
		Serial.println("LeftCtrl changed");
	}
	if (beforeMod.bmLeftShift != afterMod.bmLeftShift) {
		Serial.println("LeftShift changed");
	}
	if (beforeMod.bmLeftAlt != afterMod.bmLeftAlt) {
		Serial.println("LeftAlt changed");
	}
	if (beforeMod.bmLeftGUI != afterMod.bmLeftGUI) {
		Serial.println("LeftGUI changed");
	}

	if (beforeMod.bmRightCtrl != afterMod.bmRightCtrl) {
		Serial.println("RightCtrl changed");
	}
	if (beforeMod.bmRightShift != afterMod.bmRightShift) {
		Serial.println("RightShift changed");
	}
	if (beforeMod.bmRightAlt != afterMod.bmRightAlt) {
		Serial.println("RightAlt changed");
	}
	if (beforeMod.bmRightGUI != afterMod.bmRightGUI) {
		Serial.println("RightGUI changed");
	}

}

void NeoReportParser::OnKeyUp(uint8_t mod, uint8_t key)
{
	Keyboard.release(KeyboardKeycode(key));
	Serial.print("UP ");
	PrintKey(mod, key);
}