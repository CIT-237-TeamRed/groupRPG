#include "Map.h"
#include <stdlib.h>

void Map::setDimensions(int mapWidth, int mapLength) { //set the dimention
	width = mapWidth;
	length = mapLength;
}

void Map::setHeroCoords(int x, int y){ //set the hero coordinates of (x,y)
	heroX = x;
	heroY = y;
}

void Map::setTerrain(int x, int y, Terrain mapTerrain) { //set terrain type of specific unit (x,y)
	grid[x][y].terrain = mapTerrain;
}

void Map::setEnemy(int x, int y, bool set){ //set the enemy to be true or false based on set
	grid[x][y].isEnemy = set;
}

void Map::setItem(int x, int y, bool set){ //set the item to be true or false based on set
	grid[x][y].isItem = set;
}

void Map::switchEnemy(int x, int y) { //reverses value if isEnemy for a unit (x,y)
	grid[x][y].isEnemy = !grid[x][y].isEnemy;
}

void Map::switchItem(int x, int y) { //reverses value if isItem for a unit 
	grid[x][y].isItem = !grid[x][y].isItem;
}

bool Map::isEnemyNearby(int x, int y){
	//check the squares around (x,y) for enemy
	if (grid[x -1][y - 1].isEnemy == true || grid[x][y - 1].isEnemy == true || grid[x+ 1][y - 1].isEnemy == true || grid[x + 1][y].isEnemy == true 
		|| grid[x + 1][y + 1].isEnemy == true || grid[x][y + 1].isEnemy == true || grid[x - 1 ][y + 1].isEnemy == true || grid[x - 1][y].isEnemy == true){
		return true;
	} else {
		return false;
	}
}

bool Map::isItemNearby(int x, int y) {
	//check the squares around (x,y) item
	if (grid[x - 1][y - 1].isItem == true || grid[x][y - 1].isItem == true || grid[x + 1][y - 1].isItem == true || grid[x + 1][y].isItem == true
		|| grid[x + 1][y + 1].isItem == true || grid[x][y + 1].isItem == true || grid[x - 1][y + 1].isItem == true || grid[x - 1][y].isItem == true) {
		return true;
	} else {
		return false;
	}
}

int randPercent() {
	return rand() % (99 - 0 + 1) + 0;
}

void Map::generateMap() {
	for (int i = 0; i < length; i++) {
		for (int j = 0; j < width; j++) {
			if (randPercent() < 10 && j != heroX && i != heroY) // 10% chance to spawn an enemy if it is not where the hero currently is
				setEnemy(j, i, true);
			else
				setEnemy(j, i, false); // set it to false otherwise to clear the rest of the map

			if (randPercent() < 15) // 15% chance to spawn an item
				setItem(j, i, true);
			else
				setItem(j, i, false); // set it to false otherwise to clear the rest of the map
		}
	}
}

Map::Map(int mapWidth, int mapLength) { //create map of specified width and length
	setDimensions(mapWidth, mapLength);
	grid = new unit*[mapWidth];
    for (int i = 0; i < mapLength; i++)
        grid[i] = new unit[mapLength];		
	heroX = mapWidth / 2;
	heroY = mapLength / 2;

	setEnemy(heroX, heroY, false);
}

Map::~Map() { //destructor that delets the 2 dimentional map array
	for (int i = 0; i < length; i++) {
		delete [] grid[i];	
	}
	delete [] grid;
}

