#include "MapHeader.h"
#include <iostream>
#include <string>

using namespace std;

int main() {
	Map map(4, 4);

	cout << boolalpha << map.getEnemyState(0, 0) << endl
		<< map.getItemState(0, 0) << endl
		<< map.getTerrain(0, 0) << endl
		<< map.getLength() << endl
		<< map.getWidth() << endl << endl;

	map.setDimensions(2, 2);

	cout <<  boolalpha << map.getEnemyState(0, 0) << endl
		<< map.getItemState(0, 0) << endl
		<< map.getTerrain(0, 0) << endl
		<< map.getLength() << endl
		<< map.getWidth() << endl << endl;


	map.setTerrain(0, 0, Map::Terrain::WATER);

	cout << map.getEnemyState(0, 0) << endl
		<< map.getItemState(0, 0) << endl
		<< map.getTerrain(0, 0) << endl
		<< map.getLength() << endl
		<< map.getWidth() << endl << endl;

	map.switchEnemy(0, 0);

	cout << map.getEnemyState(0, 0) << endl
		<< map.getItemState(0, 0) << endl
		<< map.getTerrain(0, 0) << endl
		<< map.getLength() << endl
		<< map.getWidth() << endl << endl;

	map.switchItem(0, 0);

	cout << map.getEnemyState(0, 0) << endl
		<< map.getItemState(0, 0) << endl
		<< map.getTerrain(0, 0) << endl
		<< map.getLength() << endl
		<< map.getWidth() << endl << endl;


	cin.ignore();
	return 0;
}
