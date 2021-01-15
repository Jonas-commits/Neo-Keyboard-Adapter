#include "Compose.gen.h"

//generated compose tree
<GENERATOR>

uint16_t Compose::transition(uint8_t layer, uint8_t key) {
	Node* cur = currentNode;
	Node val_cur;
	memcpy_P(&val_cur, currentNode, sizeof(val_cur));
	uint16_t len = (val_cur.ptr.value == nullptr) ? val_cur.x.len : 1; 

	//stupid linear search, could be optimized
	while (len--) {
		memcpy_P(&val_cur, cur, sizeof(val_cur));
		if (val_cur.ptr.value != nullptr && //discard length element
			val_cur.x.layeredKey.layer == layer && 
			val_cur.x.layeredKey.keycode == key) { //found
			
			//pointer points to element of composeSymbols List
			if (val_cur.ptr.value >= composeSymbols && 
				val_cur.ptr.value <  (char*) composeSymbols + sizeof(composeSymbols)) {
				
				currentNode = const_cast<Node*>(root);
				return pgm_read_word(val_cur.ptr.unicode);
				
			} else { //found, waiting for next key
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