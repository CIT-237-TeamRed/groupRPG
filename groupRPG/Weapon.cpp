#include "Weapon.h"

//void Weapon::setType(Type type){
//	this->type = type;
//}

void Weapon::setPhysicalDamage(int physicalDamage){
	if(physicalDamage < 0){
		this->physicalDamage = physicalDamage;
	}
}

void Weapon::setMagicDamage(int magicDamage){
	if(magicDamage < 0){
		this->magicDamage = magicDamage;
	}
}

Weapon::Weapon(int physicalDamage, int magicDamage): Tool() {
	setName("Weapon");
	setPhysicalDamage(physicalDamage);
	setMagicDamage(magicDamage);
}
Weapon::Weapon(): Tool() {
	setName("Weapon");
	setPhysicalDamage(0);
	setMagicDamage(0);
}
