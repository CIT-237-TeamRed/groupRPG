#include "Mage.h"

void Mage::abstract() {
	return;
}

Mage::Mage(string newName, int health, int lives): Hero(newName, health, lives) {
	//name = newName;
	//setHealth(health);
	//setLevel(level);
	//setMagic(magic);
}

Mage::Mage(string newName): Hero(newName) {

}
