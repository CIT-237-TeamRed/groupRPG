#include "Magic.h"

void Magic::setType(Type type){
	this->type = type;
}

Magic::Magic(Type type) {
    switch(type) {
        case DIRT:
            magicDamage = 5;
			break;
		case FIRE:
            magicDamage = 10;
			break;
		case ELECTRICITY:
            magicDamage = 15;
			break;
		case WATER:
            magicDamage = 20;
			break;
	}
}