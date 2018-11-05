#pragma once
#ifndef WEAPON_H
#define WEAPON_H
#include "Tool.h"
class Weapon : public Tool{
protected:
    int physicalDamage = 0;
    int magicDamage = 0;
public:
    //Physical::Type::STICK
    //void setType(Type type);
    //Type getType() {return type;}
	void setPhysicalDamage(int physicalDamage);
    int getPhysicalDamage() {return physicalDamage;}
    void setMagicDamage(int physicalDamage);
    int getMagicDamage() {return magicDamage;}
    //virtual void use() = 0;

    Weapon(int physicalDamage, int magicDamage);
    Weapon();
};
#endif