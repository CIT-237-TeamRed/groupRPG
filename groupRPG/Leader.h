// Jericho Keyne
// Hero class for RPG project

#pragma once
#ifndef LEADER_H
#define LEADER_H
#include "Enemy.h"
#include "Hero.h"
class Leader: public Hero {
	private:
		int maxHealth = 10;
	public:
		//friend void stealWeapon(Enemy enemy);
		Leader(string name, int health, int lives);
};
#endif
