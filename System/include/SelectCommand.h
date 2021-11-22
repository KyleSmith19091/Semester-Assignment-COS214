/****************************************************************************************************
 *  @file ./include/SelectCommand.h
 *  @brief The header file for the SelectCommand class.
 ***************************************************************************************************/

#ifndef SELECTCOMMAND_H
#define SELECTCOMMAND_H

#include "Command.h"
#include "SelectSimulation.h"
/****************************************************************************************************
 *  @class SelectCommand
 *  @brief The Concrete Command for the Command Design Pattern.
 ***************************************************************************************************/
class SelectCommand : public Command
{
    private:
        SelectSimulation* mySim; /**< The reciever to execute the command on. */

    public:
        /**
         *  @fn SelectCommand(SelectSimulation* s)
         *  @brief The constructor for the class.
         *  
         *  @param[in]  s   The simulation to be used in the command.
         */
        SelectCommand(SelectSimulation* s);

        /**
         *  @fn ~SelectCommand()
         *  @brief The destructor for the class.
         */
        ~SelectCommand();

        /**
         *  @fn virtual void execute(std::string s, std::vector<State*>* v) override
         *  @brief The implementation of the virtual execute method.
         *  
         *  @param[in]  s   String to determine which simulation to run based off the chain of responsibility.
         *  @param[in]  v   A pointer to the vector of states used to run the simulations.
         */
        virtual void execute(std::string s, std::vector<State*>* v);
};

#endif  //SELECTCOMMAND_H
