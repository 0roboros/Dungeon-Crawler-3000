#ifndef __ENEMY_H__
#define __ENEMY_H__

#include <iostream>

class PlayerCharacter;
class Terrain;
class Display;

#include "character.h"

class Enemy : public Character {
	Terrain *** theGrid;
	Display * d;
	public:
	bool isActive;
	static bool isHostile;
	Enemy(int, int, int, std::string, Terrain*, Terrain ***,Display *);
	~Enemy();
	virtual void tick(PlayerCharacter *);
	void death();
	virtual void attack(PlayerCharacter *);
	virtual void attacked(PlayerCharacter *);
	virtual void move(Terrain *);
	void react(Terrain *);
	virtual void notify(PlayerCharacter *);
	Terrain *randTerrain();
};

#endif
