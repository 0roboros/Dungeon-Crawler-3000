#include "display.h"

using namespace std;

#include "floor.h"
#include "terrain.h"
#include "enemy.h"
#include "item.h"
#include "playerCharacter.h"

Display::Display():atype(""),sGold(0),sEnemy(0),sPot(0),eDmg(0){}

void Display::setGrid(Floor * f){
flo = f;
grid = flo->getGrid();
}
void Display::refreshGrid(){
	grid = flo->getGrid();
}

void Display::resetTrackers(){
	sGold = 0;
	sEnemy = 0;
	sPot = 0;
	atype = "";
	eDmg = 0;
}
void Display::setRace(std::string r){
	race = r;
}
void Display::printGrid(){
	for (int row = 0; row < 25; row++){
		for (int col = 0; col < 79; col++){
			Terrain * t = grid[row][col];
			std::string tt = t->getType();
			if (tt == "Wall"){
				if (t->getOrient() == 'h')
					cout << '-';
				else cout << '|';
			}
			else if (tt == "Space"){
				cout << ' ';
			}
			else if (tt == "Door"){
				if (t->getPC() == 0)
					cout << '+';
				else cout << '@';
			}
			else if (tt == "Passage"){
				if (t->getPC() == 0)
					cout << '#';
				else cout << '@';
			}
			else if (tt == "Ground"){
				if (t->occupantType() == "PC")
					cout << '@';
				else if (t->occupantType() == "Enemy"){
					std::string et = (t->getEnemy())->getRace();
					if (et == "Vampire")
						cout << 'V';
					else if (et == "Werewolf")
						cout << 'W';
					else if (et == "Troll")
						cout << 'T';
					else if (et == "Goblin")
						cout << 'N';
					else if (et == "Merchant")
						cout << 'M';
					else if (et == "Dragon")
						cout << 'D';
					else if (et == "Phoenix")
						cout << 'X';
				}
				else if (t->occupantType() == "Item"){
					std::string pt = (t->getItem())->getType();
					if (pt ==  "Gold")
						cout << 'G';
					else if (pt == "Potion")
						cout << 'P';
				}
				else 
					cout << '.';
			}	
			else if (tt == "Stairs")
				cout << '/';
			else cout << ' ';
			
		}
		cout << endl;
	}
}

void Display::printDesc(){
	cout << "Race: " << (flo->getPlayer())->getRace() << " Gold: " << (flo->getPlayer())->getGold() << endl;
	int hp = (flo->getPlayer())->getHP();
	if (hp < 0)
		cout << "HP: " << 0 << endl;
	else cout << "HP: " << hp << endl;
	cout << "Atk: " << (flo->getPlayer())->getAtk() << endl;
	cout << "Def: " << (flo->getPlayer())->getDef() << endl;
	if (atype == "Attack")
		cout << "PC deals " << pDmg << " to " << mAd << "(" << eHp << ").";
	if (eDmg != 0)
		cout << mAtk << " deals " << eDmg << " to PC.";
	if (atype == "Move")
		cout << "PC moves.";
	if (sGold == 1)
		cout << "PC sees gold.";
	if (sPot == 1)
		cout << "PC sees potion.";
	if ((sEnemy == 1) && (eDmg == 0))
		cout << "PC sees enemy.";
	cout << endl;
}

void Display::lastAction(std::string at){
	atype = at;
}

void Display::eneHP(int eh){
	eHp = eh;
}

void Display::playerDmg(int pd, std::string mtype){
	pDmg = pd;
	mAd = mtype;
}

void Display::enemyDmg(int ed, std::string mtype){
	eDmg = ed;
	mAtk = mtype;
}
void Display::notify(bool seeGold, bool seeEnemy, bool seePotion){
	sGold = seeGold;
	sEnemy = seeEnemy;
	sPot = seePotion;
}
