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

int main()
{
	int c = 0;
	Enemy *A = new Thief();
	Enemy *B = new Banshee();
	Enemy *C = new Bigfoot();
	Enemy *D = new Silverman();

	enemyAppears(A);
	enemyAppears(B);
	enemyAppears(C);
	enemyAppears(D);

	/* Testing prime function and # of primes between 0 and 100
	for (int i = 0; i <= 100; i++)
	{
		cout << i << " is " << primeFunction(i) << endl;
		if (primeFunction(i))
			c++;
	}
	cout  << c << endl << endl;*/

	system("pause");
	return 0;

}

void enemyAppears(Enemy *enemy)
{
	enemy->setEnemy();
	cout << "You have run into a " << ((enemy->isHostile()) ? "vicious " : "benign ") << enemy->getEnemyType() << " who will damage you with a " << enemy->getEnemyWeapon() << "\n";
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