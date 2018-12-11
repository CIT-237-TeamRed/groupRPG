// Jericho Keyne
// Hero class for RPG project

#pragma once
#ifndef WARRIOR_H
#define WARRIOR_H
#include "Hero.h"
class Warrior : public Hero {
	private:
		int maxHealth = 30;
		int physicalDamage = 3;
		int magicDamage = 1;
		int energy = 30;
		virtual void abstract();
	public:
		Warrior(string name, int health, int lives);
		Warrior(string name);
};
#endif
