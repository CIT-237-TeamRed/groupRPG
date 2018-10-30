#include "warrior.cpp"
Warrior::Warrior(string name, double health, int level) {
	this->name = name;
	setHealth(health);
	setLevel(level);
}
