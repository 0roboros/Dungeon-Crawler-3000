#ifndef __STAIRS_H__
#define __STAIRS_H__
#include <string>
#include "terrain.h"

class Stairs: public Terrain{
	public:
	Stairs(int r, int c);
	void react(Terrain &other);


};

#endif
