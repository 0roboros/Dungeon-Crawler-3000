#ifndef __WALL_H__
#define __WALL_H__
#include <string>
#include "terrain.h"

class Wall : public Terrain{
	char orient;
	public:
	Wall(int r, int c, char o);
	void react(Terrain &other);
	char getOrient();
};
#endif
