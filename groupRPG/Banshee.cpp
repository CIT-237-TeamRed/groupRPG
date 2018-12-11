// Daniel Richardson
// Nov. 8

/*      Banshee            *
****************************
*   -int weaponDamage      *
****************************
*   +void setEnemy()       *
****************************/

#include "Banshee.h"
#include <iostream>
#include <string>

void Banshee::setEnemy()
{
	int useElement;

	setEnemyType("Banshee");
	setHealth(13);
	setHostile(hostile);
	string weaponArray[] = { "choke", "scream", "turn you to stone" };
	int damageArray[] = { 4, 6, 8 };

	useElement = randomize(0, 100);

	if (useElement % 2 == 0)
	{
		setWeapon(weaponArray[0]);
		setWeaponDamage(damageArray[0]);
	}
	else
		(primeFunction(useElement)) ? setWeapon(weaponArray[2]), setWeaponDamage(damageArray[2]) : setWeapon(weaponArray[1]), setWeaponDamage(damageArray[1]);

}

Banshee::Banshee(): Vicious() {
	setEnemy();
	setName("Banshee");
}
