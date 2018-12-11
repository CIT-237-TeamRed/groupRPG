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
#include "Viscious.h"
#include "Warrior.h"
#include "Weapon.h"

using namespace std;

Item* generateItem();
Enemy* generateEnemy();
string getCommand();

int main() {
	Map board(10,10);
	// TODO: see below
	// Check for a save file
	// If there is one ask to load it
	// Else start a new game
	//
	// loop until the player quits
	bool runGame = true;
	// TODO: add a generate function to the map class
	board.setEnemy(5, 5, true);
	board.setItem(5, 6, true);
	while (runGame) {
		string command = getCommand();

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
		// 		TODO: let the user pickup the item
			cout << "Pickup " << item->getName() << "?\n";
		}
		
		//	output what is nearby the hero
		if (board.isEnemyNearby(board.getHeroX(), board.getHeroY())) {
			cout << "There is an enemy nearby.\n";
		}
		if (board.isItemNearby(board.getHeroX(), board.getHeroY())) {
			cout << "There is an item nearby.\n";
		}

		cout << "You are at (" << board.getHeroX() << ", " << board.getHeroY() << ")\n";

		// 	prompt them for a command
		// 	run the appropriate function
		// TODO: For some reason a second command has to be run before the player will actually move
		if (command == "EXIT" || command == "QUIT")
			runGame = false;
		if (command.substr(0, 2) == "GO") {
			command.erase(0, 3);
			if (command == "UP" || command == "NORTH")
				board.setHeroCoords(board.getHeroX(), board.getHeroY()+1);
			else if (command == "DOWN" || command == "SOUTH")
				board.setHeroCoords(board.getHeroX(), board.getHeroY()-1);
			else if (command == "LEFT" || command == "WEST")
				board.setHeroCoords(board.getHeroX()+1, board.getHeroY());
			else if (command == "RIGHT" || command == "EAST")
				board.setHeroCoords(board.getHeroX()-1, board.getHeroY());
			else {
				cout << command << " is an invalid direction\n";
				cout << "Valid directions:\n";
				cout << setw(7) << left << "UP" << "NORTH\n";
				cout << setw(7) << left << "RIGHT" << "EAST\n";
				cout << setw(7) << left << "DOWN" << "SOUTH\n";
				cout << setw(7) << left << "LEFT" << "WEST\n";
			}
		} else {
			cout << "Valid commands:\n";
			cout << setw(10) << left << "HELP:" << "Prints out the available commands\n";
			cout << setw(10) << left << "GO:" << "Move in a direction\n";
				cout << "\tValid directions:\n";
				cout << setw(7) << left << "\tUP" << "NORTH\n";
				cout << setw(7) << left << "\tRIGHT" << "EAST\n";
				cout << setw(7) << left << "\tDOWN" << "SOUTH\n";
				cout << setw(7) << left << "\tLEFT" << "WEST\n";
			cout << setw(10) << left << "EXIT:" << "Quits the game\n";
			cout << setw(10) << left << "QUIT:" << "Quits the game\n";
		}

	} 
	// Ask the user if they want to save the game before exiting
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
	if (toolNum < 50) // 50% chance of it being a tool
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
	} else { // 50% chance of it being an ingestible
		item = new Ingestible;
	}
	return item;
}

Enemy* generateEnemy() {
	Enemy* enemy = nullptr;
	int visciousNum = randBetween(0, 99);
	bool isViscious = false;
	if (visciousNum < 20) // 20% chance of it being viscious
		isViscious = true;

	int classNum = randBetween(0, 99);
	if (isViscious) { // if it is viscious find what type
		if (classNum < 30) { // 30% chance it is a banshee
			enemy = new Banshee;
		} else { // 70% chance it is a bigfoot
			enemy = new Bigfoot;
		}
	} else { // 80% chance it is benign, then find what type
		if (classNum < 30) { // 30% chance it is a silverman
			enemy = new Silverman;
		} else { // 70% chance it is a thief
			enemy = new Thief;
		}
	}
	return enemy;
}
