#include <iostream>
using namespace std;

#include "boostDef.h"
#include "playerCharacter.h"

BoostDef::BoostDef(int boost, PlayerCharacter *pc):
	boost(boost), DecoratorPC(pc) {
	cout << "BoostDef potion used: Def + " << boost << "!\n";
}

int BoostDef::getDef() {
	return pc->getDef() + boost;
}
