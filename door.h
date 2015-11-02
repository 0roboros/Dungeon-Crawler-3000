#ifndef __DOOR_H__
#define __DOOR_H__
#include <string>

class PlayerCharacter;
#include "terrain.h"

class Door: public Terrain{
	PlayerCharacter * myPC;
	public:
	Door(int r, int c);
	void react(Terrain &other);
	PlayerCharacter * getPC();
	void setPC(PlayerCharacter * pc);
	void transPC(Terrain &other);
	void removePC();
	~Door();
};

#endif
