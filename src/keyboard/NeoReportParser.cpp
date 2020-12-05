#include "NeoReportParser.h"

NeoReportParser::NeoReportParser(){
	KeyboardReportParser();
	neoModifiers.bmLeftCtrl = false;
	neoModifiers.bmLeftShift = false;
	neoModifiers.bmLeftAlt = false;
	neoModifiers.bmLeftGUI = false;
	neoModifiers.bmRightCtrl = false;
	neoModifiers.bmRightShift = false;
	neoModifiers.bmRightAlt = false;
	neoModifiers.bmRightGUI = false;
	neoModifiers.bmLeft3 = false;
	neoModifiers.bmRight3 = false;
	neoModifiers.bmLeft4 = false;
}

void NeoReportParser::OnKeyDown(uint8_t mod, uint8_t key)
{	
	Keyboard.press(KeyboardKeycode(key));
}

void NeoReportParser::OnKeyUp(uint8_t mod, uint8_t key)
{
	Keyboard.release(KeyboardKeycode(key));
}

void NeoReportParser::OnControlKeysChanged(uint8_t before, uint8_t after) {


	MODIFIERKEYS beforeMod;
	*((uint8_t*)&beforeMod) = before;

	MODIFIERKEYS afterMod;
	*((uint8_t*)&afterMod) = after;

	if (beforeMod.bmLeftCtrl != afterMod.bmLeftCtrl) {
		neoModifiers.bmLeftCtrl = !neoModifiers.bmLeftCtrl;
	}
	if (beforeMod.bmLeftShift != afterMod.bmLeftShift) {
		neoModifiers.bmLeftCtrl = !neoModifiers.bmLeftShift;
	}
	if (beforeMod.bmLeftAlt != afterMod.bmLeftAlt) {
		neoModifiers.bmLeftCtrl = !neoModifiers.bmLeftAlt;
	}
	if (beforeMod.bmLeftGUI != afterMod.bmLeftGUI) {
		neoModifiers.bmLeftCtrl = !neoModifiers.bmLeftGUI;
	}

	if (beforeMod.bmRightCtrl != afterMod.bmRightCtrl) {
		neoModifiers.bmLeftCtrl = !neoModifiers.bmRightCtrl;
	}
	if (beforeMod.bmRightShift != afterMod.bmRightShift) {
		neoModifiers.bmLeftCtrl = !neoModifiers.bmRightShift;
	}
	if (beforeMod.bmRightAlt != afterMod.bmRightAlt) {
		neoModifiers.bmLeftCtrl = !neoModifiers.bmRightAlt;
	}
	if (beforeMod.bmRightGUI != afterMod.bmRightGUI) {
		neoModifiers.bmLeftCtrl = !neoModifiers.bmRightGUI;
	}
}

