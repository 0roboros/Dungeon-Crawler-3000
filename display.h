#ifndef __DISPLAY_H__
#define __DISPLAY_H__
class Floor;
class Terrain;
#include <iostream>

class Display{
	Floor * flo;
	Terrain *** grid;
	std::string race;
	bool sGold;
	bool sEnemy;
	bool sPot;
	std::string atype;
	int pDmg;
	int eDmg;
	int eHp;
	std::string mAd;
	std::string mAtk;
	public:
	Display();
	void setGrid(Floor *);
	void setRace(std::string);
	void resetTrackers();
	void refreshGrid();
	void printGrid();
	void printDesc();
	void lastAction(std::string);
	void eneHP(int);
	void playerDmg(int, std::string);
	void enemyDmg(int, std::string);
	void notify(bool, bool, bool);

};

#endif
