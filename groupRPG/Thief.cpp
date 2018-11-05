// Daniel Richardson
// Oct. 29, 2018
// CIT237-01

/*       Theif             *
 ***************************
 *   int health            *
 *   string weapon         *
 *   int weapon            *
 ***************************
 *  void setHealth         *
 *  void setWeapon         *
 *  void setWeaponDamage   *
 *  int getHealth          *
 *  string getWeapon       *
 *  int getWeaponDamage    *
 **************************/

#include <string>
#include "Thief.h"
#include <iostream>
#include <ctime>

using namespace std;

Thief::Thief()
{
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

}

/*if (primeFunction(useElement))
{
	setWeapon(weaponArray[2]);
	setWeaponDamage(damageArray[2]);
}
else
{
	(useElement % 2 == 0) ? setWeapon(weaponArray[0]), setWeaponDamage(damageArray[0]) : setWeapon(weaponArray[1]), setWeaponDamage(damageArray[1]);
}*/