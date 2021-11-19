#ifndef SPACECRAFTCREATOR_H
#define SPACECRAFTCREATOR_H

#include "Spacecraft.h"

class SpacecraftCreator {
protected:
    virtual Spacecraft* createSpacecraft() =0;
};


#endif
