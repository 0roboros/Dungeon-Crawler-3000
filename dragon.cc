#include <iostream>
using namespace std;

#include "dragon.h"
#include "playerCharacter.h"
#include "display.h"

Dragon::Dragon(Terrain *t, Terrain ***grid, Display * dis):Enemy(150,20,20, "Dragon",t,grid, dis) {}
Dragon::~Dragon() {}

void Dragon::notify(PlayerCharacter * pc) {
	pc->nearEnemy(true);
}

void Dragon::move(Terrain *) {
	return;
}
