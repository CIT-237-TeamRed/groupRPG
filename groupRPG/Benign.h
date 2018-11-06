#pragma once
#ifndef BENIGN_H
#define BENIGN_H
#include <string>
#include "Enemy.h"
#include "Thief.h"
#include "Silverman.h"

/*        Benign           *
****************************
*  string subEnemiesArray  *
****************************
*   void setSubEnemy       *
****************************/

class Benign : public Enemy
{
private:
	//string subEnemiesArray[] = { "Thief", "Silverman" };   // Need to make an array that holds objects
	// Enemy *arr[2] = { Thief.setEnemy, Silverman.setEnemy };
	bool hostile = false;
public:
	void setSubEnemy();
	void setHostile(bool);
	bool getHostile() {
		return hostile;
	};
	
};
#endif