/****************************************************************************************************
 *  @file include/Simulate.h
 *  @brief The header file for the Simulate class.
 ***************************************************************************************************/

#ifndef SIMULATE_H
#define SIMULATE_H

#include <iostream>

#include "Command.h"
/****************************************************************************************************
 *  @class Simulate
 *  @brief The invoker for the Command Design Pattern.
 ***************************************************************************************************/
class Simulate
{
    private:
        Command* buildCommand = 0;
        Command* selectCommand = 0;

    public:
        /**
         *  @fn Simulate()
         *  @brief The constructor for the class.
         */
        Simulate();

        /**
         *  @fn ~Simulate()
         *  @brief The destructor for the class.
         */
        ~Simulate();

        /**
         *  @fn void select()
         *  @brief The method to call selectCommand execute().
         */
        void select();

        /**
         *  @fn void build()
         *  @brief The method to call buildCommand execute().
         */
        void build();

        /**
         *  @fn void setSelect(Command* c)
         *  @brief The method to set the selectCommand.
         *  
         *  @param[in]  c   The command to work with.
         */
        void setSelect(Command* c);

        /**
         *  @fn void setBuild(Command* c)
         *  @brief The method to set the buildCommand.
         *  
         *  @param[in]  c   The command to work with.
         */
        void setBuild(Command* c);
};

#endif  //SIMULATE_H
