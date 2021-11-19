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

#include <string>
#include <thread>
#include <chrono>
#include <cmath>
#include <unistd.h>
#include <iostream>

#include "Spacecraft.h"

using namespace std;

class Satelite : public Spacecraft {
    private:
        int id;

    public:
        /**
         *  @fn Satelite()
         *  @brief The constructor for the class.
         */
        Satelite(int);

        /**
         *  @fn Satelite(const Satelite&)
         *  @brief The copy constructor for the class.
         */
        Satelite(const Satelite&);

        /**
         *  @fn ~Satelite()
         *  @brief Clone the Current Satelite
         *  @return Satelite* Cloned Satelite
         */
        Satelite* clone();

        void positionSelf();
};

#endif
