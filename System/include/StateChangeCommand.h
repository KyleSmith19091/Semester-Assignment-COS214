/****************************************************************************************************
 *  @file include/StateChangeCommand.h
 *  @brief The header file for the StateChangeCommand class.
 ***************************************************************************************************/

#ifndef STATECHANGECOMMAND_H
#define STATECHANGECOMMAND_H

#include "Command.h"
/****************************************************************************************************
 *  @class StateChangeCommand
 *  @brief "Insert brief description here."
 ***************************************************************************************************/
class StateChangeCommand : public Command
{
    private:
        Falcon* myFalcon;
    public:
        /**
         *  @fn StateChangeCommand()
         *  @brief The constructor for the class.
         */
        StateChangeCommand(Falcon* f);

        /**
         *  @fn ~StateChangeCommand()
         *  @brief The destructor for the class.
         */
        ~StateChangeCommand();

        virtual void execute();
};

#endif  //STATECHANGECOMMAND_H
