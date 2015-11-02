#ifndef __WEREWOLF_H__
#define __WEREWOLF_H__
class Terrain;
class Display;
#include <iostream>
#include "enemy.h"

class Werewolf : public Enemy {
	public:
	Werewolf(Terrain *, Terrain ***, Display *);
	~Werewolf();
};
#endif
