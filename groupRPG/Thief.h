#pragma once
#ifndef Thief_H
#define Thief_H
#include <string>
#include "Benign.h"

/*       Theif              *
 ****************************
 *   -int weaponDamage      *
 ***************************
 *   +void setEnemy()       *
 ***************************/

class Thief : public Benign

{
	// Accessors
private:
	int weaponDamage;            //??? Maybe just hard code the WeaponDamage but if want to change stats would be easier to have private variables

	// Mutators
public:
	void setEnemy();
	Thief();
};
#endif
