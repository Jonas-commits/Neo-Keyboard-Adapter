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

//todo: get rid of this struture, by separating into 2 arrays, progmem does not like structures
struct InputSequence {
	uint8_t modifiers;
	uint16_t key;
};

enum C : uint8_t {
	KEY_UNICODE = 0xFF
};

class NeoReportParser : public KeyboardReportParser
{
	private:
	
	const static uint8_t NEO_MAP_SIZE = 100;
	const static uint8_t neoMap[NEO_MAP_SIZE];
	
	const static InputSequence neoMapL2[NEO_MAP_SIZE - KEY_Z - 1];
	const static InputSequence neoMapL3[NEO_MAP_SIZE] PROGMEM;
	const static InputSequence neoMapL4[NEO_MAP_SIZE] PROGMEM;
	const static InputSequence neoMapL5[NEO_MAP_SIZE] PROGMEM;
	const static InputSequence neoMapL6[NEO_MAP_SIZE] PROGMEM;
	
	NeoModifiers neoModifiers;
	boolean applyMap;
	
	void OnKeyDown  (uint8_t mod, uint8_t key) override;
	void OnKeyUp  (uint8_t mod, uint8_t key) override;
	void OnControlKeysChanged(uint8_t before, uint8_t after) override;
	
	void substitutePress(InputSequence *sq, uint8_t offset);
	
	
	
	public:
	NeoReportParser() : KeyboardReportParser(), neoModifiers(), applyMap(true){ }
	
};

#endif