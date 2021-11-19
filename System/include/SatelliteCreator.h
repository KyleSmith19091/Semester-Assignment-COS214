/****************************************************************************************************
 *  @file ./include/SatelliteCreator.h
 *  @brief The header file for the SatelliteCreator class.
 ***************************************************************************************************/

#ifndef SATELLITECREATOR_H
#define SATELLITECREATOR_H

#include "SpacecraftCreator.h"
#include "Satelite.h"

class SatelliteCreator: public SpacecraftCreator{
public:
    /* @fn createSpacecraft()
     * @brief creates a new CargoDragonCreator
     * @return Spacecraft
     */
    Spacecraft* createSpacecraft();
};


#endif
