#include <iostream>
#include "character.h"
using namespace std;

//const int Character::MAX_NEIGHBOURS = 8;
Character::Character(){}
Character::Character(int hp, int atk, int def, std::string r, Terrain *t):
	HP(hp), Atk(atk), Def(def),race(r), currentLocation(t) {}
/*
Terrain* decodeDir(string dir) {
	
}
*/


Terrain *Character::getCurLoc() {return currentLocation;}

void Character::setLoc(Terrain *newloc) {currentLocation=newloc;}

void Character::changeHP(int change) {
	HP += change;
}
void Character::changeAtk(int change) {
	Atk += change;
}
void Character::changeDef(int change) {
	Def += change;
}

int Character::getAtk() {return Atk;}
int Character::getDef() {return Def;}
int Character::getHP() {return HP;}
std::string Character::getRace(){
	return race;
}

Character::~Character() {}
