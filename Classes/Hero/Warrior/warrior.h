// Jericho Keyne
// Hero class for RPG project

#pragma once
#ifndef WARRIOR_H
#define WARRIOR_H
#include "Hero/hero.h"
class Warrior : public Hero {
	private:
		int maxHealth = 30;
	public:
		Warrior(string name, int health, int lives);
};
#endif
