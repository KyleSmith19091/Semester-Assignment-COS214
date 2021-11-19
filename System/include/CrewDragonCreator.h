/****************************************************************************************************
 *  @file CrewDragonCreator.h
 *  @brief The header file for the CrewDragonCreator class.
 ***************************************************************************************************/

#ifndef CREWDRAGONCREATOR_H
#define CREWDRAGONCREATOR_H

#include "SpacecraftCreator.h"
#include "CrewDragon.h"

class CrewDragonCreator: public SpacecraftCreator{
public:
    /* @fn createSpacecraft()
     * @brief creates a new CargoDragonCreator
     * @return Spacecraft
     */
    Spacecraft* createSpacecraft();

};


#endif
