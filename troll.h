#ifndef __TROLL_H__
#define __TROLL_H__
#include <iostream>
class Terrain;
class Display;
#include "enemy.h"

class Troll : public Enemy {
	public:
	Troll(Terrain*, Terrain ***, Display *);
	~Troll();

};

#endif
