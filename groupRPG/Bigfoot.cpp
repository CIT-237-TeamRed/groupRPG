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

#include "Bigfoot.h"
#include <ctime>

Bigfoot::Bigfoot()
{
	setEnemy();
}

void Bigfoot::setEnemy()
{
	setEnemyType("Bigfoot");
	setHealth(13);
	setHostile(hostile);

	unsigned seed = time(0);

	srand(seed);

	// setting weapon names in the array
	weaponArray[0] = WEAPON1;
	weaponArray[1] = WEAPON2;
	weaponArray[2] = WEAPON3;

	// setting weapon damage in the array which corresponds with the weaponArray
	damageArray[0] = WEAPON1_DAMAGE;
	damageArray[1] = WEAPON2_DAMAGE;
	damageArray[2] = WEAPON3_DAMAGE;

	useWeapon = randomize(0, 100);

	if (useWeapon % 2 == 0)
	{
		setWeapon(weaponArray[0]);
		setWeaponDamage(damageArray[0]);
	}
	else
		(primeFunction(useWeapon)) ? setWeapon(weaponArray[2]), setWeaponDamage(damageArray[2]) : setWeapon(weaponArray[1]), setWeaponDamage(damageArray[1]);

}

void Bigfoot::print()
{
	cout << getEnemyType();
}