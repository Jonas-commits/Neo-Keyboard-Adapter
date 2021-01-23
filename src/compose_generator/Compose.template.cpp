#include "Compose.gen.h"

//generated compose tree
<GENERATOR>

uint16_t Compose::transition(uint8_t layer, uint8_t key) {
	Node* cur = currentNode;
	Node val_cur;

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