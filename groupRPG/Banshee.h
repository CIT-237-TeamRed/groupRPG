// Daniel Richardson
// Nov. 8

/*      Banshee            *
****************************
*   -int weaponDamage      *
****************************
*   +void setEnemy()       *
****************************/

#pragma once
#ifndef BANSHEE_H
#define BANSHEE_H
#include<string>
#include "Vicious.h"

class Banshee : public Vicious
{
private:
	int weaponDamage;

public:
	void setEnemy();
	Banshee();
};
#endif
