#include "mage.h"
#include <string>

void Mage::setMagic(double newMagic) {
	if (newMagic <= 0 || newMagic > maxMagic)
		newMagic = -1;
	magic = newMagic;
}

Mage::Mage(string newName, double health, int lives, double magic): Hero(newName, health, lives) {
	//name = newName;
	//setHealth(health);
	//setLevel(level);
	//setMagic(magic);
}
