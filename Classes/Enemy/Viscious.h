#pragma once
#ifndef VISCIOUS_H
#define VISCIOUS_H
#include <string>
#include "EnemyClassHeader.h"

/*        Benign           *
****************************
*  string subEnemiesArray  *
****************************
*   void setSubEnemy       *
****************************/

class Viscious : Enemy
{
private:
	string subEnemiesArray[] = { "Banshee", "Bigfoot" };   // Need to make an array that holds objects

public:
	void setSubEnemy();
};
#endif