#include <iostream>
#include <cmath>
using namespace std;

#include "merchant.h"
#include "playerCharacter.h"
#include "gold.h"
#include "terrain.h"
#include "display.h"

Merchant::Merchant(Terrain *t, Terrain ***grid, Display * dis): Enemy(30,70,5,"Merchant",t,grid, dis) {}
Merchant::~Merchant(){}

void Merchant::tick(PlayerCharacter *pc) {
	if (isActive == true && isHostile == true) attack(pc);
	else move(randTerrain());
}

void Merchant::attack(PlayerCharacter *pc) {
	Enemy::attack(pc);
	return;
}

void Merchant::attacked(PlayerCharacter * pc){
	isHostile = true;
	int damage = ceil((100/(100+(double)getDef()))*pc->getAtk());
	changeHP(-1*damage);
	if (getHP() <= 0) {
		death(); 
		Gold *merchantHorde = new Gold(4);
		(getCurLoc())->setItem(merchantHorde);
		return;
	}
}

void Merchant::notify(PlayerCharacter * pc) {
	isActive = true;
	if (isHostile == true) {
		pc->nearEnemy(true);
		attack(pc);
	} 
}


