/* 
* Neo2Map.h
*
* Created: 20.11.2021 10:45:50
* Author: Jonas
*/


#ifndef __NEO2MAP_H__
#define __NEO2MAP_H__
#include "NeoIncludes.h"
#include "KeyboardMap.h"

class Neo2Map : public KeyboardMap
{
	private:
	const static uint8_t neoMap[NEO_MAP_SIZE];
	const static InputSequence neoMapL2[NEO_MAP_SIZE - KEY_Z - 1] PROGMEM;
	const static InputSequence neoMapL3[NEO_MAP_SIZE] PROGMEM;
	const static InputSequence neoMapL4[NEO_MAP_SIZE] PROGMEM;
	const static uint16_t neoMapL5[NEO_MAP_SIZE] PROGMEM;
	const static uint16_t neoMapL6[NEO_MAP_SIZE] PROGMEM;
	const static uint8_t L4Shift_Map[(NEO_MAP_SIZE - 1) / 8 + 1];
	
	public:
	const uint8_t* Neo2Map::getL1() { return neoMap; }
	const InputSequence* Neo2Map::getL2(){ return neoMapL2; }
	const InputSequence* Neo2Map::getL3(){ return neoMapL3; }
	const InputSequence* Neo2Map::getL4() { return neoMapL4; }
	const uint8_t* Neo2Map::getL4Shift() { return L4Shift_Map; }
	const uint16_t* Neo2Map::getL5() { return neoMapL5; }
	const uint16_t* Neo2Map::getL6() { return neoMapL6; }
}; //Neo2Map

#endif //__NEO2MAP_H__
