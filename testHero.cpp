// Jericho Keyne
// Tests the Hero class for the RPG project

#include <iostream>
#include "hero.h"
#include "item.h"

using namespace std;

int main() {
	Item test1;
	Item sword;
	cout << "Making testHero with 5 health and level 10" << endl;
	Hero testHero(5,10);
	cout << "testHero.getHealth(): " << testHero.getHealth() << endl;
	cout << "testHero.getLevel(): " << testHero.getLevel() << endl;

	cout << "testHero.getMaxHealth() should be 20: " << testHero.getMaxHealth() << endl;
	cout << "testHero.getMaxLevel() should be 10: " << testHero.getMaxLevel() << endl;

	cout << "Setting testHero's level to 40" << endl;
	testHero.setLevel(40);
	cout << "testHero.getHealth(): " << testHero.getHealth() << endl;
	cout << "testHero.getLevel(): " << testHero.getLevel() << endl;

	cout << "Setting testHero's level to -100" << endl;
	testHero.setLevel(-100);
	cout << "testHero.getHealth(): " << testHero.getHealth() << endl;
	cout << "testHero.getLevel(): " << testHero.getLevel() << endl;

	cout << "Setting testHero's health to 100" << endl;
	testHero.setHealth(100);
	cout << "testHero.getHealth(): " << testHero.getHealth() << endl;
	cout << "testHero.getLevel(): " << testHero.getLevel() << endl;

	cout << "Setting testHero's health to -140" << endl;
	testHero.setLevel(-140);
	cout << "testHero.getHealth(): " << testHero.getHealth() << endl;
	cout << "testHero.getLevel(): " << testHero.getLevel() << endl;

	cout << "Setting testHero's level to 3" << endl;
	testHero.setLevel(3);
	cout << "testHero.getHealth(): " << testHero.getHealth() << endl;
	cout << "testHero.getLevel(): " << testHero.getLevel() << endl;

	cout << "Setting testHero's health to 10" << endl;
	testHero.setHealth(10);
	cout << "testHero.getHealth(): " << testHero.getHealth() << endl;
	cout << "testHero.getLevel(): " << testHero.getLevel() << endl;

	cout << "Adding test1 to testHero's inventory" << endl;
	testHero.addToInventory(test1);

	cout << "Getting testHero's inventory" << endl;
	Item testInventory[30];
	int numItems = 0;
	testHero.getInventory(testInventory, numItems);
	cout << "There are " << numItems << " items in testHero's inventory" << endl;
	cout << "Adding sword to testHero's inventory" << endl;
	testHero.addToInventory(sword);

	cout << "Getting testHero's inventory" << endl;
	numItems = 0;
	testHero.getInventory(testInventory, numItems);
	cout << "There are " << numItems << " items in testHero's inventory" << endl;

	cout << endl;
	cout << "Making testHero2 with 5 health, max health of -3, level 10, and maxLevel of 1000" << endl;
	Hero testHero2(5.0,-3.0,10,1000);
	cout << "testHero2.getHealth(): " << testHero2.getHealth() << endl;
	cout << "testHero2.getLevel(): " << testHero2.getLevel() << endl;

	cout << "testHero2.getMaxHealth(): " << testHero2.getMaxHealth() << endl;
	cout << "testHero2.getMaxLevel(): " << testHero2.getMaxLevel() << endl;

	cout << "Setting testHero2's level to 40" << endl;
	testHero2.setLevel(40);
	cout << "testHero2.getHealth(): " << testHero2.getHealth() << endl;
	cout << "testHero2.getLevel(): " << testHero2.getLevel() << endl;

	cout << "Setting testHero2's level to -100" << endl;
	testHero2.setLevel(-100);
	cout << "testHero2.getHealth(): " << testHero2.getHealth() << endl;
	cout << "testHero2.getLevel(): " << testHero2.getLevel() << endl;

	cout << "Setting testHero2's health to 100" << endl;
	testHero2.setHealth(100);
	cout << "testHero2.getHealth(): " << testHero2.getHealth() << endl;
	cout << "testHero2.getLevel(): " << testHero2.getLevel() << endl;

	cout << "Setting testHero2's health to -140" << endl;
	testHero2.setLevel(-140);
	cout << "testHero2.getHealth(): " << testHero2.getHealth() << endl;
	cout << "testHero2.getLevel(): " << testHero2.getLevel() << endl;

	cout << "Setting testHero2's level to 3" << endl;
	testHero2.setLevel(3);
	cout << "testHero2.getHealth(): " << testHero2.getHealth() << endl;
	cout << "testHero2.getLevel(): " << testHero2.getLevel() << endl;

	cout << "Setting testHero2's health to 10" << endl;
	testHero2.setHealth(10);
	cout << "testHero2.getHealth(): " << testHero2.getHealth() << endl;
	cout << "testHero2.getLevel(): " << testHero2.getLevel() << endl;

	cout << "Adding test1 to testHero2's inventory" << endl;
	testHero2.addToInventory(test1);

	cout << "Getting testHero2's inventory" << endl;
	Item testInventory2[30];
	numItems = 0;
	testHero2.getInventory(testInventory2, numItems);
	cout << "There are " << numItems << " items in testHero2's inventory" << endl;
	cout << "Adding sword to testHero2's inventory" << endl;
	testHero2.addToInventory(sword);

	cout << "Getting testHero2's inventory" << endl;
	numItems = 0;
	testHero2.getInventory(testInventory2, numItems);
	cout << "There are " << numItems << " items in testHero2's inventory" << endl;
	system("pause");
	return 0;
}
