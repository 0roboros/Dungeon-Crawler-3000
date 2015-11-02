#ifndef __ITEM_H__
#define __ITEM_H__

class Terrain;
class Enemy;
#include <string>

class Item{
	std::string type;
	public:
	Item(std::string t);
	std::string getType();
	virtual int getAmount();
	virtual void setDp(Enemy *);
	virtual void react(Terrain &other) = 0;
	virtual ~Item() = 0;

};

#endif
