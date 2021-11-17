/****************************************************************************************************
 *  @file ./include/Returned.h
 *  @brief The header file for the Returned class.
 ***************************************************************************************************/

#ifndef RETURNED_H
#define RETURNED_H

#include "FalconState.h"

/****************************************************************************************************
 *  @class Returned
 *  @brief "Insert brief description here."
 ***************************************************************************************************/

class Returned : public FalconState {
    public:
        /**
         *  @fn ~Returned()
         *  @brief The destructor for the class.
         */
        ~Returned();

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

#endif  //RETURNED_H
