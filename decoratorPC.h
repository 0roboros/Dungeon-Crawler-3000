#ifndef __DECORATORPC_H__
#define __DECORATORPC_H__

#include <iostream>
#include "playerCharacter.h"

class DecoratorPC : public PlayerCharacter {
   protected:
	PlayerCharacter *pc;
   public:
	DecoratorPC(PlayerCharacter *pc);
	virtual ~DecoratorPC();

//	void changeHP(int);
//	void changeAtk(int);
//	void changeDef(int);
	
	int getAtk();
	int getDef();
	int getHP();
	std::string getRace();
	
	Terrain* getCurLoc();
	void setLoc(Terrain *newLoc);

	void updateNeighbours();
	void death();
	void attack(Terrain*);
	void attacked(Character *);
	void move(Terrain*);
	void notifyNeighbours();
	void notifyDisplay();
	
	//void addGold(Gold *);
	void addGold(int);
	
	void nearGold(bool);
	void nearEnemy(bool);
	void nearPotion(bool);


};

#endif
