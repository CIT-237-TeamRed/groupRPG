// Jericho Keyne
// Hero class for RPG project

#include "hero.h"
#include "item.h" // This is a temp class that doesn't do anything right now

void Hero::setHealth(double newHealth) {
	if (newHealth > 0 && newHealth <= getMaxHealth()) {
		health = newHealth;
	} else {
		health = -1;
	}
}

void Hero::setMaxHealth(double newMaxHealth) {
	if (newMaxHealth > 0) {
		maxHealth = newMaxHealth;
	} else {
		maxHealth = -1;
	}
}

void Hero::setLevel(double newLevel) { 
	if (newLevel > 0 && newLevel <= getMaxLevel()) {
		level = newLevel;
	} else {
		level = -1;
	}
}

void Hero::setMaxLevel(double newMaxLevel) { 
	if (newMaxLevel > 0) {
		maxLevel = newMaxLevel;
	} else {
		maxLevel = -1;
	}
}
void Hero::setCurrentWeapon(Weapon newWeapon) {
	for (int i = 0; i < numItems; i++) {
		if (inventory[i] == newWeapon)
			currentWeapon = newWeapon;
	}
}

void Hero::addToInventory(Item newItem) {
	if (numItems + 1 < maxItems) {
		inventory[numItems] = newItem;
		numItems++;
	}
}

void Hero::removeFromInventory(Item item) {
	// Not yet implemented
}

void Hero::getInventory(Item rtnInventory[], int &rtnNumItems) {
	rtnInventory = inventory;
	rtnNumItems = numItems;
}


Hero::Hero(double health, int level) { 
	setHealth(health);
	setLevel(level);
	inventory = new Item[maxItems];
}

Hero::Hero(double health, double maxHealth, int level, int maxLevel) {
	setMaxHealth(maxHealth);
	setMaxLevel(maxLevel);
	setHealth(health);
	setLevel(level);
	inventory = new Item[maxItems];
}
