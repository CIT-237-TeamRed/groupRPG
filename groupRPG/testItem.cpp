// Samuel Silverman
// Item Test

#include <iostream>
#include "Item.h"
#include "Ingestible.h"
#include "Tool.h"
#include "Weapon.h"
#include "Physical.h"
#include "Magic.h"

using namespace std;

int main(){
// PHYSICAL
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

// MAGIC
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

system("pause");
    return 0;
}