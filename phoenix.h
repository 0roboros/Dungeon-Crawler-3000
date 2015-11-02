#ifndef __PHOENIX_H__
#define __PHOENIX_H__
class Terrain;
class Display;
#include <iostream>
#include "enemy.h"

class Phoenix : public Enemy{
	public:
	Phoenix(Terrain*, Terrain***, Display *);
	~Phoenix();
};
#endif
