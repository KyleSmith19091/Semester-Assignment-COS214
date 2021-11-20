#include "../include/Dragon.h"

Dragon::Dragon(Falcon* falcon) : Spacecraft(falcon->getType()) {
    this->falconHeavy = falcon;
}

Dragon::~Dragon() {
    if(falconHeavy) {
        delete falconHeavy;
    }
}
