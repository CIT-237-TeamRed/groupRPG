// Daniel Richardson
// Oct. 22, 2018/ Nov. 8, 2018 - Dec. 15, 2018
// CIT237-01

/*              Enemy              *
 ***********************************
 *     -string enemyType           *
 *    -string currentWeapon        *
 *    -string characteristic       *
 *     -int health                 *
 *     -int weaponDamage           *
 *     -bool hostile               *
 ***********************************
 *     +Enemy()                    *
 *     +void setWeapon(str)        *
 *     +void setHealth(int)        *
 *     +void setEnemyType(str)     *
 *     +void setWeaponDamage(int)  *
 *     +void setHostile(bool)      *
 *     +void setCharacteristic(str)*
 *     +string getEnemyType()      *
 *     +int getEnemyHealth()       *
 *     +string getEnemyWeapon()    *
 *     +int getWeaponDamage()      *
 *     +bool isHostile()           *
 *     +string toString()          *
 *     +virtual void setEnemy()    *
 *     +virtual void print()       *
 *     +int randomize(i, i)        *
 *     +bool primeFunction(i)      *
 ***********************************/

#include "Enemy.h"
#include <iostream>
#include <sstream>
//#include "Benign.h"
using namespace std;

void Enemy::setWeapon(string randoWeapon)  //set which weapon the enemy will be using
{
	currentWeapon = randoWeapon;
}

void Enemy::setHealth(int newHealth)       // set the health of the enemy
{
	health = newHealth;
}

void Enemy::setEnemyType(string randoEnemy)     // Randomize which enemy will be used
{
	enemyType = randoEnemy;
}

void Enemy::setWeaponDamage(int newDamage)
{
	weaponDamage = newDamage;
}

void Enemy::setHostile(bool hostileIs)
{
	hostile = hostileIs;
}

void Enemy::setCharacteristic(string characteristicIs)
{
	characteristic = characteristicIs;
}

string Enemy::getEnemyType()
{
	return enemyType;
}

int Enemy::getEnemyHealth()
{
	return health;
}

string Enemy::getEnemyWeapon()
{
	return currentWeapon;
}

int Enemy::getWeaponDamage()
{
	return weaponDamage;
}

bool Enemy::isHostile()
{
	return hostile;
}

string Enemy::getCharacteristic()
{
	return characteristic;
}

string Enemy::toString()
{
	ostringstream os;
	os << "You have run into a " << getCharacteristic() <<" " << getEnemyType() << " who will damage you with " << getEnemyWeapon() << "!";
	return os.str();
}

Enemy::Enemy()
{
}

int Enemy::randomize(int firstNum, int secondNum)
{
	return ((rand() % (firstNum - secondNum + 1)) + secondNum);
}

bool Enemy::primeFunction(int testForPrime)
{
	for (int count = 2; count < testForPrime; count++)
	{
		if (testForPrime % count == 0 && testForPrime < 50)
			return false;
	}
	return true;
}
