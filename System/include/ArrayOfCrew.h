/****************************************************************************************************
 *  @file ArrayListOfCrew.h
 *  @brief The header file for the ArrayListOfCrew class.
 ***************************************************************************************************/

#ifndef VECTOROFCARGO_H
#define VECTOROFCARGO_H

/****************************************************************************************************
 *  @class ArrayListOfCrew
 *  @brief "A class to contain a vector of Cargo (ConcreteAggregate-Iterator)"
 ***************************************************************************************************/
#include "../include/Collections.h"
#include "../include/Iterator.h"
#include "../include/Crew.h"
#include <map>
/////////////////////////////////////INVALID AT THE MOMENT
using namespace std;

class ArrayOfCrew :public Collections {
    private:
        map<int,Crew*> crewList;
        int size;

    public:

        /**
         *  @brief creates a CrewIterator element
         *  @return Iterator* a new instance of CrewIterator to iterate through CrewList
         */
        Iterator* createIterator();
        ArrayOfCrew();
        ~ArrayOfCrew();
        void removeCrewMember(Crew* member);
        void addCrewMember(Crew* member);
        int getSize();

};

#endif
