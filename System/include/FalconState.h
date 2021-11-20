/***************************************************************************************************
 *  @file ./include/FalconState.h
 *  @brief The header file for the FalconState class.
 ***************************************************************************************************/

#ifndef FALCONSTATE_H
#define FALCONSTATE_H

#include <string>

class Falcon;

/****************************************************************************************************
 *  @class FalconState
 *  @brief "Interface for the current Falcon separation state"
 ***************************************************************************************************/
class FalconState {
    public:
        /**
         *  @fn ~FalconState()
         *  @brief The destructor for the class.
         */
        virtual ~FalconState();

        /**
         *  @fn handleChange()
         *  @brief Handles a change in separation state.
         *  @param[in] Falcon* Context for the falcon changing state
         *  @return void
         */
        virtual void handleChange(Falcon*) =0;

        /**
         *  @fn getCurrentState()
         *  @brief Returns the current state name.
         *  @param[out] string String representing the name of the state
         *  @return string
         */
        virtual std::string getCurrentState() =0;
};

#include "Falcon.h"

#endif  //FALCONSTATE_H
