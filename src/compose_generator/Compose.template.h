#ifndef __COMPOSE_H__
#define __COMPOSE_H__

#include "NeoIncludes.h"

/*
 * Node used as element in static defined lookup tree data structure.
 * The tree is static, therefore no methods for removing/adding elements,
 * everything has to be done in this class definition. 
 * 
 * When first element in list: Element only indicates length, instead
 * of just 0-terminating this stuff, as it provides more information
 * by using same memory, for a faster search algorithm if needed
 * Endianess is little endian and only first union can be defined in C++ 11,
 * Thats why size information is written down like this.

 * Pointer points to either next node or unicode symbol. This is detected by 
 * address range comparison.

*/

struct Node {
	union {
		struct {
			uint8_t layer;
			uint8_t keycode;
		} layeredKey;
		uint16_t len;
	} x;
	union {
		void* value;
		Node* nodes;
		uint16_t* unicode;
	} ptr;
};


class Compose
{
	private:
	Node* currentNode;

<GENERATOR>

	const static uint16_t composeSymbols[] PROGMEM;

	public:
	Compose() : currentNode(const_cast<Node*>(root)){}
		
	uint16_t transition(uint8_t layer, uint8_t key);
	void reset();
	


}; //Compose

#endif //__COMPOSE_H__