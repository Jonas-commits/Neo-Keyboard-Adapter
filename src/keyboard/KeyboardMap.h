#ifndef __KEYBOARDMAP_H__
#define __KEYBOARDMAP_H__

#include "NeoIncludes.h"


class KeyboardMap
{
//functions
public:
	virtual ~KeyboardMap(){}
	virtual const uint8_t* getL1() = 0;
	virtual const InputSequence* getL2() = 0;
	virtual const InputSequence* getL3() = 0;
	virtual const InputSequence* getL4() = 0;
	virtual const uint8_t* getL4Shift() = 0;
	virtual const uint16_t* getL5() = 0;
	virtual const uint16_t* getL6() = 0;

}; //KeyboardMap

#endif //__KEYBOARDMAP_H__
