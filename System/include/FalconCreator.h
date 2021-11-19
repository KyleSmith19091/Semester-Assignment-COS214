/****************************************************************************************************
 *  @file ./include/FalconCreator.h
 *  @brief The header file for the FalconCreator class.
 ***************************************************************************************************/

#ifndef FALCONCREATOR_H
#define FALCONCREATOR_H

#include "Spacecraft.h"
#include "Falcon.h"

class FalconCreator: public Spacecraft{
public:
    /* @fn createSpacecraft()
     * @brief creates a new CargoDragonCreator
     * @return Spacecraft
     */
    Spacecraft* createSpacecraft();

};


#endif
