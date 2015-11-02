#include "ground.h"
#include "playerCharacter.h"
#include "enemy.h"
#include "item.h"

Ground::Ground(int r, int c):Terrain("Ground", r, c), myPC(0), myEnemy(0), myItem(0){}

std::string Ground::occupantType(){
	if (myPC != 0)
		return "PC";
	if (myEnemy != 0)
		return "Enemy";
	if (myItem != 0)
		return "Item";
	return "Null";
}

void Ground::react(Terrain &other){
	if (myEnemy != 0){
		return;
	}
	else if (myItem != 0){
		if ((other.occupantType()) == "Enemy"){return;}
		else {
			myItem->react(other);
			other.transPC(*this);
		}
	}
	else if (myPC != 0){}
	else{
		if ((other.occupantType()) == "Enemy")
		other.transEnemy(*this);
		else
		other.transPC(*this);
	}
}

PlayerCharacter * Ground::getPC(){
	return myPC;
}

void Ground::setPC(PlayerCharacter * pc){
	delete myEnemy;
	delete myItem;
	myEnemy = 0;
	myItem = 0;
	myPC = pc;
	myPC->setLoc(this);
}

void Ground::transPC(Terrain &other){
        other.setPC(myPC);
        myPC = 0;
}
void Ground::removePC(){
	myPC = 0;
}
Enemy * Ground::getEnemy(){
        return myEnemy;
}

void Ground::setEnemy(Enemy * ene){
	delete myPC;
	delete myItem;
	myPC = 0;
	myItem = 0;
	myEnemy = ene;
	myEnemy->setLoc(this);
}

void Ground::transEnemy(Terrain &other){
	other.setEnemy(myEnemy);
	myEnemy = 0;
}

void Ground::removeEnemy(){
	delete myEnemy;
	myEnemy = 0;
}

Item * Ground::getItem(){
	return myItem;
}

void Ground::setItem(Item *ite){
	delete myPC;
	delete myEnemy;
	delete myItem;
	myPC = 0;
	myEnemy = 0;
	myItem = ite;

}

void Ground::notify(PlayerCharacter * pc){
	if (myEnemy != 0)
		myEnemy->notify(pc);
}

void Ground::attacked(PlayerCharacter * pc){
	if (myEnemy != 0)
		myEnemy->attacked(pc);
}

Ground::~Ground(){
	delete myPC;
	delete myEnemy;
	delete myItem;
}

