#pragma once
#ifndef ITEM_H
#define ITEM_H
#include <string>
using namespace std;

class Item {
private:
	string name;
public:
	void setName(string name);
	string getName() { return name; }
	//virtual void use() = 0;
};
#endif