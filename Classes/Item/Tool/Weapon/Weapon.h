#pragma once
#ifndef WEAPON_H
#define WEAPON_H
#include "Item/Tool/Tool.h"
class Weapon : public Tool{
public:
    enum Type {STICK, SWORD};
protected:
    int physicalDamage;
    int magicDamage;
    Type type;
public:
    //Physical::Type::STICK
    void setType(Type type);
    Type getType() {return type;}
	void setPhysicalDamage(int physicalDamage);
    int getPhysicalDamage() {return physicalDamage;}
    void setMagicDamage(int physicalDamage);
    int getMagicDamage() {return magicDamage;}
    virtual void use();
};
#endif