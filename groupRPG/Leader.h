// Jericho Keyne
// Hero class for RPG project

#pragma once
#ifndef LEADER_H
#define LEADER_H
#include "Enemy.h"
#include "Hero.h"
class Leader: public Hero {
	private:
		int maxHealth = 20;
		int physicalDamage = 2;
		int magicDamage = 2;
		int energy = 50;
		virtual void abstract();
	public:
		Leader(string name, int health, int lives);
		Leader(string name);
};
#endif
