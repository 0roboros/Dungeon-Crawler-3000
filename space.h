#ifndef __SPACE_H__
#define __SPACE_H__
#include <string>
#include "terrain.h"

class Space : public Terrain{
	public:
	Space(int r, int c);
	void react(Terrain &other);
};

#endif
