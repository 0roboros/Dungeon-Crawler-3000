#include <iostream>
using namespace std;

#include "vampire.h"
#include "display.h"

Vampire::Vampire(Terrain *t, Terrain ***grid, Display * dis):Enemy(50,25,25,"Vampire", t, grid, dis) {}
Vampire::~Vampire() {}
