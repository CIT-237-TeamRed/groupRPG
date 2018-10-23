// Including the header file in the implementation file
#include "Item.h"
// Defining functions that are called in the header file (Item.h) are written here
void Item::setItemName(string name) {
	itemName = name;
}
void Item::setItemQuantity(int quantity) {
	if (quantity <= 0)quantity = 0;
	itemQuantity = quantity;
}