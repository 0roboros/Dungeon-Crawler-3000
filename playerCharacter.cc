#include <iostream>
#include <cmath>
using namespace std;

#include "playerCharacter.h"
#include "terrain.h"
#include "display.h"

PlayerCharacter::PlayerCharacter() {}

PlayerCharacter::PlayerCharacter(int hp, int atk, int def, std::string r, Terrain * t, Terrain *** grid):
	Character(hp, atk, def, r, t), gold(0), theGrid(grid), seeGold(0), seeEnemy(0), seePotion(0),dead(0){
	cout << "pc created" << endl;
}

PlayerCharacter::~PlayerCharacter() {
//	cout <<"pc destroyed" << endl;
}

void PlayerCharacter::setDisplay(Display * di){
d = di;
}
void PlayerCharacter::death() {
	(getCurLoc())->removePC();
	dead = 1;
	cout << "You have died." << endl;
}

bool PlayerCharacter::isDead(){
	return dead;
}

int PlayerCharacter::getGold(){
	return gold;
}
void PlayerCharacter::updateNeighbours() {
	int r = getCurLoc()->getRow();
	int c = getCurLoc()->getCol();
	neighbours[0] = theGrid[r-1][c];
	neighbours[1] = theGrid[r-1][c+1];
	neighbours[2] = theGrid[r][c+1];
	neighbours[3] = theGrid[r+1][c+1];
	neighbours[4] = theGrid[r+1][c];
	neighbours[5] = theGrid[r+1][c-1];
	neighbours[6] = theGrid[r][c-1];
	neighbours[7] = theGrid[r-1][c-1];
}

void PlayerCharacter::attack(Terrain* t) {
	// attack a specific terrain and whatever thats on it
	t->attacked(this);
	updateNeighbours();
	notifyNeighbours();
	d->lastAction("Attack");
}

void PlayerCharacter::attacked(Character *enemy) {
	int damage = ceil((100/(100+(double)getDef()))*enemy->getAtk());
	d->enemyDmg(damage, enemy->getRace());
	changeHP(-1*damage);
	if (getHP() <= 0) {
		death();
	}
}

void PlayerCharacter::move(Terrain* t) {
	//moves player to a certain Terrain,
	// the terrain is responsible for setting my curLoc to the new terrain
        seeGold=false; seeEnemy=false; seePotion=false;
	t->react(*(getCurLoc()));
	// needs to update its neighbours
	updateNeighbours();
	notifyNeighbours();	
	//cout << "Player done moving" << endl;
	d->lastAction("Move");
}


void PlayerCharacter::notifyNeighbours() {
	for(int i = 0; i< 8; i++) {
		neighbours[i]->notify(this);
	}
}

void PlayerCharacter::notifyDisplay() {
	d->notify(seeGold, seeEnemy, seePotion);
}

//void PlayerCharacter::addGold(Gold * g) {
//	gold += g->getAmount();
	// this affects implementaiont of Gold
//} 

void PlayerCharacter::addGold(int amt) {
	gold += amt;
}

void PlayerCharacter::nearGold(bool gold) {seeGold=gold;}
void PlayerCharacter::nearEnemy(bool enemy) {seeEnemy=enemy;}
void PlayerCharacter::nearPotion(bool potion) {seePotion=potion;}

