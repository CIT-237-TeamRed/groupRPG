// Jericho Keyne
// Tests the Hero class for the RPG project

#include <iostream>
#include "Hero/Mage/mage.h"
#include "Item/Tool/Weapon/Physical/Physical.h"

using namespace std;

int main() {
	Physical sword(Physical::Type::SWORD);	
	cout << "Making mage named \"Steve\" with 5 health, 5 lives, and 10 magic" << endl;
	Mage mage("Steve", 5, 5, 10);
	cout << mage << endl;

	cout << "mage.getMaxHealth() should be 20: " << mage.getMaxHealth() << endl;
	cout << "mage.getMaxLives() should be 10: " << mage.getMaxLives() << endl;

	cout << "Setting mage's lives to 40" << endl;
	mage.setLives(40);
	cout << mage << endl;

	cout << "Setting mage's lives to -100" << endl;
	mage.setLives(-100);
	cout << mage << endl;

	cout << "Setting mage's health to 100" << endl;
	mage.setHealth(100);
	cout << mage << endl;

	cout << "Setting mage's health to -140" << endl;
	mage.setHealth(-140);
	cout << mage << endl;

	cout << "Setting mage's lives to 3" << endl;
	mage.setLives(3);
	cout << mage << endl;

	cout << "Setting mage's health to 10" << endl;
	mage.setHealth(10);
	cout << mage << endl;

	cout << "Setting the sword to be the current weapon" << endl;
	mage.setCurrentWeapon(sword);
	cout << mage << endl;

	cout << "Adding sword to mage's inventory" << endl;
	mage.addToInventory(sword);
	cout << mage << endl;

	cout << "Setting the sword to be the current weapon" << endl;
	mage.setCurrentWeapon(sword);
	cout << mage << endl;

	cout << "mage.getPhysicalDamage(): " << mage.getPhysicalDamage() << endl;
	cout << "mage.getMagicDamage(): " << mage.getMagicDamage() << endl;

	return 0;
}
