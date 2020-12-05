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

	protected:
	void OnControlKeysChanged(uint8_t before, uint8_t after);

	void OnKeyDown  (uint8_t mod, uint8_t key);
	void OnKeyUp  (uint8_t mod, uint8_t key);
	void OnKeyPressed(uint8_t key);
	
	public:
	NeoReportParser();
	
};

#endif