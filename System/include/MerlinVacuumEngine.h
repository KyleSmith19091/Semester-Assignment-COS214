/****************************************************************************************************
 *  @file ./include/MerlinVacuumEngine
 *  @brief The header file for the MerlinVacuumEngine class.
 ***************************************************************************************************/

#ifndef MERLINVACUUMENGINE_H
#define MERLINVACUUMENGINE_H

/****************************************************************************************************
 *  @class MerlinVacuumEngine
 *  @brief ""
 ***************************************************************************************************/
#include <string>
#include "Engine.h"

using namespace std;
class MerlinVacuumEngine : public Engine {

public:
        /**
         *  @fn checkTemperature()
         *  @brief Check Temperature of Engine.
         *  @return void
         */
        void checkTemperature() override;

        /**
         *  @fn startEngine()
         *  @brief Completes the check up and finally start up the Engine.
         *  @return void
         */
        void startEngine() override;

        /**
         *  @fn checkOil()
         *  @brief Check Oil level in Engine.
         *  @return void
         */
        void checkOil() override;

        /**
         *  @fn clone()
         *  @brief clone an engine.
         *  @return Engine*
         */
        Engine* clone() override;

};	
#endif
