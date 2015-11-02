#ifndef __GOLD_H__
#define __GOLD_H__

class Enemy;
class Terrain;
class PlayerCharacter;

#include "item.h"

class Gold: public Item{
	int amount;
	Enemy * dragonpoint;
	public:
	Gold(int am);
	Gold(int am, Enemy * dp);
	int getAmount();
	void setDp(Enemy * dp);
	void react(Terrain &other);
	void notify(PlayerCharacter * pc);



};
#endif
