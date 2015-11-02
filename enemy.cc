#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;

#include "enemy.h"
#include "gold.h"
#include "terrain.h"
#include "playerCharacter.h"
#include "display.h"

bool Enemy::isHostile = false;

Terrain * Enemy::randTerrain() {
	Terrain *t;
	int dir = rand() % 8;
	int r = getCurLoc()->getRow();
	int c = getCurLoc()->getCol();
	switch (dir){
	   case 0: t = theGrid[r-1][c]; break;
	   case 1: t = theGrid[r-1][c+1]; break;
	   case 2: t = theGrid[r][c+1]; break;
	   case 3: t = theGrid[r+1][c+1]; break;
	   case 4: t = theGrid[r+1][c]; break;
	   case 5: t = theGrid[r+1][c-1]; break;
	   case 6: t = theGrid[r][c-1]; break;
	   case 7: t = theGrid[r-1][c-1]; break;
	   default: t = theGrid[r-1][c-1]; break;
	}
	return t;
}


Enemy::Enemy(int hp, int atk, int def, string race, Terrain *t, Terrain *** grid, Display * dis):
	Character(hp,atk,def,race,t), theGrid(grid), isActive(0), d(dis){}

Enemy::~Enemy() {}

void Enemy::tick(PlayerCharacter *pc) {
	if (isActive == true) attack(pc);
	else move(randTerrain());
}

void Enemy::death() {
	getCurLoc()->removeEnemy();
}

void Enemy::attack(PlayerCharacter * pc) {
	pc->attacked(this);
	isActive = false;
}

void Enemy::attacked(PlayerCharacter * pc) {
	int damage = ceil((100/(100+(double)getDef()))*pc->getAtk());
	changeHP(-1*damage);
	d->playerDmg(damage, getRace());
	d->eneHP(getHP());
	if (getHP() <= 0) {
		pc->addGold(1);
		death();
		return;
	} 
}

void Enemy::move(Terrain *t) {
	t->react(*getCurLoc());
}

void Enemy::react(Terrain *t) {}

void Enemy::notify(PlayerCharacter *pc) {
	isActive = true;
	pc->nearEnemy(1);

}

//string Enemy::getType() {return monsterType;}


