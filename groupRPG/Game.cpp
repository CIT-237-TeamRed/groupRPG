// Game.cpp
// This is where all the game logic is stored
//
// Jericho Keyne
// Daniel Richardson

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <algorithm>
#include <stdlib.h>
#include <ctime>

// Include all of the class files
#include "Banshee.h"
#include "Benign.h"
#include "Bigfoot.h"
#include "Enemy.h"
#include "Hero.h"
#include "Ingestible.h"
#include "Item.h"
#include "Leader.h"
#include "Mage.h"
#include "Magic.h"
#include "Map.h"
#include "Physical.h"
#include "Silverman.h"
#include "Thief.h"
#include "Tool.h"
#include "Vicious.h"
#include "Warrior.h"
#include "Weapon.h"

using namespace std;

Item* generateItem();
Enemy* generateEnemy();
string getCommand();
bool getYN(string prompt);

int main() {
	Map board(10,10);
	Hero* hero = nullptr;

	const string MAP_SAVE_NAME = "map.dat";
	const string HERO_SAVE_NAME = "hero.dat";
	ifstream mapSave(MAP_SAVE_NAME, ios::binary);
	ifstream heroSave(HERO_SAVE_NAME, ios::binary);
	bool startNewGame = false;
	if (mapSave.good() && heroSave.good()) {
		if (getYN("Do you want to load " + MAP_SAVE_NAME + " and " + HERO_SAVE_NAME + "? ")) {
			startNewGame = false;
			cout << "Loading save file...\n";
			board.load(mapSave);
			try {
			hero->load(heroSave);
			} catch (const std::exception &e) {
				cout << "Loading failed" << endl;
				std::cerr << e.what();
			}
					
		} else {
			if (!getYN("Do you want to start a new game? "))
				return 0;
			startNewGame = true;
		}
	} else {
		startNewGame = true;
	}
	ofstream mapSaveOut(MAP_SAVE_NAME, ios::binary);
	ofstream heroSaveOut(HERO_SAVE_NAME, ios::binary);

	if (startNewGame) {
		// TODO: see below
		// Check for a save file
		// If there is one ask to load it
		// Else start a new game
		//
		// loop until the player quits
		cout << "1. Leader\n";
		cout << "2. Warrior\n";
		cout << "3. Mage\n";
		cout << "Select your hero: ";
		string input;
		getline(cin, input);
		while (input != "1" && input != "2" && input != "3") {
			cout << "Please enter a valid selection: ";
			getline(cin, input);
		}
		string name;
		cout << "Enter your name: ";
		getline(cin, name);
		if (input == "1")
			hero = new Leader(name);
		else if (input == "2")
			hero = new Warrior(name);
		else if (input == "3")
			hero = new Mage(name);
		board.generateMap();
	}
	bool runGame = true;
	while (runGame) {
		//	if there is an enemy
		if (board.getEnemyState(board.getHeroX(), board.getHeroY())) {
		//		generate enemy
			Enemy* enemy = generateEnemy();
		//		if enemy is viscious then start fight
		//		if enemy is begnin then ask if the player wants to fight
		//		TODO: make a fighting system
			if (enemy->isHostile()) {
				cout << "Starting fight\n";
			} else {
				cout << "Wanna fight?\n";
			}
		}
		// 	if there is an item 
		if (board.getItemState(board.getHeroX(), board.getHeroY())) {
		// 		generate item
			Item* item = generateItem();
		// 		ask the user if they want to pick it up
			if (getYN("Pickup " + item->getName() + "? ")) {
				hero->addToInventory(*item);
				board.setItem(board.getHeroX(), board.getHeroY(), false);	
			}
		}
		
		//	output what is nearby the hero
		if (board.isEnemyNearby(board.getHeroX(), board.getHeroY())) {
			cout << "There is an enemy nearby.\n";
		}
		if (board.isItemNearby(board.getHeroX(), board.getHeroY())) {
			cout << "There is an item nearby.\n";
		}

		//   output the player's position
		cout << "You are at (" << board.getHeroX() << ", " << board.getHeroY() << ")\n";
		cout << *hero << endl;

		// 	prompt them for a command
		string command = getCommand();
		// 	run the appropriate function
		if (command == "EXIT" || command == "QUIT")
			runGame = false;
		else if (command == "SAVE") {
			cout << "Saving...\n";
			board.save(mapSaveOut);	
			hero->save(heroSaveOut);
			cout << "Game saved\n";
		} else if (command.substr(0, 2) == "GO") {
			// TODO: Game currently crashes if the player moves too far to the right
			command.erase(0, 3);
			if (command == "UP" || command == "NORTH")
				board.setHeroCoords(board.getHeroX(), board.getHeroY()+1);
			else if (command == "DOWN" || command == "SOUTH")
				board.setHeroCoords(board.getHeroX(), board.getHeroY()-1);
			else if (command == "LEFT" || command == "WEST")
				board.setHeroCoords(board.getHeroX()-1, board.getHeroY());
			else if (command == "RIGHT" || command == "EAST")
				board.setHeroCoords(board.getHeroX()+1, board.getHeroY());
			else {
				cout << command << " is an invalid direction\n";
				cout << "Valid directions:\n";
				cout << setw(7) << left << "UP" << "NORTH\n";
				cout << setw(7) << left << "RIGHT" << "EAST\n";
				cout << setw(7) << left << "DOWN" << "SOUTH\n";
				cout << setw(7) << left << "LEFT" << "WEST\n";
			}
		} else if (command == "INVENTORY") {
			hero->printIventory();
		} else if (command == "EQUIP") {
			int numWeapons = hero->printWeapons();
			cout << "Enter your selection: ";
			int weaponChoice;
			cin >> weaponChoice;
			while (weaponChoice < 1 || weaponChoice > numWeapons || cin.fail()) {
				if (cin.fail()) {
					cin.ignore(1000, '\n');
					cin.clear();
				}
				cout << "Enter your selection: ";
				cin >> weaponChoice;
			}
			hero->setCurrentWeapon(weaponChoice);
		} else {
			cout << "Valid commands:\n";
			cout << setw(10) << left << "HELP:" << "Prints out the available commands\n";
			cout << setw(10) << left << "GO:" << "Move in a direction\n";
				cout << "\tValid directions:\n";
				cout << setw(7) << left << "\tUP" << "NORTH\n";
				cout << setw(7) << left << "\tRIGHT" << "EAST\n";
				cout << setw(7) << left << "\tDOWN" << "SOUTH\n";
				cout << setw(7) << left << "\tLEFT" << "WEST\n";
			cout << setw(10) << left << "EQUIP:" << "Prints your weapons and lets you equip one\n";
			cout << setw(10) << left << "INVENTORY:" << "Prints out your inventory\n";
			cout << setw(10) << left << "EXIT:" << "Quits the game\n";
			cout << setw(10) << left << "QUIT:" << "Quits the game\n";
		}

	} 
	// Ask the user if they want to save the game before exiting
	if (getYN("Do you want to save? ")) {
		cout << "Saving...\n";
		board.save(mapSaveOut);	
		hero->save(heroSaveOut);
		cout << "Game saved\n";
	}

	cout << "Now exiting the game...\n";
	mapSave.close();
	heroSave.close();
	mapSaveOut.close();
	heroSaveOut.close();
	cout << "Goodbye\n";
	return 0;
}

string getCommand() {
	string command;
	cout << "Enter your command (enter HELP for help): ";
	getline(cin, command);
	transform(command.begin(), command.end(),command.begin(), ::toupper); // This converts command to upper case
	return command;
}

int randBetween(int min, int max) {
	return rand() % (max - min + 1) + min;
}

Item* generateItem() {
	Item* item = nullptr;
	int toolNum = randBetween(0, 99);
	bool isTool = false;
	if (toolNum < 80) // 80% chance of it being a tool
		isTool = true;
	if (isTool) { // if its a tool, then find if its a weapon
		int weaponNum = randBetween(0, 99);
		bool isWeapon = false;
		if (weaponNum < 70) // 70% chance of it being a weapon
			isWeapon = true;
		if (isWeapon) { // if its a weapon, then find what type
			int physicalNum = randBetween(0, 99);
			bool isPhysical = false;
			if (physicalNum < 50) // 50% chance of being a physical weapon
				isPhysical = true;
			if (isPhysical) { // if its a physical weapon, then find what type
				int typeNum = randBetween(0, 99);
				if (typeNum < 25) { // 25% chance of it being a stick
					item = new Physical(Physical::STICK);
				} else if (typeNum < 50) { // 25% chance of it being a sword
					item = new Physical(Physical::SWORD);
				} else if (typeNum < 75) { // 25% chance of it being knuckles
					item = new Physical(Physical::KNUCKLES);
				} else { // 25% chance of it being a gun
					item = new Physical(Physical::GUN);
				}
			} else { // 50% chance of it being a magic weapon
				int typeNum = randBetween(0, 99);
				if (typeNum < 25) { // 25% chance of it being dirt
					item = new Magic(Magic::DIRT);
				} else if (typeNum < 50) { // 25% chance of it being fire
					item = new Magic(Magic::FIRE);
				} else if (typeNum < 75) { // 25% chance of it being electricity
					item = new Magic(Magic::ELECTRICITY);
				} else { // 25% chance of it being water
					item = new Magic(Magic::WATER);
				}
			}
		} else { // 30% chance of it being a tool
			item = new Tool;
		}
	} else { // 20% chance of it being an ingestible
		item = new Ingestible;
	}
	return item;
}

Enemy* generateEnemy() {
	Enemy* enemy = nullptr;
	int classNum = randBetween(0, 99);
	if (classNum < 30) { // 30% chance of being vicious
		if (classNum % 2 == 0)
			return new Banshee; // 50% chance of banshee
		else
			return new Bigfoot; // 50% chance of bigfoot
	} else { // 30% chance of being benign
		if (classNum % 2 == 0)
			return new Thief; // 50% chance of thief
		else
			return new Silverman; // 50% chance of silverman
	}
	return enemy;
}

bool getYN(string prompt) {
	string input;
	cout << prompt;
	getline(cin, input);
	transform(input.begin(), input.end(),input.begin(), ::toupper); // This converts input to upper case
	while (input != "Y" && input != "YES" && input != "N" && input != "NO") {
		cout << "Please enter yes or no: ";
		getline(cin, input);
		transform(input.begin(), input.end(),input.begin(), ::toupper); // This converts input to upper case
	}
	if (input == "Y" || input == "YES")
		return true;
	else
		return false;
}
