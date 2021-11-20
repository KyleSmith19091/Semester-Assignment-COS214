#include "../include/Falcon9Creator.h"

Spacecraft* Falcon9Creator::createSpacecraft() {
    return new Falcon("falcon-9");
}
