#include <iostream>
using namespace std;

#include "goblin.h"
#include "display.h"

Goblin::Goblin(Terrain *t, Terrain ***grid, Display * dis): Enemy(70,5,10,"Goblin", t, grid, dis) {}
Goblin::~Goblin() {}

