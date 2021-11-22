/****************************************************************************************************
 *  @file ./include/Dragon.h
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
         *  @brief Method to load the content of the dragon spacecraft.
         *  @return void
         */
        virtual void load(bool) =0;

        /**
         *  @fn unload()
         *  @brief Method to load the content of the dragon spacecraft.
         *  @return void
         */
        virtual void unload(bool) =0;

    private:
        Falcon* falconHeavy; /**< The Falcon which the Dragon will be using. */
};

#endif
