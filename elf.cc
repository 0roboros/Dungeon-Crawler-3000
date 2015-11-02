#include <iostream>
using namespace std;

#include "elf.h"

Elf::Elf(Terrain *t, Terrain *** grid): PlayerCharacter(140, 30, 10, "Elf", t, grid) {
	cout << "elf created" << endl;
}

Elf::~Elf() {
	cout << "elf destroyed" << endl;
}
