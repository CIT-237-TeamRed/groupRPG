#include "Mage.h"

void Mage::abstract() {
	return;
}

Mage::Mage(string newName): Hero(newName, 20, 1, 3) {
}
