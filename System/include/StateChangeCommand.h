/****************************************************************************************************
 *  @file include/StateChangeCommand.h
 *  @brief The header file for the StateChangeCommand class.
 ***************************************************************************************************/

#ifndef STATECHANGECOMMAND_H
#define STATECHANGECOMMAND_H

#include "Command.h"
/****************************************************************************************************
 *  @class StateChangeCommand
 *  @brief Concrete Command for the Command Design Pattern.
 ***************************************************************************************************/
class StateChangeCommand : public Command
{
    private:
        Falcon* myFalcon; /**< The Falcon to be used as a reciever. */
    public:
        /**
         *  @fn StateChangeCommand()
         *  @brief The constructor for the class.
         *  @param[in] Falcon* The falcon to change the state of.
         */
        StateChangeCommand(Falcon* f);

        /**
         *  @fn ~StateChangeCommand()
         *  @brief The destructor for the class.
         */
        ~StateChangeCommand();

        /**
         *  @fn virtual void execute()
         *  @brief The implementation of the virtual execute method.
         *  
         *  @return void
         */
        virtual void execute();
};

#endif  //STATECHANGECOMMAND_H
