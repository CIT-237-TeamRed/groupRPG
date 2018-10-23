// Jericho Keyne
// Hero class for RPG project

#pragma once
#ifndef HERO_H
#define HERO_H
#include "item.h" // This is a temp class that doesn't do anything right now
class Hero {
	private:
		double health;
		double maxHealth = 20;
		int level;
		int maxLevel = 10;
		Weapon currentWeapon;
		Item *inventory;
		int numItems;
		int maxItems = 30;
	public:
		void setHealth(double newHealth);
		void setMaxHealth(double newMaxHealth);
		void setLevel(double newLevel);
		void setMaxLevel(double newMaxLevel);
		void setCurrentWeapon(Weapon newWeapon);

		void addToInventory(Item newItem);
		void removeFromInventory(Item item);

		double getHealth() { return health; };
		double getMaxHealth() { return maxHealth; };
		int getLevel() { return level; };
		int getMaxLevel() { return maxLevel; };
		Weapon getCurrentWeapon() { return currentWeapon; };
		int getSizeOfInventory() { return numItems; };
		int getMaxSizeOfInventory() { return maxItems; };
		void getInventory(Item rtnInventory[], int &rtnNumItems);

		Hero(double health, int level);
		Hero(double health, double maxHealth, int level, int maxLevel);
};
#endif
