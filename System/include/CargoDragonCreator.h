/****************************************************************************************************
 *  @file ./include/CargoDragonCreator.h
 *  @brief The header file for the CargoDragonCreator class.
 ***************************************************************************************************/

#ifndef CARGODRAGONCREATOR_H
#define CARGODRAGONCREATOR_H

#include "SpacecraftCreator.h"
#include "CargoDragon.h"

class CargoDragonCreator: public SpacecraftCreator{
public:
    /* @fn createSpacecraft()
     * @brief creates a new CargoDragonCreator
     * @return Spacecraft
     */
    Spacecraft* createSpacecraft();

};


#endif
