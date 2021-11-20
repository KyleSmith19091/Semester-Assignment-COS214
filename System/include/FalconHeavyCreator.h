/****************************************************************************************************
 *  @file ./include/FalconHeavyCreator.h
 *  @brief The header file for the FalconHeavyCreator class.
 ***************************************************************************************************/

#ifndef FALCONHEAVYCREATOR_H
#define FALCONHEAVYCREATOR_H

#include "SpacecraftCreator.h"
#include "Falcon.h"

class FalconHeavyCreator: public SpacecraftCreator {
public:
    /** @fn createSpacecraft()
     * @brief creates a new Falcon-Heavy.
     * @return Spacecraft*
     */
    Spacecraft* createSpacecraft() override;

};


#endif
