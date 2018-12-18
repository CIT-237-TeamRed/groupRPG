// Jericho Keyne
// Hero class for RPG project

#include "Hero.h"
#include "Item.h"
#include "Physical.h"
#include "Magic.h"
#include "Ingestible.h"
#include <algorithm>
#include <iostream>

void Hero::setPhysicalDamage(int newDamage) {
	physicalDamage+=newDamage;	
}

void Hero::setMagicDamage(int newDamage) {
	magicDamage+=newDamage;	
}

void Hero::setHealth(int newHealth) {
	if (newHealth > 0) {
		health = newHealth;
	} else {
		throw INVALID_HEALTH(); //throws INVALID_HEALTH when health is <= 0
	}
}

void Hero::setLives(int newLives) { //set number of lives
	if (newLives > 0) { //if you are setting the number of lives to be greater than zero
		lives = newLives; //set number of lives to be newLives
	} else {
		lives = -1; //if you are setting < 1 then it makes number of lives -1
	}
}

void Hero::setCurrentWeapon(Weapon *newWeapon) { //set current weapon, and modify physical and magic damage accordingly
	//remove the damage from the weapon you have equipped at the moment
	if (currentWeapon != nullptr) {
		physicalDamage -= currentWeapon->getPhysicalDamage();
		magicDamage -= currentWeapon->getMagicDamage();
	}

	currentWeapon = newWeapon;
	physicalDamage += newWeapon->getPhysicalDamage();
	magicDamage += newWeapon->getMagicDamage();
}

void Hero::setCurrentWeapon(int weaponNum) { //takes in number, finds that weapon in inventory, calls (overloaded) setCurrentWeapon to set that weapon 
	int weapon = 0; //used to find weapon in 
	for (auto it = inventory.begin(); it != inventory.end(); it++) { //iterate through inventory, which is a vector
		if (dynamic_cast<Weapon *>(*it)) { //check if iterator is pointing to a weapon
			weapon++; //increment weapon
		}
		if (weapon == weaponNum) { //when you are at the correct item in inventory
			setCurrentWeapon(dynamic_cast<Weapon *>(*it)); //set current weapon using overloaded setCurrentWeapon function
		}
	}
}

void Hero::use(int ingestibleNum) { //ingest an ingestible
	int ingestible = 0; //used to find ingestible in 
	for (auto it = inventory.begin(); it != inventory.end(); it++) { //iterate through inventory
		if (static_cast<Ingestible *>(*it)) { //check if iterator is pointing to ingestible
			ingestible++;
		}
		if (ingestible == ingestibleNum) { //set the ingestible when you are at the correct place
			static_cast<Ingestible *>(inventory.at(ingestible-1))->use(this); //use the ingestible, either altering health or damage
			removeFromInventory(*(inventory.at(ingestible-1))); //delete the ingestible from inventory when you use it
		}
	}
}

void Hero::addToInventory(Item &newItem) { //add item to Inventory
	inventory.push_back(&newItem); //add item to vector
	numItems++;
}

void Hero::removeFromInventory(Item &item) {
	//if (find(inventory.begin(), inventory.end(), item) != inventory.end()) {
		//inventory.remove(&item);
		for (auto it = inventory.begin(); it != inventory.end(); it++) { //iterate through inventory
			//when on the item, erase it from the vector
			if (*it == &item)
				inventory.erase(it-1);
		}
		numItems--; //reduct number of items by one
	//}
}

void Hero::printIventory() { //print out the names of all items
	cout << "Inventory: " << endl;
	for (auto it = inventory.begin(); it != inventory.end(); it++) { //iterate through inventory 
		cout << (*it)->getName() << endl; //cout the item name
	}
}

int Hero::printWeapons() { //return number of weapons and cout the weapon names
	cout << "Weapons: " << endl;
	int weapon = 1;
	for (auto it = inventory.begin(); it != inventory.end(); it++) { //iterate through inventory
		if (dynamic_cast<Weapon *>(*it)) { //check if item is weapon
			cout << weapon++ << " " << (*it)->getName() << endl; //cout the number and name of that weapon
		}
	}
	return weapon; //return number of weapons
}

int Hero::printIngestibles() {//return number of ingestibles and cout their names
	cout << "Ingestibles: " << endl;
	int ingestible = 1;
	for (auto it = inventory.begin(); it != inventory.end(); it++) { //iterate through inventory
		if (dynamic_cast<Ingestible *>(*it)) { //check if item is Ingestible
			cout << ingestible++ << " " << (*it)->getName() << endl; //cout name of item
		}
	}
	return ingestible; //return number of ingestibles
}
void Hero::save(ostream &output) { //save the hero's variables'
	output << health << endl;
	output << lives << endl;
	output << name << endl;

	string weaponName;
	//save "fist" as the weapon if there is no weapon, otherwise save the weapon name
	if (currentWeapon == nullptr) {
		weaponName = "fist";
	} else {
		weaponName = (*currentWeapon).getName();
	}
	output << weaponName << endl;

	output << inventory.size() << endl;
	//save inventory as just the names
	for (unsigned long i = 0; i < inventory.size(); i++) {
		output << inventory[i]->getName() << endl;
	}
}

Item* findItem(string name) { //return item object using the name of the item
	if (name == "Stick")
		return new Physical(Physical::STICK);
	else if (name == "Sword")
		return new Physical(Physical::SWORD);
	else if (name == "Brass knuckles")
		return new Physical(Physical::KNUCKLES);
	else if (name == "Gun")
		return new Physical(Physical::GUN);
	else if (name == "Dirt")
		return new Magic(Magic::DIRT);
	else if (name == "Fire")
		return new Magic(Magic::FIRE);
	else if (name == "Electricity")
		return new Magic(Magic::ELECTRICITY);
	else if (name == "Water")
		return new Magic(Magic::WATER);
	else if (name == "Health Potion")
		return new Ingestible(Ingestible::HEALTH);
	else if (name == "Weapon Potion")
		return new Ingestible(Ingestible::DAMAGE);
	else if (name == "Tool")
		return new Tool;
	else
		return nullptr;
}
void Hero::load(istream &input) { //load hero's variables
	input >> health;
	input >> lives;
	input >> name;

	string weaponName;
	input.ignore(1, '\n');
	// input >> weaponName;
	getline(input, weaponName);
	setCurrentWeapon(dynamic_cast<Weapon *>(findItem(weaponName)));

	int size;
	input >> size;
	input.ignore(1, '\n');
	//save inventory as just the names
	for (unsigned long i = 0; i < size; i++) {
		string itemName;
		getline(input, itemName);
		// input >> itemName;
		Item *temp = findItem(itemName);
		inventory.push_back(temp);
		numItems++;
	}
}

// Hero::Hero(string newName) { //constructor that sets name of hero custom
// 	name = newName;
// 	setHealth(10);
// 	setLives(maxLives);
// }

// Hero::Hero(string newName, int health, int lives) { //constructor that sets hero of newName, health, and lives
// 	name = newName;
// 	setHealth(health);
// 	setLives(lives);
// }

Hero::Hero(string newName, int maxHealth, int physicalDamage, int magicDamage) { //constructor that sets the hero name, health, physical damage, and magic damage
	name = newName;
	setHealth(maxHealth);
	setLives(maxLives);
	this->maxHealth = maxHealth;
	this->physicalDamage = physicalDamage;
	this->magicDamage = magicDamage;
}

ostream &operator << (ostream &os, const Hero &hero) { //<< overload to basically be a toString for a hero object
	string weapon = "";
	if (hero.currentWeapon == nullptr) //default weapon is fist if there is nothing else equipped
		weapon = "fist";
	else
		weapon = hero.currentWeapon->getName();
	os << hero.name << " has " << hero.health << " HP, has " << hero.lives << " lives, is currently weilding a " 
		<< weapon << " with " << hero.physicalDamage << " physical damage and " << hero.magicDamage << " magic damage, and has " << hero.numItems << " item(s) in their inventory.";
	return os;
}
