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
#include <ctime>

using namespace std;

void Silverman::setEnemy()
{
	int useElement;

	setEnemyType("Silverman");
	setHealth(7);
	setHostile(hostile);
	unsigned seed = time(0);

	srand(seed);
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