#pragma once
#ifndef MAGIC_H
#define MAGIC_H
#include "Item/Tool/Weapon/Weapon.h"

class Magic : public Weapon{
public:
    enum Type {DIRT, FIRE, ELECTRICITY, WATER};
private:
    Type type;
public:
    void setType(Type type);
    Type getType() {return type;}
    void use();
    Magic(Type type);
};
#endif