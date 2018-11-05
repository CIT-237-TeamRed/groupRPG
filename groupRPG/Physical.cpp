#include "Physical.h"

void Physical::setType(Type type){
	this->type = type;
}

Physical::Physical(Type type): Weapon() {
    switch(type) {
        case STICK:
			setName("Stick");
            physicalDamage = 5;
			break;
		case SWORD:
			setName("Sword");
            physicalDamage = 10;
			break;
		case KNUCKLES:
			setName("Brass knuckles");
            physicalDamage = 15;
			break;
		case GUN:
			setName("Gun");
            physicalDamage = 20;
			break;
	}
}