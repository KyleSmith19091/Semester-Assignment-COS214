#include "../include/CrewDragonCreator.h"

/* @fn createSpacecraft()
 * @brief creates a new CargoDragonCreator
 * @return Spacecraft
 */
Spacecraft *CrewDragonCreator::createSpacecraft() {
    Falcon* falcon=new Falcon("falcon-9");
    Spacecraft *craft=new CrewDragon(falcon);
    return craft;
}
