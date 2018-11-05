#pragma once
#ifndef BENIGN_H
#define BENIGN_H
#include <string>
#include "Enemy.h"

/*        Benign           *
****************************
*  string subEnemiesArray  *
****************************
*   void setSubEnemy       *
****************************/

class Benign : Enemy
{
private:
	string subEnemiesArray[] = { "Thief", "Silverman" };   // Need to make an array that holds objects

public:
	void setSubEnemy();
};
#endif