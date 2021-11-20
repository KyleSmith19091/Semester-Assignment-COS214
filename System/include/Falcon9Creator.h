/****************************************************************************************************
 *  @file ./include/FalconCreator.h
 *  @brief The header file for the FalconCreator class.
 ***************************************************************************************************/

#ifndef FALCON9CREATOR_H
#define FALCON9CREATOR_H

#include "SpacecraftCreator.h"
#include "Falcon.h"

class Falcon9Creator: public SpacecraftCreator {
public:

    /** @fn createSpacecraft()
     * @brief creates a new create Falcon-9.
     * @return Spacecraft*
     */
    Spacecraft* createSpacecraft() override;

};


#endif
