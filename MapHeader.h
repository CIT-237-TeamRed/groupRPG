#pragma once
#ifndef MAPHEADER_H
#define MAPHEADER_H

class Map {
public:
	enum Terrain { LAND, WATER };
private:
	struct unit {
		bool isEnemy = false; //no enemy in a unit by default
		bool isItem = false; //no item in a unit by default
		Terrain terrain = LAND; //every unit is land by default
	};

	int width; //length and width of map
	int length;

	unit ** grid; //the structure of the map is a 2 dimensional array of 'units'

public:
	void setDimensions(int width, int length); //set dimensions by length and width
	void setTerrain(int x, int y, Map::Terrain mapTerrain); //set the type of terrain in a specific unit
	void switchEnemy(int x, int y); //if there is an enemy, call to make isEnemy false, and vice versa
	void switchItem(int x, int y); //reverses the value of isItem for a certain unit

	
	bool getEnemyState(int x, int y) { return grid[x][y].isEnemy; }; //returns if there is an enemy in a unit
	bool getItemState(int x, int y) { return grid[x][y].isItem; }; //returns if there is an item in a unit
	Terrain getTerrain(int x, int y) { return grid[x][y].terrain; }; //return the type of terrain of a unit
    int getLength() { return length; };
    int getWidth() { return width; };
	

    Map(int width, int length); //constructs map of width and length
};
#endif
