#include "CargoDragonCreator.h"

/* @fn createSpacecraft()
 * @brief creates a new CargoDragonCreator
 * @return Spacecraft
 */
Spacecraft *CargoDragonCreator::createSpacecraft() {
    Falcon* falcon=new Falcon();
    Spacecraft *craft=new CargoDragon(falcon);
    return craft;
}
