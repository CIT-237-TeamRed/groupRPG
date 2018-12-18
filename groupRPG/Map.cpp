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

bool Map::isEnemyNearby(int x, int y){
	//check the squares around (x,y) for enemy

	//if hero is not in top left corner, check top left corner
	if (x > 0 && y > 0) { 
		if (grid[x - 1][y - 1].isEnemy)
			return true;
	}

	//if hero is not on top side of map, check top unit
	if (y > 0) {
		if (grid[x][y - 1].isEnemy)
			return true;
	}

	//if hero is not in top right corner, check top right unit
	if (x < width-1 && y > 0) {
		if (grid[x + 1][y - 1].isEnemy)
			return true;
	}

	//if hero is not on right side of map, check right unit
	if (x < width-1) {
		if (grid[x + 1][y].isEnemy)
			return true;
	}

	//if hero is not in  bottom right corner, check bottom right unit
	if (x < width-1 && y < length) {
		if (grid[x + 1][y + 1].isEnemy)
			return true;
	}

	//if hero is not on bottom side, check bottom unit
	if (y < length) {
		if (grid[x][y + 1].isEnemy)
			return true;
	}

	//if hero is not in bottom left corner, check bottom left unit
	if (x > 0 && y < length) {
		if (grid[x - 1][y + 1].isEnemy)
			return true;
	}

	//if hero is not on left side of map, check left unit
	if (x > 0) {
		if (grid[x - 1][y].isEnemy)
			return true;
	}

	//if nothing else returns true, return false
	return false;

}

bool Map::isItemNearby(int x, int y) {
	//check the squares around (x,y) for an item

	//if hero is not in top left corner, check top left corner
	if (x > 0 && y > 0) {
		if (grid[x - 1][y - 1].isItem)
			return true;
	}

	//if hero is not on top side of map, check top unit
	if (y > 0) {
		if (grid[x][y - 1].isItem)
			return true;
	}

	//if hero is not in top right corner, check top right unit
	if (x < width-1 && y > 0) {
		if (grid[x + 1][y - 1].isItem)
			return true;
	}

	//if hero is not on right side of map, check right unit
	if (x < width-1) {
		if (grid[x + 1][y].isItem)
			return true;
	}

	//if hero is not in  bottom right corner, check bottom right unit
	if (x < width-1 && y < length) {
		if (grid[x + 1][y + 1].isItem)
			return true;
	}

	//if hero is not on bottom side, check bottom unit
	if (y < length) {
		if (grid[x][y + 1].isItem)
			return true;
	}

	//if hero is not in bottom left corner, check bottom left unit
	if (x > 0 && y < length) {
		if (grid[x - 1][y + 1].isItem)
			return true;
	}

	//if hero is not on left side of map, check left unit
	if (x > 0) {
		if (grid[x - 1][y].isItem)
			return true;
	}

	//if nothing else returns true, return false
	return false;

}

int randPercent() { //return a random number from 0-99
	return rand() % (99 - 0 + 1) + 0;
}

//puts enemies and items at random squares with a 10% and 15% spawn rate respectively 
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

//save map to binary file
void Map::save(ostream &output) {
	Map::Terrain terrain;
	bool enemyState;
	bool itemState;

	//write the width, lenth, heroX, and heroY
	output.write(reinterpret_cast<char *>(&width), sizeof(int));
	output.write(reinterpret_cast<char *>(&length), sizeof(int));
	output.write(reinterpret_cast<char *>(&heroX), sizeof(int));
	output.write(reinterpret_cast<char *>(&heroY), sizeof(int));

	//write the properties for each square  (terrain type, enemy state, item state)
	for (int l = 0; l < length; l++) { //loop length
		for (int w = 0; w < width; w++) { //loop width
			terrain = getTerrain(w, l);
			enemyState = getEnemyState(w, l);
			itemState = getItemState(w, l);

			output.write(reinterpret_cast<char *>(&terrain), sizeof(Map::Terrain));
			output.write(reinterpret_cast<char *>(&enemyState), sizeof(bool));
			output.write(reinterpret_cast<char *>(&itemState), sizeof(bool));
		}
	}
}

//load map from binary file
void Map::load(istream &input) {
	//load width and length
	int width = 0;
	input.read(reinterpret_cast<char *>(&width), sizeof(int));
	int length = 0;
	input.read(reinterpret_cast<char *>(&length), sizeof(int));

	//set dimensions based on width and length
	setDimensions(width, length);

	//set the hero coordinates
	int x = 0;
	int y = 0;
	input.read(reinterpret_cast<char *>(&x), sizeof(int));
	input.read(reinterpret_cast<char *>(&y), sizeof(int));
	setHeroCoords(x, y);
	
	
	Map::Terrain terrain = Map::LAND;
	bool enemyState = false;
	bool itemState = false;

	//set the state of the squares in the map (terrain type, item state, enemy state)
	for (int l = 0; l < length; l++) { //loop length
		for (int w = 0; w < width; w++) { //loop width
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

	//create 2 dimentional array of map width and length
	grid = new unit*[mapWidth];
    for (int i = 0; i < mapLength; i++)
        grid[i] = new unit[mapLength];		

	//set hero to be in the middle of the map
	heroX = mapWidth / 2;
	heroY = mapLength / 2;

	//make sure there isn't an enemy on the spawn of the hero
	setEnemy(heroX, heroY, false);
}

Map::~Map() { //destructor that deletes the 2 dimentional map array
	for (int i = 0; i < length; i++) { //delete second dimension of map
		delete [] grid[i];	
	}
	delete [] grid; //delete rest of map
}

