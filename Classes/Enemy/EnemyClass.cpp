// Daniel Richardson
// Oct. 22, 2018
// CIT237-01

/*              Enemy              *
 ***********************************
 *      int enemyType              *
 *      int health                 *
 *      Weapon currentWeapon       *
 ***********************************
 *     void setWeapon()            *
 *     void setHealth()            *
 *     void setEnemy()             *
 *     int getEnemyWeapon()        *
 *     int getEnemyHealth()        *
 *     int getEnemyType()          *
 ***********************************/

#include "EnemyClassHeader.h"
#include <iostream>
using namespace std;

void Enemy::setWeapon(int randoWeapon)  //set which weapon the enemy will be using
{
	currentWeapon = randoWeapon;
}

void Enemy::setHealth(int newHealth)       // set the health of the enemy
{
	health = newHealth;
}

void Enemy::setEnemyType(int randoEnemy)     // Randomize which enemy will be used
{
	enemyType = randoEnemy;
}

int Enemy::getEnemyType()
{
	return enemyType;
}

int Enemy::getEnemyHealth()
{
	return health;
}

int Enemy::getEnemyWeapon()
{
	return currentWeapon;
}


