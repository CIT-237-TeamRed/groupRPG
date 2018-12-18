#include "Ingestible.h"
#include "Hero.h"

void Ingestible::setQuantity(int quantity) {
	if (quantity <= 0){
        quantity = 0;
	    this->quantity = quantity;
    }
}

void Ingestible::use(Hero *hero) {
	if (type == Type::HEALTH) {
		hero->setHealth(hero->getHealth()+5);
	} else if (type == Type::DAMAGE) {
		hero->setPhysicalDamage(hero->getPhysicalDamage() + 5);
		hero->setMagicDamage(hero->getMagicDamage() + 5);
	}
}

Ingestible::Ingestible(Type newType): Item() {
	type = newType;
	if (type == Type::HEALTH)
		setName("Health Potion");
	else if (type == Type::DAMAGE)
		setName("Weapon Potion");
	else
		setName("Ingestible");
}
