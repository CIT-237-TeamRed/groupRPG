// Daniel Richardson
// Nov. 8, 2018
// CIT 237-01

#include <iostream>
#include "Enemy.h"
#include "Thief.h"
#include "Benign.h"
#include <string>
#include <ctime>
#include"Banshee.h"
#include"Bigfoot.h"
#include"Silverman.h"

using namespace std;

void enemyAppears(Enemy *e);
bool primeFunction(int);
Enemy *generateEnemy();
int randBetween(int, int);

int main()
{
	int c = 0;
	Enemy *thief = new Thief();
	Enemy *silverman = new Silverman();
	Enemy *bigFoot = new Bigfoot();
	Enemy *banshee = new Banshee();

	string say = thief->toString();
	cout << say << endl;
	say = silverman->toString();
	cout << say << endl;
	say = bigFoot->toString();
	cout << say << endl;
	say = banshee->toString();
	cout << say << endl;

	//int test = randBetween(0, 99);

	//cout << test << endl;

	/*Enemy *enemy = nullptr;

	enemy = generateEnemy();

	enemyAppears(enemy);

	enemy = generateEnemy();

	enemyAppears(enemy);

	enemy = generateEnemy();

	enemyAppears(enemy);

	enemy = generateEnemy();

	enemyAppears(enemy);*/

	//Testing prime function and # of primes between 0 and 100
	for (int i = 0; i <= 100; i++)
	{
		cout << i << " is " << primeFunction(i) << endl;
		if (primeFunction(i))
			c++;
	}
	cout << c << endl << endl;

	system("pause");
	return 0;

}

Enemy *generateEnemy()
{
	Enemy *enemy = nullptr;

	int pickEnemy = randBetween(0, 99);

	if (pickEnemy < 30)
		(pickEnemy % 2 == 0) ? enemy = new Bigfoot() : enemy = new Banshee();
	else
		(pickEnemy % 2 == 0) ? enemy = new Thief() : enemy = new Silverman();

	return enemy;
}
void enemyAppears(Enemy *enemy)
{
	//enemy->setEnemy();
	cout << "You have run into a " << ((enemy->isHostile()) ? "vicious " : "benign ") << enemy->getEnemyType() << " who will damage you with a" << enemy->getEnemyWeapon() << "\n";
	cout << "which will cause " << enemy->getWeaponDamage() << " points of damage!";
	cout << endl << endl;
}



bool primeFunction(int testForPrime)
{
	for (int count = 2; count < testForPrime; count++)
	{
		if (testForPrime % count == 0)
			return false;
	}
	return true;
}

int randBetween(int lowNum, int highNum)
{
	return ((rand() % (highNum - lowNum + 1)) + lowNum);
}