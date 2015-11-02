#ifndef __WOUNDATK_H__
#define __WOUNDATK_H__

#include "decoratorPC.h"

class WoundAtk : public DecoratorPC {
	int wound;
   public:
	WoundAtk(int, PlayerCharacter *pc);
	int getAtk();

};


#endif
