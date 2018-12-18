#include "Warrior.h"

void Warrior::abstract() {
    return;
}

Warrior::Warrior(string name): Hero(name, 30, 3, 1) {
}
