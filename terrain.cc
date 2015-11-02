#include "terrain.h"
#include "playerCharacter.h"
#include "enemy.h"
#include "item.h"

Terrain::Terrain(std::string t, int r, int c):type(t),row(r),col(c){}

std::string Terrain::getType(){
	return type;
}

void Terrain::react(Terrain &other){}

void Terrain::setPC(PlayerCharacter * pc){}

PlayerCharacter * Terrain::getPC(){ return 0;}

void Terrain::transPC(Terrain &other){}

void Terrain::removePC(){}

void Terrain::setEnemy(Enemy * ene){}

Enemy * Terrain::getEnemy(){return 0;}

void Terrain::transEnemy(Terrain &other){}

void Terrain::removeEnemy(){}

void Terrain::setItem(Item * ite){}

Item * Terrain::getItem(){ return 0; }

char Terrain::getOrient(){ return '0'; }

std::string Terrain::occupantType(){
	return "NULL";
}

void Terrain::notify(PlayerCharacter * pc){}
void Terrain::attacked(PlayerCharacter * pc){}

int Terrain::getRow(){
	return row;
}

int Terrain::getCol(){
	return col;
}

Terrain::~Terrain(){}
