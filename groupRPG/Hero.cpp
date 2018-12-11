// Jericho Keyne
// Hero class for RPG project

#include "Hero.h"
#include "Item.h"
#include <algorithm>
#include <iostream>

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

void Hero::setCurrentWeapon(Weapon *newWeapon) {
	//if (find(inventory.begin(), inventory.end(), newWeapon) != inventory.end()) {
			currentWeapon = newWeapon;
			physicalDamage += newWeapon->getPhysicalDamage();
			magicDamage += newWeapon->getMagicDamage();
	//}
}

void Hero::setCurrentWeapon(int weaponNum) {
	int weapon = 0;
	for (auto it = inventory.begin(); it != inventory.end(); it++) {
		if (static_cast<Weapon *>(*it)) {
			weapon++;
		}
		if (weapon == weaponNum) {
			setCurrentWeapon(static_cast<Weapon *>(*it));
		}
	}
}

void Hero::addToInventory(Item &newItem) {
	inventory.push_back(&newItem);
	numItems++;
	//if (numItems + 1 < maxItems) {
	//	inventory[numItems] = &newItem;
	//	numItems++;
	//}
}

void Hero::removeFromInventory(Item &item) {
	//if (find(inventory.begin(), inventory.end(), item) != inventory.end()) {
		inventory.remove(&item);
		numItems--;
	//}
}

void Hero::printIventory() {
	cout << "Inventory: " << endl;
	for (auto it = inventory.begin(); it != inventory.end(); it++) {
		cout << (*it)->getName() << endl;
	}
}

int Hero::printWeapons() {
	cout << "Weapons: " << endl;
	int weapon = 1;
	for (auto it = inventory.begin(); it != inventory.end(); it++) {
		if (static_cast<Weapon *>(*it)) {
			cout << weapon++ << " " << (*it)->getName() << endl;
		}
	}
	return weapon;
}

/*
void Hero::getInventory(Item rtnInventory[], int &rtnNumItems) {
	rtnInventory = inventory;
	rtnNumItems = numItems;
}
*/

void Hero::attack(Enemy &enemy) {
	enemy.setHealth(enemy.getEnemyHealth() - physicalDamage - magicDamage);
}

Hero::Hero(string newName) {
	name = newName;
	setHealth(maxHealth);
	setLives(maxLives);
}

Hero::Hero(string newName, int health, int lives) { 
	name = newName;
	setHealth(health);
	setLives(lives);
	//inventory = new Item*[maxItems];
}

Hero::Hero(string newName, int health, int maxHealth, int lives, int maxLives) {
	name = newName;
	setMaxHealth(maxHealth);
	setMaxLives(maxLives);
	setHealth(health);
	setLives(lives);
	//inventory = new Item*[maxItems];
}

ostream &operator << (ostream &os, const Hero &hero) {
	string weapon = "";
	if (hero.currentWeapon == nullptr)
		weapon = "fist";
	else
		weapon = hero.currentWeapon->getName();
	os << hero.name << " has " << hero.health << "/" << hero.maxHealth << " HP, has " << hero.lives << " lives, is currently weilding a " << weapon << " with " << hero.physicalDamage << " physical damage and " << hero.magicDamage << " magic damage, and has " << hero.numItems << " item(s) in their inventory.";
	return os;
}
