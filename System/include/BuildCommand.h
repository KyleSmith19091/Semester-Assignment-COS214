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
 *  @brief The Concrete Command for the Command Design Pattern.
 ***************************************************************************************************/
class BuildCommand : public Command
{
    private:
        BuildSimulation* mySim;

    public:
        /**
         *  @fn BuildCommand()
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
         *  @fn virtual void execute() override
         *  @brief The implementation of the pure virtual execute method.
         */
        virtual void execute(std::string s, std::vector<State*>* v);
};

#endif  //BUILDCOMMAND_H
