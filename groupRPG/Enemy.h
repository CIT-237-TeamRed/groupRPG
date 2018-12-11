// Daniel Richardson
// Nov 8, 2018

#pragma once
#ifndef ENEMY_H
#define ENEMY_H
#include <iostream>
using namespace std;


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
 ***********************************/


class Enemy
{
	//Accessors
private:                             
	string enemyType;
	int health;                           // Might need to set to virtual
	int weaponDamage;
	string name = "Enemy";

	string currentWeapon;

	bool hostile;

	//Mutators
public:                              
	void setWeapon(string);
	void setHealth(int);
	void setEnemyType(string);           // this will set the enemy being benign or viscous (not sure how to do that)
	void setWeaponDamage(int);
	void setHostile(bool);

	void setName(string newName);
	string getName() { return name; }
	
	Enemy();
	string getEnemyType();
	int getEnemyHealth();
	string getEnemyWeapon();
	int getWeaponDamage();
	bool isHostile();

	virtual void setEnemy() = 0;            // Abstract method that will be used in the main to set all the statuses for the enemy

	int randomize(int, int);                 // To randomize which weapons will be used. Even # is one weapon, Odd # is another weapon, Prime # is another weapon
	bool primeFunction(int);                 // To determine if the random number is a prime

};
#endif
