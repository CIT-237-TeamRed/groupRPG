#include "Magic.h"

void Magic::setType(Type type){
	this->type = type;
}

Magic::Magic(Type type): Weapon() {
    switch(type) {
        case DIRT:
			setName("Dirt");
            magicDamage = 5;
			break;
		case FIRE:
			setName("Fire");
            magicDamage = 10;
			break;
		case ELECTRICITY:
			setName("Electricity");
            magicDamage = 15;
			break;
		case WATER:
			setName("Water");
            magicDamage = 20;
			break;
	}
}