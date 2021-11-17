/****************************************************************************************************
 *  @file ./include/Launched.h
 *  @brief The header file for the Launched class.
 ***************************************************************************************************/

#ifndef LAUNCHED_H
#define LAUNCHED_H

#include "FalconState.h"

/****************************************************************************************************
 *  @class Launched
 *  @brief "Insert brief description here."
 ***************************************************************************************************/

class Launched : public FalconState {
    public:
        /**
         *  @fn ~Launched()
         *  @brief The destructor for the class.
         */
        ~Launched();

        void handleChange(Falcon*) override;
        std::string getCurrentState() override;

};

#endif  //LAUNCHED_H
