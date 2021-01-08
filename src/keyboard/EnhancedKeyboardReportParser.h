#include <hidboot.h>

#ifndef __ENHANCEDKEYBOARDREPORTPARSER_H__
#define __ENHANCEDKEYBOARDREPORTPARSER_H__
class EnhancedKeyboardReportParser : public HIDReportParser {
	protected:

	union {
		KBDINFO kbdInfo;
		uint8_t bInfo[sizeof (KBDINFO)];
	} prevState;

	union {
		KBDLEDS kbdLeds;
		uint8_t bLeds;
	} kbdLockingKeys;
	
	public:

	EnhancedKeyboardReportParser() {
		kbdLockingKeys.bLeds = 0;
	};

	void Parse(USBHID *hid, bool is_rpt_id, uint8_t len, uint8_t *buf);

	protected:

	virtual uint8_t HandleLockingKeys(USBHID* hid, uint8_t key) {
	};

	virtual void OnControlKeysChanged(uint8_t before __attribute__((unused)), uint8_t after __attribute__((unused))) {
	};

	virtual void OnKeyDown(uint8_t mod __attribute__((unused)), uint8_t key __attribute__((unused))) {
	};

	virtual void OnKeyUp(uint8_t mod __attribute__((unused)), uint8_t key __attribute__((unused))) {
	};
};

#endif //__ENHANCEDKEYBOARDREPORTPARSER_H__
