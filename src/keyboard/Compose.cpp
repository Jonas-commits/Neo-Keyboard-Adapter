#include "Compose.h"

/* 
 * Little Endian, hack to give the information of length directly instead of null-termination
 */
const Node Compose::root[] PROGMEM = { {{2, 0}, nullptr}, 
	{{L3, KEY_TAB}, l3Tab}
};
	
const Node Compose::l3Tab[] PROGMEM = { {{9, 0}, nullptr}, 
	{{L1, KEY_G}, l3TabG},
	{{L3, KEY_L}, l3TabMinus},
	{{L3, KEY_Q}, l3TabL3Q},
	{{L1, KEY_W}, l3TabL3W},
	{{L3, KEY_TAB}, composeSymbols + 0},
	{{L1, KEY_MINUS}, l3TabMinus},
	{{L3, KEY_RIGHT_BRACE}, l3TabRBr},
	{{L1, KEYPAD_SUBTRACT}, l3TabMinus}
};

const Node Compose::l3TabG[] PROGMEM     = { {{L1, KEY_SPACE}, composeSymbols + 1} };
const Node Compose::l3TabL3Q[] PROGMEM   = { {{L1, KEY_G}, composeSymbols + 1} };
const Node Compose::l3TabL3W[] PROGMEM   = { {{L3, KEY_W}, composeSymbols + 2} };
const Node Compose::l3TabRBr[] PROGMEM   = { {{L3, KEY_RIGHT_BRACE}, composeSymbols + 3} };
const Node Compose::l3TabMinus[] PROGMEM = { {{3, 0}, nullptr}, 
	{{L1, KEY_U}, composeSymbols + 4},
	{{L2, KEY_U}, composeSymbols + 5}
};
	
const uint16_t Compose::composeSymbols[] PROGMEM = {
	0x266B, 0x25CC, 0x0332, 0x02BC, 0x0127, 0x0126
};

uint16_t Compose::transition(uint8_t layer, uint8_t key) {
	Node* cur = currentNode;
	Node val_cur;
	memcpy_P(&val_cur, currentNode, sizeof(val_cur));
	uint16_t len = (val_cur.ptr.value == nullptr) ? val_cur.x.len : 1; 

	boolean found = false;
	
	//stupid linear search, could be optimized
	for (uint16_t i = 0; i < len; i++) {
		memcpy_P(&val_cur, cur, sizeof(val_cur));
		if(val_cur.ptr.value != nullptr && //discard length element
			val_cur.x.layeredKey.layer == layer && 
			val_cur.x.layeredKey.keycode == key) { //found
			
			//pointer points to element of composeSymbols List
			if (val_cur.ptr.value >= (void*) composeSymbols && 
				val_cur.ptr.value < (void*) composeSymbols + sizeof(composeSymbols)) {
				
				currentNode = const_cast<Node*>(root);
				return pgm_read_word(val_cur.ptr.unicode);
				
			} else {
				currentNode = const_cast<Node*>(val_cur.ptr.nodes);
				return 1; 
			}
		}
		cur++;
	}
	
	//not found
	currentNode = const_cast<Node*>(root);
	return 0;
}
