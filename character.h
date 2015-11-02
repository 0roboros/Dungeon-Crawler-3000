#ifndef __CHARACTER_H__
#define __CHARACTER_H__

#include <iostream>

class Terrain;


//static const int MAX_NEIGHBOURS = 8;


class Character {
	int HP, Atk, Def;
	Terrain* currentLocation;
	std::string race;
 public:
	Character();
	Character(int,int,int,std::string, Terrain *);
	//Terrain* decodeDir(std::string);
	virtual ~Character() = 0;
	void changeHP(int);
	void changeAtk(int);
	void changeDef(int);
	
	virtual int getAtk();
	virtual int getDef();
	virtual int getHP();
	virtual std::string getRace();
	
	virtual Terrain* getCurLoc();
	virtual void setLoc(Terrain *newLoc);
};

#endif
