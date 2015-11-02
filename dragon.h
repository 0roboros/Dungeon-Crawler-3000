#ifndef __DRAGON_H__
#define __DRAGON_H__

class PlayerCharacter;
class Terrain;
class Display;
#include <iostream>
#include "enemy.h"

class Dragon : public Enemy {
	public:
	Dragon(Terrain *, Terrain ***, Display *);
	~Dragon();
	void notify(PlayerCharacter *);
	void move(Terrain *);
};
#endif
