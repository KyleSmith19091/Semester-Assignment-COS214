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
 *  @brief Concrete Command for the Command Design Pattern.
 ***************************************************************************************************/
class UnloadCommand : public Command
{
    private:
        Loader* myLoader; /**< The loader to be used as a reciever. */
    public:
        /**
         *  @fn UnloadCommand(Loader* l)
         *  @brief The constructor for the class.
         *  
         *  @param[in]  l   The loader to be used.
         */
        UnloadCommand(Loader* l);

        /**
         *  @fn ~UnloadCommand()
         *  @brief The destructor for the class.
         */
        ~UnloadCommand();

        /**
         *  @fn virtual void execute()
         *  @brief The implementation of the virtual execute method.
         *  
         *  @return void
         */
        virtual void execute();
};

#endif  //UNLOADCOMMAND_H
