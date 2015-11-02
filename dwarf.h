#ifndef __DWARF_H__
#define __DWARF_H__

class Terrain;
#include <iostream>
#include "playerCharacter.h"

class Dwarf : public PlayerCharacter {

   public:
	Dwarf(Terrain *, Terrain ***);
	~Dwarf();
	void addGold(int);
};




#endif
