#pragma once
#ifndef INGESTIBLE_H
#define INGESTIBLE_H
#include "Item.h"
#include "Hero.h"

class Ingestible : public Item {
public:
    enum Type {HEALTH, DAMAGE}; // Types of Ingestibles. 
                                // HEALTH heals player. 
                                // DAMAGE increases player strength.
private:
    virtual void abstract() { return; }
    Type type;                  // Enum type
    int quantity;
public:
    void setPhysicalDamage(int newDamage);
    void setMagicDamage(int newDamage);
    void setQuantity(int quantity);
    int getQuantity() { return quantity; }
    void use(Hero *hero);
    Ingestible(Type newType);   // Constructor
};
#endif
