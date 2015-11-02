#ifndef __BOOSTDEF_H__
#define __BOOSTDEF_H__

class PlayerCharacter;
#include "decoratorPC.h"

class BoostDef : public DecoratorPC {
	int boost;
   public:
	BoostDef(int, PlayerCharacter *pc);
	int getDef();

};


#endif
