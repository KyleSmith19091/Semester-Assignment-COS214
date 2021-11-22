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

class State;
/****************************************************************************************************
 *  @class Command
 *  @brief The Command for the Command Design Pattern and the Handler for the Chain of Responsibility.
 ***************************************************************************************************/
class Command
{
    private:
        Command* next; /**< The next command in the chain. */
    public:
        /**
         *  @fn Command()
         *  @brief The constructor for the class.
         */
        Command();

        /**
         *  @fn virtual ~Command()
         *  @brief The virtual destructor for the class.
         */
        virtual ~Command();

        /**
         *  @fn virtual void execute()
         *  @brief The virtual execute method.
         */
        virtual void execute();

        /**
         *  @fn virtual void execute(std::string s, std::vector<State*>* v)
         *  @brief The overloaded virtual execute method used specifically for the chain of resposibility.
         *  
         *  @param[in]  s   String to determine which simulation to run based off the chain of responsibility.
         *  @param[in]  v   A pointer to the vector of states used to run the simulations.
         */
        virtual void execute(std::string s, std::vector<State*>* v);

        /**
         *  @fn void add(Command* c)
         *  @brief The virtual execute method.
         *  
         *  @param[in]  c   A pointer to the command to be added to the back of chain.
         */
        void add(Command* c);   
};

#endif  //COMMAND_H
