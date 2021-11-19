#include "../include/Iterator.h"
#include "../include/LinkedListOfCrew.h"
#include "../include/Crew.h"
#include "../include/CrewIterator.h"
#include <iostream>

Iterator* LinkedListOfCrew::createIterator(){
    return new CrewIterator(this);

}

LinkedListOfCrew::LinkedListOfCrew(){
    head=NULL;
    size=0;
}

LinkedListOfCrew::~LinkedListOfCrew(){
  Crew* temp;
  for(int i=0;i<size;i++)
  {
     temp = head;
     head = head->next;
     delete temp;
  }  
}

void LinkedListOfCrew::removeCrewMember(Crew* member){
    if(member == head)
    {
        Crew* temp = head;
        head = head->next;
        delete temp;

        size--;
        return;
    }

    Crew* temp=head;
    Crew* prev;

    for(int i=0;i<size-1;i++)
    {
        if(temp == member)
        break;

        prev = temp;
        temp =temp->next;
    }
    prev->next = temp->next;
    size--;
}

void LinkedListOfCrew::addCrewMember(Crew* member){
    if(head == NULL)
    {
        head = member;
        size++;
        return;
    }
    Crew* temp=head;
    for(int i=0;i<size-1;i++)
        temp= temp->next;

    temp->next=member;
    size++;
}

int LinkedListOfCrew::getSize(){
    return size;
}

Crew* LinkedListOfCrew::getHead(){
    return head;
}