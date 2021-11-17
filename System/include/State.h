/****************************************************************************************************
 *  @file inc/State.h
 *  @brief The header file for the State class.
 ***************************************************************************************************/

#ifndef STATE_H
#define STATE_H

#include <string>
/****************************************************************************************************
 *  @class State
 *  @brief "Insert brief description here."
 ***************************************************************************************************/
class State
{
    private:
        std::string name;
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
