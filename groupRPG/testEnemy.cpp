// Daniel Richardson
// CIT237-01
// Enemy class test

#include <iostream>
#include "EnemyClassHeader.h"
#include <string>
#include <ctime>

using namespace std;

int randomizeEnemy(int, int );

int main() 
{
	unsigned seed = time(0);

	srand(seed);

	string enemyArray[] = { "Banshee", "Bigfoot"};              // Hardcoding the enemy names until subclass
	string enemyWeapon[] = { "Scream", "Kick" };                  // Hardcoding enemy weapons until items class is included
	
	Enemy test;                                                // Making an Enemy object

	
	randomizeEnemy(0, 100) % 2 == 0 ? test.setEnemyType(0) : test.setEnemyType(1); // Randomizing which enemy will show up
	
	cout << "The enemy is a " << enemyArray[test.getEnemyType()] << endl << endl;

	test.setHealth(100);                   // setting the enemy's health to 100
	cout << "The enemies health is " << test.getEnemyHealth() << endl << endl;  

	randomizeEnemy(0, 100) % 2 == 0 ? test.setWeapon(0) : test.setWeapon(1);        // Randomizing which weapon the enemy will use

	cout << "The enemy is going to use its " << enemyWeapon[test.getEnemyWeapon()] << " weapon." << endl << endl;

	system("pause");
	return 0;
}

int randomizeEnemy(int firstNum, int secondNum)
{
	return ((rand() % (firstNum - secondNum + 1)) + secondNum);
}