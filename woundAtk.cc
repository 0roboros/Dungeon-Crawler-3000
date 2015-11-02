#include <iostream>
using namespace std;

#include "woundAtk.h"

WoundAtk::WoundAtk(int wound, PlayerCharacter *pc):
	wound(wound), DecoratorPC(pc) {
	cout << "WoundAtk potion used: Atk - " << wound << "!\n";
}

int WoundAtk::getAtk() {
	if (pc->getRace() == "elf") return pc->getAtk() + wound;
	return pc->getAtk() - wound;
}
