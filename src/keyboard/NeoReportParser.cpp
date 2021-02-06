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
	{KEY_UNICODE, 0x2013},			{KEY_UNICODE, 0x2022},			{0, 0},							{0, 0}, 
	
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
	{KEY_UNICODE, 0x2023},			{KEY_UNICODE, 0x2714},			{KEY_UNICODE, 0x2718},			{KEY_UNICODE, 0x2020},
  
  //KEYPAD_0						KEYPAD_DOT
	{KEY_UNICODE, 0x2423},			{KEY_RESERVED, KEY_PERIOD} 
}; 

const InputSequence NeoReportParser::neoMapL3[] PROGMEM = {
  //KEY_RESERVED					KEY_ERROR_ROLLOVER	KEY_POST_FAIL								KEY_ERROR_UNDEFINED	
	{0, 0},							{0, 0},							{0, 0},							{0, 0},
		
  //KEY_A							KEY_B							KEY_C							KEY_D
	{KEY_RIGHT_ALT, KEY_MINUS},		{KEY_UNICODE, 0x60},			{KEY_RIGHT_ALT, KEY_NON_US},	{KEY_RIGHT_ALT, KEY_7},
		
  //KEY_E							KEY_F							KEY_G							KEY_H
	{KEY_RIGHT_ALT, KEY_8},			{KEY_RIGHT_ALT, KEY_0},		{KEY_LEFT_SHIFT, KEY_RIGHT_BRACE},	{KEY_LEFT_SHIFT, KEY_MINUS},
		
  //KEY_I							KEY_J							KEY_K							KEY_L
	{KEY_LEFT_SHIFT, KEY_NON_US},	{KEY_LEFT_SHIFT, KEY_8},		{KEY_LEFT_SHIFT, KEY_9},		{KEY_RESERVED, KEY_SLASH},
		
  //KEY_M							KEY_N							KEY_O							KEY_P
	{KEY_LEFT_SHIFT, KEY_5},		{KEY_RESERVED, KEY_RIGHT_BRACE},{KEY_LEFT_SHIFT, KEY_0},		{KEY_LEFT_SHIFT, KEY_6},
		
  //KEY_Q							KEY_R							KEY_S							KEY_T
	{KEY_UNICODE, 0x2026},			{KEY_RIGHT_ALT, KEY_9},			{KEY_LEFT_SHIFT, KEY_7},		{KEY_UNICODE, 0x5E},
		
  //KEY_U							KEY_V							KEY_W							KEY_X
	{KEY_RESERVED, KEY_NON_US},	{KEY_RIGHT_ALT, KEY_RIGHT_BRACE},	{KEY_LEFT_SHIFT, KEY_SLASH},	{KEY_LEFT_SHIFT, KEY_4},
		
  //KEY_Y							KEY_Z							KEY_1							KEY_2
	{KEY_LEFT_SHIFT, KEY_1},		{KEY_RESERVED, KEY_NON_US_NUM},	{KEY_UNICODE, 0xB9},			{KEY_RIGHT_ALT, KEY_2},
		
  //KEY_3							KEY_4							KEY_5							KEY_6
	{KEY_RIGHT_ALT, KEY_3},			{KEY_UNICODE, 0x203A},			{KEY_UNICODE, 0x2039},			{KEY_UNICODE, 0xA2},
		
  //KEY_7							KEY_8							KEY_9							KEY_0
	{KEY_UNICODE, 0xA5},			{KEY_UNICODE, 0x201A},			{KEY_UNICODE, 0x2018},			{KEY_UNICODE, 0x2019},
		
  //KEY_ENTER						KEY_ESC							KEY_BACKSPACE					KEY_TAB
	{KEY_RESERVED, KEY_ENTER},		{KEY_RESERVED, KEY_ESC},		{KEY_RESERVED, KEY_BACKSPACE},	{KEY_UNICODE, 0x266B},
		
  //KEY_SPACE						KEY_MINUS						KEY_EQUAL						KEY_LEFT_BRACE
	{KEY_RESERVED, KEY_SPACE},		{KEY_UNICODE, 0x2014},			{KEY_UNICODE, 0x2DA},			{KEY_UNICODE, 0x17F},
		
  //KEY_RIGHT_BRACE					KEY_BACKSLASH					KEY_NON_US_NUM					KEY_SEMICOLON
	{KEY_UNICODE, 0x2011},			{0, 0},							{0, 0},							{KEY_LEFT_SHIFT, KEY_PERIOD},
		
  //KEY_QUOTE						KEY_TILDE						KEY_COMMA						KEY_PERIOD
	{KEY_RIGHT_ALT, KEY_Q},			{KEY_UNICODE, 0x21BB},			{KEY_LEFT_SHIFT, KEY_2},		{KEY_LEFT_SHIFT, KEY_NON_US_NUM},

  //KEY_SLASH						KEY_CAPS_LOCK					KEY_F1							KEY_F2
	{KEY_LEFT_SHIFT, KEY_COMMA},	{0, 0},							{KEY_RESERVED, KEY_F1},			{KEY_RESERVED, KEY_F2},
		
  //KEY_F3							KEY_F4							KEY_F5							KEY_F6
	{KEY_RESERVED, KEY_F3},			{KEY_RESERVED, KEY_F4},			{KEY_RESERVED, KEY_F5},			{KEY_RESERVED, KEY_F6},
		
  //KEY_F7							KEY_F8							KEY_F9							KEY_F10
	{KEY_RESERVED, KEY_F7},			{KEY_RESERVED, KEY_F8},			{KEY_RESERVED, KEY_F9},			{KEY_RESERVED, KEY_F10},
		
  //KEY_F11							KEY_F12							KEY_PRINT						KEY_SCROLL_LOCK
	{KEY_RESERVED, KEY_F11},		{KEY_RESERVED, KEY_F12},		{KEY_RESERVED, KEY_PRINT},		{KEY_RESERVED, KEY_SCROLL_LOCK},
		
  //KEY_PAUSE						KEY_INSERT						KEY_HOME						KEY_PAGE_UP
	{KEY_RESERVED, KEY_PAUSE},		{KEY_RESERVED, KEY_INSERT},		{KEY_RESERVED, KEY_HOME},		{KEY_RESERVED, KEY_PAGE_UP},
		
  //KEY_DELETE						KEY_END							KEY_PAGE_DOWN					KEY_RIGHT_ARROW
	{KEY_RESERVED, KEY_DELETE},		{KEY_RESERVED, KEY_END},		{KEY_RESERVED, KEY_PAGE_DOWN},	{KEY_RESERVED, KEY_RIGHT_ARROW},
		
  //KEY_LEFT_ARROW					KEY_DOWN_ARROW					KEY_UP_ARROW					KEY_NUM_LOCK
{KEY_RESERVED, KEY_LEFT_ARROW},		{KEY_RESERVED, KEY_DOWN_ARROW},	{KEY_RESERVED, KEY_UP_ARROW},	{KEY_LEFT_SHIFT, KEY_0},
		
  //KEYPAD_DIVIDE					KEYPAD_MULTIPLY					KEYPAD_SUBTRACT					KEYPAD_ADD
	{KEY_UNICODE, 0xF7},			{KEY_UNICODE, 0x22C5},			{KEY_UNICODE, 0x2212},			{KEY_UNICODE, 0xB1},
		
  //KEYPAD_ENTER					KEYPAD_1						KEYPAD_2						KEYPAD_3
	{KEY_RESERVED, KEYPAD_ENTER},	{KEY_UNICODE, 0x2194},			{KEY_UNICODE, 0x2193},			{KEY_UNICODE, 0x21CC},
		
  //KEYPAD_4						KEYPAD_5						KEYPAD_6						KEYPAD_7
	{KEY_UNICODE, 0x2190},			{KEY_LEFT_SHIFT, KEY_PERIOD},	{KEY_UNICODE, 0x2192},			{KEY_UNICODE, 0x2195},
		
  //KEYPAD_8						KEYPAD_9						KEYPAD_0						KEYPAD_DOT
	{KEY_UNICODE, 0x2191},			{KEY_UNICODE, 0x20D7},			{KEY_LEFT_SHIFT, KEY_5},		{KEY_RESERVED, KEYPAD_DOT}
};

const InputSequence NeoReportParser::neoMapL4[] PROGMEM = {
  //KEY_RESERVED					KEY_ERROR_ROLLOVER	KEY_POST_FAIL								KEY_ERROR_UNDEFINED	
	{0, 0},							{0, 0},							{0, 0},							{0, 0},
		
  //KEY_A							KEY_B							KEY_C							KEY_D
	{KEY_RESERVED, KEY_HOME},		{KEY_LEFT_CTRL, KEY_Y},			{KEY_RESERVED, KEY_INSERT},		{KEY_RESERVED, KEY_DOWN_ARROW},
		
  //KEY_E							KEY_F							KEY_G							KEY_H
	{KEY_RESERVED, KEY_UP_ARROW},	{KEY_RESERVED, KEY_RIGHT_ARROW},{KEY_RESERVED, KEY_END},		{KEY_UNICODE, 0xBF},
		
  //KEY_I							KEY_J							KEY_K							KEY_L
	{KEY_RESERVED, KEYPAD_8},		{KEY_RESERVED, KEYPAD_4},		{KEY_RESERVED, KEYPAD_5},		{KEY_RESERVED, KEYPAD_6},
		
  //KEY_M							KEY_N							KEY_O							KEY_P
	{KEY_RESERVED, KEYPAD_1},		{KEY_LEFT_SHIFT, KEY_PERIOD},	{KEY_RESERVED, KEY_9},			{KEY_RESERVED, KEYPAD_ADD},
		
  //KEY_Q							KEY_R							KEY_S							KEY_T
	{KEY_RESERVED, KEY_PAGE_UP},	{KEY_RESERVED, KEY_DELETE},		{KEY_RESERVED, KEY_LEFT_ARROW},	{KEY_RESERVED, KEY_PAGE_DOWN},
		
  //KEY_U							KEY_V							KEY_W							KEY_X
	{KEY_RESERVED, KEYPAD_7},		{KEY_RESERVED, KEY_ENTER},		{KEY_RESERVED, KEY_BACKSPACE},	{KEY_RESERVED, KEY_TAB},
		
  //KEY_Y							KEY_Z							KEY_1							KEY_2
	{KEY_UNICODE, 0xA1},			{KEY_RESERVED, KEY_ESC},		{KEY_UNICODE, 0xAA},			{KEY_UNICODE, 0xBA},
		
  //KEY_3							KEY_4							KEY_5							KEY_6
	{KEY_UNICODE, 0x2116},			{0, 0},							{KEY_UNICODE, 0xB7},			{KEY_UNICODE, 0xA3},
		
  //KEY_7							KEY_8							KEY_9							KEY_0
	{KEY_UNICODE, 0xA4},			{KEY_RESERVED, KEY_TAB},		{KEY_RESERVED, KEYPAD_DIVIDE},	{KEY_RESERVED, KEYPAD_MULTIPLY},
		
  //KEY_ENTER						KEY_ESC							KEY_BACKSPACE					KEY_TAB
	{KEY_RESERVED, KEYPAD_ENTER},	{KEY_RESERVED, KEY_ESC},		{KEY_RESERVED, KEY_BACKSPACE},	{KEY_RESERVED, KEY_TAB},
		
  //KEY_SPACE						KEY_MINUS						KEY_EQUAL						KEY_LEFT_BRACE
	{KEY_RESERVED, KEYPAD_0},		{KEY_RESERVED, KEYPAD_SUBTRACT},{KEY_UNICODE, 0xA8},			{KEY_UNICODE, 0x2212},
		
  //KEY_RIGHT_BRACE					KEY_BACKSLASH					KEY_NON_US_NUM					KEY_SEMICOLON
	{KEY_UNICODE, 0x2DD},			{0, 0},							{0, 0},							{KEY_RESERVED, KEY_COMMA},
		
  //KEY_QUOTE						KEY_TILDE						KEY_COMMA						KEY_PERIOD
	{KEY_RESERVED, KEY_PERIOD},		{KEY_UNICODE, 0x2D9},			{KEY_RESERVED, KEYPAD_2},		{KEY_RESERVED, KEYPAD_3},

  //KEY_SLASH						KEY_CAPS_LOCK					KEY_F1							KEY_F2
	{KEY_LEFT_SHIFT, KEY_COMMA},	{0, 0},							{KEY_RESERVED, KEY_F1},			{KEY_RESERVED, KEY_F2},
		
  //KEY_F3							KEY_F4							KEY_F5							KEY_F6
	{KEY_RESERVED, KEY_F3},			{KEY_RESERVED, KEY_F4},			{KEY_RESERVED, KEY_F5},			{KEY_RESERVED, KEY_F6},
		
  //KEY_F7							KEY_F8							KEY_F9							KEY_F10
	{KEY_RESERVED, KEY_F7},			{KEY_RESERVED, KEY_F8},			{KEY_RESERVED, KEY_F9},			{KEY_RESERVED, KEY_F10},
		
  //KEY_F11							KEY_F12							KEY_PRINT						KEY_SCROLL_LOCK
	{KEY_RESERVED, KEY_F11},		{KEY_RESERVED, KEY_F12},		{KEY_RESERVED, KEY_PRINT},		{KEY_RESERVED, KEY_SCROLL_LOCK},
		
  //KEY_PAUSE						KEY_INSERT						KEY_HOME						KEY_PAGE_UP
	{KEY_RESERVED, KEY_PAUSE},		{KEY_CONSUMER, MEDIA_VOL_MUTE},	{KEY_CONSUMER, MEDIA_PREV},		{KEY_CONSUMER, MEDIA_VOL_UP},
		
  //KEY_DELETE						KEY_END							KEY_PAGE_DOWN					KEY_RIGHT_ARROW
	{KEY_CONSUMER, MEDIA_PLAY_PAUSE},{KEY_CONSUMER, MEDIA_NEXT},	{KEY_CONSUMER, MEDIA_VOL_DOWN},	{KEY_RESERVED, KEY_RIGHT_ARROW},
		
  //KEY_LEFT_ARROW					KEY_DOWN_ARROW					KEY_UP_ARROW					KEY_NUM_LOCK
	{KEY_RESERVED, KEY_LEFT_ARROW},	{KEY_RESERVED, KEY_DOWN_ARROW},	{KEY_RESERVED, KEY_UP_ARROW},	{KEY_UNICODE, 0x2260},
		
  //KEYPAD_DIVIDE					KEYPAD_MULTIPLY					KEYPAD_SUBTRACT					KEYPAD_ADD
	{KEY_UNICODE, 0x2044},			{KEY_UNICODE, 0xD7},			{KEY_UNICODE, 0x2216},			{KEY_UNICODE, 0x2213},
		
  //KEYPAD_ENTER					KEYPAD_1						KEYPAD_2						KEYPAD_3
	{KEY_RESERVED, KEYPAD_ENTER},	{KEY_RESERVED, KEY_END},		{KEY_RESERVED, KEY_DOWN},		{KEY_RESERVED, KEY_PAGE_DOWN},
		
  //KEYPAD_4						KEYPAD_5						KEYPAD_6						KEYPAD_7
	{KEY_RESERVED, KEY_LEFT_ARROW},	{KEY_RESERVED, KEY_APPLICATION},{KEY_RESERVED, KEY_RIGHT_ARROW},{KEY_RESERVED, KEY_HOME},
		
  //KEYPAD_8						KEYPAD_9						KEYPAD_0						KEYPAD_DOT
	{KEY_RESERVED, KEY_UP_ARROW},	{KEY_RESERVED, KEY_PAGE_UP},	{KEY_RESERVED, KEY_INSERT},		{KEY_RESERVED, KEY_DELETE}
};

const uint16_t NeoReportParser::neoMapL5[] PROGMEM = {
  //KEY_RESERVED		KEY_ERROR_ROLLOVER	KEY_POST_FAIL		KEY_ERROR_UNDEFINED	KEY_A				KEY_B				KEY_C				KEY_D
	0,					0,					0,					0,					0,					0x3B6,				0x3B7,				0x3B1,
	
  //KEY_E				KEY_F				KEY_G				KEY_H				KEY_I				KEY_J				KEY_K				KEY_L
	0x3BB,				0x3B5,				0x3BF,				0x3C3,				0x3B3,				0x3BD,				0x3C1,				0x3C4,
	
  //KEY_M				KEY_N				KEY_O				KEY_P				KEY_Q				KEY_R				KEY_S				KEY_T
	0xB5,				0x3B2,				0x3C6,				0x3D5,				0x3BE,				0x3C7,				0x3B9,				0x3C9,
	
  //KEY_U				KEY_V				KEY_W				KEY_X				KEY_Y				KEY_Z				KEY_1				KEY_2
	0x3C8,				0x3C0,				0,					0x3F5,				0x3BA,				0,					0x2081,				0x2082,
	
  //KEY_3				KEY_4				KEY_5				KEY_6				KEY_7				KEY_8				KEY_9				KEY_0
	0x2083,				0x2640,				0x2642,				0x26A5,				0x3F0,				0x27E8,				0x27E9,				0x2080,
	
  //KEY_ENTER			KEY_ESC				KEY_BACKSPACE		KEY_TAB				KEY_SPACE			KEY_MINUS			KEY_EQUAL			KEY_LEFT_BRACE
	0,					0,					0,					0,					0xA0,				0x2011,				0x1FFE,				0x3C2,
	
  //KEY_RIGHT_BRACE		KEY_BACKSLASH		KEY_NON_US_NUM		KEY_SEMICOLON		KEY_QUOTE			KEY_TILDE			KEY_COMMA			KEY_PERIOD
	0x1FBF,				0,					0,					0x3B4,				0x3C5,				0x2DE,				0x3F1,				0x3D1,
	
  //KEY_SLASH			KEY_CAPS_LOCK		KEY_F1				KEY_F2				KEY_F3				KEY_F4				KEY_F5				KEY_F6
	0x3B8,				0,					0,					0,					0,					0,					0,					0,
	
  //KEY_F7				KEY_F8				KEY_F9				KEY_F10				KEY_F11				KEY_F12				KEY_PRINT			KEY_SCROLL_LOCK
	0,					0,					0,					0,					0,					0,					0,					0,
	
  //KEY_PAUSE			KEY_INSERT			KEY_HOME			KEY_PAGE_UP			KEY_DELETE			KEY_END				KEY_PAGE_DOWN		KEY_RIGHT_ARROW
	0,					0,					0,					0,					0,					0,					0,					0,
	
  //KEY_LEFT_ARROW		KEY_DOWN_ARROW		KEY_UP_ARROW		KEY_NUM_LOCK		KEYPAD_DIVIDE		KEYPAD_MULTIPLY		KEYPAD_SUBTRACT		KEYPAD_ADD
	0,					0,					0,					0x2248,				0x2300,				0x2299,				0x2296,				0x2295,
	
  //KEYPAD_ENTER		KEYPAD_1			KEYPAD_2			KEYPAD_3			KEYPAD_4			KEYPAD_5			KEYPAD_6			KEYPAD_7
	0,					0x2264,				0x222A,				0x2265,				0x2282,				0x22B6,				0x2283,				0x226A,
	
  //KEYPAD_8			KEYPAD_9			KEYPAD_0			KEYPAD_DOT
	0x2229,				0x226B,				0x2030,				0x2032
};

const uint16_t NeoReportParser::neoMapL6[] PROGMEM = {
  //KEY_RESERVED		KEY_ERROR_ROLLOVER	KEY_POST_FAIL		KEY_ERROR_UNDEFINED	KEY_A				KEY_B				KEY_C				KEY_D
	0,					0,					0,					0,					0x2282,				0x2124,				0x2135,				0x2200,
	
  //KEY_E				KEY_F				KEY_G				KEY_H				KEY_I				KEY_J				KEY_K				KEY_L
	0x39B,				0x2203,				0x2208,				0x3A3,				0x393,				0x2115,				0x211D,				0x2202,
	
  //KEY_M				KEY_N				KEY_O				KEY_P				KEY_Q				KEY_R				KEY_S				KEY_T
	0x21D4,				0x21D0,				0x3A6,				0x211A,				0x39E,				0x2102,				0x222B,				0x3A9,
	
  //KEY_U				KEY_V				KEY_W				KEY_X				KEY_Y				KEY_Z				KEY_1				KEY_2
	0x3A8,				0x3A0,				0x221A,				0x2229,				0x00D7,				0x222A,				0xAC,				0x2228,
	
  //KEY_3				KEY_4				KEY_5				KEY_6				KEY_7				KEY_8				KEY_9				KEY_0
	0x2227,				0x22A5,				0x2221,				0x2225,				0x2192,				0x221E,				0x221D,				0x2205,
	
  //KEY_ENTER			KEY_ESC				KEY_BACKSPACE		KEY_TAB				KEY_SPACE			KEY_MINUS			KEY_EQUAL			KEY_LEFT_BRACE
	0,					0,					0,					0,					0x202F,				0xAD,				0xAF,				0x2218,
	
  //KEY_RIGHT_BRACE		KEY_BACKSLASH		KEY_NON_US_NUM		KEY_SEMICOLON		KEY_QUOTE			KEY_TILDE			KEY_COMMA			KEY_PERIOD
	0x2D8,				0,					0,					0x394,				0x2207,				0x2E,				0x21D2,				0x21A6,
	
  //KEY_SLASH			KEY_CAPS_LOCK		KEY_F1				KEY_F2				KEY_F3				KEY_F4				KEY_F5				KEY_F6
  0x3B8,				0,					0,					0,					0,					0,					0,					0,
  
  //KEY_F7				KEY_F8				KEY_F9				KEY_F10				KEY_F11				KEY_F12				KEY_PRINT			KEY_SCROLL_LOCK
  0,					0,					0,					0,					0,					0,					0,					0,
  
  //KEY_PAUSE			KEY_INSERT			KEY_HOME			KEY_PAGE_UP			KEY_DELETE			KEY_END				KEY_PAGE_DOWN		KEY_RIGHT_ARROW
  0,					0,					0,					0,					0,					0,					0,					0,
  
  //KEY_LEFT_ARROW		KEY_DOWN_ARROW		KEY_UP_ARROW		KEY_NUM_LOCK		KEYPAD_DIVIDE		KEYPAD_MULTIPLY		KEYPAD_SUBTRACT		KEYPAD_ADD
  0,					0,					0,					0x2261,				0x2223,				0x2297,				0x2238,				0x2214,
	
  //KEYPAD_ENTER		KEYPAD_1			KEYPAD_2			KEYPAD_3			KEYPAD_4			KEYPAD_5			KEYPAD_6			KEYPAD_7
	0,					0x230A,				0x222A,				0x230B,				0x2286,				0x22B7,				0x2287,				0x2308,
	
  //KEYPAD_8			KEYPAD_9			KEYPAD_0			KEYPAD_DOT
	0x22C2,				0x2309,				0x25A1,				0x2033
};

const uint8_t NeoReportParser::L4Shift_Map[] = {
	0<<7 | 0<<6 | 0<<5 | 0<<4 | 1<<3 | 0<<2 | 0<<1 | 1, //KEY_RESERVED - KEY_D
	1<<7 | 1<<6 | 1<<5 | 0<<4 | 0<<3 | 0<<2 | 0<<1 | 0, //KEY_E - KEY_L
	0<<7 | 1<<6 | 0<<5 | 0<<4 | 1<<3 | 1<<2 | 1<<1 | 1, //KEY_M - KEY_T
	0<<7 | 1<<6 | 1<<5 | 1<<4 | 0<<3 | 1<<2 | 0<<1 | 0, //KEY_U - KEY_2
	0<<7 | 0<<6 | 0<<5 | 0<<4 | 0<<3 | 1<<2 | 0<<1 | 0, //KEY_3 - KEY_0
	1<<7 | 1<<6 | 1<<5 | 1<<4 | 0<<3 | 0<<2 | 0<<1 | 0, //KEY_ENTER - KEY_LEFT_BRACE
	0<<7 | 0<<6 | 0<<5 | 0<<4 | 0<<3 | 0<<2 | 0<<1 | 0, //KEY_RIGHT_BRACE - KEY_PERIOD
	1<<7 | 0<<6 | 1<<5 | 1<<4 | 1<<3 | 1<<2 | 1<<1 | 1, //KEY_SLASH - KEY_F6
	1<<7 | 1<<6 | 1<<5 | 1<<4 | 1<<3 | 1<<2 | 1<<1 | 1, //KEY_F7 - KEY_SCROLL_LOCK
	0<<7 | 0<<6 | 0<<5 | 0<<4 | 0<<3 | 0<<2 | 0<<1 | 0, //KEY_PAUSE - KEY_RIGHT_ARROW
	1<<7 | 1<<6 | 1<<5 | 0<<4 | 0<<3 | 0<<2 | 0<<1 | 0, //KEY_LEFT_ARROW - KEYPAD_ADD
	0<<7 | 1<<6 | 1<<5 | 1<<4 | 1<<3 | 0<<2 | 1<<1 | 1, //KEYPAD_ENTER - KEYPAD_7
	1<<7 | 1<<6 | 1<<5 | 0<<4                           //KEYPAD_8 - KEYPAD_DOT
};

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
						Keyboard.press(KeyboardKeycode(neoMap[key]));
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
							
						Keyboard.press(KeyboardKeycode(neoMap[key]));
							
					} else {
						substitutePress(const_cast<InputSequence*>(neoMapL2), key - KEY_Z - 1);
					}
					break;
					
				case L3:
						substitutePress(const_cast<InputSequence*>(neoMapL3), key);
					break;
					
				case L4:
					substitutePress(const_cast<InputSequence*>(neoMapL4), key);
					break;
				
				case L4_SHIFT:
					{
						memcpy_P(&sq, (neoMapL4 + key), sizeof(sq));
						
						uint8_t shift_bit = L4Shift_Map[key / 8u] & (uint8_t) (1u << ( 7u - ( key % 8u ))) ;
						if (shift_bit > 0) {
							sq.modifier = KEY_LEFT_SHIFT;
						}
						substitutePress(sq);
					}
					break;
					
				case L5:
					substitutePress(const_cast<uint16_t*>(neoMapL5), key);
					break;
					
				case L6:
					substitutePress(const_cast<uint16_t*>(neoMapL6), key);
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
			Keyboard.release(KeyboardKeycode(neoMap[key]));
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
