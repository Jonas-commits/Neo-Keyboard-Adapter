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

class InputSequence {
	public:
	uint8_t modifier;
	uint16_t key;
	boolean isNull(){
		return (modifier == 0 && key == 0);
	}
};

enum C : uint8_t {
	KEY_UNICODE = 0xFF,
	KEY_CONSUMER = 0xFE,
	NEO_MAP_SIZE = 100
};

/* Layer values must not exceed 64 because of bit sharing in Compose*/
enum Layer : uint8_t {
	L1 = 1,
	L2 = 2,
	L3 = 3,
	L4 = 4,
	L5 = 5,
	L6 = 6,
	L4_SHIFT = 7,
};

enum UnicodeMethod {
	WIN_DEC,
	WIN_HEX,
	UNIX_HEX
};


#endif /* NEOINCLUDES_H_ */