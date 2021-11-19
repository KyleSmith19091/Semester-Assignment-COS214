/****************************************************************************************************
 *  @file MerlinEngine
 *  @brief The header file for the MerlinEngine class.
 ***************************************************************************************************/

#ifndef MERLINENGINE_H
#define MERLINENGINE_H

/****************************************************************************************************
 *  @class MerlinEngine
 *  @brief ""
 ***************************************************************************************************/
#include <string>
#include "Engine.h"

using namespace std;
class MerlinEngine : public Engine {

public:
/**
         *  @fn checkTemp()
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

};	
#endif
