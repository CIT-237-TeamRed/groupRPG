#include "MapHeader.h"

void Map::setDimensions(int mapWidth, int mapLength) {
	width = mapWidth;
	length = mapLength;
}

void Map::setTerrain(int x, int y, Terrain mapTerrain) { //set terrain type of specific unit
	grid[x][y].terrain = mapTerrain;
}

void Map::switchEnemy(int x, int y) { //reverses value if isEnemy for a unit
	grid[x][y].isEnemy = !grid[x][y].isEnemy;
}

void Map::switchItem(int x, int y) { //reverses value if isItem for a unit
	grid[x][y].isItem = !grid[x][y].isItem;
}


Map::Map(int mapWidth, int mapLength) { //create map of specified width and length
	setDimensions(mapWidth, mapLength);
	grid = new unit*[mapWidth];
    for (int i = 0; i < mapLength; i++)
        grid[i] = new unit[mapLength];		
}
