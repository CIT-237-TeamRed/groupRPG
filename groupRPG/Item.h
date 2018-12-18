// Samuel Silverman
// Item class

#pragma once
#ifndef ITEM_H
#define ITEM_H
#include <string>
using namespace std;

class Item {
protected:
	virtual void abstract() = 0;
	string name = "Item";
public:
	void setName(string name);
	string getName() { return name; }
	bool operator== (Item* right); // Overloaded comparison operator
};
#endif
