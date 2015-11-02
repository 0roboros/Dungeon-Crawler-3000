#include <iostream>
using namespace std;

#include "werewolf.h"
#include "display.h"

Werewolf::Werewolf(Terrain *t, Terrain ***grid, Display * dis):Enemy(120,30,5,"Werewolf",t,grid, dis) {}
Werewolf::~Werewolf() {}
