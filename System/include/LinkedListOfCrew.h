/****************************************************************************************************
 *  @file ./include/LinkedListOfCrew.h
 *  @brief The header file for the LinkedListOfCrew class.
 ***************************************************************************************************/

#ifndef LINKEDLISTOFCREW_H
#define LINKEDLISTOFCREW_H

/****************************************************************************************************
 *  @class LinkedListOfCrew
 *  @brief "A class to contain a linked list of Crew (ConcreteAggregate-Iterator)"
 ***************************************************************************************************/
#include "../include/Collections.h"
#include "../include/Iterator.h"
#include "../include/Crew.h"

using namespace std;

class LinkedListOfCrew :public Collections {
    private:
        Crew* head; /**< The start of the list of crew. */
        int size; /**< The size of the list of crew. */

    public:

        /**
         *  @fn createIterator()
         *  @brief creates a CrewIterator element
         *  @return Iterator* a new instance of CrewIterator to iterate through CrewList
         */
        Iterator* createIterator();
        /**
         *  @fn LinkedListOfCrew()
         *  @brief The constructor of the class
         */
        LinkedListOfCrew();
        /**
         *  @fn ~LinkedListOfCrew()
         *  @brief The destructor of the class
         */
        ~LinkedListOfCrew();
        /**
         *  @fn removeCrewMember(Crew* member)
         *  @brief Removes the specified crew item from the list/collection/vector
         *  @param[in] Crew* Crew Member to be removed to the list
         *  @return void
         */
        void removeCrewMember(Crew* member);
         /**
         *  @fn addCrewMember(Crew* member)
         *  @brief Adds the specified crew item to the list/collection/vector
         *  @param[in] Crew* Crew Member to be added to the list
         *  @return void
         */
        void addCrewMember(Crew* member);
        /**
         *  @fn getSize()
         *  @brief Returns the size of the linked list
         *  @return int
         */
        int getSize();
        /**
         *  @fn getHead()
         *  @brief Returns the head of the linked list
         *  @return Crew*
         */
        Crew* getHead(); 

};

#endif
