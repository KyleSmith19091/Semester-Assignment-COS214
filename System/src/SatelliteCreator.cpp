#include "SatelliteCreator.h"

/* @fn createSpacecraft()
 * @brief creates a new CargoDragonCreator
 * @return Spacecraft
 */
Spacecraft *SatelliteCreator::createSpacecraft() {
    return new Satelite();
}
