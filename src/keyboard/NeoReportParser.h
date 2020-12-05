#ifndef NEO_REPORT_PARSER_H
#define NEO_REPORT_PARSER_H

#include <hidboot.h>
#include <SPI.h>
#include <HID-Project.h>

class NeoReportParser : public KeyboardReportParser
{
	private:
	void PrintKey(uint8_t m, uint8_t key);
	
	protected:
	void OnControlKeysChanged(uint8_t before, uint8_t after);

	void OnKeyDown  (uint8_t mod, uint8_t key);
	void OnKeyUp  (uint8_t mod, uint8_t key);
	void OnKeyPressed(uint8_t key);
	
	public:
	
};

#endif