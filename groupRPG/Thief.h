#pragma once
#ifndef Thief_H
#define Thief_H
#include <string>
#include "Benign.h"

/*      Thief              *
****************************
*   -int useWeapon         *
*   -string THIEF_NAME     *
*   -int THIEF_HEALTH      *
*   -string WEAPON1        *
*   -string WEAPON2        *
*   -string WEAPON3        *
*   -int WEAPON1_DAMAGE    *
*   -int WEAPON2_DAMAGE    *
*   -int WEAPON3_DAMAGE    *
*   -string weaponArray[]  *
*   -int damageArray[]     *
****************************
*   + Thief()              *
*   +void setEnemy()       *
*   +void print()          *
****************************/

class Thief : public Benign

{
	// Accessors
private:
	int useWeapon; // to hold random number

	const string THIEF_NAME = "Thief";
	const int THIEF_HEALTH = 7;

	const string WEAPON1 = "a smack";
	const string WEAPON2 = "a stick";
	const string WEAPON3 = "an eyepoke";

	const int WEAPON1_DAMAGE = 2;
	const int WEAPON2_DAMAGE = 3;
	const int WEAPON3_DAMAGE = 4;

	// Array to hold the weapon names and damage
	string weaponArray[3];
	int damageArray[3];

	// Mutators
public:
	Thief();
	void setEnemy();
	void print();
};
#endif