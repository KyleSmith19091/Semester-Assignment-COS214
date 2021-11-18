/****************************************************************************************************
 *  @file include/SelectCommand.h
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
        SelectSimulation* mySim;

    public:
        /**
         *  @fn SelectCommand()
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
         *  @fn virtual void execute() override
         *  @brief The implementation of the pure virtual execute method.
         */
        virtual std::vector<State*> execute() override;
};

#endif  //SELECTCOMMAND_H
