#include <iostream>
using namespace std;

#include "dwarf.h"
#include "elf.h"
#include "orc.h"
#include "human.h"
#include "character.h"
#include "playerCharacter.h"
#include "decoratorPC.h"
#include "woundAtk.h"
#include "woundDef.h"
#include "boostAtk.h"
#include "boostDef.h"

void status(Character *c) {
	cout << "Health: " << c->getHP() << " Atk: " << c->getAtk() << " Def: " << c->getDef() << endl;
}

int main () {
/*	
	PlayerCharacter *d[4];
	d[0] = new Human();
	d[1] = new Dwarf();
	d[2] = new Elf();
	d[3] = new Orc();
*/
	PlayerCharacter *pc = new Human();
	status(pc);
	pc = new WoundAtk(10, pc);
	status(pc);
	pc = new WoundDef(5, new BoostAtk(100, new BoostDef(30, pc)));
	status(pc);
	delete pc;
	
//	for (int i=0; i<4; i++) {delete d[i];}
/*	Dwarf d;
	Elf e;
	Orc c;
	Human h;
*/
	
	return 0;
}
