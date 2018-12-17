// Daniel Richardson
// Nov. 8 - Dec 15

#pragma once
#ifndef BENIGN_H
#define BENIGN_H
#include <string>
#include "Enemy.h"


/*        Benign           *
****************************
*   string characteristic  *
****************************
*      bool hostile        *
****************************
*       Benign()           *
*   virtual void setEnemy()*
*   virtual void print()   *
****************************/

class Benign : public Enemy
{
private:
	string characteristic = "benign";

protected:
	bool hostile = false;  // Protected because Thief and Silverman need access

public:
	Benign();

	// Fall through to Thief.setEnemy() and Silverman.setEnemy()
	virtual void setEnemy() = 0;
	virtual void print() = 0;

};
#endif
