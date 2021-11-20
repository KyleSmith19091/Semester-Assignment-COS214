/****************************************************************************************************
 *  @file inc/State.h
 *  @brief The header file for the State class.
 ***************************************************************************************************/

#ifndef STATE_H
#define STATE_H

#include <string>

#include "Spacecraft.h"
#include "Cluster.h"
/****************************************************************************************************
 *  @class State
 *  @brief The abstraction of the State of the simulation.
 ***************************************************************************************************/
class State
{
    private:
        std::string name;
        Spacecraft* vessel;
        Cluster* satellites;

    public:
        /**
         *  @fn State()
         *  @brief The constructor for the class.
         */
        State(std::string n, Spacecraft* s);

        /**
         *  @fn State()
         *  @brief The constructor for the class.
         */
        State(std::string n, Cluster* c);

        /**
         *  @fn ~State()
         *  @brief The destructor for the class.
         */
        ~State();

        std::string getName();

        Spacecraft* getVessel();

        Cluster* getCluster();
};

#endif  //STATE_H
