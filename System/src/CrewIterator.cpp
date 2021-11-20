#include "../include/Iterator.h"
#include "../include/CarryType.h"
#include "../include/CrewIterator.h"
#include "../include/Crew.h"
#include <iostream>

CrewIterator::CrewIterator(LinkedListOfCrew* list){
    this->list = list;
    index=0;
}

CarryType* CrewIterator::first(){
    return list->getHead();
}

CarryType* CrewIterator::next(){
	index++;
	return current();
}

CarryType* CrewIterator::current(){
    Crew* temp = list->getHead();
	for(int i=0;i<index-1;i++)
    temp = temp->next;
    return temp;
}

bool CrewIterator::isDone(){
    Crew* temp = list->getHead();

    for(int i=0;i<index;i++) {
        temp= temp->next;
    }

    if(temp == NULL) {
        return true;
    }

    return false;
}

CrewIterator::~CrewIterator() {
	delete list;
}
