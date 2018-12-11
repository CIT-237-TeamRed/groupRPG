// Daniel Richardson
// Nov. 8

/*      Bigfoot            *
****************************
*   -int weaponDamage      *
****************************
*   +void setEnemy()       *
****************************/

#include "Bigfoot.h"
#include <ctime>

void Bigfoot::setEnemy()
{

	int useElement;
	setEnemyType("Bigfoot");
	setHealth(13);
	setHostile(hostile);
	string weaponArray[] = { "fist smash", "foot stomp", "bite" };
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

Bigfoot::Bigfoot(): Vicious() {
	setEnemy();
	setName("Bigfoot");
}
