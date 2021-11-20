/****************************************************************************************************
 *  @file ./include/Falcon.h
 *  @brief The header file for the Falcon class.
 ***************************************************************************************************/

#ifndef FALCON_H 
#define FALCON_H

/****************************************************************************************************
 *  @class Falcon
 *  @brief "Falcon Rocket"
 ***************************************************************************************************/

#include "Spacecraft.h"
#include "MerlinCore.h"

#include <vector>

using namespace std;

class FalconState;

class Falcon : public Spacecraft {
    private:
        vector<MerlinCore*> coreList;
        FalconState* launchState;

    public:
        /**
         *  @fn Falcon()
         *  @brief The constructor for the class.
         *  @param[in] std::string Type of falcon
         */
        Falcon(std::string);

        /**
         *  @fn ~Falcon()
         *  @brief The destructor for the class.
         */
        ~Falcon();

        /**
         *  @fn getCurrentState()
         *  @brief Get current launch state.
         *  @return string
         */
        string getCurrentState() const;

        /**
         *  @fn change()
         *  @brief Change launch state.
         *  @return void
         */
        void change();

        /**
         *  @fn setState()
         *  @brief Set launch state.
         *  @param[in] FalconState* Falcon Launch State 
         *  @return void
         */
        void setState(FalconState*);
};	

#include "FalconState.h"

#endif
