/****************************************************************************************************
 *  @file ./include/CarryType.h
 *  @brief "The header file for the base class CarryType"
 ***************************************************************************************************/

#ifndef CARRYTYPE_H
#define CARRYTYPE_H

/****************************************************************************************************
 *  @class CarryType
 *  @brief "A base class for Crew and Cargo"
 ***************************************************************************************************/
#include <string>

using namespace std;

class CarryType {
    public:
        /**
         *  @fn ~CarryType()
         *  @brief Destructor for this class.
         */
        virtual ~CarryType();

        /**
         *  @fn toString()
         *  @brief Returns a summary of the Carry type object.
         *  @return string
         */
    virtual string toString();
};

#endif
