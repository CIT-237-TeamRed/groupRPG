#pragma once
#ifndef ITEM_H
#define ITEM_H
#include <string>
using namespace std;

class Item {
private:
	// Declaring private variables that items will use
	string itemName;
	int itemQuantity;
public:
	// Setters and Getters to edit and return private variables
	// Definitions are written in the implementation file (item.cpp)
	void setItemName(string name);
	string getItemName() { return itemName; } // Simple definitions can be written within the class
	void setItemQuantity(int quantity);
	int getItemQuantity() { return itemQuantity; }
};
#endif