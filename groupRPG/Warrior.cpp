#include "Warrior.h"

void Warrior::abstract() {
    return;
}

Warrior::Warrior(string name, int health, int lives): Hero(name, health, lives) {
}
