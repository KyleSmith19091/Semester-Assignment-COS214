/****************************************************************************************************
 *  @file Dragon.h
 *  @brief The header file for the Dragon.h class.
***************************************************************************************************/

#ifndef DRAGON_H
#define DRAGON_H

/****************************************************************************************************
 *  @class Dragon
 *  @brief "Interface for the dragon spacecraft"
 ***************************************************************************************************/

#include "Spacecraft.h"

class Dragon : public Spacecraft {
    protected:
        /**
         *  @fn load()
         *  @brief Template method to load the content of the dragon spacecraft.
         *  @return void
         */
        virtual void load() =0;
};

#endif
