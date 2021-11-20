/****************************************************************************************************
 *  @file ./include/SpacecraftCreator.h
 *  @brief The header file for the SpacecraftCreator class.
 ***************************************************************************************************/

#ifndef SPACECRAFTCREATOR_H
#define SPACECRAFTCREATOR_H

/****************************************************************************************************
 *  @class SpacecraftCreator
 *  @brief "Interface for the creation of spacecraft"
 ***************************************************************************************************/

#include "Spacecraft.h"

class SpacecraftCreator {
public:

    /**
     * @fn createSpacecraft()
     * @brief interface method for creating a spacecraft
     * @return newly created Spacecraft
     */
    virtual Spacecraft* createSpacecraft() =0;
};


#endif
