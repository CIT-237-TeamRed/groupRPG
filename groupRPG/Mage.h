// Jericho Keyne
// Hero class for RPG project

#pragma once
#ifndef MAGE_H
#define MAGE_H
#include "Hero.h"
class Mage : public Hero {
	private:
		int maxHealth;
		int magicDamage;
		int physicalDamage;
		virtual void abstract();
	public:
		Mage(string name);
};
#endif
