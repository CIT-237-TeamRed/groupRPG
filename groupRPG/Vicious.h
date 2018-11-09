// Daniel Richardson
// Nov. 8, 

#pragma once
#ifndef VICIOUS_H
#define VICIOUS_H
#include "Enemy.h"

/*        Vicious          *
****************************
*      bool hostile        *
****************************
*       Vicious)           *
*   virtual void setEnemy  *
****************************/

class Vicious : public Enemy
{
public:
	Vicious();             // may not be necessary
	bool hostile = true;   // ??? Maybe put in private and make protected

	virtual void setEnemy() = 0;
};
#endif