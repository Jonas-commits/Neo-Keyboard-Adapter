#include "Compose.h"

/* 
 * Little Endian, hack to give the information of length directly instead of null-termination
 */
const Node Compose::root[] = { {{1, 0}, root}, 
	{{L3, KEY_TAB}, l3Tab}
};
	
const Node Compose::l3Tab[] = { {{3, 0}, l3Tab}, 
	{{L1, KEY_G}, l3TabG},
	{{L3, KEY_Q}, l3TabL3Q},
	{{L3, KEY_TAB}, composeSymbols}
};

const Node Compose::l3TabG[] = { {{1, 0}, l3TabG},
	{{L1, KEY_SPACE}, composeSymbols + 1}
};

const Node Compose::l3TabL3Q[] = { {{1, 0}, l3TabL3Q},
	{{L1, KEY_G}, composeSymbols + 1}
};

const uint16_t Compose::composeSymbols[] = {0x266B, 0x25CC};

uint16_t Compose::transition(uint8_t layer, uint8_t key){
	Node* cur = currentNode;
	uint16_t len = currentNode->x.len;
	boolean found = false;
	
	//stupid linear search, could be optimized
	for (uint16_t i = 0; i < len; i++){
		cur++;
		if(cur->x.layeredKey.layer == layer && cur->x.layeredKey.keycode == key) { //found
			
			//pointer points to element of composeSymbols List
			if (cur->ptr.value >= (void*) composeSymbols && 
				cur->ptr.value < (void*) composeSymbols + sizeof(composeSymbols)) {
				
				currentNode = const_cast<Node*>(root);
				return *(cur->ptr.unicode);
				
			} else {
				currentNode = const_cast<Node*>(cur->ptr.nodes);
				return 1; 
			}
		}
	}
	
	//not found
	currentNode = const_cast<Node*>(root);
	return 0;
}
