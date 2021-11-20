#ifndef NEO_REPORT_PARSER_H
#define NEO_REPORT_PARSER_H

#include "NeoIncludes.h"
#include "Compose.gen.h"
#include "Neo2Map.h"

class NeoReportParser : public EnhancedKeyboardReportParser
{
	private:
	const Neo2Map neo2Map = Neo2Map();
	const KeyboardMap* keyboardMap = &neo2Map;
	const static uint16_t SQ_DELAY = 10;   // delay before a key is entered after the modifiers
	const static uint16_t GUI_DELAY = 250; // delay to wait for a popup
	
	Compose compose;
	NeoModifiers neoModifiers;
	boolean applyMap;
	boolean m4Lock;
	boolean composeState;
	UnicodeMethod unicodeMethod;
	
	InputSequence activeSequence;
	boolean activeConsumerSequence;
	boolean leftGuiSinglePress;

	
	void OnKeyDown  (uint8_t mod, uint8_t key) override;
	void OnKeyUp  (uint8_t mod, uint8_t key) override;
	void OnControlKeysChanged(uint8_t before, uint8_t after) override;
	uint8_t HandleLockingKeys(USBHID* hid, uint8_t key) override;
	
	void substitutePress(InputSequence *sq, uint8_t offset);
	void substitutePress(const InputSequence &sq);
	void substitutePress(uint16_t *uni_map, uint8_t offset);
	void pressUnicode(uint16_t code);
	Layer getActiveLayer();
	boolean neoModifierChange(uint8_t key, boolean isKeyDownEvent);
	void toggleM4Lock();
	
	
	public:
	NeoReportParser() : EnhancedKeyboardReportParser(), neoModifiers(), applyMap(true), m4Lock(false), composeState(false), activeSequence(){}
	void setLedState(uint8_t leds);
	void install();
	void help();
	
};

#endif