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
	
	//Transition 0
	const static Node root[] PROGMEM;
	
	//Transition 1
	const static Node l3Tab[] PROGMEM;
	const static Node l1Equal[] PROGMEM;
	const static Node l2Equal[] PROGMEM;
	const static Node l3Equal[] PROGMEM;
	const static Node l4Equal[] PROGMEM;
	const static Node l5Equal[] PROGMEM;
	const static Node l6Equal[] PROGMEM;
	const static Node l1RBr[] PROGMEM;
	const static Node l2RBr[] PROGMEM;
	const static Node l3RBr[] PROGMEM;
	const static Node l4RBr[] PROGMEM;
	const static Node l5RBr[] PROGMEM;
	const static Node l6RBr[] PROGMEM;
	const static Node l1Tilde[] PROGMEM;
	const static Node l2Tilde[] PROGMEM;
	const static Node l3Tilde[] PROGMEM;
	const static Node l4Tilde[] PROGMEM;
	const static Node l5Tilde[] PROGMEM;
	const static Node l6Tilde[] PROGMEM;
	
	//Transition 2
	const static Node l3TabB[] PROGMEM;
	const static Node l3TabE[] PROGMEM;
	const static Node l3TabL2E[] PROGMEM;
	const static Node l3TabL3E[] PROGMEM;
	const static Node l3TabL2F[] PROGMEM;
	const static Node l3TabG[] PROGMEM;
	const static Node l3TabH[] PROGMEM;
	const static Node l3TabL2H[] PROGMEM;
	const static Node l3TabL3H[] PROGMEM;
	const static Node l3TabJ[] PROGMEM;
	const static Node l3TabL2J[] PROGMEM;
	const static Node l3TabK[] PROGMEM;
	const static Node l3TabL2K[] PROGMEM;
	const static Node l3TabL[] PROGMEM;
	const static Node l3TabL2L[] PROGMEM;
	const static Node l3TabO[] PROGMEM;
	const static Node l3TabL2O[] PROGMEM;
	const static Node l3TabL3Q[] PROGMEM;
	const static Node l3TabR[] PROGMEM;
	const static Node l3TabS[] PROGMEM;
	const static Node l3TabL2S[] PROGMEM;
	const static Node l3TabL3U[] PROGMEM;
	const static Node l3TabV[] PROGMEM;
	const static Node l3TabL3W[] PROGMEM;
	const static Node l3TabL3Y[] PROGMEM;
	const static Node l3Tab1[] PROGMEM;
	const static Node l3Tab2[] PROGMEM;
	const static Node l3Tab3[] PROGMEM;
	const static Node l3Tab4[] PROGMEM;
	const static Node l3TabL54[] PROGMEM;
	const static Node l3Tab5[] PROGMEM;
	const static Node l3TabL55[] PROGMEM;
	const static Node l3Tab7[] PROGMEM;
	const static Node l3TabL5Space[] PROGMEM;
	const static Node l3TabL3LBr[] PROGMEM;
	const static Node l3TabSemicolon [] PROGMEM;
	const static Node l3TabL2Semicolon[] PROGMEM;
	const static Node l3TabL3Semicolon[] PROGMEM;
	const static Node l3TabL6Semicolon[] PROGMEM;
	const static Node l3TabRBr[] PROGMEM;
	const static Node l3TabPeriod[] PROGMEM;
	const static Node l3TabL2Period[] PROGMEM;
	const static Node l3TabMinus[] PROGMEM;
	const static Node l3TabL2Kp7[] PROGMEM;
	const static Node l3TabL2Kp8[] PROGMEM;
	const static Node l3TabL2Kp9[] PROGMEM;
	const static Node l3TabL2Kp0[] PROGMEM;
	const static Node l3TabL6Kp0[] PROGMEM;
	const static Node l6EqualL3Tab[] PROGMEM;
	const static Node l6EqualL2Equal[] PROGMEM;
	const static Node l2TildeL3Tab[] PROGMEM;
	const static Node l3TildeL2Equal[] PROGMEM;
	const static Node l3TildeL4RBr[] PROGMEM;
	const static Node l3TildeL6RBr[] PROGMEM;
	
	//Transition 3
	const static Node l3TabGV[] PROGMEM;
	const static Node l3TabK1[] PROGMEM;
	const static Node l3TabL2K1[] PROGMEM;
	const static Node l3TabRJ[] PROGMEM;
	const static Node l3TabRSlash[] PROGMEM;
	const static Node l3TabVG[] PROGMEM;
	const static Node l3Tab1L3H[] PROGMEM;
	const static Node l3Tab1L4H[] PROGMEM;
	const static Node l3Tab1L3Y[] PROGMEM;
	const static Node l3Tab1L4Y[] PROGMEM;
	const static Node l3TabSemicolonD[] PROGMEM;
	const static Node l3TabPeriodSlash[] PROGMEM;
	const static Node l6EqualL3TabD[] PROGMEM;
	const static Node l6EqualL3TabL2D[] PROGMEM;
	const static Node l2TildeL3TabSemicolon[] PROGMEM;
	const static Node l2TildeL3TabL2Semicolon[] PROGMEM;
	
	//characters
	const static uint16_t composeSymbols[] PROGMEM;


	public:
	Compose() : currentNode(const_cast<Node*>(root)){}
		
	uint16_t transition(uint8_t layer, uint8_t key);
	void reset();
	

}; //Compose

#endif //__COMPOSE_H__