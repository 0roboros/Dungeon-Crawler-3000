#include "passage.h"
#include "playerCharacter.h"
Passage::Passage(int r, int c):Terrain("Passage", r, c),myPC(0){};

void Passage::react(Terrain &other){
	other.transPC(*this);
}

PlayerCharacter * Passage::getPC(){
	return myPC;
}

void Passage::setPC(PlayerCharacter * pc){
	myPC = pc;
	myPC->setLoc(this);
}

void Passage::transPC(Terrain &other){
	other.setPC(myPC);
	myPC = 0;
}

void Passage::removePC(){
	myPC = 0;
}
Passage::~Passage(){
	delete myPC;
}
