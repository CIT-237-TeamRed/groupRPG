// Jericho Keyne
// Hero class for RPG project

#pragma once
#ifndef THEIF_H
#define THEIF_H
#include "Enemy/EnemyClassHeader.h"
#include "Hero/hero.h"
class Theif: public Hero {
	private:
		double maxHealth = 10;
	public:
		friend void stealWeapon(Enemy enemy);
		Theif(string name, double health, int level);
};
#endif
