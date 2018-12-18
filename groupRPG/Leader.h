// Jericho Keyne
// Hero class for RPG project

#pragma once
#ifndef LEADER_H
#define LEADER_H
#include "Enemy.h"
#include "Hero.h"
class Leader: public Hero {
	private:
		int maxHealth;
		int physicalDamage;
		int magicDamage;
		virtual void abstract();
	public:
		Leader(string name);
};
#endif
