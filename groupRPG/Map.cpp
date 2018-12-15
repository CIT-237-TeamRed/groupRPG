#include "Map.h"
#include <stdlib.h>
#include <iostream>

using namespace std;

void Map::setDimensions(int mapWidth, int mapLength) { //set the dimention
	width = mapWidth;
	length = mapLength;
}

void Map::setHeroCoords(int x, int y){ //set the hero coordinates of (x,y)
	if (x > 0 && x < width)
		heroX = x;
	if (y > 0 && y < length)
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
	if (x > 0 && y > 0) {
		if (grid[x - 1][y - 1].isEnemy)
			return true;
	}
	if (y > 0) {
		if (grid[x][y - 1].isEnemy)
			return true;
	}
	if (x < width && y > 0) {
		if (grid[x + 1][y - 1].isEnemy)
			return true;
	}
	if (x < width) {
		if (grid[x + 1][y].isEnemy)
			return true;
	}
	if (x < width && y < length) {
		if (grid[x + 1][y + 1].isEnemy)
			return true;
	}
	if (y < length) {
		if (grid[x][y + 1].isEnemy)
			return true;
	}
	if (x > 0 && y < length) {
		if (grid[x - 1][y + 1].isEnemy)
			return true;
	}
	if (x > 0) {
		if (grid[x - 1][y].isEnemy)
			return true;
	}
	return false;
//	if (grid[x -1][y - 1].isEnemy == true || grid[x][y - 1].isEnemy == true || grid[x+ 1][y - 1].isEnemy == true || grid[x + 1][y].isEnemy == true 
//		|| grid[x + 1][y + 1].isEnemy == true || grid[x][y + 1].isEnemy == true || grid[x - 1 ][y + 1].isEnemy == true || grid[x - 1][y].isEnemy == true){
//		return true;
//	} else {
//		return false;
//	}
}

bool Map::isItemNearby(int x, int y) {
	//check the squares around (x,y) item
	if (x > 0 && y > 0) {
		if (grid[x - 1][y - 1].isItem)
			return true;
	}
	if (y > 0) {
		if (grid[x][y - 1].isItem)
			return true;
	}
	if (x < width && y > 0) {
		if (grid[x + 1][y - 1].isItem)
			return true;
	}
	if (x < width) {
		if (grid[x + 1][y].isItem)
			return true;
	}
	if (x < width && y < length) {
		if (grid[x + 1][y + 1].isItem)
			return true;
	}
	if (y < length) {
		if (grid[x][y + 1].isItem)
			return true;
	}
	if (x > 0 && y < length) {
		if (grid[x - 1][y + 1].isItem)
			return true;
	}
	if (x > 0) {
		if (grid[x - 1][y].isItem)
			return true;
	}
	return false;
//	if (grid[x - 1][y - 1].isItem == true || grid[x][y - 1].isItem == true || grid[x + 1][y - 1].isItem == true || grid[x + 1][y].isItem == true
//		|| grid[x + 1][y + 1].isItem == true || grid[x][y + 1].isItem == true || grid[x - 1][y + 1].isItem == true || grid[x - 1][y].isItem == true) {
//		return true;
//	} else {
//		return false;
//	}
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

void Map::save(ostream &output) {
	Map::Terrain terrain;
	bool enemyState;
	bool itemState;

	output.write(reinterpret_cast<char *>(&width), sizeof(int));
	output.write(reinterpret_cast<char *>(&length), sizeof(int));
	output.write(reinterpret_cast<char *>(&heroX), sizeof(int));
	output.write(reinterpret_cast<char *>(&heroY), sizeof(int));
	for (int l = 0; l < length; l++) {
		for (int w = 0; w < width; w++) {
			terrain = getTerrain(w, l);
			enemyState = getEnemyState(w, l);
			itemState = getItemState(w, l);

			output.write(reinterpret_cast<char *>(&terrain), sizeof(Map::Terrain));
			output.write(reinterpret_cast<char *>(&enemyState), sizeof(bool));
			output.write(reinterpret_cast<char *>(&itemState), sizeof(bool));
		}
	}
}

void Map::load(istream &input) {
	int width = 0;
	input.read(reinterpret_cast<char *>(&width), sizeof(int));
	int length = 0;
	input.read(reinterpret_cast<char *>(&length), sizeof(int));

	setDimensions(width, length);

	int x = 0;
	int y = 0;
	input.read(reinterpret_cast<char *>(&x), sizeof(int));
	input.read(reinterpret_cast<char *>(&y), sizeof(int));
	setHeroCoords(x, y);
	
	bool enemyState = false;
	bool itemState = false;
	Map::Terrain terrain = Map::LAND;
	for (int l = 0; l < length; l++) {
		for (int w = 0; w < width; w++) {
			input.read(reinterpret_cast<char *>(&terrain), sizeof(Map::Terrain));
			input.read(reinterpret_cast<char *>(&enemyState), sizeof(bool));
			input.read(reinterpret_cast<char *>(&itemState), sizeof(bool));

			setTerrain(w, l, terrain);
			setEnemy(w, l, enemyState);
			setItem(w, l, itemState);
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

