#include <iostream>
using namespace std;


#include "boostAtk.h"
#include "playerCharacter.h"
BoostAtk::BoostAtk(int boost, PlayerCharacter *pc):
	boost(boost), DecoratorPC(pc) {
	cout << "BoostAtk potion used: Atk + " << boost << "!\n";
}

int BoostAtk::getAtk() {
	return pc->getAtk() + boost;
}
