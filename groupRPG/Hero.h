// Jericho Keyne
// Hero class for RPG project

#pragma once
#ifndef HERO_H
#define HERO_H
#include "Item.h"
#include "Weapon.h"
#include "Enemy.h"
#include <iostream>
#include <list>
#include <vector>
class Item;
class Weapon;
class Hero {
	protected:
		string name;
		int health;
		int maxHealth;
		int lives;
		Weapon* currentWeapon = nullptr;
		vector<Item *> inventory;
		int numItems = 0;
		int maxLives = 3;
		int physicalDamage;
		int magicDamage;
		virtual void abstract() = 0;
	public:
		class INVALID_HEALTH {}; //gets thrown in setHealth when 
		void setHealth(int newHealth);
		void setLives(int newLives);
		void setCurrentWeapon(Weapon *newWeapon);
		void setCurrentWeapon(int weaponNum); //set current weapon 
		void use(int ingestibleNum); //use an ingestible
		void setPhysicalDamage(int newDamage);
		void setMagicDamage(int newDamage);

		void addToInventory(Item &newItem);
		void removeFromInventory(Item &item);

		int getHealth() { return health; };
		int getMaxHealth() { return maxHealth; };
		int getLives() { return lives; };
		int getMaxLives() { return maxLives; };
		void printIventory();
		int printWeapons(); //return number of weapons
		int printIngestibles(); //return number and names of ingestibles
		Weapon* getCurrentWeapon() { return currentWeapon; };
		int getSizeOfInventory() { return numItems; };
		int getPhysicalDamage() { return physicalDamage; };
		int getMagicDamage() { return magicDamage; };
		//void getInventory(Item rtnInventory[], int &rtnNumItems)
		void save(ostream &output);
		void load(istream &input);

		// Hero(string name);
		// Hero(string name, int health, int lives);
		Hero(string name, int maxHealth, int physicalDamage, int magicDamage);
		friend ostream &operator << (ostream &os, const Hero &hero);
};
#endif
