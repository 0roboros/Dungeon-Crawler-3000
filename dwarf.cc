#include <iostream>
using namespace std;

#include "dwarf.h"

Dwarf::Dwarf(Terrain *t, Terrain ***grid): PlayerCharacter(100, 20, 30, "Dwarf",t, grid) 
{
	cout << "dwarf created" << endl;
}

Dwarf::~Dwarf() {
	cout << "dwarf destroyed" << endl;
}

void Dwarf::addGold(int amount) {
	PlayerCharacter::addGold(2*amount);
}


