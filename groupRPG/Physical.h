#pragma once
#ifndef PHYSICAL_H
#define PHYSICAL_H
#include "Weapon.h"
class Physical : public Weapon{
public:
    enum Type { STICK, SWORD, KNUCKLES, GUN };
private:
    Type type;
public:
    void setType(Type type);
    Type getType() {return type;}
    //void use();

	Physical(Type type);
};
#endif