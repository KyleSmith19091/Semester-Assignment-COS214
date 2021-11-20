/****************************************************************************************************
 *  @file ./include/Idle.h
 *  @brief The header file for the Idle class.
 ***************************************************************************************************/

#ifndef IDLE_H
#define IDLE_H

#include "FalconState.h"

/****************************************************************************************************
 *  @class Idle
 *  @brief "Idle Falcon State"
 ***************************************************************************************************/
class Idle : public FalconState {
    public:
        /**
         *  @fn ~Idle()
         *  @brief The destructor for the class.
         */
        ~Idle();

        /**
         *  @fn handleChange()
         *  @brief Handles a change in separation state.
         *  @param[in] Falcon* Context for the falcon changing state
         *  @return void
         */
        void handleChange(Falcon*) override;

        /**
         *  @fn getCurrentState()
         *  @brief Returns the current state name.
         *  @param[out] string String representing the name of the state
         *  @return string
         */
        std::string getCurrentState() override;
};

#endif  //IDLE_H
