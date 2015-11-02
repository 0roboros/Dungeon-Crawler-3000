#ifndef __WOUNDDEF_H__
#define __WOUNDDEF_H__

#include <iostream>
#include "decoratorPC.h"

class WoundDef : public DecoratorPC {
	int wound;
   public:
	WoundDef(int, PlayerCharacter *pc);
	int getDef();
};

#endif
