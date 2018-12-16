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

#include "Banshee.h"
#include <iostream>
#include <ctime>
#include <string>

Banshee::Banshee()
{
	setEnemy();
}
void Banshee::setEnemy()
{
	// Put the weapon names in the weapon array.  Would not allowed to be done in thief.h
	weaponArray[0] = WEAPON1;
	weaponArray[1] = WEAPON2;
	weaponArray[2] = WEAPON3;

	damageArray[0] = WEAPON1_DAMAGE;
	damageArray[1] = WEAPON2_DAMAGE;
	damageArray[2] = WEAPON3_DAMAGE;

	// set the name, health, and that Banshee is vicious
	setEnemyType(BANSHEE_NAME);
	setHealth(BANSHEE_HEALTH);
	setHostile(hostile);

	unsigned seed = time(0);

	srand(seed);

	useWeapon = randomize(0, 100);

	if (useWeapon % 2 == 0)
	{
		setWeapon(weaponArray[0]);
		setWeaponDamage(damageArray[0]);
	}
	else
		(primeFunction(useWeapon)) ? setWeapon(weaponArray[2]), setWeaponDamage(damageArray[2]) : setWeapon(weaponArray[1]), setWeaponDamage(damageArray[1]);
}

void Banshee::print()
{
	cout << getEnemyType();
}
