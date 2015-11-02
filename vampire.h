#ifndef __VAMPIRE_H__
#define __VAMPIRE_H__
class Terrain;
class Display;
#include <iostream>
#include "enemy.h"

class Vampire : public Enemy {
	public:
	Vampire(Terrain *, Terrain ***, Display*);
	~Vampire();
};

#endif
