#pragma once
#ifndef Thief_H
#define Thief_H
#include <string>
#include "Enemy.h"
#include "Benign.h"

/*       Theif             *
 ***************************
 *   int health            *
 *   string weapon         *
 *   int weaponDamage            *
 ***************************
 *  void setHealth         *
 *  void setWeapon         *
 *  void setWeaponDamage   *
 *  int getHealth          *
 *  string getWeapon       *
 *  int getWeaponDamage    *
 **************************/

class Thief : Enemy

{
	// Accessors
private:
	int weaponDamage;

public:
	Thief();
};
#endif