#ifndef __PLAYERCHARACTER_H__
#define __PLAYERCHARACTER_H__

class Display;
class Terrain;

#include <iostream>
#include "character.h"


class PlayerCharacter : public Character {
//	int HP, Atk, Def;
	int gold;
	Terrain *** theGrid;
	bool seeGold, seeEnemy, seePotion;
	Terrain *neighbours[8];
	Terrain *currentLocation;
	Display * d;
	bool dead;

   public:
	PlayerCharacter();
	PlayerCharacter(int,int,int,std::string, Terrain *, Terrain *** );
	virtual ~PlayerCharacter() = 0;
	virtual void setDisplay(Display *);
	virtual void updateNeighbours();
	virtual void death();
	virtual void attack(Terrain*);
	virtual void attacked(Character *);
	virtual void move(Terrain*);
	virtual void notifyNeighbours();
	virtual void notifyDisplay();
	bool isDead();
	//virtual void addGold(Gold *);
	virtual void addGold(int);
	virtual int getGold();
	virtual void nearGold(bool);
	virtual void nearEnemy(bool);
	virtual void nearPotion(bool);

};

#endif
