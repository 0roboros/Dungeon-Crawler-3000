#ifndef __GROUND_H__
#define __GROUND_H__
#include <string>

class PlayerCharacter;
class Enemy;
class Item;

#include "terrain.h"

class Ground: public Terrain{
	PlayerCharacter * myPC;
	Enemy * myEnemy;
	Item * myItem;
	public:
	Ground(int r, int c);
	std::string occupantType();
	void react(Terrain &other);
	PlayerCharacter * getPC();
	void setPC(PlayerCharacter * pc);
	void transPC(Terrain &other);
	void removePC();
	void setEnemy(Enemy * ene);
	Enemy * getEnemy();
	void transEnemy(Terrain &other);
	void removeEnemy();
	void setItem(Item *ite);
	Item * getItem();
	void notify(PlayerCharacter * pc);
	void attacked(PlayerCharacter * pc);
	~Ground();
};
#endif
