#ifndef NEO_REPORT_PARSER_H
#define NEO_REPORT_PARSER_H

#include <hidboot.h>
#include <SPI.h>
#include <HID-Project.h>

struct NeoModifiers {
	boolean bmLeftCtrl;
	boolean bmLeftShift;
	boolean bmLeftAlt;
	boolean bmLeftGUI;
	boolean bmRightCtrl;
	boolean bmRightShift;
	boolean bmRightAlt;
	boolean bmRightGUI;
	boolean bmLeft3;
	boolean bmRight3;
	boolean bmLeft4;
};

class NeoReportParser : public KeyboardReportParser
{
	private:
	NeoModifiers neoModifiers;
	boolean applyMap;
	
	const static uint8_t NEO_MAP_SIZE = 100;
	const static uint8_t neoMap[NEO_MAP_SIZE] = {
		KEY_RESERVED, KEY_ERROR_ROLLOVER, KEY_POST_FAIL, KEY_ERROR_UNDEFINED, KEY_U, KEY_Z, KEY_QUOTE, KEY_A,
		KEY_L, KEY_E, KEY_O, KEY_S, KEY_G, KEY_N, KEY_R, KEY_T,
		KEY_M, KEY_B, KEY_F, KEY_Q, KEY_X, KEY_C, KEY_I, KEY_W,
		KEY_H, KEY_P, KEY_V, KEY_SEMICOLON, KEY_K, KEY_LEFT_BRACE, KEY_1, KEY_2,
		KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_0,
		KEY_ENTER, KEY_ESC, KEY_BACKSPACE, KEY_TAB, KEY_SPACE, KEY_SLASH, KEY_RIGHT_BRACE, KEY_MINUS,
		KEY_EQUAL, KEY_BACKSLASH, KEY_NON_US_NUM, KEY_D, KEY_Y, KEY_TILDE, KEY_COMMA, KEY_PERIOD,
		KEY_J, KEY_CAPS_LOCK, KEY_F1, KEY_F2, KEY_F3, KEY_F4, KEY_F5, KEY_F6,
		KEY_F7, KEY_F8, KEY_F9, KEY_F10, KEY_F11, KEY_F12, KEY_PRINTSCREEN, KEY_SCROLL_LOCK,
		KEY_PAUSE, KEY_INSERT, KEY_HOME, KEY_PAGE_UP, KEY_DELETE, KEY_END, KEY_PAGE_DOWN, KEY_RIGHT,
		KEY_LEFT, KEY_DOWN, KEY_UP, KEY_TAB, KEYPAD_DIVIDE, KEYPAD_MULTIPLY, KEYPAD_SUBTRACT, KEYPAD_ADD,
		KEYPAD_ENTER, KEYPAD_1, KEYPAD_2, KEYPAD_3, KEYPAD_4, KEYPAD_5, KEYPAD_6, KEYPAD_7, 
		KEYPAD_8, KEYPAD_9, KEYPAD_0, KEYPAD_DECIMAL
	};

	protected:
	void OnControlKeysChanged(uint8_t before, uint8_t after);

	void OnKeyDown  (uint8_t mod, uint8_t key);
	void OnKeyUp  (uint8_t mod, uint8_t key);
	void OnKeyPressed(uint8_t key);
	
	public:
	NeoReportParser() : KeyboardReportParser(), neoModifiers(), applyMap(true) { }
	
};

#endif