/****************************************************************************************************
 *  @file ./include/Launched.h
 *  @brief The header file for the Launched class.
 ***************************************************************************************************/

#ifndef LAUNCHED_H
#define LAUNCHED_H

#include "FalconState.h"

/****************************************************************************************************
 *  @class Launched
 *  @brief "Launched Falcon State"
 ***************************************************************************************************/

class Launched : public FalconState {
    public:
        /**
         *  @fn ~Launched()
         *  @brief The destructor for the class.
         */
        ~Launched();

        /**
         *  @fn handleChange()
         *  @brief Handles a change in seperation state.
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

#endif  //LAUNCHED_H
