/****************************************************************************************************
 *  @file ./include/Crew
 *  @brief The header file for the Crew class.
 ***************************************************************************************************/

#ifndef CREW_H 
#define CREW_H

/****************************************************************************************************
 *  @class Crew
 *  @brief "A class for storing info about the Crew members that will be boarding the spacecraft"
 ***************************************************************************************************/
#include <string>
#include "CarryType.h"

using namespace std;
class Crew : public CarryType {
private:
	string name; /**< The name of the crew member. */
	string jobTitle; /**< The job of the crew member. */
public:

    Crew* next; /**< The next crew member in the list. */

	/**
     *  @fn Crew(string name, string jobTitle)
     *  @brief The constructor of the class.
     *  @param[in] name The name of the crew member.
     *  @param[in] jobTitle The job of the crew member.
     */
	Crew(string name, string jobTitle);

	/**
    *  @fn ~Crew()
    *  @brief The destructor of the class.
    */
    ~Crew(); 

	/**
     *  @fn getName()
     *  @brief Getter for the Crew member's name.
     *  @return string
     */
	string getName();
	/**
     *  @fn getJobTitle()
     *  @brief Getter for the Crew member's job title.
     *  @return string
     */
	string getJobTitle();
	/**
     *  @fn toString()
     *  @brief Returns a summary of the Crew member's information.
     *  @return string
     */
	string toString() override;

};	
#endif
