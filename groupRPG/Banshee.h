// Daniel Richardson
// Nov. 8

/*      Banshee            *
****************************
*   -int useWeapon         *
*   -string BANSHEE_NAME   *
*   -int BANSHEE_HEALTH    *
*   -string WEAPON1        *
*   -string WEAPON2        *
*   -string WEAPON3        *
*   -int WEAPON1_DAMAGE    *
*   -int WEAPON2_DAMAGE    *
*   -int WEAPON3_DAMAGE    *
*   -string weaponArray[]  *
*   -int damageArray[]     *
****************************
*   + Banshee()            *
*   +void setEnemy()       *
*   +void print()          *
****************************/

#pragma once
#ifndef BANSHEE_H
#define BANSHEE_H
#include<string>
#include "Vicious.h"

class Banshee : public Vicious
{
private:

	int useWeapon;   // variable to hold random number

	const string BANSHEE_NAME = "Banshee";
	const int BANSHEE_HEALTH = 100;

	const string WEAPON1 = "a throat choke";
	const string WEAPON2 = "an ear piercing scream";
	const string WEAPON3 = "turning you into stone";

	const int WEAPON1_DAMAGE = 4;
	const int WEAPON2_DAMAGE = 6;
	const int WEAPON3_DAMAGE = 8;
	
	// Arrays to hold the weapon names and damage
	string weaponArray[3];
	int damageArray[3];

public:
	Banshee();
	void setEnemy();
	void print();
};
#endif
