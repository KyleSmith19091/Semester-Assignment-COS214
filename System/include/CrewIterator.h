/****************************************************************************************************
 *  @file ./include/CrewIterator.h
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
#include "LinkedListOfCrew.h"
#include <vector>

using namespace std;

class CrewIterator :public Iterator{
    private:
    LinkedListOfCrew* list; /**< The list of crew members to iterate over. */
    int index; /**< The index to determine the current place in the list. */

    public:

        /**
         *  @fn CrewIterator()
         *  @brief Constructor for this class
         *  @param[in] LinkedListOfCrew* list of crew members
         */
        CrewIterator(LinkedListOfCrew* list);

        /**
         *  @fn ~CrewIterator()
         *  @brief Destructor for this class
         */
        ~CrewIterator();

        /**
         *  @fn first()
         *  @brief Gets the first element in the list/collection
         *  @return CarryType* the first element in the list/collection
         */
        CarryType* first() override;

        /**
        *  @fn next()
        *  @brief Gets the next element in the list/collection
        *  @return CarryType* the next element in the list/collection
        */
        CarryType* next() override;

        /**
        *  @fn current()
       *  @brief Gets the current element in the list/collection
       *  @return CarryType* the current element in the list/collection
       */
        CarryType* current() override;

        /**
        *  @fn isDone()
        *  @brief Determines if there are more elements
        *  @return Boolean true if the end of the list/collection is reached
        */
        bool isDone() override;
};

#endif
