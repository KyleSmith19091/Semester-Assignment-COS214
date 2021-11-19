#include "../include/Dragon.h"

Dragon::Dragon(Falcon* falcon) : Spacecraft("Dragon") {
    this->falconHeavy = falcon;
}

Dragon::~Dragon() {
    if(falconHeavy) {
        delete falconHeavy;
    }
}
