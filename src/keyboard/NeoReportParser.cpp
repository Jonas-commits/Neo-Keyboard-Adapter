#include "NeoReportParser.h"

 const uint8_t NeoReportParser::neoMap[] = {
	 KEY_RESERVED, KEY_ERROR_ROLLOVER, KEY_POST_FAIL, KEY_ERROR_UNDEFINED, KEY_U, KEY_Y, KEY_QUOTE, KEY_A,
	 KEY_L, KEY_E, KEY_O, KEY_S, KEY_G, KEY_N, KEY_R, KEY_T,
	 KEY_M, KEY_B, KEY_F, KEY_Q, KEY_X, KEY_C, KEY_I, KEY_W,
	 KEY_H, KEY_P, KEY_V, KEY_SEMICOLON, KEY_K, KEY_LEFT_BRACE, KEY_1, KEY_2,
	 KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_0,
	 KEY_ENTER, KEY_ESC, KEY_BACKSPACE, KEY_TAB, KEY_SPACE, KEY_SLASH, KEY_RIGHT_BRACE, KEY_MINUS,
	 KEY_EQUAL, KEY_BACKSLASH, KEY_NON_US_NUM, KEY_D, KEY_Z, KEY_TILDE, KEY_COMMA, KEY_PERIOD,
	 KEY_J, KEY_CAPS_LOCK, KEY_F1, KEY_F2, KEY_F3, KEY_F4, KEY_F5, KEY_F6,
	 KEY_F7, KEY_F8, KEY_F9, KEY_F10, KEY_F11, KEY_F12, KEY_PRINTSCREEN, KEY_SCROLL_LOCK,
	 KEY_PAUSE, KEY_INSERT, KEY_HOME, KEY_PAGE_UP, KEY_DELETE, KEY_END, KEY_PAGE_DOWN, KEY_RIGHT,
	 KEY_LEFT, KEY_DOWN, KEY_UP, KEY_TAB, KEYPAD_DIVIDE, KEYPAD_MULTIPLY, KEYPAD_SUBTRACT, KEYPAD_ADD,
	 KEYPAD_ENTER, KEYPAD_1, KEYPAD_2, KEYPAD_3, KEYPAD_4, KEYPAD_5, KEYPAD_6, KEYPAD_7,
	 KEYPAD_8, KEYPAD_9, KEYPAD_0, KEYPAD_DOT
 };

void NeoReportParser::OnKeyDown(uint8_t mod, uint8_t key) {
	if (applyMap && key < NEO_MAP_SIZE + 1){ //act like neo keyboard
		
		switch (key){ //handle neo-only-modifiers, others are handled in OnControlKeysChanged already
			case KEY_CAPS_LOCK:
				neoModifiers.bmLeft3 = true;
				break;
			
			case KEY_BACKSLASH:
			case KEY_NON_US_NUM:
				neoModifiers.bmRight3 = true;
				break;
				
			case KEY_NON_US:
				neoModifiers.bmLeft4 = true;
				break;
			
			default:
				if (neoModifiers.bmLeftShift || neoModifiers.bmRightShift) {
					if (neoModifiers.bmLeft3 || neoModifiers.bmRight3) { //layer 5
						
					} else { // layer 2
						if ( 
							key <= KEY_Z || KEY_ENTER <= key <= KEY_SPACE || key == KEY_SEMICOLON || key == KEY_QUOTE
							|| neoModifiers.bmLeftCtrl || neoModifiers.bmRightCtrl
							|| neoModifiers.bmLeftGUI || neoModifiers.bmRightGUI || neoModifiers.bmLeftAlt
						) {
							Keyboard.press(KeyboardKeycode(neoMap[key]));
							
						} else {
							
						}
					}
				
				} else if (neoModifiers.bmLeft3 || neoModifiers.bmRight3) {
					if (neoModifiers.bmLeft4 || neoModifiers.bmRightAlt) { // layer 6
						
					} else { // layer 3
						
					}
					
				} else if (neoModifiers.bmLeft4 || neoModifiers.bmRightAlt) { // layer 4
				
				} else { // layer 1
					if (key != KEY_RIGHT_BRACE) { //only key not fitting in layer1
						Keyboard.press(KeyboardKeycode(neoMap[key]));
					} else {
						
					}
				}
		}
		
	} else { //act like a normal keyboard
		Keyboard.press(KeyboardKeycode(key));
	}
}

void NeoReportParser::OnKeyUp(uint8_t mod, uint8_t key) {
	if (applyMap && key < NEO_MAP_SIZE + 1) { //act like neo keyboard
		
		switch (key){ //handle neo-only-modifiers, others are handled in OnControlKeysChanged already
			case KEY_CAPS_LOCK:
				neoModifiers.bmLeft3 = false;
				break;
			
			case KEY_BACKSLASH:
			case KEY_NON_US_NUM:
				neoModifiers.bmRight3 = false;
				break;
			
			case KEY_NON_US:
				neoModifiers.bmLeft4 = false;
				break;
			
			default:
				Keyboard.release(KeyboardKeycode(neoMap[key]));
		}
	} else { //act like a normal keyboard
		Keyboard.release(KeyboardKeycode(key));
	}
}

void NeoReportParser::OnControlKeysChanged(uint8_t before, uint8_t after) {


	MODIFIERKEYS beforeMod;
	*((uint8_t*)&beforeMod) = before;

	MODIFIERKEYS afterMod;
	*((uint8_t*)&afterMod) = after;

	if (beforeMod.bmLeftCtrl != afterMod.bmLeftCtrl) {
		if (neoModifiers.bmLeftCtrl) {
			OnKeyUp(before, KEY_LEFT_CTRL);
			neoModifiers.bmLeftCtrl = false;
		} else {
			OnKeyDown(after, KEY_LEFT_CTRL);
			neoModifiers.bmLeftCtrl = true;
		}
	}
	
	if (beforeMod.bmLeftShift != afterMod.bmLeftShift) {
		if (neoModifiers.bmLeftShift) {
			OnKeyUp(before, KEY_LEFT_SHIFT);
			neoModifiers.bmLeftShift = false;
		} else {
			OnKeyDown(after, KEY_LEFT_SHIFT);
			neoModifiers.bmLeftShift = true;
		}
	}
	
	if (beforeMod.bmLeftAlt != afterMod.bmLeftAlt) {
		if (neoModifiers.bmLeftAlt) {
			OnKeyUp(before, KEY_LEFT_ALT);
			neoModifiers.bmLeftAlt = false;
		} else {
			OnKeyDown(after, KEY_LEFT_ALT);
			neoModifiers.bmLeftAlt = true;
		}
		
	}
	
	if (beforeMod.bmLeftGUI != afterMod.bmLeftGUI) {
		if (neoModifiers.bmLeftGUI) {
			OnKeyUp(before, KEY_LEFT_GUI);
			neoModifiers.bmLeftGUI = false;
		} else {
			OnKeyDown(after, KEY_LEFT_GUI);
			neoModifiers.bmLeftGUI = true;
		}
	}

	if (beforeMod.bmRightCtrl != afterMod.bmRightCtrl) {
		if (neoModifiers.bmRightCtrl) {
			OnKeyUp(before, KEY_RIGHT_CTRL);
			neoModifiers.bmRightCtrl = false;
		} else {
			OnKeyDown(after, KEY_RIGHT_CTRL);
			neoModifiers.bmRightCtrl = true;
		}
	}
	
	if (beforeMod.bmRightShift != afterMod.bmRightShift) {
		if (neoModifiers.bmRightShift) {
			OnKeyUp(before, KEY_RIGHT_SHIFT);
			neoModifiers.bmRightShift = false;
		} else {
			OnKeyDown(after, KEY_RIGHT_SHIFT);
			neoModifiers.bmRightShift = true;
		}
	}
	
	if (beforeMod.bmRightAlt != afterMod.bmRightAlt) {
		if (neoModifiers.bmRightAlt) {
			OnKeyUp(before, KEY_RIGHT_ALT);
			neoModifiers.bmRightAlt = false;
		} else {
			OnKeyDown(after, KEY_RIGHT_ALT);
			neoModifiers.bmRightAlt = true;
		}
	}
	
	if (beforeMod.bmRightGUI != afterMod.bmRightGUI) {
		if (neoModifiers.bmRightGUI) {
			OnKeyUp(before, KEY_RIGHT_GUI);
			neoModifiers.bmRightGUI = false;
		} else {
			OnKeyDown(after, KEY_RIGHT_GUI);
			neoModifiers.bmRightGUI = true;
		}
		
	}
}

