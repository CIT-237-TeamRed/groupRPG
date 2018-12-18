// Samuel Silverman
// Magic Weapon class

#pragma once
#ifndef MAGIC_H
#define MAGIC_H
#include "Weapon.h"

class Magic : public Weapon{
public:
    enum Type {DIRT, FIRE, ELECTRICITY, WATER}; // Types of magic weapons
private:
    Type type;
    virtual void abstract() { return; }         // To make abstract
public:
    void setType(Type type);
    Type getType() {return type;}
    Magic(Type type);
};

#endif