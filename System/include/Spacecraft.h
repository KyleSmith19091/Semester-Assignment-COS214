/****************************************************************************************************
 *  @file Spacecraft.h
 *  @brief The header file for the Spacecraft class.
 ***************************************************************************************************/

#ifndef SPACECRAFT_H
#define SPACECRAFT_H

/****************************************************************************************************
 *  @class Spacecraft
 *  @brief "Interface for all spacecraft"
 ***************************************************************************************************/

#include <string>

using namespace std;

class Spacecraft {
    private:
        string type;
    public:
        /**
         *  @fn Spacecraft()
         *  @brief The constructor for the class.
         *  @param[in] string  Spacecraft type
         */
        Spacecraft(string);

        /**
         *  @fn Spacecraft()
         *  @brief The constructor for the class.
         *  @return string Spacecraft type
         */
        string getType() const;
};

#endif
