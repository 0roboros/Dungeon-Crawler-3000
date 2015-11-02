#include <iostream>
using namespace std;

#include "woundDef.h"

WoundDef::WoundDef(int wound, PlayerCharacter *pc):
	wound(wound), DecoratorPC(pc) {
	cout << "WoundDef potion used: Def - " << wound << "!\n";
}

int WoundDef::getDef() {
	if (pc->getRace() == "elf") return pc->getDef() + wound;
	return pc->getDef() - wound;
}
