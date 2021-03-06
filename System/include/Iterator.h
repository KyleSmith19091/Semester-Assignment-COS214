/****************************************************************************************************
 *  @file ./include/Iterator.h
 *  @brief The header file for the Iterator class.
 ***************************************************************************************************/

#ifndef ITERATOR_H
#define ITERATOR_H

/****************************************************************************************************
 *  @class Iterator
 *  @brief "The base class of the cargo- and crew-list iterators (Iterator-Iterator)"
 ***************************************************************************************************/
#include "CarryType.h"
using namespace std;

class Iterator {
    public:

        /**
         *  @fn first()
         *  @brief Gets the first element in the list/collection
         *  @return CarryType*
         */
        virtual CarryType* first();

        /**
        * @fn next()
        *  @brief Gets the next element in the list/collection
        *  @return CarryType*
        */
        virtual CarryType* next();

        /**
       * @fn current()
       *  @brief Gets the current element in the list/collection
       *  @return CarryType*
       */
        virtual CarryType* current();

        /**
        * @fn isDone()
        *  @brief Determines if there are more elements
        *  @return Boolean: true if the end of the list/collection is reached
        */
        virtual bool isDone();
};

#endif
