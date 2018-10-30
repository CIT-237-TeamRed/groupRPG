#include "theif.h"
Theif::Theif(string name, double health, int level) {
	this->name = name;
	setHealth(health);
	setLevel(level);
}
