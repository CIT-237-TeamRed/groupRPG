#include <iostream>
#include "Item/Item.h"
#include "Item/Ingestible/Ingestible.h"
#include "Item/Tool/Tool.h"
#include "Item/Tool/Weapon/Weapon.h"
#include "Item/Tool/Weapon/Physical/Physical.h"
#include "Item/Tool/Weapon/Magic/Magic.h"
// Include all .h's present within Item folder

using namespace std;

int main(){
    Weapon arr[5];
    Physical sword(Physical::Type::SWORD);
    Magic fire(Magic::Type::FIRE);
    cout << "Making fire weapon";
    cout << "fire.getDamage(): (should be 5) ";
    // in constructor:
    // in .h
    Physical(Type type);
    //in .cpp
    Physical::Physical(Type type) {
    switch(type) {
        case SWORD:
            physicalDamage = 5;
			break;
    }
    }    
system("pause");
    return 0;
}