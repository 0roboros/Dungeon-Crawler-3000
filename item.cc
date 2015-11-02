#include "item.h"


Item::Item(std::string t):type(t){}

std::string Item::getType(){
	return type;
}

int Item::getAmount(){

	return 0;

}

void Item::setDp(Enemy * ene){

}

Item::~Item(){}
