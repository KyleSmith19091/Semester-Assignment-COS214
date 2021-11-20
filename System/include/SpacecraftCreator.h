#ifndef SPACECRAFTCREATOR_H
#define SPACECRAFTCREATOR_H

#include "Spacecraft.h"

class SpacecraftCreator {
public:
    /* @fn createSpacecraft()
     * @brief interface method for creating a spacecraft
     * @return newly created Spacecraft
     */
    virtual Spacecraft* createSpacecraft() =0;
};


#endif
