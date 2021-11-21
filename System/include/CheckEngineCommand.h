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
        std::vector<MerlinCore*> myCores;
        MerlinVacuumEngine* vacuumEng;
    public:
        /**
         *  @fn CheckEngineCommand()
         *  @brief The constructor for the class.
         */
        CheckEngineCommand(std::vector<MerlinCore*> v, MerlinVacuumEngine* mv);

        /**
         *  @fn ~CheckEngineCommand()
         *  @brief The destructor for the class.
         */
        ~CheckEngineCommand();

        virtual void execute();
};

#endif  //CheckEngineCommand_H