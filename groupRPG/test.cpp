#include <iostream>
#include <string>
#include "Mage.h"
#include "Leader.h"
#include "Warrior.h"
#include "Thief.h"
#include "Silverman.h"//add rest of enemies later
#include "Physical.h"
#include "Magic.h"
#include "Map.h"

using namespace std;

int main() {
    // Test the leader class
    cout << "-------------" << endl
         << "TESTING THE LEADER CLASS" << endl 
         << "-------------" << endl;
	Physical sword1(Physical::SWORD);
	cout << "Making testLeader with 5 health and 10 lives" << endl;
	Leader testLeader("Steve", 5, 10);
	cout << testLeader << endl;

	cout << "testLeader.getMaxHealth() should be 20: " << testLeader.getMaxHealth() << endl;
	cout << "testLeader.getMaxLives() should be 10: " << testLeader.getMaxLives() << endl;

	cout << "Setting testLeader's level to 40" << endl;
	testLeader.setLives(40);
	cout << testLeader << endl;

	cout << "Setting testLeader's level to -100" << endl;
	testLeader.setLives(-100);
	cout << testLeader << endl;

	cout << "Setting testLeader's health to 100" << endl;
	testLeader.setHealth(100);
	cout << testLeader << endl;

	cout << "Setting testLeader's health to -140" << endl;
	testLeader.setLives(-140);
	cout << testLeader << endl;

	cout << "Setting testLeader's level to 3" << endl;
	testLeader.setLives(3);
	cout << testLeader << endl;

	cout << "Setting testLeader's health to 10" << endl;
	testLeader.setHealth(10);
	cout << testLeader << endl;

	cout << "Adding sword to testLeader's iventory" << endl;
	testLeader.addToInventory(sword1);
	cout << testLeader << endl;

    cout << "Equiping sword" << endl;
    testLeader.setCurrentWeapon(sword1);
    cout << testLeader << endl;

    // Test the mage class
    cout << "-------------" << endl
         << "TESTING THE MAGE CLASS" << endl 
         << "-------------" << endl;
	Physical sword2(Physical::SWORD);
	cout << "Making testMage with 5 health and 10 lives" << endl;
	Mage testMage("Glenn", 5, 10);
	cout << testMage << endl;

	cout << "testMage.getMaxHealth() should be 20: " << testMage.getMaxHealth() << endl;
	cout << "testMage.getMaxLives() should be 10: " << testMage.getMaxLives() << endl;

	cout << "Setting testMage's level to 40" << endl;
	testMage.setLives(40);
	cout << testMage << endl;

	cout << "Setting testMage's level to -100" << endl;
	testMage.setLives(-100);
	cout << testMage << endl;

	cout << "Setting testMage's health to 100" << endl;
	testMage.setHealth(100);
	cout << testMage << endl;

	cout << "Setting testMage's health to -140" << endl;
	testMage.setLives(-140);
	cout << testMage << endl;

	cout << "Setting testMage's level to 3" << endl;
	testMage.setLives(3);
	cout << testMage << endl;

	cout << "Setting testMage's health to 10" << endl;
	testMage.setHealth(10);
	cout << testMage << endl;

	cout << "Adding sword to testMage's iventory" << endl;
	testMage.addToInventory(sword2);
	cout << testMage << endl;

    cout << "Equiping sword" << endl;
    testMage.setCurrentWeapon(sword2);
    cout << testMage << endl;

    // Test the warrior class
    cout << "-------------" << endl
         << "TESTING THE WARRIOR CLASS" << endl 
         << "-------------" << endl;
	Physical sword3(Physical::SWORD);
	cout << "Making testWarrior with 5 health and 10 lives" << endl;
	Warrior testWarrior("Paul", 5, 10);
	cout << testWarrior << endl;

	cout << "testWarrior.getMaxHealth() should be 20: " << testWarrior.getMaxHealth() << endl;
	cout << "testWarrior.getMaxLives() should be 10: " << testWarrior.getMaxLives() << endl;

	cout << "Setting testWarrior's level to 40" << endl;
	testWarrior.setLives(40);
	cout << testWarrior << endl;

	cout << "Setting testWarrior's level to -100" << endl;
	testWarrior.setLives(-100);
	cout << testWarrior << endl;

	cout << "Setting testWarrior's health to 100" << endl;
	testWarrior.setHealth(100);
	cout << testWarrior << endl;

	cout << "Setting testWarrior's health to -140" << endl;
	testWarrior.setLives(-140);
	cout << testWarrior << endl;

	cout << "Setting testWarrior's level to 3" << endl;
	testWarrior.setLives(3);
	cout << testWarrior << endl;

	cout << "Setting testWarrior's health to 10" << endl;
	testWarrior.setHealth(10);
	cout << testWarrior << endl;

	cout << "Adding sword to testWarrior's iventory" << endl;
	testWarrior.addToInventory(sword3);
	cout << testWarrior << endl;

    cout << "Equiping sword" << endl;
    testWarrior.setCurrentWeapon(sword3);
    cout << testWarrior << endl;

    // Test the physical class
    cout << "-------------" << endl
         << "TESTING THE PHYSICAL CLASS" << endl 
         << "-------------" << endl;
        {
            // TESTING STICK (Physical)
            cout << "Making stick weapon" << endl;
            Physical stick(Physical::Type::STICK);
            
            cout << "stick.getPhysicalDamage(): (should be 5) " << endl;
            cout << stick.getPhysicalDamage() << endl;
            
            cout << "stick.getMagicDamage(): (should be 0) " << endl;
            cout << stick.getMagicDamage() << endl;
            
            // TESTING SWORD (Physical)
            cout << "Making sword weapon" << endl;
            Physical sword(Physical::Type::SWORD);
            
            cout << "sword.getPhysicalDamage(): (should be 10) " << endl;
            cout << sword.getPhysicalDamage() << endl;
            
            cout << "sword.getMagicDamage(): (should be 0) " << endl;
            cout << sword.getMagicDamage() << endl;

            // TESTING KNUCKLES (Physical)
            cout << "Making knuckles weapon" << endl;
            Physical knuckles(Physical::Type::KNUCKLES);
            
            cout << "knuckles.getPhysicalDamage(): (should be 15) " << endl;
            cout << knuckles.getPhysicalDamage() << endl;
            
            cout << "knuckles.getMagicDamage(): (should be 0) " << endl;
            cout << knuckles.getMagicDamage() << endl;

            // TESTING GUN (Physical)
            cout << "Making gun weapon" << endl;
            Physical gun(Physical::Type::GUN);
            
            cout << "gun.getPhysicalDamage(): (should be 20) " << endl;
            cout << gun.getPhysicalDamage() << endl;
            
            cout << "gun.getMagicDamage(): (should be 0) " << endl;
            cout << gun.getMagicDamage() << endl;
        }

    // Test the magic class
    cout << "-------------" << endl
         << "TESTING THE MAGIC CLASS" << endl 
         << "-------------" << endl;
        {
            // TESTING DIRT (Magic)
            cout << "Making dirt weapon" << endl;
            Magic dirt(Magic::Type::DIRT);
            
            cout << "dirt.getMagicDamage(): (should be 5) " << endl;
            cout << dirt.getMagicDamage() << endl;
            
            cout << "dirt.getPhysicalDamage(): (should be 0) " << endl;
            cout << dirt.getPhysicalDamage() << endl;

            // TESTING FIRE (Magic)
            cout << "Making fire weapon" << endl;
            Magic fire(Magic::Type::FIRE);
            
            cout << "fire.getMagicDamage(): (should be 10) " << endl;
            cout << fire.getMagicDamage() << endl;
            
            cout << "fire.getPhysicalDamage(): (should be 0) " << endl;
            cout << fire.getPhysicalDamage() << endl;

            // TESTING ELECTRICITY (Magic)
            cout << "Making electricity weapon" << endl;
            Magic electricity(Magic::Type::ELECTRICITY);
            
            cout << "electricity.getMagicDamage(): (should be 15) " << endl;
            cout << electricity.getMagicDamage() << endl;
            
            cout << "electricity.getPhysicalDamage(): (should be 0) " << endl;
            cout << electricity.getPhysicalDamage() << endl;

            // TESTING WATER (Magic)
            cout << "Making water weapon" << endl;
            Magic water(Magic::Type::WATER);
            
            cout << "water.getMagicDamage(): (should be 20) " << endl;
            cout << water.getMagicDamage() << endl;
            
            cout << "water.getPhysicalDamage(): (should be 0) " << endl;
            cout << water.getPhysicalDamage() << endl;
        }

    // Test the tool class
    cout << "-------------" << endl
         << "TESTING THE TOOL CLASS" << endl 
         << "-------------" << endl;

    // Test the thief class
    cout << "-------------" << endl
         << "TESTING THE THIEF CLASS" << endl 
         << "-------------" << endl;

    // Test the silverman class
    cout << "-------------" << endl
         << "TESTING THE SILVERMAN CLASS" << endl 
         << "-------------" << endl;

    // Test the map class
    cout << "-------------" << endl
         << "TESTING THE MAP CLASS" << endl 
         << "-------------" << endl;


    return 0;
}