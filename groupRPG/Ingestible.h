#pragma once
#ifndef INGESTIBLE_H
#define INGESTIBLE_H
#include "Item.h"

class Ingestible : public Item{
private:
    int quantity;
public:
    void setQuantity(int quantity);
	int getQuantity() { return quantity; }
    void use();
    Ingestible();
};

#endif
