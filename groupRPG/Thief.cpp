// Daniel Richardson
// Oct. 29, 2018/ Nov.8
// CIT237-01

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

#include "Thief.h"
#include <iostream>
#include <ctime>

using namespace std;

Thief::Thief() : Benign()
{
	setEnemy();
}

void Thief::setEnemy()
{
	setEnemyType(THIEF_NAME);
	setHealth(THIEF_HEALTH);
	setHostile(hostile);     // hostile taken from benign class

	unsigned seed = time(0);
	srand(seed);

	// Put the weapon names in the weapon array.  Would not allowed to be done in thief.h
	weaponArray[0] = WEAPON1;
	weaponArray[1] = WEAPON2;
	weaponArray[2] = WEAPON3;

	damageArray[0] = WEAPON1_DAMAGE;
	damageArray[1] = WEAPON2_DAMAGE;
	damageArray[2] = WEAPON3_DAMAGE;

	// Randomly decide what weapon the theif will be using
	useWeapon = randomize(0, 100);

	// Use modulus operator to pick which element in the weapon array to use
	if (useWeapon % 2 == 0)
	{
		setWeapon(weaponArray[0]);         //SetWeapon
		setWeaponDamage(damageArray[0]);   // set the damage to the weapon in the corrosponding element;
	}
	else
		(primeFunction(useWeapon)) ? setWeapon(weaponArray[2]), setWeaponDamage(damageArray[2]) : setWeapon(weaponArray[1]), setWeaponDamage(damageArray[1]);

}

void Thief::print()
{
	cout << getEnemyType();
}
