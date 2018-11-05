// Daniel Richardson
// Oct. 22, 2018
// CIT237-01

/*              Enemy              *
 ***********************************
 *      string enemyType           *
 *      int health                 *
 *      string currentWeapon       *
 *      int weaponDamage           *
 ***********************************
 *     void setWeapon()            *
 *     void setHealth()            *
 *     void setEnemy()             *
 *     void setWeaponDamage        *
 *     string getEnemyWeapon()     *
 *     int getEnemyHealth()        *
 *     string getEnemyType()       *
 *     int getWeaponDamage         *
 ***********************************/

#include "EnemyClassHeader.h"
#include <iostream>
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