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

struct InputSequence {
	uint8_t modifier;
	uint16_t key;
};

enum C : uint8_t {
	KEY_UNICODE = 0xFF,
	NEO_MAP_SIZE = 100
};

enum Layer {
	L1,
	L2,
	L3,
	L4,
	L4_SHIFT,
	L5,
	L6,
};

class NeoReportParser : public KeyboardReportParser
{
	private:
	const static uint8_t neoMap[NEO_MAP_SIZE];
	const static InputSequence neoMapL2[NEO_MAP_SIZE - KEY_Z - 1] PROGMEM;
	const static InputSequence neoMapL3[NEO_MAP_SIZE] PROGMEM;
	const static InputSequence neoMapL4[NEO_MAP_SIZE] PROGMEM;
	const static InputSequence neoMapL4Shift[NEO_MAP_SIZE] PROGMEM;
	const static uint16_t neoMapL5[NEO_MAP_SIZE] PROGMEM;
	const static uint16_t neoMapL6[NEO_MAP_SIZE] PROGMEM;
	
	InputSequence *activeSequence;
	NeoModifiers neoModifiers;
	boolean applyMap;
	
	void OnKeyDown  (uint8_t mod, uint8_t key) override;
	void OnKeyUp  (uint8_t mod, uint8_t key) override;
	void OnControlKeysChanged(uint8_t before, uint8_t after) override;
	
	void substitutePress(InputSequence *sq, uint8_t offset);
	void substitutePress(uint16_t *uni_map, uint8_t offset);
	void pressUnicode(uint16_t code);
	Layer getActiveLayer();
	boolean neoModifierChange(uint8_t key, boolean isKeyDownEvent);
	
	
	public:
	NeoReportParser() : KeyboardReportParser(), neoModifiers(), applyMap(true), activeSequence(nullptr){ }
	
};

#endif