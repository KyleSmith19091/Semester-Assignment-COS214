#include "../include/CargoDragonCreator.h"

/* @fn createSpacecraft()
 * @brief creates a new CargoDragonCreator
 * @return Spacecraft
 */
Spacecraft* CargoDragonCreator::createSpacecraft() {
    Falcon* falcon=new Falcon("falcon-9");
    Spacecraft *craft=new CargoDragon(falcon);
    return craft;
}
