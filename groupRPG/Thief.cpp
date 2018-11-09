// Daniel Richardson
// Oct. 29, 2018/ Nov.8
// CIT237-01

/*       Theif              *
 ****************************
 *   -int weaponDamage      *
 ****************************
 *   +void setEnemy()       *
 ****************************/

#include "Thief.h"
#include <iostream>
#include <ctime>

using namespace std;


void Thief::setEnemy()
{
	int useElement;

	setEnemyType("Thief");
	setHealth(7);
	setHostile(hostile);
	unsigned seed = time(0);

	srand(seed);
	string weaponArray[] = { "smack", "stick", "eyepoke" };   // Maybe set as private variables
	int damageArray[] = { 2, 3, 4 };                          // Maybe set as private variables

	useElement = randomize(0, 100);

	if (useElement % 2 == 0)
	{
		setWeapon(weaponArray[0]);
		setWeaponDamage(damageArray[0]);
	}
	else
		(primeFunction(useElement)) ? setWeapon(weaponArray[2]), setWeaponDamage(damageArray[2]) : setWeapon(weaponArray[1]), setWeaponDamage(damageArray[1]);

}

// PREVIOUS CODING ATTEMPTS

//Thief::Thief()
/*{
	int useElement;
	setHealth(7);
	unsigned seed = time(0);
	srand(seed);
	string weaponArray[] = { "smack", "stick", "eyepoke" };
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
/*if (primeFunction(useElement))
{
	setWeapon(weaponArray[2]);
	setWeaponDamage(damageArray[2]);
}
else
{
	(useElement % 2 == 0) ? setWeapon(weaponArray[0]), setWeaponDamage(damageArray[0]) : setWeapon(weaponArray[1]), setWeaponDamage(damageArray[1]);
}*/