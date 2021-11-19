#include "../include/Satelite.h"

Satelite::Satelite(int _id) : Spacecraft("Satelite") {
    this->id = rand() % 1000 + 1;
}

Satelite::Satelite(const Satelite& s) : Spacecraft("Satelite") {
    this->id = rand() % 1000 + 1;
}

Satelite* Satelite::clone() {
    return new Satelite(*this);
}

void Satelite::positionSelf() {
    std::cout << "Positioning 🛰.. DONE.{id=" + to_string(id) + "}\n";
}
