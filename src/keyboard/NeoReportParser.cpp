#include "NeoReportParser.h"

const uint8_t NeoReportParser::neoMap[] = {
  //KEY_RESERVED		KEY_ERROR_ROLLOVER	KEY_POST_FAIL		KEY_ERROR_UNDEFINED	KEY_A				KEY_B				KEY_C				KEY_D
	KEY_RESERVED,		KEY_ERROR_ROLLOVER,	KEY_POST_FAIL,		KEY_ERROR_UNDEFINED,KEY_U,				KEY_Y,				KEY_QUOTE,			KEY_A,
	
  //KEY_E				KEY_F				KEY_G				KEY_H				KEY_I				KEY_J				KEY_K				KEY_L
	KEY_L,				KEY_E,				KEY_O,				KEY_S,				KEY_G,				KEY_N,				KEY_R,				KEY_T,
	
  //KEY_M				KEY_N				KEY_O				KEY_P				KEY_Q				KEY_R				KEY_S				KEY_T
	KEY_M,				KEY_B,				KEY_F,				KEY_Q,				KEY_X,				KEY_C,				KEY_I,				KEY_W,
	
  //KEY_U				KEY_V				KEY_W				KEY_X				KEY_Y				KEY_Z				KEY_1				KEY_2
	KEY_H,				KEY_P,				KEY_V,				KEY_SEMICOLON,		KEY_K,				KEY_LEFT_BRACE,		KEY_1,				KEY_2,
	
  //KEY_3				KEY_4				KEY_5				KEY_6				KEY_7				KEY_8				KEY_9				KEY_0
	KEY_3,				KEY_4,				KEY_5,				KEY_6,				KEY_7,				KEY_8,				KEY_9,				KEY_0,
	
  //KEY_ENTER			KEY_ESC				KEY_BACKSPACE		KEY_TAB				KEY_SPACE			KEY_MINUS			KEY_EQUAL			KEY_LEFT_BRACE
	KEY_ENTER,			KEY_ESC,			KEY_BACKSPACE,		KEY_TAB,			KEY_SPACE,			KEY_SLASH,			KEY_RIGHT_BRACE,	KEY_MINUS,
	
  //KEY_RIGHT_BRACE		KEY_BACKSLASH		KEY_NON_US_NUM		KEY_SEMICOLON		KEY_QUOTE			KEY_TILDE			KEY_COMMA			KEY_PERIOD
	KEY_EQUAL,			KEY_BACKSLASH,		KEY_NON_US_NUM,		KEY_D,				KEY_Z,				KEY_TILDE,			KEY_COMMA,			KEY_PERIOD,
	
  //KEY_SLASH			KEY_CAPS_LOCK		KEY_F1				KEY_F2				KEY_F3				KEY_F4				KEY_F5				KEY_F6
	KEY_J,				KEY_CAPS_LOCK,		KEY_F1,				KEY_F2,				KEY_F3,				KEY_F4,				KEY_F5,				KEY_F6,
	
  //KEY_F7				KEY_F8				KEY_F9				KEY_F10				KEY_F11				KEY_F12				KEY_PRINT			KEY_SCROLL_LOCK
	KEY_F7,				KEY_F8,				KEY_F9,				KEY_F10,			KEY_F11,			KEY_F12,			KEY_PRINTSCREEN,	KEY_SCROLL_LOCK,
	
  //KEY_PAUSE			KEY_INSERT			KEY_HOME			KEY_PAGE_UP			KEY_DELETE			KEY_END				KEY_PAGE_DOWN		KEY_RIGHT_ARROW
	KEY_PAUSE,			KEY_INSERT,			KEY_HOME,			KEY_PAGE_UP,		KEY_DELETE,			KEY_END,			KEY_PAGE_DOWN,		KEY_RIGHT_ARROW,
	
  //KEY_LEFT_ARROW		KEY_DOWN_ARROW		KEY_UP_ARROW		KEY_NUM_LOCK		KEYPAD_DIVIDE		KEYPAD_MULTIPLY		KEYPAD_SUBTRACT		KEYPAD_ADD
	KEY_LEFT_ARROW,		KEY_DOWN_ARROW,		KEY_UP_ARROW,		KEY_TAB,			KEYPAD_DIVIDE,		KEYPAD_MULTIPLY,	KEYPAD_SUBTRACT,	KEYPAD_ADD,
	
  //KEYPAD_ENTER		KEYPAD_1			KEYPAD_2			KEYPAD_3			KEYPAD_4			KEYPAD_5			KEYPAD_6			KEYPAD_7
	KEYPAD_ENTER,		KEYPAD_1,			KEYPAD_2,			KEYPAD_3,			KEYPAD_4,			KEYPAD_5,			KEYPAD_6,			KEYPAD_7,
	
  //KEYPAD_8			KEYPAD_9			KEYPAD_0			KEYPAD_DOT
	KEYPAD_8,			KEYPAD_9,			KEYPAD_0,			KEYPAD_DOT
};

const InputSequence NeoReportParser::neoMapL2[] PROGMEM = {
  //KEY_1							KEY_2							KEY_3							KEY_4
	{KEY_LEFT_SHIFT, KEY_TILDE},	{KEY_LEFT_SHIFT, KEY_3},		{KEY_UNICODE, 0x2113},			{KEY_UNICODE, 0xBB},
	
  //KEY_5							KEY_6							KEY_7							KEY_8
	{KEY_UNICODE, 0xAB},			{KEY_LEFT_SHIFT, KEY_4},		{KEY_RIGHT_ALT, KEY_E},			{KEY_UNICODE, 0x201E},
	
  //KEY_9							KEY_0							KEY_ENTER						KEY_ESC
	{KEY_UNICODE, 0x201C},			{KEY_UNICODE, 0x201D},			{0, 0},							{0, 0},
	
  //KEY_BACKSPACE					KEY_TAB							KEY_SPACE						KEY_MINUS
	{0, 0},							{0, 0},							{0, 0},							{KEY_UNICODE, 0x2014},

  //KEY_EQUAL						KEY_LEFT_BRACE					KEY_RIGHT_BRACE					KEY_BACKSLASH
	{KEY_UNICODE, 0xB8},			{KEY_UNICODE, 0x1E9E},			{KEY_UNICODE, 0x2DC},			{0, 0},
	
  //KEY_NON_US_NUM					KEY_SEMICOLON					KEY_QUOTE						KEY_TILDE
	{0, 0},							{0, 0},							{0, 0},							{KEY_UNICODE, 0x2C7},
	
  //KEY_COMMA						KEY_PERIOD						KEY_SLASH						KEY_CAPS_LOCK
	{KEY_UNICODE, 0x2013},			{KEY_UNICODE, 0x2022},			{0, 0},			{0, 0}, 
	
  //KEY_F1							KEY_F2							KEY_F3							KEY_F4
	{0, 0},							{0, 0},							{0, 0},							{0, 0},
	
  //KEY_F5							KEY_F6							KEY_F7							KEY_F8
	{0, 0},							{0, 0},							{0, 0},							{0, 0},
	
  //KEY_F9							KEY_F10							KEY_F11							KEY_F12
	{0, 0},							{0, 0},							{0, 0},							{0, 0},
		
  //KEY_PRINT						KEY_SCROLL_LOCK					KEY_PAUSE						KEY_INSERT
	{0, 0},							{0, 0},							{0, 0},							{0, 0},
		
  //KEY_HOME						KEY_PAGE_UP						KEY_DELETE						KEY_END
	{0, 0},							{0, 0},							{0, 0},							{0, 0},
		
  //KEY_PAGE_DOWN					KEY_RIGHT_ARROW					KEY_LEFT_ARROW					KEY_DOWN_ARROW
	{0, 0},							{0, 0},							{0, 0},							{0, 0},
	
  //KEY_UP_ARROW					KEY_NUM_LOCK					KEYPAD_DIVIDE					KEYPAD_MULTIPLY
	{0, 0},							{0, 0},							{0, 0},							{0, 0},

  //KEYPAD_SUBTRACT					KEYPAD_ADD						KEYPAD_ENTER					KEYPAD_1
	{0, 0},							{0, 0},							{0, 0},							{KEY_UNICODE, 0x2666},
	
  //KEYPAD_2						KEYPAD_3						KEYPAD_4						KEYPAD_5
	{KEY_UNICODE, 0x2665},			{KEY_UNICODE, 0x2660},			{KEY_UNICODE, 0x2663},			{KEY_RIGHT_ALT, KEY_E},
	
  //KEYPAD_6						KEYPAD_7						KEYPAD_8						KEYPAD_9
	{KEY_UNICODE, 0x2023},			{KEY_UNICODE, 0x2714},			{KEY_UNICODE, 0x2718},			{KEY_RIGHT_ALT, 0x2020},
  
  //KEYPAD_0						KEYPAD_DOT
	{KEY_UNICODE, 0x2423},			{KEY_RESERVED, KEY_PERIOD} 
}; 
	
const InputSequence NeoReportParser::neoMapL3[] PROGMEM = {0}; //TODO
const InputSequence NeoReportParser::neoMapL4[] PROGMEM = {0}; //TODO
const InputSequence NeoReportParser::neoMapL5[] PROGMEM = {0}; //TODO
const InputSequence NeoReportParser::neoMapL6[] PROGMEM = {0}; //TODO

void NeoReportParser::OnKeyDown(uint8_t mod, uint8_t key) {
	if (applyMap && key < NEO_MAP_SIZE + 1){ //act like neo keyboard

		if(neoModifierChange(key, true)){
			return;
		}
		
		// map action according the current layer active, indicated by modifier states
		switch (getActiveLayer()) {
			case 1:
				if (key != KEY_EQUAL) { //only key not fitting in layer1
					Keyboard.press(KeyboardKeycode(neoMap[key]));
				} else {
					const static InputSequence sq PROGMEM = {KEY_LEFT_SHIFT, KEY_EQUAL};
					substitutePress(&sq, 0);
				}
				break;
					
			case 2:
				if ( key <= KEY_Z || (KEY_ENTER <= key && key <= KEY_SPACE) ||
							(KEY_BACKSLASH <= key && key <= KEY_QUOTE) || (KEY_SLASH <= key && key <= KEYPAD_ENTER)
							|| neoModifiers.bmLeftCtrl || neoModifiers.bmRightCtrl
							|| neoModifiers.bmLeftGUI || neoModifiers.bmRightGUI || neoModifiers.bmLeftAlt) {
							
					Keyboard.press(KeyboardKeycode(neoMap[key]));
							
				} else {
					substitutePress(neoMapL2, key - KEY_Z - 1);
				}
				break;
					
			case 3:
				substitutePress(neoMapL3, key);
				break;
					
			case 4:
				substitutePress(neoMapL4, key);
				break;
					
			case 5:
				substitutePress(neoMapL5, key);
				break;
					
			case 6:
				substitutePress(neoMapL6, key);
				break;
		}

	} else { //act like a normal keyboard
		Keyboard.press(KeyboardKeycode(key));
	}
}

void NeoReportParser::OnKeyUp(uint8_t mod, uint8_t key) {
	if (applyMap && key < NEO_MAP_SIZE + 1) { //act like neo keyboard
		
		if(neoModifierChange(key, false)){
			return;
		}
		
		if(activeSequence){ //release active holds from substitution
			InputSequence sq;
			memcpy_P(&sq, activeSequence, sizeof(sq));
		
			Keyboard.release(KeyboardKeycode(sq.key));
			Keyboard.release(KeyboardKeycode(sq.modifier));
			activeSequence = nullptr;
			
		} else { //otherwise just release the actual key
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
			Keyboard.release(KEY_LEFT_GUI);
		} else {
			neoModifiers.bmLeftGUI = true;
			Keyboard.press(KEY_LEFT_GUI);
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
			Keyboard.release(KEY_RIGHT_ALT);
		} else {
			neoModifiers.bmRightAlt = true;
			Keyboard.press(KEY_RIGHT_ALT);
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
}

void NeoReportParser::substitutePress(InputSequence *sq, uint8_t offset){
	InputSequence modKey;
	memcpy_P(&modKey, (sq + offset), sizeof(modKey));

	Keyboard.releaseAll();
	if(modKey.modifier == KEY_UNICODE){
		uint16_t uni = modKey.key;
		uint8_t digits[5];
		//load digits into array to send them in reverse order
		for(int8_t i = 0; i < 5; i++){
			digits[i] =  uni % 10;
			uni /= 10;
		}
		
		Keyboard.press(KeyboardKeycode(KEY_LEFT_ALT));
		for(int8_t i = 4; i >= 0; i--){
			uint8_t digit = digits[i];
			if(digit == 0){ //0 is after 9 in keypad key order
				digit = 10;
			}
			Keyboard.write(KeyboardKeycode(digit + KEYPAD_1 - 1));
		}
		Keyboard.releaseAll();
		
		/*
		 * modifiers are stored internally still but reported as key-up event to host, 
		 * therefore restore by re-pressing. Other layers not restored, as key-presses
		 * of those are omitted anyway
		 */
		if(neoModifiers.bmLeftShift){
			OnKeyDown(0, KEY_LEFT_SHIFT);
		} else if(neoModifiers.bmRightShift){
			OnKeyDown(0, KEY_RIGHT_SHIFT);
		}
		
	} else{
		Keyboard.press(KeyboardKeycode(modKey.modifier));
		Keyboard.press(KeyboardKeycode(modKey.key));
		
		//will be released on release event, so holding of the key is possible
		activeSequence = sq + offset;
	}
}

int8_t NeoReportParser::getActiveLayer() {
	if (neoModifiers.bmLeftShift || neoModifiers.bmRightShift) {
		if (neoModifiers.bmLeft3 || neoModifiers.bmRight3) {
			return 5;
		
		} else {
			return 2;
		}
		
	} else if (neoModifiers.bmLeft3 || neoModifiers.bmRight3) {
		if (neoModifiers.bmLeft4 || neoModifiers.bmRightAlt) {
			return 6;
		
		} else {
			return 3;
		}
		
	} else if (neoModifiers.bmLeft4 || neoModifiers.bmRightAlt) {
		return 4;
		
	} else {
		return 1;
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
			return true;
			
		default:
			return false;
	}
}
