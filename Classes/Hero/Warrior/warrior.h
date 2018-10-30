// Jericho Keyne
// Hero class for RPG project

#pragma once
#ifndef WARRIOR_H
#define WARRIOR_H
#include "Hero/hero.h"
class Warrior : public Hero {
	private:
		double maxHealth = 30;
	public:
		Warrior(string name, double health, int level);
};
#endif
