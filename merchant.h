#ifndef __MERCHANT_H__
#define __MERCHANT_H__
class Terrain;
class PlayerCharacter;
class Display;
#include <iostream>
#include "enemy.h"

class Merchant : public Enemy {
	public:
	Merchant(Terrain*, Terrain***, Display *);
	~Merchant();
	void attack(PlayerCharacter *);
	void attacked(PlayerCharacter *);
	void notify(PlayerCharacter *);
	void tick(PlayerCharacter *);

};

#endif
