// Jericho Keyne
// Hero class for RPG project

#pragma once
#ifndef WARRIOR_H
#define WARRIOR_H
#include "Hero.h"
class Warrior : public Hero {
	private:
		int maxHealth;
		int physicalDamage;
		int magicDamage;
		virtual void abstract();
	public:
		Warrior(string name);
};
#endif
