/****************************************************************************************************
 *  @file ./include/BuildCommand.h
 *  @brief The header file for the BuildCommand class.
 ***************************************************************************************************/

#ifndef BUILDCOMMAND_H
#define BUILDCOMMAND_H

#include "Command.h"
#include "BuildSimulation.h"
/****************************************************************************************************
 *  @class BuildCommand
 *  @brief The Concrete Command for the Command Design Pattern and the Conrete Handler for the Chain of Responsibility.
 ***************************************************************************************************/
class BuildCommand : public Command
{
    private:
        BuildSimulation* mySim; /**< The reciever to execute the command on. */

    public:
        /**
         *  @fn BuildCommand(BuildSimulation* s)
         *  @brief The constructor for the class.
         *  
         *  @param[in]  s   The simulation to be used in the command.
         */
        BuildCommand(BuildSimulation* s);

        /**
         *  @fn ~BuildCommand()
         *  @brief The destructor for the class.
         */
        ~BuildCommand();

        /**
         *  @fn virtual void execute(std::string s, std::vector<State*>* v)
         *  @brief The implementation of the virtual execute method.
         *  
         *  @param[in]  s   String to determine which simulation to run based off the chain of responsibility.
         *  @param[in]  v   A pointer to the vector of states used to run the simulations.
         *  
         *  @return void
         */
        virtual void execute(std::string s, std::vector<State*>* v);
};

#endif  //BUILDCOMMAND_H
