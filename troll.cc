#include <iostream>
using namespace std;
#include "troll.h"
#include "display.h"

Troll::Troll(Terrain *t, Terrain ***grid, Display * dis): Enemy(120, 25, 15, "Troll",t,grid, dis) {}
Troll::~Troll() {}
