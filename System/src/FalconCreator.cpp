#include "FalconCreator.h"

/* @fn createSpacecraft()
 * @brief creates a new CargoDragonCreator
 * @return Spacecraft
 */
Spacecraft *FalconCreator::createSpacecraft() {
    return new Falcon();
}
