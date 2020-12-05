#ifndef NEO_REPORT_PARSER_H
#define NEO_REPORT_PARSER_H

#include <hidboot.h>
#include <SPI.h>
#include <HID-Project.h>

struct NeoModifiers {
	boolean bmLeftCtrl : 1;
	boolean bmLeftShift : 1;
	boolean bmLeftAlt : 1;
	boolean bmLeftGUI : 1;
	boolean bmRightCtrl : 1;
	boolean bmRightShift : 1;
	boolean bmRightAlt : 1;
	boolean bmRightGUI : 1;
	boolean bmLeft3 : 1;
	boolean bmRight3 : 1;
	boolean bmLeft4 : 1;
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