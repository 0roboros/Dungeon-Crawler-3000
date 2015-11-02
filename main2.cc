#include <iostream>
#include "floor.h"
#include "display.h"
#include "terrain.h"
#include "wall.h"
#include "ground.h"
#include "passage.h"
#include "stairs.h"
#include "character.h"
#include "playerCharacter.h"
#include "orc.h"
#include "human.h"
#include "elf.h"
#include "dwarf.h"
#include "enemy.h"
#include "item.h"
#include "potion.h"
#include "gold.h"
#include "vampire.h"
#include "troll.h"
#include "phoenix.h"
#include "dragon.h"
#include "werewolf.h"
#include "goblin.h"
#include "merchant.h"

using namespace std;

int main(){
	Display * d = new Display();
        Floor * fl = new Floor("floorlayout.txt",d);
	d->setGrid(fl);
	fl->setDisplay(d);
	d->printGrid();
	char first;
	char second;
	char third;
	int cont = 1;
	while (cont){
		if ((fl->getPlayer()->isDead()) == 1){
			break;}
		cin >> first;
		Terrain * cur = (fl->getPlayer())->getCurLoc();
		switch (first){
			case 'n':
				cin >> second;
				switch (second){
					case 'o':
						(fl->getPlayer())->move(fl->getNorth(cur));
						break;
					case 'w':
                                                (fl->getPlayer())->move(fl->getNW(cur));
						break;
					case 'e':
                                                (fl->getPlayer())->move(fl->getNE(cur));
						break;
				}
				break;
			case 's':
				cin >> second;
				switch (second){
					case 'o':
                                                (fl->getPlayer())->move(fl->getSouth(cur));
						break;
					case 'e':

                                                (fl->getPlayer())->move(fl->getSE(cur));
                                                break;
					case 'w':
                                                (fl->getPlayer())->move(fl->getSW(cur));
                                                break;
				}
				break;
			case 'e':
				cin >> second;
                                             
                                                (fl->getPlayer())->move(fl->getEast(cur));
                                                break;
			case 'w':
				cin >> second;
                                               
                                                (fl->getPlayer())->move(fl->getWest(cur));
                                                break;
			case 'a':
				cin >> second;
				cin >> third;
					if (second == 'e')
						(fl->getPlayer())->attack(fl->getEast(cur));
					else if (second == 'w')
						(fl->getPlayer())->attack(fl->getWest(cur));
					else if ((second == 'n') && (third == 'o'))
						(fl->getPlayer())->attack(fl->getNorth(cur));
					else if ((second == 'n') && (third == 'w'))
						(fl->getPlayer())->attack(fl->getNW(cur));
                                        else if ((second == 'n') && (third == 'e'))
                                                (fl->getPlayer())->attack(fl->getNE(cur));
                                        else if ((second == 's') && (third == 'o'))
                                                (fl->getPlayer())->attack(fl->getSouth(cur));
                                        else if ((second == 's') && (third == 'w'))
                                                (fl->getPlayer())->attack(fl->getSW(cur));
                                        else if ((second == 's') && (third == 'e'))
                                                (fl->getPlayer())->attack(fl->getSE(cur));
					break;
			case 'u':
                                cin >> second;
                                cin >> third;
                                        if (second == 'e')
                                                (fl->getPlayer())->move(fl->getEast(cur));
                                        else if (second == 'w')
                                                (fl->getPlayer())->move(fl->getWest(cur));
                                        else if ((second == 'n') && (third == 'o'))
                                                (fl->getPlayer())->move(fl->getNorth(cur));
                                        else if ((second == 'n') && (third == 'w'))
                                                (fl->getPlayer())->move(fl->getNW(cur));
                                        else if ((second == 'n') && (third == 'e'))
                                                (fl->getPlayer())->move(fl->getNE(cur));
                                        else if ((second == 's') && (third == 'o'))
                                                (fl->getPlayer())->move(fl->getSouth(cur));
                                        else if ((second == 's') && (third == 'w'))
                                                (fl->getPlayer())->move(fl->getSW(cur));
                                        else if ((second == 's') && (third == 'e'))
                                                (fl->getPlayer())->move(fl->getSE(cur));
					break;


			
			case 'q': cont = 0;
				break;


		}	
	fl->tick();
	d->refreshGrid();
	d->printGrid();
	d->printDesc();
	d->resetTrackers();


	}
	delete fl;
	
/*	Terrain *** t = new Terrain ** [5];
	for (int k= 0; k< 5; k++)
		t[k] = new Terrain * [6];
	for (int k = 0; k < 5; k++){
		for (int l = 0; l < 6; l++){
			t[k][l] = new Ground(k,l);
			t[k][l]->setEnemy(new Vampire());
			cout << "Made a Vampire!" << endl;
		}
	}
	Terrain * g = new Ground(0,0);
	g->setEnemy(new Vampire());
	delete g;
        Terrain * g2 = new Ground(0,0);
        g->setEnemy(new Werewolf());
        delete g2;
        Terrain * g3 = new Ground(0,0);
        g->setEnemy(new Troll());
        delete g3;
        Terrain * g4 = new Ground(0,0);
        g->setEnemy(new Phoenix());
        delete g4;
        Terrain * g5 = new Ground(0,0);
        g->setEnemy(new Goblin());
        delete g5;
        Terrain * g6 = new Ground(0,0);
        g->setEnemy(new Dragon());
        delete g6;
        Terrain * g7 = new Ground(0,0);
        g->setItem(new Potion("RH"));
        delete g7;
        Terrain * g8 = new Ground(0,0);
        g->setItem(new Potion("BD"));
        delete g8;
        Terrain * g9 = new Ground(0,0);
        g->setItem(new Potion("BA"));
        delete g9;
        Terrain * g10 = new Ground(0,0);
        g10->setPC(new Orc(g10, t));
        delete g10;
        Terrain * g11 = new Ground(0,0);
        g->setEnemy(new Vampire());
        delete g11;
        Terrain * g12 = new Ground(0,0);
        g->setEnemy(new Vampire());
        delete g12;
        Terrain * g13 = new Ground(0,0);
        g->setEnemy(new Vampire());
        delete g13;
        Terrain * g14 = new Ground(0,0);
        g->setEnemy(new Vampire());
        delete g14;
        Terrain * g15 = new Ground(0,0);
        g->setEnemy(new Vampire());
        delete g15;
*/
}
