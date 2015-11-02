#ifndef __PASSAGE_H__
#define __PASSAGE_H__
#include <string>

class PlayerCharacter;
#include "terrain.h"

class Passage: public Terrain{
	PlayerCharacter * myPC;
	public:
	Passage(int r, int c);
	void react(Terrain &other);
	PlayerCharacter * getPC();
	void setPC(PlayerCharacter * cha);
	void transPC(Terrain &other);
	void removePC();
	~Passage();
};

#endif
