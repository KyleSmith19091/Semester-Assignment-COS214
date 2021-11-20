/****************************************************************************************************
 *  @file ./include/Command.h
 *  @brief The header file for the Command class.
 ***************************************************************************************************/

#ifndef COMMAND_H
#define COMMAND_H

#include <vector>
#include <iostream>
#include <string>

#include "State.h"
/****************************************************************************************************
 *  @class Command
 *  @brief The Command for the Command Design Pattern.
 ***************************************************************************************************/
class Command
{
    private:
        Command* next;
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
         *  @fn virtual void execute()
         *  @brief The virtual execute method.
         */
        virtual void execute(std::string s, std::vector<State*>* v);

        void add(Command* c);
};

#endif  //COMMAND_H
