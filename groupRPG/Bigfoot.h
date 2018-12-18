// Daniel Richardson
// Nov. 8 - Dec. 15

/*      Bigfoot            *
****************************
*   -int useWeapon         *
*   -string BIGFOOT_NAME   *
*   -int BIGFOOT_HEALTH    *
*   -string WEAPON1        *
*   -string WEAPON2        *
*   -string WEAPON3        *
*   -int WEAPON1_DAMAGE    *
*   -int WEAPON2_DAMAGE    *
*   -int WEAPON3_DAMAGE    *
*   -string weaponArray[]  *
*   -int damageArray[]     *
****************************
*   + Bigfoot()            *
*   +void setEnemy()       *
*   +void print()          *
****************************/

#pragma once
#ifndef BIGFOOT_H
#define BIGFOOT_H
#include <string>
#include "Vicious.h"

class Bigfoot : public Vicious
{
private:

	int useWeapon;   // variable to hold a random number

	const string BIGFOOT_NAME = "Bigfoot";
	const int BIGFOOT_HEALTH = 130;

	const string WEAPON1 = "a fist smash";
	const string WEAPON2 = "a big foot stomp";
	const string WEAPON3 = "a skull crushing bite";

	const int WEAPON1_DAMAGE = 4;
	const int WEAPON2_DAMAGE = 6;
	const int WEAPON3_DAMAGE = 8;

	// Arrays to hold weapon names and correspond with the damage
	string weaponArray[3];
	int damageArray[3];

public:
	Bigfoot();
	void setEnemy();
	void print();
};
#endif
