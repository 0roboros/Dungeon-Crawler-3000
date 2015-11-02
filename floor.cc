#include <iostream>
#include <iomanip>
#include <fstream>
#include "floor.h"
#include "door.h"
#include "wall.h"
#include "space.h"
#include "passage.h"
#include "ground.h"
#include "stairs.h"
#include "potion.h"
#include "gold.h"
#include "vampire.h"
#include "werewolf.h"
#include "troll.h"
#include "goblin.h"
#include "merchant.h"
#include "phoenix.h"
#include "dragon.h"
#include "human.h"
#include "dwarf.h"
#include "orc.h"
#include "elf.h"
#include "display.h"

using namespace std;

Floor::Floor(std::string filename, Display * dis):grid(new Terrain ** [25]), d(dis){

	for (int k = 0; k < 25; k++)
		grid[k] = new Terrain * [79];

	readFromFile(filename);
}

void Floor::setDisplay(Display * dis){
	d = dis;
	if (thePlayer != 0)
		thePlayer->setDisplay(d);
}

PlayerCharacter * Floor::getPlayer(){
return thePlayer;
}

Terrain * Floor::getTerrain(int r, int c){
	return grid[r][c];
}

Terrain *  Floor::getNorth(Terrain * t){
	return grid[t->getRow() - 1][t->getCol()];
}

Terrain * Floor::getSouth(Terrain * t){
        return grid[t->getRow() + 1][t->getCol()];
}

Terrain * Floor::getWest(Terrain * t){
        return grid[t->getRow()][t->getCol()-1];

}

Terrain * Floor::getEast(Terrain * t){
        return grid[t->getRow()][t->getCol()+1];

}

Terrain * Floor::getNW(Terrain * t){
        return grid[t->getRow() - 1][t->getCol()-1];
}

Terrain * Floor::getNE(Terrain * t){
        return grid[t->getRow() - 1][t->getCol()+1];

}

Terrain * Floor::getSW(Terrain * t){
        return grid[t->getRow() + 1][t->getCol()-1];

}

Terrain * Floor::getSE(Terrain * t){
        return grid[t->getRow() + 1][t->getCol()+1];

}




void Floor::readFromFile(std::string filename){

        ifstream inp(filename.c_str());
        char c;
	inp >> noskipws;
	for (int row = 0; row < 25; row++){

		for (int col = 0; col < 80; col++){
			inp >> c;
			Terrain * thisCell;
			switch(c){
				case '\n': break;
				case '\r': break;
				case '|':
					grid[row][col] = new Wall(row, col, 'v');
					 break;
				case '-':
					grid[row][col] = new Wall(row, col, 'h'); break;
				case ' ':
					grid[row][col] = new Space(row, col); break;
				case '.':
					grid[row][col] = new Ground(row, col); break;
				case '#':
					grid[row][col] = new Passage(row, col); break;
				case '+':
					grid[row][col] = new Door(row, col); break;
				case '/':
					grid[row][col] = new Stairs(row, col); break;
				case '@':
					thisCell = new Ground(row, col);
					grid[row][col] = thisCell;
					(grid[row][col])->setPC(new Human(thisCell, grid));
					thePlayer = (grid[row][col])->getPC();
					break;
				case 'V':
					thisCell = new Ground(row, col);
					grid[row][col] = thisCell;
					(grid[row][col])->setEnemy(new Vampire(thisCell, grid,d));
					break;
				case 'W':
                                        thisCell = new Ground(row, col);
                                        grid[row][col] = thisCell;
                                        (grid[row][col])->setEnemy(new Werewolf(thisCell, grid, d));

					break;
				case 'T':
                                        thisCell = new Ground(row, col);
                                        grid[row][col] = thisCell;
                                        (grid[row][col])->setEnemy(new Troll(thisCell, grid, d));

					break;
				case 'N':
                                        thisCell = new Ground(row, col);
                                        grid[row][col] = thisCell;
                                        (grid[row][col])->setEnemy(new Goblin(thisCell, grid, d));

					break;
				case 'M':
                                        thisCell = new Ground(row, col);
                                        grid[row][col] = thisCell;
                                        (grid[row][col])->setEnemy(new Merchant(thisCell, grid, d));

					break;
/*				case 'D':
				        grid[row][col] = new Ground(row, col);
					(grid[row][col])->setEnemy(new Dragon());
                                        for (int c = (col - 1); c <= (col + 1); c++){
                                                if ((((grid[row-1][c])->getType()) == "Ground")
                                                && (((grid[row-1][c])->getItem()) != 0)
						&& (((((grid[row-1][c]))->getItem())->getType()) == "Gold")
						&& (((((grid[row-1][c]))->getItem())->getAmount()) == 6)){
                                                        (((grid[row-1][c])->getItem())->setDp((grid[row][col])->getEnemy()));
                                                }
                                        }

                                        if ((((grid[row][col-1])->getType()) == "Ground")
                                        && (((grid[row][col-1])->getItem()) != 0) 
					&& (((((grid[row][col-1]))->getItem())->getType()) == "Gold")
        				&& (((((grid[row][col-1]))->getItem())->getAmount()) == 6)){
                                        	(((grid[row][col-1])->getItem())->setDp((grid[row][col])->getEnemy()));
                                        }
                                        break;
*/
				case 'X':
                                        thisCell = new Ground(row, col);
                                        grid[row][col] = thisCell;
                                        (grid[row][col])->setEnemy(new Phoenix(thisCell, grid, d));
					break;
				case '0':
					grid[row][col] = new Ground(row, col);
					(grid[row][col])->setItem(new Potion("RH"));
					break;
				case '1':
					grid[row][col] = new Ground(row, col);
					(grid[row][col])->setItem(new Potion("BA"));
					break;
				case '2':
					grid[row][col] = new Ground(row, col);
					(grid[row][col])->setItem(new Potion("BD"));
					break;
				case '3':
					grid[row][col] = new Ground(row, col);
					(grid[row][col])->setItem(new Potion("PH"));
					break;
				case '4':
					grid[row][col] = new Ground(row, col);
					(grid[row][col])->setItem(new Potion("WA"));
					break;
				case '5':
					grid[row][col] = new Ground(row, col);
					(grid[row][col])->setItem(new Potion("WD"));
					break;
				case '6':
					grid[row][col] = new Ground(row, col);
					(grid[row][col])->setItem(new Gold(1));
					break;
				case '7':
					grid[row][col] = new Ground(row, col);
					(grid[row][col])->setItem(new Gold(2));
					break;
				case '8':
					grid[row][col] = new Ground(row, col);
					(grid[row][col])->setItem(new Gold(4));
					break;
/*				case '9':
					grid[row][col] = new Ground(row, col);
					for (int c = (col - 1); c < (col + 1); c++){
						if ((((grid[row-1][c])->getType()) == "Ground") 
						&& (((grid[row-1][c])->getEnemy()) != 0) && (((((grid[row-1][c]))->getEnemy())->getRace()) == "Dragon")){
							(grid[row][col])->setItem(new Gold(6, (grid[row-1][c])->getEnemy()));
						}
					}
					
					if ((((grid[row][col-1])->getType()) == "Ground")
                                        && (((grid[row][col-1])->getEnemy()) != 0) && (((((grid[row][col-1]))->getEnemy())->getRace()) == "Dragon")){
                                        (grid[row][col-1])->setItem(new Gold(6, (grid[row][col-1])->getEnemy()));
                                        }
					break;
*/				default: break;
					
                	}               
		}
        }


}

Terrain *** Floor::getGrid(){
	return grid;
}

void Floor::tick(){
	for (int row = 0; row < 25; row++){
		for (int col = 0; col < 79; col++){
			if(((grid[row][col])->getPC()) != 0)
				thePlayer = (((grid[row][col])->getPC()));
		}
	}
	thePlayer->notifyDisplay();
	for (int row = 0; row < 25; row++){
		for (int col = 0; col < 79; col++){
			if (((grid[row][col])->getEnemy()) != 0)
				(((grid[row][col])->getEnemy())->tick(thePlayer));
		}
	}
}

Floor::~Floor(){
	for (int row = 0; row < 25; row++){
		for (int col = 0; col < 79; col++)
			delete grid[row][col];
		delete [] grid[row];
	}
	delete [] grid;
}


