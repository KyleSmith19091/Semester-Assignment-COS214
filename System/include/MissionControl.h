/****************************************************************************************************
 *  @file ./include/MissionControl.h
 *  @brief The header file for the MissionControl class.
 ***************************************************************************************************/

#ifndef MISSIONCONTROL_H
#define MISSIONCONTROL_H

#include <string>
#include <iostream>

class Satelite;

/****************************************************************************************************
 *  @class MissionControl
 *  @brief "MissionControl for controlling rockets and other spacecraft"
 ***************************************************************************************************/
class MissionControl
{
    public:
        /**
         *  @fn MissionControl()
         *  @brief The constructor for the class.
         */
        MissionControl();

        /**
         *  @fn ~MissionControl()
         *  @brief The destructor for the class.
         */
        ~MissionControl();

        /**
         *  @fn receiveRadioSignal()
         *  @brief The destructor for the class.
         *  @param[in] int satelliteID
         *  @param[in] std::string Satellite Keplerian Coordinates
         *  @return void
         */
        void receiveRadioSignal(int, std::string);

        void sendRepositionRequest(Satelite*);
    
};

#include "Satelite.h"

#endif  //MISSIONCONTROL_H
