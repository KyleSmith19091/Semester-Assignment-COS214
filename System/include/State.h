/****************************************************************************************************
 *  @file ./include/State.h
 *  @brief The header file for the State class.
 ***************************************************************************************************/

#ifndef STATE_H
#define STATE_H

#include <string>

#include "Spacecraft.h"
/****************************************************************************************************
 *  @class State
 *  @brief The abstraction of the State of the simulation.
 ***************************************************************************************************/
class State
{
    private:
        std::string name;
        Spacecraft* vessel;
    public:
        /**
         *  @fn State()
         *  @brief The constructor for the class.
         */
        State(std::string n);

        /**
         *  @fn ~State()
         *  @brief The destructor for the class.
         */
        ~State();

        std::string getName();
};

#endif  //STATE_H
