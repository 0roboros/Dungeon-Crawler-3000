#include "potion.h"
#include "terrain.h"
#include "playerCharacter.h"
#include "boostAtk.h"
#include "woundAtk.h"
#include "boostDef.h"
#include "woundDef.h"

Potion::Potion(std::string pt):Item("Potion"),pottype(pt){}

std::string Potion::getPotType(){
	return pottype;
}

void Potion::react(Terrain &other){
if (other.getPC() != 0){

	if(pottype == "RH")
		(other.getPC())->changeHP(10);
	else if (pottype == "PH")
		(other.getPC())->changeHP(-10);
	else if (pottype == "BA")
		(other.setPC(new BoostAtk(5, other.getPC())));
	else if (pottype == "WA")
		(other.setPC(new WoundAtk(5, other.getPC())));
	else if (pottype == "BD")
		(other.setPC(new BoostDef(5, other.getPC())));
	else (other.setPC(new WoundDef(5, other.getPC())));
}
}


void Potion::notify(PlayerCharacter * pc){
	pc->nearPotion(1);
}
