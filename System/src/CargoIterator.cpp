#include "../include/Iterator.h"
#include "../include/CarryType.h"
#include "../include/CargoIterator.h"
#include "../include/Cargo.h"
#include <iostream>

CargoIterator::CargoIterator(vector<Cargo*>& list){
	CargoList = &list;
	index = 0;
}

CarryType* CargoIterator::first(){
	return *(CargoList->begin());
}

CarryType* CargoIterator::next(){
	index++;
	return current();
}

CarryType* CargoIterator::current(){
	vector<Cargo*>::iterator it = CargoList->begin();

	for (int i = 1; i < index; i++)
		++it;

	return (*it);
}

bool CargoIterator::isDone(){
	if(index==CargoList->size())
	return true;

	return false;
}

CargoIterator::CargoIterator() {}

CargoIterator::~CargoIterator() {
	vector<Cargo*>::iterator it;

	for (it = CargoList->begin(); it != CargoList->end(); ++it)
		delete* it;

	delete CargoList;
}