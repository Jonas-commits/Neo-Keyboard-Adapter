#include "NeoReportParser.h"

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
		if (neoModifiers.bmLeftCtrl) {
			OnKeyUp(after, KEY_LEFT_CTRL);
			neoModifiers.bmLeftCtrl = false;
		} else {
			OnKeyDown(after, KEY_LEFT_CTRL);
			neoModifiers.bmLeftCtrl = true;
		}
	}
	
	if (beforeMod.bmLeftShift != afterMod.bmLeftShift) {
		if (neoModifiers.bmLeftShift) {
			OnKeyUp(after, KEY_LEFT_SHIFT);
			neoModifiers.bmLeftShift = false;
		} else {
			OnKeyDown(after, KEY_LEFT_SHIFT);
			neoModifiers.bmLeftShift = true;
		}
	}
	
	if (beforeMod.bmLeftAlt != afterMod.bmLeftAlt) {
		if (neoModifiers.bmLeftAlt) {
			OnKeyUp(after, KEY_LEFT_ALT);
			neoModifiers.bmLeftAlt = false;
		} else {
			OnKeyDown(after, KEY_LEFT_ALT);
			neoModifiers.bmLeftAlt = true;
		}
		
	}
	
	if (beforeMod.bmLeftGUI != afterMod.bmLeftGUI) {
		if (neoModifiers.bmLeftGUI) {
			OnKeyUp(after, KEY_LEFT_GUI);
			neoModifiers.bmLeftGUI = false;
		} else {
			OnKeyDown(after, KEY_LEFT_GUI);
			neoModifiers.bmLeftGUI = true;
		}
	}

	if (beforeMod.bmRightCtrl != afterMod.bmRightCtrl) {
		if (neoModifiers.bmRightCtrl) {
			OnKeyUp(after, KEY_RIGHT_CTRL);
			neoModifiers.bmRightCtrl = false;
		} else {
			OnKeyDown(after, KEY_RIGHT_CTRL);
			neoModifiers.bmRightCtrl = true;
		}
	}
	
	if (beforeMod.bmRightShift != afterMod.bmRightShift) {
		if (neoModifiers.bmRightShift) {
			OnKeyUp(after, KEY_RIGHT_SHIFT);
			neoModifiers.bmRightShift = false;
		} else {
			OnKeyDown(after, KEY_RIGHT_SHIFT);
			neoModifiers.bmRightShift = true;
		}
	}
	
	if (beforeMod.bmRightAlt != afterMod.bmRightAlt) {
		if (neoModifiers.bmRightAlt) {
			OnKeyUp(after, KEY_RIGHT_ALT);
			neoModifiers.bmRightAlt = false;
		} else {
			OnKeyDown(after, KEY_RIGHT_ALT);
			neoModifiers.bmRightAlt = true;
		}
	}
	
	if (beforeMod.bmRightGUI != afterMod.bmRightGUI) {
		if (neoModifiers.bmRightGUI) {
			OnKeyUp(after, KEY_RIGHT_GUI);
			neoModifiers.bmRightGUI = false;
		} else {
			OnKeyDown(after, KEY_RIGHT_GUI);
			neoModifiers.bmRightGUI = true;
		}
		
	}
}

