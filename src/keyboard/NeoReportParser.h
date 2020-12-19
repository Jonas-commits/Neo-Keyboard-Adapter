#ifndef NEO_REPORT_PARSER_H
#define NEO_REPORT_PARSER_H

#include "NeoIncludes.h"
#include "Compose.h"

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
	
	Compose compose;
	NeoModifiers neoModifiers;
	boolean applyMap;
	boolean m4Lock;
	boolean composeState;
	UnicodeMethod unicodeMethod;
	
	InputSequence *activeSequence;
	boolean leftGuiSinglePress;

	
	void OnKeyDown  (uint8_t mod, uint8_t key) override;
	void OnKeyUp  (uint8_t mod, uint8_t key) override;
	void OnControlKeysChanged(uint8_t before, uint8_t after) override;
	uint8_t HandleLockingKeys(USBHID* hid, uint8_t key) override {
		uint8_t lockLeds = kbdLockingKeys.bLeds;
		return (hid->SetReport(0, 0, 2, 0, 1, &lockLeds));
	}
	
	void substitutePress(InputSequence *sq, uint8_t offset);
	void substitutePress(uint16_t *uni_map, uint8_t offset);
	void pressUnicode(uint16_t code);
	Layer getActiveLayer();
	boolean neoModifierChange(uint8_t key, boolean isKeyDownEvent);
	void toggleM4Lock();
	
	
	public:
	NeoReportParser() : KeyboardReportParser(), neoModifiers(), applyMap(true), m4Lock(false), composeState(false), activeSequence(nullptr){ }
	void setLedState(uint8_t leds);
	void install();
	void help();
	
};

#endif