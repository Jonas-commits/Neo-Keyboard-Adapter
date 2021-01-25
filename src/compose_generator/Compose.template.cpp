#include "Compose.gen.h"

//generated compose tree
<GENERATOR>

/*
 * Mapping of Keys which exist multiple times on keyboard
 * left Sequence will be remapped right sequence for lookup
*/
const LayeredKey Compose::aliases[][2] {
	{{L3, KEY_L}, {L1, KEY_MINUS}},
	{{L1, KEYPAD_SUBTRACT}, {L1, KEY_MINUS}},
	{{L1, KEYPAD_1}, {L1, KEY_1}},
	{{L1, KEYPAD_2}, {L1, KEY_2}},
	{{L1, KEYPAD_3}, {L1, KEY_3}},
	{{L1, KEYPAD_4}, {L1, KEY_4}},
	{{L1, KEYPAD_5}, {L1, KEY_5}},
	{{L1, KEYPAD_6}, {L1, KEY_6}},
	{{L1, KEYPAD_7}, {L1, KEY_7}},
	{{L1, KEYPAD_8}, {L1, KEY_8}},
	{{L1, KEYPAD_9}, {L1, KEY_9}},
	{{L1, KEYPAD_0}, {L1, KEY_0}},
	{{L1, KEYPAD_DIVIDE}, {L3, KEY_S}},
	{{L1, KEYPAD_MULTIPLY}, {L3, KEY_G}},
	{{L1, KEYPAD_ADD}, {L3, KEY_N}},
};

LayeredKey Compose::getAlias(uint8_t layer, uint8_t key) {
	for(int16_t i = 0; i < (sizeof(aliases) / sizeof(aliases[0])); i++){
		if(layer == aliases[i][0].layer && key == aliases[i][0].key){
			return aliases[i][1];
		}
	}
	return {0,0};
}

uint16_t Compose::transition(uint8_t layer, uint8_t key) {
	Node* cur = currentNode;
	Node val_cur;
	
	LayeredKey alias = getAlias(layer, key);
	if(alias.layer != 0 && alias.key != 0){
		layer = alias.layer;
		key = alias.key;
	}
	
	do {
		memcpy_P(&val_cur, cur, sizeof(val_cur));
		if (val_cur.layeredKey.layer == layer && val_cur.layeredKey.keycode == key) { //found
			if (val_cur.layeredKey.isLeaf) {
				currentNode = const_cast<Node*>(root);
				return val_cur.payload.unicode;
				
				} else { //found, waiting for next key
				currentNode = const_cast<Node*>(val_cur.payload.nodes);
				return 1;
			}
		}
		cur++;
	} while (val_cur.layeredKey.isLastElement == 0);
	
	//not found
	currentNode = const_cast<Node*>(root);
	return 0;
}

void Compose::reset(){
	currentNode = const_cast<Node*>(root);
}