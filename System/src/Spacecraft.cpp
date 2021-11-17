#include "../include/Spacecraft.h"

Spacecraft::Spacecraft(std::string type) {
    this->type = type;
}

string Spacecraft::getType() const {
    return this->type;
}
