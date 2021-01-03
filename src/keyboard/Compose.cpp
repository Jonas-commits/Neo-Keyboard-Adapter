#include "Compose.h"

/*********************************** Layer 0 **********************************/
const Node Compose::root[2] PROGMEM              = { {{2, 0}, nullptr}, 
	{{L3, KEY_TAB}, l3Tab}
};


/*********************************** Layer 1 **********************************/
const Node Compose::l3Tab[37] PROGMEM            = { {{37, 0}, nullptr}, 
	{{L1, KEY_B}, l3TabB},
	{{L1, KEY_E}, l3TabE},
	{{L2, KEY_E}, l3TabL2E},
	{{L2, KEY_F}, l3TabL2F},
	{{L1, KEY_G}, l3TabG},
	{{L1, KEY_H}, l3TabH},
	{{L2, KEY_H}, l3TabL2H},
	{{L3, KEY_H}, l3TabL3H},
	{{L1, KEY_J}, l3TabJ},
	{{L2, KEY_J}, l3TabL2J},
	{{L1, KEY_K}, l3TabK},
	{{L2, KEY_K}, l3TabL2K},
	{{L1, KEY_L}, l3TabL},
	{{L2, KEY_L}, l3TabL2L},
	{{L3, KEY_L}, l3TabMinus},
	{{L1, KEY_O}, l3TabO},
	{{L2, KEY_O}, l3TabL2O},
	{{L3, KEY_Q}, l3TabL3Q},
	{{L1, KEY_S}, l3TabS},
	{{L2, KEY_S}, l3TabL2S},
	{{L1, KEY_W}, l3TabL3W},
	{{L3, KEY_Y}, l3TabL3Y},
	{{L1, KEY_1}, l3Tab1},
	{{L1, KEY_2}, l3Tab2},
	{{L1, KEY_7}, l3Tab7},
	{{L3, KEY_TAB}, composeSymbols + 0},
	{{L5, KEY_SPACE}, l3TabL5Space},
	{{L1, KEY_MINUS}, l3TabMinus},
	{{L1, KEY_SEMICOLON}, l3TabSemicolon},
	{{L2, KEY_SEMICOLON}, l3TabL2Semicolon},
	{{L3, KEY_RIGHT_BRACE}, l3TabRBr},
	{{L1, KEYPAD_SUBTRACT}, l3TabMinus},
	{{L1, KEYPAD_1}, l3Tab1},
	{{L1, KEYPAD_2}, l3Tab2},
	{{L1, KEYPAD_7}, l3Tab7},
	{{L2, KEYPAD_9}, l3TabL2Kp9}
};


/*********************************** Layer 2 **********************************/
const Node Compose::l3TabG[1] PROGMEM            = { {{L1, KEY_SPACE}, composeSymbols + 1} };
	
const Node Compose::l3TabL3Q[3] PROGMEM          = { {{3, 0}, nullptr},
	{{L3, KEY_C}, composeSymbols + 64},
	{{L1, KEY_G}, composeSymbols + 1}
};
	
const Node Compose::l3TabL3W[1] PROGMEM          = { {{L3, KEY_W}, composeSymbols + 2} };
	
const Node Compose::l3TabRBr[1] PROGMEM          = { {{L3, KEY_RIGHT_BRACE}, composeSymbols + 3} };
	
const Node Compose::l3TabMinus[3] PROGMEM        = { {{3, 0}, nullptr},
	{{L1, KEY_U}, composeSymbols + 4},
	{{L2, KEY_U}, composeSymbols + 5}
};

const Node Compose::l3TabH[3] PROGMEM            = { {{3, 0}, nullptr},
	{{L1, KEY_L}, composeSymbols + 21},
	{{L1, KEY_COMMA}, composeSymbols + 6}
};

const Node Compose::l3TabL2H[1] PROGMEM          = { {{L1, KEY_COMMA}, composeSymbols + 7} };
	
const Node Compose::l3TabL[1] PROGMEM            = { {{L1, KEY_COMMA}, composeSymbols + 8} };
	
const Node Compose::l3TabL2L[1] PROGMEM          = { {{L1, KEY_COMMA}, composeSymbols + 9} };
	
const Node Compose::l3TabL2F[1] PROGMEM          = { {{L2, KEY_F}, composeSymbols + 10} };
	
const Node Compose::l3TabE[3] PROGMEM            = { {{3, 0}, nullptr},
	{{L1, KEY_SLASH}, composeSymbols + 29},
	{{L1, KEY_PERIOD}, composeSymbols + 11},
};

const Node Compose::l3TabL2E[4] PROGMEM          = { {{4, 0}, nullptr},
	{{L1, KEY_SLASH}, composeSymbols + 27},
	{{L2, KEY_SLASH}, composeSymbols + 28},
	{{L1, KEY_PERIOD}, composeSymbols + 12}
};

const Node Compose::l3TabS[3] PROGMEM            = { {{3, 0}, nullptr},
	{{L1, KEY_S}, composeSymbols + 13},
	{{L1, KEY_SLASH}, composeSymbols + 23}
};

const Node Compose::l3TabL2S[3] PROGMEM          = { {{3, 0}, nullptr},
	{{L2, KEY_S}, composeSymbols + 14},
	{{L2, KEY_SLASH}, composeSymbols + 22}
};

const Node Compose::l3TabB[3] PROGMEM            = { {{3, 0}, nullptr},
	{{L1, KEY_B}, composeSymbols + 15},
	{{L1, KEY_U}, composeSymbols + 15}
};

const Node Compose::l3TabO[4] PROGMEM            = { {{4, 0}, nullptr},
	{{L1, KEY_E}, composeSymbols + 16},
	{{L1, KEY_O}, composeSymbols + 17},
	{{L1, KEY_S}, composeSymbols + 18}
};

const Node Compose::l3TabL2O[3] PROGMEM          = { {{3, 0}, nullptr},
	{{L1, KEY_E}, composeSymbols + 19},
	{{L1, KEY_S}, composeSymbols + 20}
};

const Node Compose::l3TabSemicolon[1] PROGMEM    =  { {{L1, KEY_B}, composeSymbols + 24} };

const Node Compose::l3TabL2Semicolon[3] PROGMEM  =  { {{3, 0}, nullptr},
	{{L1, KEY_B}, composeSymbols + 25},
	{{L2, KEY_B}, composeSymbols + 26}
};

const Node Compose::l3TabJ[1] PROGMEM            = { {{L1, KEY_SLASH}, composeSymbols + 30} };

const Node Compose::l3TabL2J[3] PROGMEM          =  { {{3, 0}, nullptr},
	{{L1, KEY_SLASH}, composeSymbols + 31},
	{{L2, KEY_SLASH}, composeSymbols + 32}
};

const Node Compose::l3TabL2K[19] PROGMEM         = { {{19, 0}, nullptr},
	{{L1, KEY_1}, l3TabL2K1},
	{{L1, KEY_2}, composeSymbols + 34},
	{{L1, KEY_3}, composeSymbols + 35},
	{{L1, KEY_4}, composeSymbols + 36},
	{{L1, KEY_5}, composeSymbols + 37},
	{{L1, KEY_6}, composeSymbols + 38},
	{{L1, KEY_7}, composeSymbols + 39},
	{{L1, KEY_8}, composeSymbols + 40},
	{{L1, KEY_9}, composeSymbols + 41},
	{{L1, KEYPAD_1}, l3TabL2K1},
	{{L1, KEYPAD_2}, composeSymbols + 34},
	{{L1, KEYPAD_3}, composeSymbols + 35},
	{{L1, KEYPAD_4}, composeSymbols + 36},
	{{L1, KEYPAD_5}, composeSymbols + 37},
	{{L1, KEYPAD_6}, composeSymbols + 38},
	{{L1, KEYPAD_7}, composeSymbols + 39},
	{{L1, KEYPAD_8}, composeSymbols + 40},
	{{L1, KEYPAD_9}, composeSymbols + 41}
};

const Node Compose::l3TabK[19] PROGMEM           = { {{19, 0}, nullptr},
	{{L1, KEY_1}, l3TabK1},
	{{L1, KEY_2}, composeSymbols + 46},
	{{L1, KEY_3}, composeSymbols + 47},
	{{L1, KEY_4}, composeSymbols + 48},
	{{L1, KEY_5}, composeSymbols + 49},
	{{L1, KEY_6}, composeSymbols + 50},
	{{L1, KEY_7}, composeSymbols + 51},
	{{L1, KEY_8}, composeSymbols + 52},
	{{L1, KEY_9}, composeSymbols + 53},
	{{L1, KEYPAD_1}, l3TabK1},
	{{L1, KEYPAD_2}, composeSymbols + 46},
	{{L1, KEYPAD_3}, composeSymbols + 47},
	{{L1, KEYPAD_4}, composeSymbols + 48},
	{{L1, KEYPAD_5}, composeSymbols + 49},
	{{L1, KEYPAD_6}, composeSymbols + 50},
	{{L1, KEYPAD_7}, composeSymbols + 51},
	{{L1, KEYPAD_8}, composeSymbols + 52},
	{{L1, KEYPAD_9}, composeSymbols + 53}
};

const Node Compose::l3Tab1[5] PROGMEM            = { {{5, 0}, nullptr},
	{{L3, KEY_H}, l3Tab1L3H},
	{{L4, KEY_H}, l3Tab1L4H},
	{{L3, KEY_Y}, l3Tab1L3Y},
	{{L4, KEY_Y}, l3Tab1L4Y}
};
	
const Node Compose::l3Tab2[3] PROGMEM            = { {{3, 0}, nullptr},
	{{L3, KEY_H}, composeSymbols + 58},
	{{L3, KEY_Y}, composeSymbols + 57}
};
	
const Node Compose::l3TabL3H[4] PROGMEM          = { {{4, 0}, nullptr},
	{{L3, KEY_Y}, composeSymbols + 59},
	{{L1, KEY_2}, composeSymbols + 58},
	{{L1, KEYPAD_2}, composeSymbols + 58}
};
	
const Node Compose::l3TabL3Y[4] PROGMEM          = { {{4, 0}, nullptr},
	{{L3, KEY_H}, composeSymbols + 60},
	{{L1, KEY_2}, composeSymbols + 57},
	{{L1, KEYPAD_2}, composeSymbols + 57}
};

const Node Compose::l3TabL2Kp9[1] PROGMEM        = { {{L2, KEYPAD_9}, composeSymbols + 63} };
	
const Node Compose::l3TabL5Space[1] PROGMEM      = { {{L5, KEY_SPACE}, composeSymbols + 65} };
	
const Node Compose::l3Tab7[3] PROGMEM            = { {{3, 0}, nullptr},
	{{L1, KEY_7}, composeSymbols + 66},
	{{L1, KEYPAD_7}, composeSymbols + 66}
};


/*********************************** Layer 3 **********************************/
const Node Compose::l3TabL2K1[8] PROGMEM         = { {{8, 0}, nullptr},
	{{L1, KEY_1}, composeSymbols + 43},
	{{L1, KEY_2}, composeSymbols + 44},
	{{L1, KEY_0}, composeSymbols + 42},
	{{L1, KEY_SPACE}, composeSymbols + 33},
	{{L1, KEYPAD_1}, composeSymbols + 43},
	{{L1, KEYPAD_2}, composeSymbols + 44},
	{{L1, KEYPAD_0}, composeSymbols + 42}
};

const Node Compose::l3TabK1[8] PROGMEM           = { {{8, 0}, nullptr},
	{{L1, KEY_1}, composeSymbols + 55},
	{{L1, KEY_2}, composeSymbols + 56},
	{{L1, KEY_0}, composeSymbols + 54},
	{{L1, KEY_SPACE}, composeSymbols + 45},
	{{L1, KEYPAD_1}, composeSymbols + 55},
	{{L1, KEYPAD_2}, composeSymbols + 56},
	{{L1, KEYPAD_0}, composeSymbols + 54}
};

const Node Compose::l3Tab1L3H[1] PROGMEM         = { {{L3, KEY_Y}, composeSymbols + 61} };
	
const Node Compose::l3Tab1L3Y[1] PROGMEM         = { {{L3, KEY_H}, composeSymbols + 61} };
	
const Node Compose::l3Tab1L4H[1] PROGMEM         = { {{L4, KEY_Y}, composeSymbols + 62} };

const Node Compose::l3Tab1L4Y[1] PROGMEM         = { {{L4, KEY_H}, composeSymbols + 62} };


/********************************* characters ********************************/
const uint16_t Compose::composeSymbols[] PROGMEM = {
	0x266B, 0x25CC, 0x0332, 0x02BC, 0x0127, 0x0126, 0x0219, 0x0218, //  8
	0x021B, 0x021A, 0x018F, 0x0140, 0x013F, 0x0131, 0x0130, 0x0292, // 16
	0xFB02, 0xFB00, 0xFB01, 0xFB04, 0xFB03, 0xFB06, 0x0132, 0x0133, // 24
	0x01F3, 0x01F2, 0x01F1, 0x01C8, 0x01C7, 0x01C9, 0x01CC, 0x01CB, // 32
	0x01CA, 0x2160, 0x2161, 0x2162, 0x2163, 0x2164, 0x2165, 0x2166, // 40
	0x2167, 0x2168, 0x2169, 0x216A, 0x216B, 0x2170, 0x2171, 0x2172, // 48
	0x2173, 0x2174, 0x2175, 0x2176, 0x2177, 0x2178, 0x2179, 0x217A, // 56
	0x217B, 0x203C, 0x2047, 0x2048, 0x2049, 0x203D, 0x2E18, 0x2021, // 64
	0x22EE, 0x002D, 0x204A
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
				val_cur.ptr.value <  (char*) composeSymbols + sizeof(composeSymbols)) {
				
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
