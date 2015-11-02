#include <iostream>
using namespace std;
#include "human.h"

Human::Human(Terrain *t, Terrain ***grid): PlayerCharacter(140, 20, 20,"Human",t,grid) {
	cout << "human created" << endl;
}

Human::~Human() {
	cout << "human destroyed" << endl;
}
