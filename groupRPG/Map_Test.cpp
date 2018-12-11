// Map Test Program
// by Team Red
// Jericho Keyne
// Daniel Richardson
// Karlos Boehlke
// Samuel Silverman

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include "Map.h"
#include "Position.h"
#include "Direction.h"

using namespace std;

void printCommands();

bool checkCreatures(Map map, Position pos);
bool checkTreasures(Map map, Position pos);
void checkCreaturesAndTreasures(Map cMap, Map tMap, Position heroPos);

void saveMap(Map map, string fName);
void savePos(Position pos, string fName);

int main() {
	// Setup
	system("color 3E");
	system("title Map Test - Team Red");

	// Declaring constant variables
	const int NUM_CREATURES = 5;
	const int NUM_TREASURES = 5;
	const int MAP_WIDTH = 10;
	const int MAP_LENGTH = 10;
	
	//create Position array for treasures
	Position treasures[NUM_TREASURES]; 

	//set the values of the positions
	Position t1(2, 4);
	treasures[0] = t1;
	Position t2(8, 5);
	treasures[1] = t2;
	Position t3(3, 7);
	treasures[2] = t3;
	Position t4(9, 6);
	treasures[3] = t4;
	Position t5(7, 2);
	treasures[4] = t5;	
	
	//create treasure map based on position array
	Map treasureMap(treasures);

	//create Position array for creatures
	Position creatures[NUM_CREATURES]; 

	//set the values of the positions
	Position c1(1, 4); 
	creatures[0] = c1;
	Position c2(8, 4);
	creatures[1] = c2;
	Position c3(3, 8);
	creatures[2] = c3;
	Position c4(9, 6);
	creatures[3] = c4;
	Position c5(7, 2);
	creatures[4] = c5;

	//create creature map based on position array
	Map creatureMap(creatures);

	//set position of the hero
	Position hero(0, 0);

	//check if there are files, if so, load that data to overwrite the current maps
	ifstream creatureMapFile("creatureMap.dat");
	ifstream treasureMapFile("treasureMap.dat");
	ifstream heroPosFile("heroPos.txt");
	if (creatureMapFile.good() && treasureMapFile.good() && heroPosFile.good()) { //if files exist then ask to load, else continue with program
		string input;
		cout << "Do you want to load the save data? (y/n) ";
		getline(cin, input);
		transform(input.begin(), input.end(), input.begin(), ::toupper);
		if (input == "Y" || input == "YES") { //if the user says yes, then try and load the maps and hero
			try {						
				creatureMap.readBinaryMap("creatureMap.dat");
			} catch (Map::ILLEGAL_WIDTH) {
				cout << "creatureMap.dat has an illegal width value\n";
				return 1;
			} catch (Map::ILLEGAL_HEIGHT) {
				cout << "creatureMap.dat has an illegal height value\n";
				return 2;
			}
			try {							
				treasureMap.readBinaryMap("treasureMap.dat");
			} catch (Map::ILLEGAL_WIDTH) {
				cout << "treasureMap.dat has an illegal width value\n";
				return 3;
			} catch (Map::ILLEGAL_HEIGHT) {
				cout << "treasureMap.dat has an illegal height value\n";
				return 4;
			}
			loadPos(hero, "heroPos.txt");
		}		
	}
		
	//create direction object assuming that Direction::dir is not public static
	Direction direction;

	// set input string to be empty before loop
	string input = "";
	do {
		checkCreaturesAndTreasures(creatureMap, treasureMap, hero); //outputs if you are on a square with a creature or treasure
		cout << "Enter a command: (type \"HELP\" for a list of commands)" ;
		getline(cin, input);
		transform(input.begin(), input.end(), input.begin(), ::toupper); // make input upper case
		if (input == "") // if the input is empty, do nothing
			continue;
		if (input == "N" || input == "NE" || input == "E" || input == "SE" || input == "S" || input == "SW" || input == "W" || input == "NW") //update direction from input
			hero.update(direction.dir(input));
		else if (input == "SAVE") { // save the map and position
			creatureMap.writeBinaryMap("creatureMap.dat");
			treasureMap.writeBinaryMap("treasureMap.dat");
			savePos(hero, "heroPos.txt");
			cout << "\nYour game has been saved. Continue playing or enter Quit or Exit to leave the game.\n";
			continue;
		}
		else if (input == "QUIT" || input == "EXIT") { //quit or exit the game
			cout << "Are you sure (y/n)? ";
			getline(cin, input);
			transform(input.begin(), input.end(), input.begin(), ::toupper); //make input upper case
			if (input == "Y" || input == "YES") {
				creatureMap.writeBinaryMap("creatureMap.dat");
				treasureMap.writeBinaryMap("treasureMap.dat");
				savePos(hero, "heroPos.txt");
				cout << "\nYour game has been saved.\n";
				break;
			} else 
				input = ""; // reset the input string so the loop will continue
		}
		else if (input == "HELP") //display the commands if desired
			printCommands();
		else { // catch if the user inputs an invalid command
			cout << "\'" << input << "\' is not a valid command\n";
			continue;
		}

	} while (input != "QUIT" || input != "EXIT"); //continue the loop if the user does not quit or exit

	cout << "\n Game closing...";
	system("pause");
	return 0;
}

void printCommands(){ //print the commands
	cout
		<< "\n        Available Commands:				"
		<< "\n           N, NE, E, SE, S, SW, W, NW	"
		<< "\n           SAVE, QUIT, EXIT				\n\n";
}

void checkCreaturesAndTreasures(Map creatureMap, Map treasureMap, Position hero)) { //outputs based on the positions of treasures and creastures around the hero
	bool isCreature = checkCreatures(creatureMap, hero);
	bool isTreasure = checkTreasures(treasureMap, hero);
	bool isCreatureNearby = creatureMap.nearPosition(hero);
	bool isTreasureNearby = treasureMap.nearPosition(hero);

	if (isCreature)
		cout << "There is a creature at " << hero.toString() <<endl;
	if (isTreasure)
		cout << "There is a treasure at " << hero.toString() << endl;
	if (isCreatureNearby)
		cout << "There is an enemy nearby\n";
	if (isTreasureNearby)
		cout << "There is treasure nearby\n";
	if (!isCreature && !isTreasure && !isCreatureNearby && !isTreasureNearby)
		cout << "There is nothing nearby\n";
}

bool checkCreatures(Map map, Position pos) { //return true if there is a creature at location
	return map.checkPosition(pos);
}

bool checkTreasures(Map map, Position pos) {//return true if there is a treasure at location
	return map.checkPosition(pos);
}

void loadPos(Position &pos, string fName) { //load a position file for hero
	ifstream inputFile(fName);
	if (ifstream.fail()) {
		cout << "Failed to open file";
		return;																										
	}
	int rowPos;
	inputFile >> rowPos;
	int colPos;
	inputFile >> colPos;
	pos.setRowPos(rowPos);
	pos.setColPos(colPos);					
}

void savePos(Position pos, string fName) { //save a position file for hero
	ofstream outputFile(fName);
	if (ofstream.fail()) {
		cout << "Failed to open file\n";
		return;
	}
	outputFile << pos.getColPos() << endl;
	outputFile << pos.getRowPos() << endl;																												
}