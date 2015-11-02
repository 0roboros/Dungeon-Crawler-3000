#include "gold.h"
#include "playerCharacter.h"
#include "terrain.h"
#include "enemy.h"

Gold::Gold(int am):Item("Gold"),amount(am),dragonpoint(0){}

Gold::Gold(int am, Enemy * dp):Item("Gold"),amount(am),dragonpoint(dp){}

int Gold::getAmount(){
	return amount;
}

void Gold::setDp(Enemy * dp){
	dragonpoint = dp;
}

void Gold::react(Terrain &other){
	if (other.getPC() != 0){
	PlayerCharacter * pc = other.getPC();
	pc->addGold(amount);
	}
}

void Gold::notify(PlayerCharacter * pc){
	if (dragonpoint != 0)
		dragonpoint->notify(pc);
	pc->nearGold(1);
}
