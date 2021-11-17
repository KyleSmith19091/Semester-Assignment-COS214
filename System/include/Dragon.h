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
#include "Falcon.h"

#include <fstream>

class Dragon : public Spacecraft {
    public: 
        /**
         *  @fn ~Dragon()
         *  @brief The destructor for the class.
         */
        Dragon(Falcon*);

        /**
         *  @fn Dragon()
         *  @brief The destructor for the class.
         */
        virtual ~Dragon();

        /**
         *  @fn load()
         *  @brief Template method to load the content of the dragon spacecraft.
         *  @return void
         */
        virtual void load() =0;

    private:
        Falcon* falconHeavy;
};

#endif
