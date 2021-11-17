#include "../include/Iterator.h"
#include "../include/VectorOfCargo.h"
#include "../include/Cargo.h"
#include "../include/CargoIterator.h"
#include <iostream>

void VectorOfCargo::addCargo(Cargo* cargo) {
	CargoList.push_back(cargo);
}

Iterator* VectorOfCargo::createIterator() {
	return new CargoIterator(CargoList);
}

void VectorOfCargo::removeCargo(Cargo* cargo) {
	vector<Cargo*>::iterator ptr;

	for (ptr = CargoList.begin(); ptr < CargoList.end(); ptr++)
	{
		if ((*ptr) == cargo)
			CargoList.erase(ptr);

	}
}

VectorOfCargo::~VectorOfCargo() {
	vector<Cargo*>::iterator it;

	for (it = CargoList.begin(); it != CargoList.end(); ++it)
		delete* it;
}
