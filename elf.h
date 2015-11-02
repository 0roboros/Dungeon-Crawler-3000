#ifndef __ELF_H__
#define __ELF_H__
class Terrain;
#include <iostream>
#include "playerCharacter.h"

class Elf : public PlayerCharacter {

   public:
	Elf(Terrain *, Terrain ***);
	~Elf();
	
	// negative potions have postive effect
};


#endif

