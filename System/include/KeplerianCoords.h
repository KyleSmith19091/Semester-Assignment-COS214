/****************************************************************************************************
 *  @file ./include/KeplerianCoords.h
 *  @brief The header file for the KeplerianCoords class.
 ***************************************************************************************************/

#ifndef KEPLERIANCOORDS_H
#define KEPLERIANCOORDS_H

#include <string>

/****************************************************************************************************
 *  @class KeplerianCoords
 *  @brief "Class for encoding Keplerian Coordinates for Satellites"
 ***************************************************************************************************/

class KeplerianCoords {
    public:
        /**
         *  @fn KeplerianCoords()
         *  @brief The constructor for the class.
         */
        KeplerianCoords();

        /**
         *  @fn KeplerianCoords()
         *  @param[in] int angle between equator and orbit plane
         *  @param[in] semiMajorAxis
         *  @param[in] trueAnomaly
         *  @param[in] rightAscension
         *  @param[in] argumentOfPerigree
         *  @brief The constructor for the class.
         */
        KeplerianCoords(int,int,int,int,int);

        /**
         *  @fn ~KeplerianCoords()
         *  @brief The destructor for the class.
         */
        ~KeplerianCoords();

        /**
         *  @fn toString()
         *  @brief Serialises the attributes of the class.
         */
        std::string toString() const;

        /**
         *  @fn randomiseCoords()
         *  @brief Randomises the values of attributes.
         */
        void randomiseCoords();

        /**
         *  @fn randomiseCoords()
         *  @brief Used in determining intersection of coords.
         */
        bool operator<(const KeplerianCoords&);

    private:
        int angle; // angle between equator and orbit plane
        int semiMajorAxis; // meters => size of the orbit
        int trueAnomaly; // degrees => the angle between perigee and the vehicle (in the orbit plane)
        int rightAscension; // degrees => the angle between vernal equinox and the point where the orbit crosses the equatorial plane (going north)
        int argumentOfPerigree; // degrees => the angle between the ascending node and the orbit's point of closest approach to the earth (perigee)
        const int eccentricty = 1;

};

#endif  //KEPLERIANCOORDS_H
