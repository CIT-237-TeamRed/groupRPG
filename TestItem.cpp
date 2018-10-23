#include <iostream>
#include "Item.h" // Including the Item header file to access the class
using namespace std;

void printItem(Item);

int main() {
	Item item; // Declaring a class of type Item
	item.setItemName("Red Balloon"); // Editing class variable via setter
	item.setItemQuantity(99);
	printItem(item);

	cout << "----------------------\n";

	Item item2;
	item2.setItemName("Bottle");
	item2.setItemQuantity(1);
	printItem(item2);

	system("pause");
	return 0;
}

void printItem(Item item) {
	cout << "Item name: " << item.getItemName() << endl; // and using getter to print the item name and quantity
	cout << "Quantity: " << item.getItemQuantity() << endl;
	cout << "You have " << item.getItemQuantity() << " " << item.getItemName() << (item.getItemQuantity() > 1 ? "s" : "") << ".\n";
}