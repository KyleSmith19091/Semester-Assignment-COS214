/****************************************************************************************************
 *  @file CargoIterator.h
 *  @brief The header file for the CargoIterator class.
 ***************************************************************************************************/

#ifndef CARGOITERATOR_H
#define CARGOITERATOR_H

/****************************************************************************************************
 *  @class CargoIterator
 *  @brief "The base class of the cargo- and crew-list iterators (ConcreteIterator-Iterator)"
 ***************************************************************************************************/
#include "CarryType.h"
#include "Iterator.h"
#include "Cargo.h"
#include <vector>

using namespace std;

class CargoIterator :public Iterator{
    private:
        vector<Cargo*>* CargoList; /**< The vector of cargo to iterate over. */
        int index;
        /**
         *  @fn CargoIterator()
         *  @brief The default constuctor of the class specified as private such that it forces the use of the other constructor.
         */
        CargoIterator();
    
    public:

        /**
         *  @fn ~CargoIterator()
         *  @brief The destructor of the class.
         */
        ~CargoIterator();

        /**
         *  @fn CargoIterator(vector<Cargo*>& list)
         *  @brief The accepted constructor of the class.
         *  @param[in]  list    The vector of cargo that will be used.
         */
        CargoIterator(vector<Cargo*>& list);

        /**
         *  @fn first()
         *  @brief Gets the first element in the list/collection
         *  @return CarryType*
         */
        CarryType* first() override;

        /**
         *  @fn next()
         *  @brief Gets the next element in the list/collection
         *  @return CarryType*
         */
        CarryType* next() override;

        /**
         *  @fn current()
         *  @brief Gets the current element in the list/collection
         *  @return CarryType*
         */
        CarryType* current() override;

        /**
         *  @fn isDone()
         *  @brief Determines if there are more elements
         *  @return Boolean: true if the end of the list/collection is reached
         */
        bool isDone() override;
};

#endif
