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

	const static Node root[] PROGMEM;
	const static Node OBJ_2966248738464[] PROGMEM;
	const static Node OBJ_2966249033136[] PROGMEM;
	const static Node OBJ_2966249033376[] PROGMEM;
	const static Node OBJ_2966249033296[] PROGMEM;
	const static Node OBJ_2966249053056[] PROGMEM;
	const static Node OBJ_2966249053376[] PROGMEM;
	const static Node OBJ_2966249053856[] PROGMEM;
	const static Node OBJ_2966249066560[] PROGMEM;
	const static Node OBJ_2966249066800[] PROGMEM;
	const static Node OBJ_2966249066960[] PROGMEM;
	const static Node OBJ_2966249067040[] PROGMEM;
	const static Node OBJ_2966249068320[] PROGMEM;
	const static Node OBJ_2966249068480[] PROGMEM;
	const static Node OBJ_2966249069360[] PROGMEM;
	const static Node OBJ_2966249069760[] PROGMEM;
	const static Node OBJ_2966249070000[] PROGMEM;
	const static Node OBJ_2966249070080[] PROGMEM;
	const static Node OBJ_2966249033216[] PROGMEM;
	const static Node OBJ_2966249068160[] PROGMEM;
	const static Node OBJ_2966249068560[] PROGMEM;
	const static Node OBJ_2966249053216[] PROGMEM;
	const static Node OBJ_2966249068240[] PROGMEM;
	const static Node OBJ_2966249054016[] PROGMEM;
	const static Node OBJ_2966249087280[] PROGMEM;
	const static Node OBJ_2966249087680[] PROGMEM;
	const static Node OBJ_2966249068880[] PROGMEM;
	const static Node OBJ_2966248738384[] PROGMEM;
	const static Node OBJ_2966248832512[] PROGMEM;
	const static Node OBJ_2966248832752[] PROGMEM;
	const static Node OBJ_2966248832912[] PROGMEM;
	const static Node OBJ_2966249009456[] PROGMEM;
	const static Node OBJ_2966249009376[] PROGMEM;
	const static Node OBJ_2966248738304[] PROGMEM;
	const static Node OBJ_2966248738704[] PROGMEM;
	const static Node OBJ_2966241097504[] PROGMEM;
	const static Node OBJ_2966248830512[] PROGMEM;
	const static Node OBJ_2966248830672[] PROGMEM;
	const static Node OBJ_2966248830752[] PROGMEM;
	const static Node OBJ_2966249089920[] PROGMEM;
	const static Node OBJ_2966248784176[] PROGMEM;
	const static Node OBJ_2966249089840[] PROGMEM;
	const static Node OBJ_2966248784416[] PROGMEM;
	const static Node OBJ_2966248784656[] PROGMEM;
	const static Node OBJ_2966248784736[] PROGMEM;
	const static Node OBJ_2966248786336[] PROGMEM;
	const static Node OBJ_2966248787696[] PROGMEM;
	const static Node OBJ_2966248930176[] PROGMEM;
	const static Node OBJ_2966248930496[] PROGMEM;
	const static Node OBJ_2966248931216[] PROGMEM;
	const static Node OBJ_2966248947776[] PROGMEM;
	const static Node OBJ_2966248948096[] PROGMEM;
	const static Node OBJ_2966249009696[] PROGMEM;
	const static Node OBJ_2966249009776[] PROGMEM;
	const static Node OBJ_2966249012736[] PROGMEM;
	const static Node OBJ_2966249032496[] PROGMEM;
	const static Node OBJ_2966249087600[] PROGMEM;
	const static Node OBJ_2966249313200[] PROGMEM;
	const static Node OBJ_2966249050336[] PROGMEM;
	const static Node OBJ_2966249050656[] PROGMEM;
	const static Node OBJ_2966249050896[] PROGMEM;
	const static Node OBJ_2966248784576[] PROGMEM;
	const static Node OBJ_2966249151920[] PROGMEM;
	const static Node OBJ_2966249152080[] PROGMEM;
	const static Node OBJ_2966248784896[] PROGMEM;
	const static Node OBJ_2966249149040[] PROGMEM;
	const static Node OBJ_2966249149120[] PROGMEM;
	const static Node OBJ_2966249149600[] PROGMEM;
	const static Node OBJ_2966249149760[] PROGMEM;
	const static Node OBJ_2966248785056[] PROGMEM;
	const static Node OBJ_2966249090560[] PROGMEM;
	const static Node OBJ_2966248785216[] PROGMEM;
	const static Node OBJ_2966248803200[] PROGMEM;
	const static Node OBJ_2966248830192[] PROGMEM;
	const static Node OBJ_2966248830432[] PROGMEM;
	const static Node OBJ_2966248830272[] PROGMEM;
	const static Node OBJ_2966249291184[] PROGMEM;
	const static Node OBJ_2966248785616[] PROGMEM;
	const static Node OBJ_2966248785776[] PROGMEM;
	const static Node OBJ_2966248980288[] PROGMEM;
	const static Node OBJ_2966248992992[] PROGMEM;
	const static Node OBJ_2966248996512[] PROGMEM;
	const static Node OBJ_2966249012976[] PROGMEM;
	const static Node OBJ_2966249230800[] PROGMEM;
	const static Node OBJ_2966249231040[] PROGMEM;
	const static Node OBJ_2966249231200[] PROGMEM;
	const static Node OBJ_2966249231440[] PROGMEM;
	const static Node OBJ_2966249231360[] PROGMEM;
	const static Node OBJ_2966248993232[] PROGMEM;
	const static Node OBJ_2966248994512[] PROGMEM;
	const static Node OBJ_2966249013136[] PROGMEM;
	const static Node OBJ_2966249029776[] PROGMEM;
	const static Node OBJ_2966249030016[] PROGMEM;
	const static Node OBJ_2966248786096[] PROGMEM;
	const static Node OBJ_2966248786016[] PROGMEM;
	const static Node OBJ_2966249088880[] PROGMEM;
	const static Node OBJ_2966249089120[] PROGMEM;
	const static Node OBJ_2966249090160[] PROGMEM;
	const static Node OBJ_2966248785936[] PROGMEM;
	const static Node OBJ_2966248786496[] PROGMEM;
	const static Node OBJ_2966248948896[] PROGMEM;
	const static Node OBJ_2966248949216[] PROGMEM;
	const static Node OBJ_2966248951696[] PROGMEM;
	const static Node OBJ_2966249233600[] PROGMEM;
	const static Node OBJ_2966249233680[] PROGMEM;
	const static Node OBJ_2966249233760[] PROGMEM;
	const static Node OBJ_2966249234000[] PROGMEM;
	const static Node OBJ_2966248977328[] PROGMEM;
	const static Node OBJ_2966248993392[] PROGMEM;
	const static Node OBJ_2966248786736[] PROGMEM;
	const static Node OBJ_2966249090800[] PROGMEM;
	const static Node OBJ_2966248787056[] PROGMEM;
	const static Node OBJ_2966248787136[] PROGMEM;
	const static Node OBJ_2966248928656[] PROGMEM;
	const static Node OBJ_2966249149280[] PROGMEM;
	const static Node OBJ_2966249149440[] PROGMEM;
	const static Node OBJ_2966249149920[] PROGMEM;
	const static Node OBJ_2966249150080[] PROGMEM;
	const static Node OBJ_2966248786896[] PROGMEM;
	const static Node OBJ_2966248871152[] PROGMEM;
	const static Node OBJ_2966249246864[] PROGMEM;
	const static Node OBJ_2966249246944[] PROGMEM;
	const static Node OBJ_2966249247104[] PROGMEM;
	const static Node OBJ_2966248801360[] PROGMEM;
	const static Node OBJ_2966249051216[] PROGMEM;
	const static Node OBJ_2966249052016[] PROGMEM;
	const static Node OBJ_2966248801040[] PROGMEM;
	const static Node OBJ_2966241096624[] PROGMEM;
	const static Node OBJ_2966248994352[] PROGMEM;
	const static Node OBJ_2966248703616[] PROGMEM;
	const static Node OBJ_2966248702256[] PROGMEM;
	const static Node OBJ_2966249170800[] PROGMEM;
	const static Node OBJ_2966249270224[] PROGMEM;
	const static Node OBJ_2966248702176[] PROGMEM;
	const static Node OBJ_2966248703536[] PROGMEM;
	const static Node OBJ_2966248804160[] PROGMEM;
	const static Node OBJ_2966248804240[] PROGMEM;
	const static Node OBJ_2966248829072[] PROGMEM;
	const static Node OBJ_2966248829872[] PROGMEM;
	const static Node OBJ_2966249031216[] PROGMEM;
	const static Node OBJ_2966249170880[] PROGMEM;
	const static Node OBJ_2966248829792[] PROGMEM;
	const static Node OBJ_2966248830912[] PROGMEM;
	const static Node OBJ_2966248831232[] PROGMEM;
	const static Node OBJ_2966248831552[] PROGMEM;
	const static Node OBJ_2966248831792[] PROGMEM;
	const static Node OBJ_2966248832192[] PROGMEM;
	const static Node OBJ_2966248832432[] PROGMEM;
	const static Node OBJ_2966248928816[] PROGMEM;
	const static Node OBJ_2966248849792[] PROGMEM;
	const static Node OBJ_2966248850032[] PROGMEM;
	const static Node OBJ_2966248851872[] PROGMEM;
	const static Node OBJ_2966248851952[] PROGMEM;
	const static Node OBJ_2966248852032[] PROGMEM;
	const static Node OBJ_2966248852432[] PROGMEM;
	const static Node OBJ_2966248852912[] PROGMEM;
	const static Node OBJ_2966248853072[] PROGMEM;
	const static Node OBJ_2966248852992[] PROGMEM;
	const static Node OBJ_2966248870112[] PROGMEM;
	const static Node OBJ_2966248870272[] PROGMEM;
	const static Node OBJ_2966248853232[] PROGMEM;
	const static Node OBJ_2966248869952[] PROGMEM;
	const static Node OBJ_2966248853392[] PROGMEM;
	const static Node OBJ_2966248870432[] PROGMEM;
	const static Node OBJ_2966248870592[] PROGMEM;
	const static Node OBJ_2966248870752[] PROGMEM;
	const static Node OBJ_2966248871232[] PROGMEM;
	const static Node OBJ_2966248871472[] PROGMEM;
	const static Node OBJ_2966248871392[] PROGMEM;
	const static Node OBJ_2966248871872[] PROGMEM;
	const static Node OBJ_2966248871792[] PROGMEM;
	const static Node OBJ_2966248872832[] PROGMEM;
	const static Node OBJ_2966248873872[] PROGMEM;
	const static Node OBJ_2966248890512[] PROGMEM;
	const static Node OBJ_2966248891472[] PROGMEM;
	const static Node OBJ_2966248892832[] PROGMEM;
	const static Node OBJ_2966248892912[] PROGMEM;
	const static Node OBJ_2966248893232[] PROGMEM;
	const static Node OBJ_2966248894192[] PROGMEM;
	const static Node OBJ_2966248894272[] PROGMEM;
	const static Node OBJ_2966248906976[] PROGMEM;
	const static Node OBJ_2966248908176[] PROGMEM;
	const static Node OBJ_2966248908416[] PROGMEM;
	const static Node OBJ_2966248908576[] PROGMEM;
	const static Node OBJ_2966248908496[] PROGMEM;
	const static Node OBJ_2966248908736[] PROGMEM;
	const static Node OBJ_2966248910096[] PROGMEM;
	const static Node OBJ_2966249230480[] PROGMEM;
	const static Node OBJ_2966248910336[] PROGMEM;
	const static Node OBJ_2966248910496[] PROGMEM;
	const static Node OBJ_2966248910416[] PROGMEM;
	const static Node OBJ_2966248910656[] PROGMEM;
	const static Node OBJ_2966248927296[] PROGMEM;
	const static Node OBJ_2966248927616[] PROGMEM;
	const static Node OBJ_2966248927696[] PROGMEM;
	const static Node OBJ_2966248928096[] PROGMEM;
	const static Node OBJ_2966248928176[] PROGMEM;
	const static Node OBJ_2966248928576[] PROGMEM;
	const static Node OBJ_2966249171040[] PROGMEM;
	const static Node OBJ_2966249171280[] PROGMEM;
	const static Node OBJ_2966249290624[] PROGMEM;
	const static Node OBJ_2966248929216[] PROGMEM;
	const static Node OBJ_2966248929296[] PROGMEM;
	const static Node OBJ_2966248929136[] PROGMEM;
	const static Node OBJ_2966248929456[] PROGMEM;
	const static Node OBJ_2966248951296[] PROGMEM;
	const static Node OBJ_2966248976608[] PROGMEM;
	const static Node OBJ_2966248976768[] PROGMEM;
	const static Node OBJ_2966249232720[] PROGMEM;
	const static Node OBJ_2966248977408[] PROGMEM;
	const static Node OBJ_2966248977648[] PROGMEM;
	const static Node OBJ_2966248978208[] PROGMEM;
	const static Node OBJ_2966248978288[] PROGMEM;
	const static Node OBJ_2966248978608[] PROGMEM;
	const static Node OBJ_2966248978528[] PROGMEM;
	const static Node OBJ_2966248993792[] PROGMEM;
	const static Node OBJ_2966249030976[] PROGMEM;
	const static Node OBJ_2966249212880[] PROGMEM;
	const static Node OBJ_2966248996752[] PROGMEM;
	const static Node OBJ_2966249010336[] PROGMEM;
	const static Node OBJ_2966249010416[] PROGMEM;
	const static Node OBJ_2966249010496[] PROGMEM;
	const static Node OBJ_2966249010736[] PROGMEM;
	const static Node OBJ_2966249010976[] PROGMEM;
	const static Node OBJ_2966249011216[] PROGMEM;
	const static Node OBJ_2966249011456[] PROGMEM;
	const static Node OBJ_2966249011376[] PROGMEM;
	const static Node OBJ_2966249011616[] PROGMEM;
	const static Node OBJ_2966249011776[] PROGMEM;
	const static Node OBJ_2966249011936[] PROGMEM;
	const static Node OBJ_2966249029936[] PROGMEM;
	const static Node OBJ_2966249030496[] PROGMEM;
	const static Node OBJ_2966249030656[] PROGMEM;
	const static Node OBJ_2966249030576[] PROGMEM;
	const static Node OBJ_2966249030816[] PROGMEM;
	const static Node OBJ_2966249031536[] PROGMEM;
	const static Node OBJ_2966249191200[] PROGMEM;
	const static Node OBJ_2966249031456[] PROGMEM;
	const static Node OBJ_2966249032256[] PROGMEM;
	const static Node OBJ_2966249033536[] PROGMEM;
	const static Node OBJ_2966249232160[] PROGMEM;
	const static Node OBJ_2966249232640[] PROGMEM;
	const static Node OBJ_2966249052256[] PROGMEM;
	const static Node OBJ_2966249052496[] PROGMEM;
	const static Node OBJ_2966249052896[] PROGMEM;
	const static Node OBJ_2966249052576[] PROGMEM;
	const static Node OBJ_2966249052976[] PROGMEM;
	const static Node OBJ_2966249110720[] PROGMEM;
	const static Node OBJ_2966249111040[] PROGMEM;
	const static Node OBJ_2966249133776[] PROGMEM;
	const static Node OBJ_2966249133856[] PROGMEM;
	const static Node OBJ_2966249134176[] PROGMEM;
	const static Node OBJ_2966249232800[] PROGMEM;
	const static Node OBJ_2966249134496[] PROGMEM;
	const static Node OBJ_2966249134576[] PROGMEM;
	const static Node OBJ_2966249135456[] PROGMEM;
	const static Node OBJ_2966249150640[] PROGMEM;
	const static Node OBJ_2966249230880[] PROGMEM;
	const static Node OBJ_2966249151200[] PROGMEM;
	const static Node OBJ_2966249213760[] PROGMEM;
	const static Node OBJ_2966249169360[] PROGMEM;
	const static Node OBJ_2966249170320[] PROGMEM;
	const static Node OBJ_2966249170640[] PROGMEM;
	const static Node OBJ_2966249290944[] PROGMEM;
	const static Node OBJ_2966249172560[] PROGMEM;
	const static Node OBJ_2966249172640[] PROGMEM;
	const static Node OBJ_2966249189520[] PROGMEM;
	const static Node OBJ_2966249190320[] PROGMEM;
	const static Node OBJ_2966249212240[] PROGMEM;
	const static Node OBJ_2966249213360[] PROGMEM;
	const static Node OBJ_2966249233040[] PROGMEM;
	const static Node OBJ_2966249233200[] PROGMEM;
	const static Node OBJ_2966249190800[] PROGMEM;
	const static Node OBJ_2966249210240[] PROGMEM;
	const static Node OBJ_2966249210640[] PROGMEM;
	const static Node OBJ_2966249270864[] PROGMEM;
	const static Node OBJ_2966249271024[] PROGMEM;
	const static Node OBJ_2966249289344[] PROGMEM;
	const static Node OBJ_2966249289744[] PROGMEM;
	const static Node OBJ_2966249289984[] PROGMEM;
	const static Node OBJ_2966249290304[] PROGMEM;
	const static Node OBJ_2966249291424[] PROGMEM;
	const static Node OBJ_2966249291504[] PROGMEM;
	const static Node OBJ_2966249291664[] PROGMEM;
	const static Node OBJ_2966249312320[] PROGMEM;

	const static uint16_t composeSymbols[] PROGMEM;

	public:
	Compose() : currentNode(const_cast<Node*>(root)){}
		
	uint16_t transition(uint8_t layer, uint8_t key);
	void reset();
	


}; //Compose

#endif //__COMPOSE_H__