#ifndef __BOOSTATK_H__
#define __BOOSTATK_H__
class PlayerCharacter;
#include "decoratorPC.h"

class BoostAtk : public DecoratorPC {
	int boost;
   public:
	BoostAtk(int, PlayerCharacter *pc);
	int getAtk();
};

#endif
