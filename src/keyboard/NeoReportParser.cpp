#include "NeoReportParser.h"


void NeoReportParser::OnKeyDown(uint8_t mod, uint8_t key) {

	//Use left windows key to change behavior of our driver
	if (neoModifiers.bmLeftGUI) {
		leftGuiSinglePress = false; //Host will never know we pressed something :)
		
		switch (key){
			case KEY_F1:
				help();
				return;
			
			case KEY_F9:
				unicodeMethod = WIN_DEC;
				return;
				
			case KEY_F10:
				if (neoModifiers.bmLeftShift) {
					install();
				} else {
					unicodeMethod = WIN_HEX;
				}
				return;
				
			case KEY_F11:
				unicodeMethod = UNIX_HEX;
				return;
				
			case KEY_F12:
				applyMap = !applyMap;
				return;
				
			default:
				Keyboard.press(KeyboardKeycode(KEY_LEFT_GUI));
		}
	}
	
	if (applyMap && key < NEO_MAP_SIZE + 1){ //act like neo keyboard
		
		//Never let go of num lock :)
		if(!kbdLockingKeys.kbdLeds.bmNumLock){
			Keyboard.write(KeyboardKeycode(KEY_NUM_LOCK));
		}

		//in case of neo modifier pressed we have to handle it and can spare the rest of the code
		if(neoModifierChange(key, true)){
			return;
		}
		
		Layer layer = getActiveLayer();
		
		if (composeState){
			if (key == KEY_ESC){
				compose.reset();
				composeState = false;
			} else {
				uint16_t result  = compose.transition(layer, key);
				if(result == 0){
					composeState = false;
					
				} else if (result > 1) { //result == 1: just remain, nothing to do
					// we got a result
					pressUnicode(result);
					composeState = false;
				}
			}
		
		}  else if(layer == L3 && key == KEY_TAB || key == KEY_RIGHT_BRACE || 
				key == KEY_TILDE || key == KEY_EQUAL){  //is compose key
			composeState = true;
			compose.transition(layer, key);
		
		} else {
			// map action according the current layer active, indicated by modifier states
			switch (layer) {
				InputSequence sq;
				case L1:
					if (key != KEY_EQUAL) { //only key not fitting in layer1
						Keyboard.press(KeyboardKeycode(keyboardMap->getL1()[key]));
					} else { //dead code as long as Base Compose Module is used
						sq = {KEY_LEFT_SHIFT, KEY_EQUAL};
						substitutePress(sq);
					}
					break;
					
				case L2:
					if (key <= KEY_Z || (KEY_ENTER <= key && key <= KEY_SPACE) ||
								(KEY_BACKSLASH <= key && key <= KEY_QUOTE) || (KEY_SLASH <= key && key <= KEYPAD_ENTER)
								|| neoModifiers.bmLeftCtrl || neoModifiers.bmRightCtrl
								|| neoModifiers.bmLeftGUI || neoModifiers.bmRightGUI || neoModifiers.bmLeftAlt) {
							
						Keyboard.press(KeyboardKeycode(keyboardMap->getL1()[key]));
							
					} else {
						substitutePress(const_cast<InputSequence*>(keyboardMap->getL2()), key - KEY_Z - 1);
					}
					break;
					
				case L3:
						substitutePress(const_cast<InputSequence*>(keyboardMap->getL3()), key);
					break;
					
				case L4:
					substitutePress(const_cast<InputSequence*>(keyboardMap->getL4()), key);
					break;
				
				case L4_SHIFT:
					{
						memcpy_P(&sq, (keyboardMap->getL4() + key), sizeof(sq));
						
						uint8_t shift_bit = keyboardMap->getL4Shift()[key / 8u] & (uint8_t) (1u << ( 7u - ( key % 8u ))) ;
						if (shift_bit > 0) {
							sq.modifier = KEY_LEFT_SHIFT;
						}
						substitutePress(sq);
					}
					break;
					
				case L5:
					substitutePress(const_cast<uint16_t*>(keyboardMap->getL5()), key);
					break;
					
				case L6:
					substitutePress(const_cast<uint16_t*>(keyboardMap->getL6()), key);
					break;
			}
		}

	} else { //act like a normal keyboard
		Keyboard.press(KeyboardKeycode(key));
	}
		
}

void NeoReportParser::OnKeyUp(uint8_t mod, uint8_t key) {
	if (key == KEY_ESC) { //panic button in case something hangs up :)
		Keyboard.releaseAll();
		Consumer.releaseAll();
		activeConsumerSequence = false;
		activeSequence = {0, 0};
	
	} else if (applyMap && key < NEO_MAP_SIZE + 1) { //act like neo keyboard
		
		if(neoModifierChange(key, false)){
			return;
		}
		
		if (activeConsumerSequence){
			Consumer.releaseAll();
		}
		
		//release keys from active sequence if active sequence ended
		if(!(activeSequence.key == 0 && activeSequence.modifier == 0)) {
			Keyboard.release(KeyboardKeycode(activeSequence.key));
			
			if (kbdLockingKeys.kbdLeds.bmCapsLock && activeSequence.key < KEY_SLASH && activeSequence.key != KEY_TILDE) {
				if(activeSequence.modifier == KEY_RESERVED) {
					Keyboard.release(KeyboardKeycode(KEY_LEFT_SHIFT));
				} else if (activeSequence.modifier != KEY_LEFT_SHIFT){
					Keyboard.release(KeyboardKeycode(activeSequence.modifier));
				}
			} else {
				Keyboard.release(KeyboardKeycode(activeSequence.modifier));
			}
			
			Keyboard.release(KeyboardKeycode(activeSequence.key));
			
			//restore modifiers 
			if(neoModifiers.bmLeftShift){
				Keyboard.press(KeyboardKeycode(KEY_LEFT_SHIFT));
			} else if(neoModifiers.bmRightShift){
				Keyboard.press(KeyboardKeycode(KEY_RIGHT_SHIFT));
			}
			
			activeSequence = {0,0};
			
		} else { //otherwise just release the actual key
			Keyboard.release(KeyboardKeycode(keyboardMap->getL1()[key]));
		}
	
	} else { //act like a normal keyboard
		Keyboard.release(KeyboardKeycode(key));
	}
	
	setLedState(BootKeyboard.getLeds()); //update LEDs
}

void NeoReportParser::OnControlKeysChanged(uint8_t before, uint8_t after) {
	MODIFIERKEYS beforeMod;
	*((uint8_t*)&beforeMod) = before;

	MODIFIERKEYS afterMod;
	*((uint8_t*)&afterMod) = after;

	if (beforeMod.bmLeftCtrl != afterMod.bmLeftCtrl) {
		if (neoModifiers.bmLeftCtrl) {
			neoModifiers.bmLeftCtrl = false;
			Keyboard.release(KEY_LEFT_CTRL);
		} else {
			neoModifiers.bmLeftCtrl = true;
			Keyboard.press(KEY_LEFT_CTRL);
		}
	}
	
	if (beforeMod.bmLeftShift != afterMod.bmLeftShift) {
		if (neoModifiers.bmLeftShift) {
			neoModifiers.bmLeftShift = false;
			Keyboard.release(KEY_LEFT_SHIFT);
		} else {
			neoModifiers.bmLeftShift = true;
			Keyboard.press(KEY_LEFT_SHIFT);
		}
	}
	
	if (beforeMod.bmLeftAlt != afterMod.bmLeftAlt) {
		if (neoModifiers.bmLeftAlt) {
			neoModifiers.bmLeftAlt = false;
			Keyboard.release(KEY_LEFT_ALT);
		} else {
			neoModifiers.bmLeftAlt = true;
			Keyboard.press(KEY_LEFT_ALT);
		}
		
	}
	
	if (beforeMod.bmLeftGUI != afterMod.bmLeftGUI) {
		if (neoModifiers.bmLeftGUI) {
			neoModifiers.bmLeftGUI = false;
			
			if (leftGuiSinglePress){ // no combo observed, press it eventually
				leftGuiSinglePress = false;
				Keyboard.press(KEY_LEFT_GUI);
			}
			Keyboard.release(KEY_LEFT_GUI);
		} else {
			neoModifiers.bmLeftGUI = true;
			//OnKeyDown will set this, in case combo with win-key is hit
			leftGuiSinglePress = true;
		}
	}

	if (beforeMod.bmRightCtrl != afterMod.bmRightCtrl) {
		if (neoModifiers.bmRightCtrl) {
			neoModifiers.bmRightCtrl = false;
			Keyboard.release(KEY_RIGHT_CTRL);
		} else {
			neoModifiers.bmRightCtrl = true;
			Keyboard.press(KEY_RIGHT_CTRL);
		}
	}
	
	if (beforeMod.bmRightShift != afterMod.bmRightShift) {
		if (neoModifiers.bmRightShift) {
			neoModifiers.bmRightShift = false;
			Keyboard.release(KEY_RIGHT_SHIFT);
		} else {
			neoModifiers.bmRightShift = true;
			Keyboard.press(KEY_RIGHT_SHIFT);
		}
	}
	
	if (beforeMod.bmRightAlt != afterMod.bmRightAlt) {
		if (neoModifiers.bmRightAlt) {
			neoModifiers.bmRightAlt = false;
			if(!applyMap){
				Keyboard.release(KEY_RIGHT_ALT);
			}
		} else {
			neoModifiers.bmRightAlt = true;
			if(neoModifiers.bmLeft4 && applyMap){
				toggleM4Lock();
			}
			if(!applyMap){
				Keyboard.press(KEY_RIGHT_ALT);
			}
		}
	}
	
	if (beforeMod.bmRightGUI != afterMod.bmRightGUI) {
		if (neoModifiers.bmRightGUI) {
			neoModifiers.bmRightGUI = false;
			Keyboard.release(KEY_RIGHT_GUI);
		} else {
			neoModifiers.bmRightGUI = true;
			Keyboard.press(KEY_RIGHT_GUI);
		}
		
	}
	
	if (afterMod.bmLeftShift && afterMod.bmRightShift && applyMap) { //CAPS hotkey
		if (m4Lock){ //can't have caps and m4 locked
			m4Lock = false;
		}
		Keyboard.write(KEY_CAPS_LOCK);
	}
	
	setLedState(BootKeyboard.getLeds()); //update LEDs
	
}

uint8_t NeoReportParser::HandleLockingKeys(USBHID* hid, uint8_t key){
	uint8_t lockLeds = kbdLockingKeys.bLeds;
	KBDLEDS* kLockLeds = (KBDLEDS*) &lockLeds;
		
	//turn off NUM-Lock in case of M4-Lock, light everything in case of compose
	if(m4Lock && applyMap) { 
		(kLockLeds->bmNumLock) = 0;
	} else if (composeState && applyMap){
		lockLeds = 0xFF;
	}
	return (hid->SetReport(0, 0, 2, 0, 1, &lockLeds));
}

//pure unicode layers
void NeoReportParser::substitutePress(uint16_t *uni_map, uint8_t offset) {
	uint16_t key = pgm_read_word(uni_map + offset);
	pressUnicode(key);
}

void NeoReportParser::substitutePress(const InputSequence &sq){
	if(sq.modifier == KEY_UNICODE){
		pressUnicode(sq.key);
		
	} else if (sq.modifier == KEY_CONSUMER) {
		Consumer.releaseAll();
		Consumer.press(ConsumerKeycode(sq.key));
		activeConsumerSequence = true;
		
	} else {
		
		Keyboard.releaseAll();
		
		//restore control keys (used for word-wise marking in L4)
		if (neoModifiers.bmLeftCtrl) {
			Keyboard.press(KeyboardKeycode(KEY_LEFT_CTRL));
		}
		if (neoModifiers.bmRightCtrl){
			Keyboard.press(KeyboardKeycode(KEY_RIGHT_CTRL));
		}
		if (neoModifiers.bmLeftAlt) {
			Keyboard.press(KeyboardKeycode(KEY_LEFT_ALT));
		}
		if (neoModifiers.bmLeftGUI){
			Keyboard.press(KeyboardKeycode(KEY_LEFT_GUI));
		}
		if (neoModifiers.bmRightGUI){
			Keyboard.press(KeyboardKeycode(KEY_RIGHT_GUI));
		}
		
		if (kbdLockingKeys.kbdLeds.bmCapsLock && sq.key < KEY_SLASH && sq.key != KEY_TILDE) {
			if(sq.modifier == KEY_RESERVED) {
				Keyboard.press(KeyboardKeycode(KEY_LEFT_SHIFT));
			} else if (sq.modifier != KEY_LEFT_SHIFT){
				Keyboard.press(KeyboardKeycode(sq.modifier));
			}
		} else {
			Keyboard.press(KeyboardKeycode(sq.modifier));
		}
		delay(SQ_DELAY); //sometimes we are just too fast, e.g. RDP
		
		Keyboard.press(KeyboardKeycode(sq.key));
		
		//will be released on release event, so holding of the key is possible
		activeSequence = sq;
	}
}

void NeoReportParser::substitutePress(InputSequence *sq, uint8_t offset){
	InputSequence modKey;
	memcpy_P(&modKey, (sq + offset), sizeof(modKey));
	substitutePress(modKey);
	
}

void NeoReportParser::pressUnicode(uint16_t code) {
	uint8_t div = (unicodeMethod == WIN_DEC) ? 10 : 16;
	uint8_t digits[5];
	
	for(int8_t i = 0; i < 5; i++){
		digits[i] =  code % div;
		code /= div;
	}

	Keyboard.releaseAll();
		
	switch (unicodeMethod){
		case WIN_DEC:
			Keyboard.press(KeyboardKeycode(KEY_LEFT_ALT));
			delay(SQ_DELAY); //sometimes we are just too fast, e.g. RDP
			if (digits[4] != 0) {
				Keyboard.write(KeyboardKeycode(digits[4] - 1 + KEYPAD_1));
			}
			break;

		case WIN_HEX:
			Keyboard.press(KeyboardKeycode(KEY_LEFT_ALT));
			delay(SQ_DELAY);
			Keyboard.write(KeyboardKeycode(KEYPAD_ADD));
			break;
	
		case UNIX_HEX:
			Keyboard.press(KeyboardKeycode(KEY_LEFT_CTRL));
			Keyboard.press(KeyboardKeycode(KEY_LEFT_SHIFT));
			delay(SQ_DELAY);
			Keyboard.write(KeyboardKeycode(KEY_U));
			break;
	}
	
	for(int8_t i = 3; i >= 0; i--){
		if(digits[i] == 0){
			Keyboard.write(KeyboardKeycode(KEYPAD_0));
		} else if (digits[i] < 10){
			Keyboard.write(KeyboardKeycode(digits[i] - 1 + KEYPAD_1));
		} else {
			Keyboard.write(KeyboardKeycode(digits[i] - 10 + KEY_A));
		}
	}
	
	Keyboard.releaseAll();
	/*
	* modifiers are stored internally still but reported as key-up event to host,
	* therefore restore by re-pressing. Other layers not restored, as key-presses
	* of those are omitted anyway
	*/
	if(neoModifiers.bmLeftShift){
		Keyboard.press(KeyboardKeycode(KEY_LEFT_SHIFT));
	} else if(neoModifiers.bmRightShift){
		Keyboard.press(KeyboardKeycode(KEY_RIGHT_SHIFT));
	}
}

Layer NeoReportParser::getActiveLayer() {
	boolean m2 = neoModifiers.bmLeftShift || neoModifiers.bmRightShift;
	boolean m3 = neoModifiers.bmLeft3 || neoModifiers.bmRight3;
	boolean m4 = neoModifiers.bmLeft4 || neoModifiers.bmRightAlt;
	
	if(m4Lock) {
		if(!m3){
			m4 = !m4;
		}
	}
	
	if (kbdLockingKeys.kbdLeds.bmCapsLock){
		if(!m3 && !m4){
			m2 = !m2;
		}
	}
	
	if (!m2 && !m3 && !m4){
		return L1;
	} else if (!m2 && !m3 && m4){
		return L4;
	} else if (!m2 && m3 && !m4){
		return L3;
	} else if (!m2 && m3 && m4){
		return L6;
	} else if (m2 && !m3 && !m4){
		return L2;
	} else if (m2 && !m3 && m4){
		return L4_SHIFT;
	} else if (m2 && m3 && !m4){
		return L5;
	} else {
		return None;
	}

} 


boolean NeoReportParser::neoModifierChange(uint8_t key, boolean isKeyDownEvent){
	switch (key){ 
		case KEY_CAPS_LOCK:
			neoModifiers.bmLeft3 = isKeyDownEvent;
			return true;
			
		case KEY_BACKSLASH:
		case KEY_NON_US_NUM:
			neoModifiers.bmRight3 = isKeyDownEvent;
			return true;
				
		case KEY_NON_US:
			neoModifiers.bmLeft4 = isKeyDownEvent;
			if(isKeyDownEvent && neoModifiers.bmRightAlt){
				toggleM4Lock();
			}
			return true;
			
		default:
			return false;
	}
}

void NeoReportParser::setLedState(uint8_t leds){
	kbdLockingKeys.bLeds = leds;
}

void NeoReportParser::toggleM4Lock() {
	if(kbdLockingKeys.kbdLeds.bmCapsLock){
		Keyboard.press(KEY_CAPS_LOCK); // cant have caps with m4 locked
	}
	m4Lock = !m4Lock;
}

void NeoReportParser::install() {
	Keyboard.releaseAll();
	Keyboard.press(KeyboardKeycode(KEY_LEFT_GUI));
	Keyboard.write(KeyboardKeycode(KEY_R));
	Keyboard.release(KeyboardKeycode(KEY_LEFT_GUI));
	delay(GUI_DELAY);
	Keyboard.println(F("cmd"));
	delay(GUI_DELAY);
	for(int8_t i = 0; i<5; i++){
		Keyboard.println(F("echo ))) PLEASE REBOOT AFTER INSTALLATION )))"));
	}

	//"reg add "HKCU\Control Panel\Input Method" /v EnableHexNumpad /t REG_SZ /d 1 /f"
	Keyboard.print(F("reg add @HKCU"));
	Keyboard.press(KeyboardKeycode(KEY_RIGHT_ALT));
	Keyboard.write(KeyboardKeycode(KEY_MINUS));
	Keyboard.release(KeyboardKeycode(KEY_RIGHT_ALT));
	Keyboard.print(F("Control Panel"));
	Keyboard.press(KeyboardKeycode(KEY_RIGHT_ALT));
	Keyboard.write(KeyboardKeycode(KEY_MINUS));
	Keyboard.release(KeyboardKeycode(KEY_RIGHT_ALT));
	Keyboard.println(F("Input Method@ &v EnableHexNumpad &t REG?SY &d 1 &f"));
}

void NeoReportParser::help() {
	Keyboard.releaseAll();
	Keyboard.press(KeyboardKeycode(KEY_LEFT_GUI));
	Keyboard.write(KeyboardKeycode(KEY_R));
	Keyboard.release(KeyboardKeycode(KEY_LEFT_GUI));
	delay(GUI_DELAY);
	
	//https://github.com/Jonas-commits/Neo-Keyboard-Adapter
	Keyboard.println(F("https>&&github.com&Jonas/commits&Neo/Kezboard/Adapter"));
}
