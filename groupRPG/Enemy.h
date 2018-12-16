// Daniel Richardson
// Nov 8, 2018

#pragma once
#ifndef ENEMY_H
#define ENEMY_H
#include <iostream>
using namespace std;


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


class Enemy
{
	//Accessors
private:                             
	string enemyType;
	string characteristic;
	string currentWeapon;

	int health;                           
	int weaponDamage;

	bool hostile;

	//Mutators
public:   
	Enemy();

	void setWeapon(string);
	void setHealth(int);
	void setEnemyType(string);           // this will set the enemy to Thief, Silverman, Bigfoot, Banshee
	void setWeaponDamage(int);
	void setHostile(bool);
	void setCharacteristic(string);     // this will set the enemy to benign or vicious
	
	string getEnemyType();
	int getEnemyHealth();
	string getEnemyWeapon();
	int getWeaponDamage();
	string getCharacteristic();
	bool isHostile();
	string toString();

	virtual void setEnemy() = 0;            // Abstract method that will be used in the main to set all the statuses for the enemy
	virtual void print() = 0;                // cout getEnemyType

	int randomize(int, int);                 // To randomize which weapons will be used. Based on the number being even, odd, or prime will select type of weapon from an array
	bool primeFunction(int);                 // To determine if the random number is a prime

};
#endif