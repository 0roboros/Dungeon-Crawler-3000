#include "wall.h"

Wall::Wall(int r, int c, char o):Terrain("Wall",r,c),orient(o){}

void Wall::react(Terrain &other){}

char Wall::getOrient(){
	return orient;
}
