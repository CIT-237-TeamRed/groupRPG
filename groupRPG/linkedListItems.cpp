#include <iostream>
#include <forward_list>
#include "Item.h"
#include "Magic.h"
#include "Physical.h"

using namespace std;

int main() {
	Physical sword(Physical::SWORD);
	Physical knuckles(Physical::KNUCKLES);
	Physical sword2(Physical::SWORD);
	Magic electricity(Magic::ELECTRICITY);
	forward_list<Item*> itemList;

	// Setting names
	sword.setName("Elvis the greatsword");
	knuckles.setName("Brass Knuckles");
	sword2.setName("Tim the zweihander");
	electricity.setName("Electric attack");

	// Adding items to the list
	itemList.push_front(&sword);
	cout << "Adding sword\n";
	itemList.push_front(&knuckles);
	cout << "Adding knuckles\n";
	itemList.push_front(&sword2);
	cout << "Adding sword2\n";
	itemList.push_front(&electricity);	
	cout << "Adding electricity\n";

	// Find the index of knuckles
	cout << "Searching for knuckles\n";
	int index = 0;
	for (auto it = itemList.begin(); it != itemList.end(); ++it) {
		if (*it == &knuckles) {
			break;
		}
		next(it);
		index++;
	}
	{
		cout << "knuckles is index " << index << endl;
		auto it = itemList.begin();
		advance(it, index);
		cout << "knuckles' name is " << (*it)->getName() << endl;
	}

	// Remove knuckles
	{
		cout << "Removing knuckles" << endl;
		auto it = itemList.begin();
		advance(it, index-1);
		itemList.erase_after(it);
	}

	// Display the list
	for (auto it = itemList.begin(); it != itemList.end(); ++it) {
		cout << (*it)->getName() << " " << static_cast<Weapon *>(*it)->getPhysicalDamage() << endl;
	}
}
