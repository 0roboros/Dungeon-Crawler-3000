#ifndef __FLOOR_H__
#define __FLOOR_H__
#include <string>

class Terrain;
class PlayerCharacter;
class Display;

class Floor{
	Terrain *** grid;
	PlayerCharacter * thePlayer;
	Display * d;
	public:
	Floor(std::string filename, Display *);
	void setDisplay(Display *);
	Terrain *** getGrid();
	PlayerCharacter * getPlayer();
	Terrain * getTerrain(int, int);
	Terrain * getNorth(Terrain *);
	Terrain * getSouth(Terrain *);
	Terrain * getWest(Terrain *);
	Terrain * getEast(Terrain *);
	Terrain * getNW(Terrain *);
	Terrain * getNE(Terrain *);
	Terrain * getSW(Terrain *);
	Terrain * getSE(Terrain *);
	//void spawnCharacter();
	//void addEnemies();
	//void addItems();
	//void init();
	void readFromFile(std::string filename);
	void tick();
	~Floor();
};
#endif
