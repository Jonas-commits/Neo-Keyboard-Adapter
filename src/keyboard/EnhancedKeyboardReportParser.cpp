#include "EnhancedKeyboardReportParser.h"

void EnhancedKeyboardReportParser::Parse(USBHID *hid, bool is_rpt_id __attribute__((unused)), uint8_t len __attribute__((unused)), uint8_t *buf) {
	// On error - return
	if (buf[2] == 1){
		return;
	}

	// provide event for changed control key state
	if (prevState.bInfo[0x00] != buf[0x00]) {
		OnControlKeysChanged(prevState.bInfo[0x00], buf[0x00]);
		HandleLockingKeys(hid, buf[0]);
	}

	for (uint8_t i = 2; i < 8; i++) {
		bool down = false;
		bool up = false;

		for (uint8_t j = 2; j < 8; j++) {
			if (buf[i] == prevState.bInfo[j] && buf[i] != 1)
			down = true;
			if (buf[j] == prevState.bInfo[i] && prevState.bInfo[i] != 1)
			up = true;
		}
		if (!down) {
			OnKeyDown(*buf, buf[i]);
		}
		if (!up){
			OnKeyUp(prevState.bInfo[0], prevState.bInfo[i]);
			HandleLockingKeys(hid, buf[i]);
		}
	}
	for (uint8_t i = 0; i < 8; i++) {
		prevState.bInfo[i] = buf[i];
	}
	
};