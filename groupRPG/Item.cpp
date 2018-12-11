#include "Item.h"

void Item::setName(string name) {
	this->name = name;
}

//bool Item::operator== (Item right) {
//	if (this->name == right.getName())
//		return true;
//	return false;
//}

bool Item::operator== (Item* right) {
	if (this->name == right->getName())
		return true;
	return false;
}
