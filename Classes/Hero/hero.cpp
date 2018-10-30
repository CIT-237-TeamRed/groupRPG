// Jericho Keyne
// Hero class for RPG project

#include "hero.h"
#include "Item/Item.h"

void Hero::setHealth(int newHealth) {
	if (newHealth > 0 && newHealth <= getMaxHealth()) {
		health = newHealth;
	} else {
		health = -1;
	}
}

void Hero::setMaxHealth(int newMaxHealth) {
	if (newMaxHealth > 0) {
		maxHealth = newMaxHealth;
	} else {
		maxHealth = -1;
	}
}

void Hero::setLives(int newLives) { 
	if (newLives > 0 && newLives <= getMaxLives()) {
		lives = newLives;
	} else {
		lives = -1;
	}
}

void Hero::setMaxLives(int newMaxLives) { 
	if (newMaxLives > 0) {
		maxLives = newMaxLives;
	} else {
		maxLives = -1;
	}
}

void Hero::setCurrentWeapon(Weapon &newWeapon) {
	for (int i = 0; i < numItems; i++) {
		//if (inventory[i] == newWeapon)
			currentWeapon = &newWeapon;
			physicalDamage += newWeapon.getPhysicalDamage();
			magicDamage += newWeapon.getMagicDamage();
	}
}


void Hero::addToInventory(Item &newItem) {
	if (numItems + 1 < maxItems) {
		inventory[numItems] = &newItem;
		numItems++;
	}
}

void Hero::removeFromInventory(Item &item) {
	// Not yet implemented
}
/*
void Hero::getInventory(Item rtnInventory[], int &rtnNumItems) {
	rtnInventory = inventory;
	rtnNumItems = numItems;
}
*/

Hero::Hero(string newName, double health, int lives) { 
	name = newName;
	setHealth(health);
	setLives(lives);
	inventory = new Item*[maxItems];
}

Hero::Hero(string newName, double health, double maxHealth, int lives, int maxLives) {
	name = newName;
	setMaxHealth(maxHealth);
	setMaxLives(maxLives);
	setHealth(health);
	setLives(lives);
	inventory = new Item*[maxItems];
}

ostream &operator << (ostream &os, const Hero &hero) {
	string weapon = "";
	if (hero.currentWeapon == nullptr)
		weapon = "fist";
	else
		weapon = hero.currentWeapon->getName();
	os << hero.name << " has " << hero.health << "/" << hero.maxHealth << " HP, has " << hero.lives << " lives, is currently weilding a " << weapon << ", and has " << hero.numItems << " item(s) in their inventory.";
	return os;
}
