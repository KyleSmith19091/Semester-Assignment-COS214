/****************************************************************************************************
 *  @file ./include/VectorOfCargo.h
 *  @brief The header file for the VectorOfCargo class.
 ***************************************************************************************************/

#ifndef VECTOROFCARGO_H
#define VECTOROFCARGO_H

/****************************************************************************************************
 *  @class VectorOfCargo
 *  @brief "A class to contain a vector of Cargo (ConcreteAggregate-Iterator)"
 ***************************************************************************************************/
#include "Collections.h"
#include "Iterator.h"
#include "Cargo.h"
#include <vector>

using namespace std;

class VectorOfCargo :public Collections {
    private:
        vector<Cargo*> CargoList; /**< The vector of cargo to be used. */

    public:

        /**
         *  @fn createIterator())
         *  @brief Creates a new instance of CargoIterator for the iteration through CargoList
         *  @return Iterator*
         */
        Iterator* createIterator();
        /**
         *  @fn ~VectorOfCargo()
         *  @brief The destructor of the class
         */
        ~VectorOfCargo();
        /**
         *  @fn removeCargo(Cargo* cargo)
         *  @brief Removes the specified cargo item from the list/collection/vector
         *  @param[in] Cargo* The specific cargo to be removed from the vector.
         *  @return void
         */
        void removeCargo(Cargo* cargo);
        /**
         *  @fn addCargo()
         *  @brief Adds the specified cargo item to the list/collection/vector
         *  @param[in] Cargo* The cargo to add to the vector.
         *  @return void
         */
        void addCargo(Cargo* cargo);

};

#endif
