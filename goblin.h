#ifndef __GOBLIN_H__
#define __GOBLIN_H__
class Terrain;
class Display;
#include <iostream>
#include "enemy.h"

class Goblin : public Enemy {
	public:
	Goblin(Terrain *, Terrain ***, Display *);
	~Goblin();
};
#endif
