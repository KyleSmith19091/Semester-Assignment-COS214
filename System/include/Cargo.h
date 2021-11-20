/****************************************************************************************************
 *  @file Cargo
 *  @brief The header file for the Cargo class.
 ***************************************************************************************************/

#ifndef CARGO_H 
#define CARGO_H

/****************************************************************************************************
 *  @class Cargo
 *  @brief "A class for storing info about the Cargo that spacecraft will transport"
 ***************************************************************************************************/
#include <string>
#include "CarryType.h"

using namespace std;
class Cargo : public CarryType {
private:
	string type;
	double weight;
public:

	/**
         *  @fn Cargo(string type,double weight)
         *  @brief The constructor of the class.
         */
	Cargo(string type, double weight);
	/**
         *  @fn getType()
         *  @brief Getter for the Cargo type attribute.
         *  @return string
         */
	string getType();
	/**
         *  @fn getWeight()
         *  @brief Getter for the Cargo weight attribute.
         *  @return double
         */
	double getWeight();
	/**
         *  @fn setWeight()
         *  @brief Setter for the Cargo weight attribute.
         *  @return void
         */
	void setWeight(double d);
	/**
         *  @fn setType()
         *  @brief Setter for the Cargo type attribute.
         *  @return void
         */
	void setType(string s);
	/**
         *  @fn toString()
         *  @brief Returns a summary of the Cargo attributes.
         *  @return string
         */
	string toString() override;

};	
#endif
