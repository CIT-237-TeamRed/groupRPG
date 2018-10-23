#include "MapHeader.h"
#include <iostream>

using namespace std;

int main() {
	Map map(4, 4);


	map.setDimensions(2, 2);

	map.setTerrain(0, 0, Map::Terrain::WATER);

	map.switchEnemy(0, 1);

	map.switchItem(1, 1);
	cout << "hi";
	return 0;
}