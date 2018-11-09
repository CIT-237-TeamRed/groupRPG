// Daniel Richardson
// Nov. 8, 2018

/*       Silverman          *
 ****************************
 *   -int weaponDamage      *
 ****************************
 *   +void setEnemy()       *
 ****************************/

#pragma once
#ifndef Silverman_H
#define Silverman_H
#include <string>
#include "Benign.h"

class Silverman : public Benign
{
private:
	int weaponDamage;
public:
	void setEnemy();
};
#endif