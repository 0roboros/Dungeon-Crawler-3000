#include <iostream>
using namespace std;

#include "decoratorPC.h"
#include "playerCharacter.h"

DecoratorPC::DecoratorPC(PlayerCharacter *pc): pc(pc) {}

DecoratorPC::~DecoratorPC() {delete pc;}

int DecoratorPC::getAtk() {return pc->getAtk();}
int DecoratorPC::getDef() {return pc->getDef();}
int DecoratorPC::getHP() {return pc->getHP();}
string DecoratorPC::getRace() {return pc->getRace();}
Terrain * DecoratorPC::getCurLoc() {return pc->getCurLoc();}
void DecoratorPC::setLoc(Terrain *t) { pc->setLoc(t);}

void DecoratorPC::updateNeighbours() {pc->updateNeighbours();}
void DecoratorPC::death() {pc->death();}
void DecoratorPC::attack(Terrain* t) {pc->attack(t);}
void DecoratorPC::attacked(Character * enemy) {pc->attacked(enemy);}
void DecoratorPC::move(Terrain *t) {pc->move(t);}
void DecoratorPC::notifyNeighbours() {pc->notifyNeighbours();}
void DecoratorPC::notifyDisplay() {pc->notifyDisplay();}
	
//void DecoratorPC::addGold(Gold *g) {pc->addGold(g);}
void DecoratorPC::addGold(int amt) {pc->addGold(amt);}
	
void DecoratorPC::nearGold(bool gold) {pc->nearGold(gold);}
void DecoratorPC::nearEnemy(bool enemy) {pc->nearEnemy(enemy);}
void DecoratorPC::nearPotion(bool potion) {pc->nearPotion(potion);}

