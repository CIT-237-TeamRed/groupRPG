#pragma once
#ifndef ENEMY_H
#define ENEMY_H
#include <iostream>
using namespace std;


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
	string enemyType;       
    int health ;                           // Might need to set to virtual
	string currentWeapon;               // Weapon.h will be included later and will really say Weapon currentWeapon
	int weaponDamage;

public:                              //Mutators
	void setWeapon(string);
	void setHealth(int);
	void setEnemyType(string);           // this will set the enemy being benign or viscous (not sure how to do that)
	void setWeaponDamage(int);
	
	string getEnemyType();   
	int getEnemyHealth();
	string getEnemyWeapon();
	int getWeaponDamage();
	
	int randomize(int, int);
	bool primeFunction(int);
	
};
#endif


