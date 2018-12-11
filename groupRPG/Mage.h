// Jericho Keyne
// Hero class for RPG project

#pragma once
#ifndef MAGE_H
#define MAGE_H
#include "Hero.h"
class Mage : public Hero {
	private:
		int maxHealth = 20;
		int magicDamage = 3;
		int physicalDamage = 1;
		int energy = 100;
		virtual void abstract();
	public:
		Mage(string name, int health, int lives)/*: Hero(string name, double health, int level)*/;
		Mage(string name);
};
#endif
