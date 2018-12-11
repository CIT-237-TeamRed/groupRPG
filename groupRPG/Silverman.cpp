// Daniel Richardson
// Nov. 8

/*      Silverman          *
****************************
*   -int weaponDamage      *
***************************
*   +void setEnemy()       *
***************************/

#include "Silverman.h"
#include <string>
#include <iostream>

using namespace std;

void Silverman::setEnemy()
{
	int useElement;

	setEnemyType("Silverman");
	setHealth(7);
	setHostile(hostile);
	string weaponArray[] = { "punch", "kick", "round house to the face" };
	int damageArray[] = { 2, 3, 4 };

	useElement = randomize(0, 100);

	if (useElement % 2 == 0)
	{
		setWeapon(weaponArray[0]);
		setWeaponDamage(damageArray[0]);
	}
	else
		(primeFunction(useElement)) ? setWeapon(weaponArray[2]), setWeaponDamage(damageArray[2]) : setWeapon(weaponArray[1]), setWeaponDamage(damageArray[1]);

}

Silverman::Silverman() : Benign() {
	setEnemy();
	setName("Silverman");
}

// PREVIOUS
/*Silverman::Silverman()
{
	int useElement;

	setHealth(7);
	unsigned seed = time(0);

	srand(seed);
	string weaponArray[] = { "punch", "kick", "round house kick" };
	int damageArray[] = { 2, 3, 4 };

	useElement = randomize(0, 100);

	if (useElement % 2 == 0)
	{
		setWeapon(weaponArray[0]);
		setWeaponDamage(damageArray[0]);
	}
	else
		(primeFunction(useElement)) ? setWeapon(weaponArray[2]), setWeaponDamage(damageArray[2]) : setWeapon(weaponArray[1]), setWeaponDamage(damageArray[1]);

}*/
