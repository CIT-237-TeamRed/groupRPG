// Samuel Silverman
// Physical Weapon class

#pragma once
#ifndef PHYSICAL_H
#define PHYSICAL_H
#include "Weapon.h"

class Physical : public Weapon{
public:
    enum Type { STICK, SWORD, KNUCKLES, GUN };  // Types of physical weapons
private:
    Type type;
    virtual void abstract() { return; }         // To make abstract
public:
    void setType(Type type);
    Type getType() {return type;}
    Physical(Type type);                        // Constructor
};
#endif