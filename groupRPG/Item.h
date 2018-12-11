#pragma once
#ifndef ITEM_H
#define ITEM_H
#include <string>
using namespace std;

class Item {
protected:
	string name = "Item";
public:
	void setName(string name);
	string getName() { return name; }
	//bool operator== (Item right);
	bool operator== (Item* right);
	//virtual void use() = 0;
};
#endif
