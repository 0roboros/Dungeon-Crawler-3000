#ifndef __HUMAN_H__
#define __HUMAN_H__
class Terrain;
#include <iostream>
#include "playerCharacter.h"

class Human : public PlayerCharacter {

   public:
	Human(Terrain *t, Terrain ***);
	~Human();
	
};

#endif
