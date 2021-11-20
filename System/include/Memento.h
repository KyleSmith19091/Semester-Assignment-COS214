/****************************************************************************************************
 *  @file inc/Memento.h
 *  @brief The header file for the Memento class.
 ***************************************************************************************************/

#ifndef MEMENTO_H
#define MEMENTO_H

#include "State.h"
/****************************************************************************************************
 *  @class Memento
 *  @brief "Insert brief description here."
 ***************************************************************************************************/
class Memento
{
    private:
        State* state;
    public:
        /**
         *  @fn Memento()
         *  @brief The constructor for the class.
         */
        Memento();

        /**
         *  @fn ~Memento()
         *  @brief The destructor for the class.
         */
        ~Memento();

        /**
         *  @fn getState()
         *  @brief Get state attribute.
         *  @return State* state attribute
         */
        State* getState();

        /**
         *  @fn setState()
         *  @brief The destructor for the class.
         *  @param[in] State* reference to state that will be set
         *  @return void
         */
        void setState(State* s);
};

#endif  //MEMENTO_H
