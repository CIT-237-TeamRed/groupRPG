// Jericho Keyne
// Hero class for RPG project

#pragma once
#ifndef HERO_H
#define HERO_H
#include "Item/Item.h"
#include "Item/Tool/Weapon/Weapon.h"
#include "Enemy/EnemyClassHeader.h"
#include <iostream>
class Item;
class Weapon;
class Hero {
	private:
		string name;
		int health;
		int maxHealth = 20;
		int lives;
		int maxLives = 10;
		//Weapon currentWeapon;
		Item **inventory;
		int numItems = 0;
		int maxItems = 30;
		int energy;
		int physicalDamage = 1;
		int magicDamage = 1;
	public:
		void setHealth(int newHealth);
		void setMaxHealth(int newMaxHealth);
		void setLives(int newLives);
		void setMaxLives(int newMaxLives);
		//void setCurrentWeapon(Weapon newWeapon);

		void addToInventory(Item &newItem);
		void removeFromInventory(Item &item);

		double getHealth() { return health; };
		double getMaxHealth() { return maxHealth; };
		int getLives() { return lives; };
		int getMaxLives() { return maxLives; };
		//Weapon getCurrentWeapon() { return currentWeapon; };
		int getSizeOfInventory() { return numItems; };
		int getMaxSizeOfInventory() { return maxItems; };
		//void getInventory(Item rtnInventory[], int &rtnNumItems);
		void attack(Enemy enemy);

		Hero(string name, double health, int lives);
		Hero(string name, double health, double maxHealth, int lives, int maxLives);
		friend ostream &operator << (ostream &os, const Hero &hero);
};
#endif
