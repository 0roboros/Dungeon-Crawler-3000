#include <iostream>
using namespace std;

#include "orc.h"

Orc::Orc(Terrain *t, Terrain ***grid): PlayerCharacter(180, 30, 25, "Orc",t,grid) {
	cout << "orc created" << endl;
}

Orc::~Orc() {
	cout << "orc destroyed" << endl;
}

void Orc::addGold(int amount) {
	PlayerCharacter::addGold(amount/2);
}
