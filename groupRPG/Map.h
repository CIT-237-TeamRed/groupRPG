#pragma once
#ifndef MAP_H
#define MAP_H

#include <iostream>

class Map {
public:
	enum Terrain { LAND, WATER }; //the types of terrain a unit can be 
private:
	struct unit {
		bool isEnemy = false; //no enemy in a unit by default
		bool isItem = false; //no item in a unit by default
		Terrain terrain = LAND; //every unit is land by default
	};

	int heroX = 0; //hero's x coord
	int heroY = 0; //hero's y coord

	int width; //length and width of map
	int length; 

	unit ** grid; //the structure of the map is a 2 dimensional array of 'units'

public:
	void setDimensions(int width, int length); //set dimensions by length and width, width is horizontal
	void setHeroCoords(int x, int y); //set coordininates for hero
	void setTerrain(int x, int y, Map::Terrain mapTerrain); //set the type of terrain in a specific unit
	void setEnemy(int x, int y, bool set); //set the enemy to be true or false based on set
	void setItem(int x, int y, bool set); //set the item to be true or false based on set
	void generateMap(); //generates a map with randomly placed enemies and items 
	void save(std::ostream &output); //saves map state to binary file
	void load(std::istream &input); //loads map stat from binary file


	int getHeroX() { return heroX; };
	int getHeroY() { return heroY; };
	bool getEnemyState(int x, int y) { return grid[x][y].isEnemy; }; //returns if there is an enemy in a unit
	bool getItemState(int x, int y) { return grid[x][y].isItem; }; //returns if there is an item in a unit
	bool isEnemyNearby(int x, int y);
	bool isItemNearby(int x, int y);
	Terrain getTerrain(int x, int y) { return grid[x][y].terrain; }; //return the type of terrain of a unit
    int getLength() { return length; };
    int getWidth() { return width; };
	

    Map(int width, int length); //constructs map of width and length
	~Map(); //deconstructs the map array
};
#endif
