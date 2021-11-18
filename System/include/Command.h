/****************************************************************************************************
 *  @file include/Command.h
 *  @brief The header file for the Command class.
 ***************************************************************************************************/

#ifndef COMMAND_H
#define COMMAND_H

#include <vector>
#include "State.h"

/****************************************************************************************************
 *  @class Command
 *  @brief The Command for the Command Design Pattern.
 ***************************************************************************************************/
class Command
{
    public:
        /**
         *  @fn Command()
         *  @brief The constructor for the class.
         */
        Command();

        /**
         *  @fn virtual ~Command()
         *  @brief The destructor for the class.
         */
        virtual ~Command();

        /**
         *  @fn virtual void execute() = 0
         *  @brief The pure virtual execute method.
         */
        virtual std::vector<State*> execute() = 0;
};

#endif  //COMMAND_H
