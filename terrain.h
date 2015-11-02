#ifndef __TERRAIN_H__
#define __TERRAIN_H__
class Item;
class Enemy;
class PlayerCharacter;

#include <string>

class Terrain{
	std::string type;
	int row;
	int col;
	public:
	Terrain(std::string t, int r, int c);
	std::string getType();
	virtual void react(Terrain &other);
	virtual void setPC(PlayerCharacter * pc);
	virtual PlayerCharacter * getPC();
	virtual void transPC(Terrain &other);
	virtual void removePC();
	virtual void setEnemy(Enemy * ene);
	virtual Enemy * getEnemy();
	virtual void transEnemy(Terrain &other);
	virtual void removeEnemy();
	virtual void setItem(Item * ite);
	virtual Item * getItem();
	virtual char getOrient();
	virtual std::string occupantType();
	virtual void notify(PlayerCharacter * pc);
	virtual void attacked(PlayerCharacter * pc);
	int getRow();
	int getCol();
	virtual ~Terrain() = 0;
};

#endif
