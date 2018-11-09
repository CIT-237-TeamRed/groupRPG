// Daniel Richardson
// Oct. 22, 2018/ Nov. 8, 2018
// CIT237-01

/*              Enemy              *
 ***********************************
 *     -int enemyType              *
 *     -int health                 *
 *     -int weaponDamage           *
 *     -string currentWeapon       *
 *     -bool hostile               *
 ***********************************
 *     +void setWeapon(s)            *
 *     +void setHealth(i)            *
 *     +void setEnemyType(s)         *
 *     +void setWeaponDamage(i)      *
 *     +Enemy()                      *
 *     +string getEnemyType()        *
 *     +int getEnemyHealth()         *
 *     +string getEnemyWeapon()      *
 *     +int getWeaponDamage()        *
 *     +bool isHostile()             *
 *     +virtual void setEnemy()      *
 *     +int randomize(i, i)          *
 *     +bool primeFunction(i)        *
 *************************************/

#include "Enemy.h"
#include <iostream>
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
		if (testForPrime % count == 0)
			return false;
	}
	return true;
}