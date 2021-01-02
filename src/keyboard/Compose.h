#ifndef __COMPOSE_H__
#define __COMPOSE_H__

#include "NeoIncludes.h"

/*
* Node used as element in static defined lookup tree data structure.
* The tree is static, therefore no methods for removing/adding elements,
* everything has to be done in this class definition. 
* 
*  When first element in list: data taken from union,
  data = list length when nodes != nullptr,
  data = Unicode character when nodes == nullptr
  
  When not first element in list: layeredKey taken from union, 
  nodes = first list element of list to continue search for next keystroke
*/

struct Node {
	union {
		struct {
			uint8_t layer;
			uint8_t keycode;
		} layeredKey;
		uint16_t data;
	} x;
	Node* nodes;
};

class Compose
{
	private:
	Node* currentNode;

	//the lookup data
	const static Node root[];
	
	//composition steps
	const static Node l3Tab[];
	const static Node l3TabG[];
	const static Node l3TabL3Q[];
	
	//Unicode characters
	const static Node uniNote[];
	const static Node uniDottedCircle[];

	public:
	Compose() : currentNode(const_cast<Node*>(root)){}
		
	uint16_t transition(uint8_t layer, uint8_t key);

}; //Compose

#endif //__COMPOSE_H__
