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
		int maxHealth = 20;
		int lives;
		int maxLives = 10;
		Weapon* currentWeapon = nullptr;
		//Item **inventory = nullptr;
		//list<Item *> inventory;
		vector<Item *> inventory;
		int numItems = 0;
		int maxItems = 30;
		int energy;
		int physicalDamage = 1;
		int magicDamage = 1;
		virtual void abstract() = 0;
	public:
		void setHealth(int newHealth);
		void setMaxHealth(int newMaxHealth);
		void setLives(int newLives);
		void setMaxLives(int newMaxLives);
		void setCurrentWeapon(Weapon *newWeapon);
		void setCurrentWeapon(int weaponNum);

		void addToInventory(Item &newItem);
		void removeFromInventory(Item &item);

		int getHealth() { return health; };
		int getMaxHealth() { return maxHealth; };
		int getLives() { return lives; };
		int getMaxLives() { return maxLives; };
		void printIventory();
		int printWeapons();
		Weapon* getCurrentWeapon() { return currentWeapon; };
		int getSizeOfInventory() { return numItems; };
		int getMaxSizeOfInventory() { return maxItems; };
		int getPhysicalDamage() { return physicalDamage; };
		int getMagicDamage() { return magicDamage; };
		//void getInventory(Item rtnInventory[], int &rtnNumItems);
		void attack(Enemy &enemy);
		void save(ostream &output);
		void load(istream &input);

		Hero(string name);
		Hero(string name, int health, int lives);
		Hero(string name, int health, int maxHealth, int lives, int maxLives);
		friend ostream &operator << (ostream &os, const Hero &hero);
};
#endif
