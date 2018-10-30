#include "Physical.h"

void Physical::setType(Type type){
	this->type = type;
}

Physical::Physical(Type type) {
    switch(type) {
        case STICK:
            physicalDamage = 5;
			break;
		case SWORD:
            physicalDamage = 10;
			break;
		case KNUCKLES:
            physicalDamage = 15;
			break;
		case GUN:
            physicalDamage = 20;
			break;
	}
}