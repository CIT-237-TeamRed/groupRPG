// Jericho Keyne
// Hero class for RPG project

#pragma once
#ifndef MAGE_H
#define MAGE_H
#include "Hero/hero.h"
class Mage : public Hero {
	private:
		double maxHealth = 20;
		double magic;
		double maxMagic = 10;
	public:
		double getMagic() { return magic; };
		double getMaxMagic() { return maxMagic; };

		void setMagic(double newMagic);

		Mage(string name, double health, int lives, double magic)/*: Hero(string name, double health, int level)*/;
};
#endif
