// Daniel Richardson
// Nov. 8 - Dec. 15

/*      Silverman          *
****************************
*   -int useWeapon         *
*   -string SILVERMAN_NAME *
*   -int SILVERMAN_HEALTH  *
*   -string WEAPON1        *
*   -string WEAPON2        *
*   -string WEAPON3        *
*   -int WEAPON1_DAMAGE    *
*   -int WEAPON2_DAMAGE    *
*   -int WEAPON3_DAMAGE    *
*   -string weaponArray[]  *
*   -int damageArray[]     *
****************************
*   + Silverman()          *
*   +void setEnemy()       *
*   +void print()          *
****************************/

#pragma once
#ifndef Silverman_H
#define Silverman_H
#include <string>
#include "Benign.h"

class Silverman : public Benign
{
private:
	int useWeapon; // to hold random number

	const string SILVERMAN_NAME = "Silverman";
	const int SILVERMAN_HEALTH = 75;

	const string WEAPON1 = "a punch";
	const string WEAPON2 = "a kick";
	const string WEAPON3 = "a round house to the face";

	const int WEAPON1_DAMAGE = 2;
	const int WEAPON2_DAMAGE = 5;
	const int WEAPON3_DAMAGE = 15;

	// Arrays to hold the weapon names and damage
	string weaponArray[3];
	int damageArray[3];
public:
	Silverman();
	void setEnemy();
	void print();
};
#endif