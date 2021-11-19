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
#include <ctime>

#include "Spacecraft.h"
#include "KeplerianCoords.h"

class MissionControl;

using namespace std;

class Satelite : public Spacecraft {
    private:
        MissionControl* missionControl;
        KeplerianCoords* coords;

    public:
        /**
         *  @fn Satelite()
         *  @brief The constructor for the class.
         */
        Satelite();

        /**
         *  @fn Satelite(const Satelite&)
         *  @brief The copy constructor for the class.
         */
        Satelite(const Satelite&);

        /**
         *  @fn ~Satelite()
         *  @brief The destructor for the class.
         */
        ~Satelite();

        /**
         *  @fn clone()
         *  @brief Clone the Current Satelite
         *  @return Satelite* Cloned Satelite
         */
        Satelite* clone();

        /**
         *  @fn positionSelf()
         *  @brief Position self in the Satellite cluster
         *  @return void
         */
        void positionSelf();

        /**
         *  @fn sendGroundSignal()
         *  @brief Send signal to mission control
         *  @return void
         */
        void sendGroundSignal();

        /**
         *  @fn sendSatelliteSignal()
         *  @brief Send laser signal to fellow satellite
         *  @return void
         */
        void sendSatelliteSignal(Satelite*);

        /**
         *  @fn setMissionControl(MissionControl*)
         *  @brief Set reference to mission control to which radio signals are sent
         *  @return void
         */
        void setMissionControl(MissionControl*);

        /**
         *  @fn getCoords()
         *  @brief Return the Keplerian coordinates of the current satellite
         *  @return KeplerianCoords* pointer to the coordinates object
         */
        KeplerianCoords* getCoords() const;
};

#include "MissionControl.h"

#endif
