#ifndef __ORC_H__
#define __ORC_H__
class Terrain;
#include <iostream>
#include "playerCharacter.h"

class Orc : public PlayerCharacter {
   public:
	Orc(Terrain *, Terrain ***);
	~Orc();
	void addGold(int);
};

#endif
