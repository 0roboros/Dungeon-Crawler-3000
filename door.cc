#include "door.h"
#include "playerCharacter.h"

Door::Door(int r, int c):Terrain("Door", r, c), myPC(0){}

void Door::react(Terrain &other){
		if (other.getPC() != 0)
		other.transPC(*this);
}

PlayerCharacter * Door::getPC(){
	return myPC;
}

void Door::setPC(PlayerCharacter * pc){
	myPC = pc;
	myPC->setLoc(this);
}

void Door::transPC(Terrain &other){
	other.setPC(myPC);
	myPC = 0;
}

void Door::removePC(){
	myPC = 0;
}

Door::~Door(){
	delete myPC;

}
