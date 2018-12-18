// Samuel Silverman
// Weapon class

#pragma once
#ifndef WEAPON_H
#define WEAPON_H
#include "Tool.h"
class Weapon : public Tool{
protected:
    int physicalDamage = 0; // Damage of a physical weapon
    int magicDamage = 0;    // Damage of a magic weapon
public:
	void setPhysicalDamage(int physicalDamage);
    int getPhysicalDamage() {return physicalDamage;}
    void setMagicDamage(int physicalDamage);
    int getMagicDamage() {return magicDamage;}

    Weapon(int physicalDamage, int magicDamage); // Constructors
    Weapon();
};
#endif