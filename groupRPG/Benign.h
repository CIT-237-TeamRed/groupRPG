// Daniel Richardson
// Nov. 8

#pragma once
#ifndef BENIGN_H
#define BENIGN_H
#include <string>
#include "Enemy.h"


/*        Benign           *
****************************
*      bool hostile        *
****************************
*       Benign()           *
*   virtual void setEnemy  *
****************************/

class Benign : public Enemy
{

public:
	bool hostile = false;       //??? Should I make this private?  But Thief and Silverman need access to it.  That might mean I need to make it protected
	
	Benign();                 //??? Is this necessary;
	
	// Fall through to Thief.setEnemy() and Silverman.setEnemy()
	virtual void setEnemy() = 0;

};
#endif

// PREVIOUS CODE ATTEMPTS

//private:
	//string subEnemiesArray[] = { "Thief", "Silverman" };   // Need to make an array that holds objects
	//Enemy *arr[1] = { new Thief() };     // Going to try something with this later
	// bool hostile = false;             // Need to make it friend or protected.  Thief and Silverman need acces to this variable

//public:
//void setSubEnemy();

/*bool isHostile() {
		return hostile;
	};*/