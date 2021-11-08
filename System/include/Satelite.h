/****************************************************************************************************
 *  @file Satelite.h
 *  @brief The header file for the Satelite class.
 ***************************************************************************************************/

#ifndef SATELITE_H
#define SATELITE_H

/****************************************************************************************************
 *  @class Satelite
 *  @brief "Starlink Satelite"
 ***************************************************************************************************/

#include "Spacecraft.h"

using namespace std;

class Satelite : public Spacecraft {
    public:
        /**
         *  @fn Satelite()
         *  @brief The constructor for the class.
         */
        Satelite();

        /**
         *  @fn ~Satelite()
         *  @brief Clone the Current Satelite
         *  @return Satelite* Cloned Satelite
         */
        Satelite* clone();
};

#endif
