#ifndef __POTION_H__
#define __POTION_H__
#include <string>

class Terrain;
class PlayerCharacter;
#include "item.h"

class Potion: public Item{
	std::string pottype;
	public:
	Potion(std::string pt);
	std::string getPotType();
        void react(Terrain &other);
	void notify(PlayerCharacter * pc);
};

#endif
