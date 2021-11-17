/****************************************************************************************************
 *  @file CrewIterator.h
 *  @brief The header file for the CrewIterator class.
 ***************************************************************************************************/

#ifndef CREWITERATOR_H
#define CREWITERATOR_H

/****************************************************************************************************
 *  @class CrewIterator
 *  @brief "The base class of the cargo- and crew-list iterators (ConcreteIterator-Iterator)"
 ***************************************************************************************************/
#include "CarryType.h"
#include "Iterator.h"
#include "Crew.h"
#include <vector>

using namespace std;
////////////////////////////////////////////////////INVALID AT THE MOMENT
class CrewIterator :public Iterator{
    private:
    Crew** crewList[4];
    int index;

    CrewIterator();
    public:

      
        ~CrewIterator();

        /**
         *  @brief Gets the first element in the list/collection
         *  @return CarryType* the first element in the list/collection
         */
        CrewIterator(Crew** list);

        /**
         *  @brief Gets the first element in the list/collection
         *  @return CarryType* the first element in the list/collection
         */
        CarryType* first() override;

        /**
        *  @brief Gets the next element in the list/collection
        *  @return CarryType* the next element in the list/collection
        */
        CarryType* next() override;

        /**
       *  @brief Gets the current element in the list/collection
       *  @return CarryType* the current element in the list/collection
       */
        CarryType* current() override;

        /**
        *  @brief Determines if there are more elements
        *  @return Boolean true if the end of the list/collection is reached
        */
        bool isDone() override;
};

#endif
