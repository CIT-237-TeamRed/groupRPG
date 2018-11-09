// Daniel Richardson
// Nov. 8

/*      Bigfoot            *
****************************
*   -int weaponDamage      *
****************************
*   +void setEnemy()       *
****************************/

#pragma once
#ifndef BIGFOOT_H
#define BIGFOOT_H
#include <string>
#include "Vicious.h"

class Bigfoot : public Vicious
{
private:
	int weaponDamage;

public:
	void setEnemy();
};
#endif
