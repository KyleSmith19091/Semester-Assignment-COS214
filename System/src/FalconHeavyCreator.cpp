#include "../include/FalconHeavyCreator.h"

/* @fn createSpacecraft()
 * @brief creates a new CargoDragonCreator
 * @return Spacecraft
 */
Spacecraft *FalconHeavyCreator::createSpacecraft() {
    return new Falcon("falcon-heavy");
}
