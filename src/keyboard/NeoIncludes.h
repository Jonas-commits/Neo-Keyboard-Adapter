#ifndef NEOINCLUDES_H_
#define NEOINCLUDES_H_

#include <hidboot.h>     //arduino -> shield
#include <SPI.h>
#include <HID-Project.h> //arduino -> host
#include "EnhancedKeyboardReportParser.h"

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

struct InputSequence {
	uint8_t modifier;
	uint16_t key;
};

enum C : uint8_t {
	KEY_UNICODE = 0xFF,
	KEY_CONSUMER = 0xFE,
	NEO_MAP_SIZE = 100
};

enum Layer : uint8_t {
	L1,
	L2,
	L3,
	L4,
	L4_SHIFT,
	L5,
	L6,
};

enum UnicodeMethod {
	WIN_DEC,
	WIN_HEX,
	UNIX_HEX
};


#endif /* NEOINCLUDES_H_ */