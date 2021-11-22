/****************************************************************************************************
 *  @file CheckEngineCommandH
 *  @brief The header file for the CheckEngineCommand class.
 ***************************************************************************************************/

#ifndef CheckEngineCommandUp_H
#define CheckEngineCommandUp_H

#include <vector>

#include "Command.h"
#include "Engine.h"
#include "MerlinCore.h"
#include "MerlinVacuumEngine.h"
/****************************************************************************************************
 *  @class CheckEngineCommand
 *  @brief Concrete Command for checking the engines.
 ***************************************************************************************************/
class CheckEngineCommand : public Command
{
    private:
        std::vector<MerlinCore*> myCores; /**< The vector of Merlin Cores to be used as recievers. */
        MerlinVacuumEngine* vacuumEng; /**< The Merlin Vacuum Engine to be used as a reciever. */
    public:
        /**
         *  @fn CheckEngineCommand()
         *  @brief The constructor for the class.
         *  
         *  @param[in]  v   The vector of Merlin Cores to be used.
         *  @param[in]  mv  The Merlin Vacuum Engine to be used.
         */
        CheckEngineCommand(std::vector<MerlinCore*> v, MerlinVacuumEngine* mv);

        /**
         *  @fn ~CheckEngineCommand()
         *  @brief The destructor for the class.
         */
        ~CheckEngineCommand();

        /**
         *  @fn virtual void execute()
         *  @brief The implementation of the virtual execute method.
         *  
         *  @return void
         */
        virtual void execute();
};

#endif  //CheckEngineCommand_H