// Daniel Richardson
// Nov. 8, 

#pragma once
#ifndef VICIOUS_H
#define VICIOUS_H
#include "Enemy.h"

/*        Vicious          *
****************************
*   string characteristic  *
****************************
*      bool hostile        *
****************************
*       Vicious()          *
*  virtual void setEnemy() *
*  virtual void print()    *
****************************/

class Vicious : public Enemy
{
private:
	string characteristic = "vicious";

protected:
	bool hostile = true;   // protected because Bigfoot and Banshee need access

public:
	Vicious();

	// Falling through to Banshee.setEnemy() and Bigfoot.setEnemy()
	virtual void setEnemy() = 0;
	virtual void print() = 0;

};
#endif
