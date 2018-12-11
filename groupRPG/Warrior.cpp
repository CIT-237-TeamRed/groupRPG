#include "Warrior.h"

void Warrior::abstract() {
    return;
}

Warrior::Warrior(string name, int health, int lives): Hero(name, health, lives) {
}

Warrior::Warrior(string name): Hero(name) {
}
