// Game.cpp
// This is where all the game logic is stored
//
// Jericho Keyne
// Daniel Richardson
// Karlos Boehlke
// Samuel Silverman

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

int randBetween(int min, int max);
void attack(Enemy *enemy, Hero *hero, string who);
void fight(Enemy *enemy, Hero *hero, Map &board);
Item* generateItem(); //create randomized item object
Enemy* generateEnemy(); //create randomized enemy object
string getCommand(); //take command from player
void save(Hero* hero, Map board);
bool getYN(string prompt); //take a yes or no command from player

int main() {
	srand(time(0));
	Map board(10,10); //create a map of dimensions 10x10
	Hero* hero = new Mage("You should never see this"); //initialize hero object

	ifstream mapSave("map.dat", ios::binary); //create input file stream for map save
	ifstream heroSave("hero.txt"); //create input file stream for hero save

	bool startNewGame = false; //becomes true if there is not a save file, or player does not want to load an old game 

	//if the save files exist, ask user if they want to load it
	if (mapSave.good() && heroSave.good()) {
		if (getYN("Do you want to load map.dat and hero.txt? ")) {
			startNewGame = false;
			cout << "Loading save file...\n";
			board.load(mapSave);
			// try {
			hero->load(heroSave);
			// } catch (const std::exception &e) {
			// 	cout << "Loading failed" << endl;
			// 	std::cerr << e.what();
			// }
		} else {
			if (!getYN("Do you want to start a new game? ")) //if they don't want to start a new game
				return 0; //close the game
			startNewGame = true; //start new game if they do want to start a new game
		}
	} else {
		startNewGame = true; //start new game if there is no save file
	}
	mapSave.close();
	heroSave.close();

	if (startNewGame) { //if a new game is starting

		//give hero type choices
		cout << "Select your hero: \n"; 
		cout << "1. Leader\n";
		cout << "2. Warrior\n";
		cout << "3. Mage\n\n";
		
		//take input for hero 
		string input;
		getline(cin, input);

		//check for input validation
		while (input != "1" && input != "2" && input != "3") { 
			cout << "Please enter a valid selection: ";
			getline(cin, input);
		}
		cout << "You have chosen ";
		if (input == "1")
			cout << "a Leader\n";
		else if (input == "2")
			cout << "a Warrior\n";
		else if (input == "3")
			cout << "a Mage\n";

		//ask for what name the player wants, and initialize a hero of their chosen type with that name
		string name;
		cout << "Enter your name: ";
		getline(cin, name);
		if (input == "1")
			hero = new Leader(name);
		else if (input == "2")
			hero = new Warrior(name);
		else if (input == "3")
			hero = new Mage(name);

		//spawn items and enemies in a random fashion
		board.generateMap();
	}

	bool runGame = true; //gets set to false if you want to stop the game
	while (runGame) {
		cout << endl;
		//	if there is an enemy
		if (board.getEnemyState(board.getHeroX(), board.getHeroY())) {
		//		generate enemy
			Enemy* enemy = generateEnemy();
		//		if enemy is viscious then start fight
		//		if enemy is benign then ask if the player wants to fight
		//		TODO: make a fighting system, make classes unique
			try {
				if (enemy->isHostile()) {
					fight(enemy, hero, board);
				} else { //if enemy is passive
					if (getYN("Wanna fight a " + enemy->getEnemyType() + "? "))
						fight(enemy, hero, board);
				}
			} catch (Hero::INVALID_HEALTH) {
				if (hero->getLives() > 1) {
					hero->setLives(hero->getLives() - 1);
					cout << "You died\n";
					hero->setHealth(hero->getMaxHealth());
					int x = randBetween(0, board.getWidth()-1);
					int y = randBetween(0, board.getLength()-1);
					board.setHeroCoords(x, y);
					cout << "You have respawned at (" << x << ", " << y << ")\n";
					continue;
				} else {
					cout << "GAME OVER\n";
					return 0;
				}
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
		cout << *hero << endl; //shows hero's name, health, live, current weapon, damage, items 

		// 	prompt them for a command
		string command = getCommand();
		// 	run the appropriate function
		if (command == "EXIT" || command == "QUIT")
			runGame = false;
		else if (command == "SAVE") {
			save(hero, board);
			//if command starts with "go", move in a direction of the next word
		} else if (command.substr(0, 2) == "GO") { 
			// TODO: Game currently crashes if the player moves too far to the right
			command.erase(0, 3); //erase "GO "
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
				cout << setw(7) << left << "LEFT" << "WEST\n\n";
			}
		} else if (command == "INVENTORY") {
			hero->printIventory(); //displays inventory
		} else if (command == "EQUIP") {
			//set number of weapons, and display prompt to equip weapons
			int numWeapons = hero->printWeapons(); 
			cout << "Enter your selection: ";
			int weaponChoice;

			cin >> weaponChoice;
			while (weaponChoice < 1 || weaponChoice > numWeapons || cin.fail()) { //if the number the playe chooses is not valid, try again
				if (cin.fail()) {
					cin.ignore(1000, '\n');
					cin.clear();
				}
				cout << "Enter your selection: ";
				cin >> weaponChoice;
				cout << endl;
			}
			hero->setCurrentWeapon(weaponChoice); //set the weapon to the choice

			//if the user doen't input a valid command, display the the valid commands
		} else if (command == "USE") {
			//set number of ingestibles, and display prompt to use an ingestible
			int numIngestibles = hero->printIngestibles(); 
			cout << "Enter your selection: ";
			int ingestibleChoice;
			cin >> ingestibleChoice;
			while (ingestibleChoice < 1 || ingestibleChoice > numIngestibles || cin.fail()) { //if the number the player chooses is not valid, try again
				if (cin.fail()) {
					cin.ignore(1000, '\n');
					cin.clear();
				}
				cout << "Enter your selection: ";
				cin >> ingestibleChoice;
				cout << endl;
			}

			hero->use(ingestibleChoice); //use the ingestible chosen
			cout << "You used your ingestible.\n";
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
			cout << setw(10) << left << "USE:" << "Use a potion\n";
			cout << setw(10) << left << "EXIT:" << "Quits the game\n";
			cout << setw(10) << left << "QUIT:" << "Quits the game\n\n";
		}

	} 
	//while loop is end from exit command or quit command
	
	// Ask the user if they want to save the game before exiting
	if (getYN("Do you want to save? ")) {
		save(hero, board);
	}

	//close the input and output streams
	cout << "Now exiting the game...\n";
	return 0;
}

string getCommand() { //prompts for and returns a string that is the command
	string command;
	cout << "\nEnter your command (enter HELP for help): ";
	getline(cin, command);
	transform(command.begin(), command.end(),command.begin(), ::toupper); // This converts command to upper case
	return command;
}

int randBetween(int min, int max) { //generates a random number between min and max
	return rand() % (max - min + 1) + min;
}

Item* generateItem() { //generate randomized item
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
		int potionNum = randBetween(0, 99);
		if (potionNum < 50) // 50% chance of it being health potion
			item = new Ingestible(Ingestible::HEALTH);
		else // 50% chance of it being damage potion
			item = new Ingestible(Ingestible::DAMAGE);
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

void attack(Enemy *enemy, Hero *hero, string who) { //attack between the hero and enemy, "who" being who is attacking
	if (who == "enemy") {
		hero->setHealth(hero->getHealth() - enemy->getWeaponDamage()); //set hero health to be minus by enemy's attack damage
		cout << enemy->getEnemyType() << " attacked you for " << enemy->getWeaponDamage() << " damage\n";
	} else if (who == "hero") {
		enemy->setHealth(enemy->getEnemyHealth() - (hero->getPhysicalDamage() + hero->getMagicDamage())); //set enemy health to be minus hero's attack damage + magic damage
		cout << "You attacked the enemy for " << hero->getPhysicalDamage() << " physical damage and " << hero->getMagicDamage() << " magic damage\n";
	}
}

void fight(Enemy *enemy, Hero *hero, Map &board) {
	if (enemy->isHostile()) { // The enemy attacks first if it is hostile
		cout << "\nYou are being attacked by a " << enemy->getEnemyType() << endl;
		attack(enemy, hero, "enemy");
	}
	while (hero->getHealth() > 0 && enemy->getEnemyHealth() > 0) { //while either the enemy or hero is alive, do the fight sequence
		//cout << enemy->toString() << endl;
		cout << endl;
		cout << *hero << endl;
		string input = getCommand();
		if (input == "INVENTORY") { //print hero's inventory 
			hero->printIventory();
			continue;
		} else if (input == "EQUIP") {
			//set number of weapons, and display prompt to equip weapons
			int numWeapons = hero->printWeapons(); 
			cout << "Enter your selection: ";
			int weaponChoice;
			cin >> weaponChoice;
			while (weaponChoice < 1 || weaponChoice > numWeapons || cin.fail()) { //if the number the player chooses is not valid, try again
				if (cin.fail()) {
					cin.ignore(1000, '\n');
					cin.clear();
				}
				cout << "Enter your selection: ";
				cin >> weaponChoice;
				cout << endl;
			}
			hero->setCurrentWeapon(weaponChoice); //set the weapon to the choice
			continue;
		}
		else if (input == "USE") {
			//set number of ingestibles, and display prompt to use an ingestible
			int numIngestibles = hero->printIngestibles(); 
			cout << "Enter your selection: ";
			int ingestibleChoice;
			cin >> ingestibleChoice;
			while (ingestibleChoice < 1 || ingestibleChoice > numIngestibles || cin.fail()) { //if the number the player chooses is not valid, try again
				if (cin.fail()) {
					cin.ignore(1000, '\n');
					cin.clear();
				}
				cout << "Enter your selection: ";
				cin >> ingestibleChoice;
				cout << endl;
			}

			hero->use(ingestibleChoice); //use the ingestible chosen
			cout << "You used your ingestible.\n";
			continue;

		}
		else if (input == "ATTACK") {
			attack(enemy, hero, "hero"); //attack the enemy
		} else {
			//print out the valid commands
			cout << input << " is an invalid option\n"
				<< "VALID COMMANDS:\n"
				<< setw(10) << left << "INVENTORY" << "Prints the hero's inventory\n"
				<< setw(10) << left << "EQUIP" << "Equip a new weapon\n"
				<< setw(10) << left << "ATTACK" << "Attack the enemy\n"
				<< setw(10) << left << "USE" << "Use a potion\n\n";
			continue;
		}
		if (enemy->getEnemyHealth() > 0)
			attack(enemy, hero, "enemy");//enemy attacks after hero''s turn
	} 

	cout << enemy->getEnemyType() << " has DIED\n\n";
	board.setEnemy(board.getHeroX(), board.getHeroY(), false);
	
}

bool getYN(string prompt) { //prompts for yes or no and returns answer
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

void save(Hero* hero, Map board) {
	cout << "Saving...\n";
	cout << "Please do not unplug the console\n";
	ofstream mapSaveOut("map.dat", ios::binary); //create output stream for saving the map
	ofstream heroSaveOut("hero.txt"); //create ouput stream for saving the hero
	board.save(mapSaveOut);	
	hero->save(heroSaveOut);
	mapSaveOut.close();
	heroSaveOut.close();
	cout << "Game saved\n";
}