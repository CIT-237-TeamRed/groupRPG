#include "Ingestible.h"

void Ingestible::setQuantity(int quantity) {
	if (quantity <= 0){
        quantity = 0;
	    this->quantity = quantity;
    }
}

Ingestible::Ingestible(): Item() {
	setName("Ingestible");
}
