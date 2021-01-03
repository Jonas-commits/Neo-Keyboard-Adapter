#include "Compose.h"

/* 
 * Little Endian, hack to give the information of length directly instead of null-termination
 */
const Node Compose::root[] PROGMEM = { {{2, 0}, nullptr}, 
	{{L3, KEY_TAB}, l3Tab}
};
	
const Node Compose::l3Tab[] PROGMEM = { {{25, 0}, nullptr}, 
	{{L1, KEY_B}, l3TabB},
	{{L1, KEY_E}, l3TabE},
	{{L2, KEY_E}, l3TabL2E},
	{{L2, KEY_F}, l3TabL2F},
	{{L1, KEY_G}, l3TabG},
	{{L1, KEY_H}, l3TabH},
	{{L2, KEY_H}, l3TabL2H},
	{{L1, KEY_J}, l3TabJ},
	{{L2, KEY_J}, l3TabL2J},
	{{L1, KEY_L}, l3TabL},
	{{L2, KEY_L}, l3TabL2L},
	{{L3, KEY_L}, l3TabMinus},
	{{L1, KEY_O}, l3TabO},
	{{L2, KEY_O}, l3TabL2O},
	{{L3, KEY_Q}, l3TabL3Q},
	{{L1, KEY_S}, l3TabS},
	{{L2, KEY_S}, l3TabL2S},
	{{L1, KEY_W}, l3TabL3W},
	{{L3, KEY_TAB}, composeSymbols + 0},
	{{L1, KEY_MINUS}, l3TabMinus},
	{{L1, KEY_SEMICOLON}, l3TabSemicolon},
	{{L2, KEY_SEMICOLON}, l3TabL2Semicolon},
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
const Node Compose::l3TabH[] PROGMEM     = { {{3, 0}, nullptr},
	{{L1, KEY_L}, composeSymbols + 21},
	{{L1, KEY_COMMA}, composeSymbols + 6}
};
const Node Compose::l3TabL2H[] PROGMEM   = { {{L1, KEY_COMMA}, composeSymbols + 7} };
const Node Compose::l3TabL[] PROGMEM     = { {{L1, KEY_COMMA}, composeSymbols + 8} };
const Node Compose::l3TabL2L[] PROGMEM   = { {{L1, KEY_COMMA}, composeSymbols + 9} };
const Node Compose::l3TabL2F[] PROGMEM   = { {{L2, KEY_F}, composeSymbols + 10} };
const Node Compose::l3TabE[] PROGMEM     = { {{3, 0}, nullptr},
	{{L1, KEY_SLASH}, composeSymbols + 29},
	{{L1, KEY_PERIOD}, composeSymbols + 11},
};
const Node Compose::l3TabL2E[] PROGMEM   = { {{4, 0}, nullptr},
	{{L1, KEY_SLASH}, composeSymbols + 27},
	{{L2, KEY_SLASH}, composeSymbols + 28},
	{{L1, KEY_PERIOD}, composeSymbols + 12}
};
const Node Compose::l3TabS[] PROGMEM     = { {{3, 0}, nullptr},
	{{L1, KEY_S}, composeSymbols + 13},
	{{L1, KEY_SLASH}, composeSymbols + 23},
};
const Node Compose::l3TabL2S[] PROGMEM   = { {{3, 0}, nullptr},
	{{L2, KEY_S}, composeSymbols + 14},
	{{L2, KEY_SLASH}, composeSymbols + 22},
};
const Node Compose::l3TabB[] PROGMEM     = { {{3, 0}, nullptr},
	{{L1, KEY_B}, composeSymbols + 15},
	{{L1, KEY_U}, composeSymbols + 15}
};
const Node Compose::l3TabO[] PROGMEM     =  { {{4, 0}, nullptr},
	{{L1, KEY_E}, composeSymbols + 16},
	{{L1, KEY_O}, composeSymbols + 17},
	{{L1, KEY_S}, composeSymbols + 18}
};
const Node Compose::l3TabL2O[] PROGMEM     =  { {{3, 0}, nullptr},
	{{L1, KEY_E}, composeSymbols + 19},
	{{L1, KEY_S}, composeSymbols + 20}
};
const Node Compose::l3TabSemicolon[] PROGMEM    =  { {{L1, KEY_B}, composeSymbols + 24} };
const Node Compose::l3TabL2Semicolon[] PROGMEM  =  { {{3, 0}, nullptr},
	{{L1, KEY_B}, composeSymbols + 25},
	{{L2, KEY_B}, composeSymbols + 26}
};
const Node Compose::l3TabJ[] PROGMEM   = { {{L1, KEY_SLASH}, composeSymbols + 30} };
const Node Compose::l3TabL2J[] PROGMEM  =  { {{3, 0}, nullptr},
	{{L1, KEY_SLASH}, composeSymbols + 31},
	{{L2, KEY_SLASH}, composeSymbols + 32}
};

const uint16_t Compose::composeSymbols[] PROGMEM = {
	0x266B, 0x25CC, 0x0332, 0x02BC, 0x0127, 0x0126, 0x0219, 0x0218,
	0x021B, 0x021A, 0x018F, 0x0140, 0x013F, 0x0131, 0x0130, 0x0292,
	0xFB02, 0xFB00, 0xFB01, 0xFB04, 0xFB03, 0xFB06, 0x0132, 0x0133,
	0x01F3, 0x01F2, 0x01F1, 0x01C8, 0x01C7, 0x01C9, 0x01CC, 0x01CB,
	0x01CA
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
		if (val_cur.ptr.value != nullptr && //discard length element
			val_cur.x.layeredKey.layer == layer && 
			val_cur.x.layeredKey.keycode == key) { //found
			
			//pointer points to element of composeSymbols List
			if (val_cur.ptr.value >= composeSymbols && 
				val_cur.ptr.value <  composeSymbols + sizeof(composeSymbols)) {
				
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

void Compose::reset(){
	currentNode = const_cast<Node*>(root);
}
