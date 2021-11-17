/****************************************************************************************************
 *  @file ./include/Seperated.h
 *  @brief The header file for the Seperated class.
 ***************************************************************************************************/

#ifndef SEPERATED_H
#define SEPERATED_H

#include "FalconState.h"

/****************************************************************************************************
 *  @class Seperated
 *  @brief "Insert brief description here."
 ***************************************************************************************************/

class Seperated : public FalconState {
    public:
        /**
         *  @fn ~Seperated()
         *  @brief The destructor for the class.
         */
        ~Seperated();

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

#endif  //SEPERATED_H
