#include "Compose.h"

/* 
 * Little Endian! as only initialization of first union member is supported for
 * C++ 11, and a union is unfortunately the only solution to initialize this
 * in a ROM-saving way
 */
const Node Compose::root[] = { {{1, 0}, root}, 
	{{L3, KEY_TAB}, l3Tab}
};
	
//composition steps
const Node Compose::l3Tab[] = { {{3, 0}, l3Tab}, 
	{{L1, KEY_G}, l3TabG},
	{{L3, KEY_Q}, l3TabL3Q},
	{{L3, KEY_TAB}, uniNote}
};

const Node Compose::l3TabG[] = { {{1, 0}, l3TabG},
	{{L1, KEY_SPACE}, uniDottedCircle}
};

const Node Compose::l3TabL3Q[] = { {{1, 0}, l3TabL3Q},
	{{L1, KEY_G}, uniDottedCircle}
};

//Unicode characters
const Node Compose::uniNote[] = { {{0x6B, 0x26}, nullptr} };
const Node Compose::uniDottedCircle[] = { {{0xCC, 0x25}, nullptr} };

uint16_t Compose::transition(uint8_t layer, uint8_t key){
	Node* cur = currentNode;
	uint16_t len = currentNode->x.data;
	boolean found = false;
	
	//stupid linear search, could be optimized
	for (uint16_t i = 0; i < len; i++){
		cur++;
		if(cur->x.layeredKey.layer == layer && cur->x.layeredKey.keycode == key) { //found
			if (cur->nodes->nodes == nullptr) { //is leaf
				currentNode = const_cast<Node*>(root);
				return cur->nodes->x.data;
			} else {
				currentNode = const_cast<Node*>(cur->nodes);
				return 1; 
			}
		}
	}
	
	//not found
	currentNode = const_cast<Node*>(root);
	return 0;
}
