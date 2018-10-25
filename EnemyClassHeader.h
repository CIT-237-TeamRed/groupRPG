#pragma once
#ifndef EnemyClassHeader_H
#define EnemyClassHeader_H
#include <iostream>


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


class Enemy
{
private:                             //Accessors
	int enemyType;       
	int health;
	int currentWeapon;               // Weapon.h will be included later and will really say Weapon currentWeapon

public:                              //Mutators
	void setWeapon(int);
	void setHealth(int);
	void setEnemyType(int);           // this will set the enemy being benign or viscous (not sure how to do that)
	int getEnemyType();   
	int getEnemyHealth();
	int getEnemyWeapon();
};
#endif
