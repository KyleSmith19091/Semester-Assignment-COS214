/****************************************************************************************************
 *  @file include/UnloadCommand.h
 *  @brief The header file for the UnloadCommand class.
 ***************************************************************************************************/

#ifndef UNLOADCOMMAND_H
#define UNLOADCOMMAND_H

#include "Command.h"
#include "Loader.h"
/****************************************************************************************************
 *  @class UnloadCommand
 *  @brief "Insert brief description here."
 ***************************************************************************************************/
class UnloadCommand : public Command
{
    private:
        Loader* myLoader;
    public:
        /**
         *  @fn UnloadCommand()
         *  @brief The constructor for the class.
         */
        UnloadCommand(Loader* l);

        /**
         *  @fn ~UnloadCommand()
         *  @brief The destructor for the class.
         */
        ~UnloadCommand();

        virtual void execute();
};

#endif  //UNLOADCOMMAND_H
