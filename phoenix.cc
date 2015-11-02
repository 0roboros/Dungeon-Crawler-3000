#include <iostream>
using namespace std;
#include "phoenix.h"
#include "display.h"

Phoenix::Phoenix(Terrain *t, Terrain*** grid, Display * dis): Enemy(50, 35, 20, "Phoenix",t,grid, dis) {}
Phoenix::~Phoenix() {}
