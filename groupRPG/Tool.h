// Samuel Silverman
// Tool class

#pragma once
#ifndef TOOL_H
#define TOOL_H
#include "Item.h"
class Tool : public Item{
protected:
    virtual void abstract() { return; } // To make abstract
public:
	Tool(); // Constructor
};
#endif
