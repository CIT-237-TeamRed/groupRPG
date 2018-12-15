// Jericho Keyne
// Team Red
// This file creates a map, writes it to a binary file, and then loads that into a new map

#include <iostream>
#include "Map.h"
#include <fstream>

using namespace std;

void saveMap(Map board, ostream &output);
void loadMap(Map &board, istream &input);

int main() {
	Map board(4, 4);
	ofstream output("map.dat", ios::binary);
	board.switchEnemy(3,1);
	board.switchItem(3,1);
	saveMap(board, output);
	cout << "board.getWidth: " << board.getWidth() << endl;

	Map newBoard(20, 4);
	ifstream input("map.dat", ios::binary);
	loadMap(newBoard, input);
	cout << "newBoard.getWidth: " << newBoard.getWidth() << endl;
	cout << "newBoard.getEnemyState(3,3): " << newBoard.getEnemyState(3,3) << endl;
	cout << "newBoard.getEnemyState(3,1): " << newBoard.getEnemyState(3,1) << endl;
	cout << "newBoard.getItemState(3,3): " << newBoard.getItemState(3,3) << endl;
	cout << "newBoard.getItemState(3,1): " << newBoard.getItemState(3,1) << endl;
	return 0;
}

void saveMap(Map board, ostream &output) {
	int width = board.getWidth();
	int length = board.getLength();
	Map::Terrain terrain;
	bool enemyState;
	bool itemState;

	output.write(reinterpret_cast<char *>(&width), sizeof(int));
	output << endl;
	output.write(reinterpret_cast<char *>(&length), sizeof(int));
	output << endl;
	for (int l = 0; l < length; l++) {
		for (int w = 0; w < width; w++) {
			terrain = board.getTerrain(w, l);
			enemyState = board.getEnemyState(w, l);
			itemState = board.getItemState(w, l);

			output.write(reinterpret_cast<char *>(&terrain), sizeof(Map::Terrain));
			output << endl;
			output.write(reinterpret_cast<char *>(&enemyState), sizeof(bool));
			output << endl;
			output.write(reinterpret_cast<char *>(&itemState), sizeof(bool));
			output << endl;
		}
	}
}

void loadMap(Map &board, istream &input) {
	int width = 0;
	input.read(reinterpret_cast<char *>(&width), sizeof(int));
	input.seekg(1, ios::cur);
	cout << "width: " << width << endl;
	int length = 0;
	input.read(reinterpret_cast<char *>(&length), sizeof(int));
	input.seekg(1, ios::cur);
	cout << "length: " << length << endl;

	board.setDimensions(width, length);
	
	bool enemyState = false;
	bool itemState = false;
	Map::Terrain terrain = Map::LAND;
	for (int l = 0; l < length; l++) {
		for (int w = 0; w < width; w++) {
			input.read(reinterpret_cast<char *>(&terrain), sizeof(Map::Terrain));
			input.seekg(1, ios::cur);
			input.read(reinterpret_cast<char *>(&enemyState), sizeof(bool));
			input.seekg(1, ios::cur);
			input.read(reinterpret_cast<char *>(&itemState), sizeof(bool));
			input.seekg(1, ios::cur);

			board.setTerrain(w, l, terrain);
			if (enemyState)
				board.switchEnemy(w, l);
			if (itemState)
				board.switchItem(w, l);
			cout << "(" << w << ", " << l << "): enemyState: " << enemyState << ", itemState: " << itemState << endl;
		}
	}
}
