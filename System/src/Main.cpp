#include "../include/SelectSimulation.h"
#include "../include/Cargo.h"
#include "../include/VectorOfCargo.h"
#include "../include/CargoIterator.h"
#include "../include/CarryType.h"
#include <iostream>

int main() {
	//////////////////////////////////////////////////////////////// Iterator
	Cargo* c1 = new Cargo("one",0.3);
	Cargo* c2 = new Cargo("two",2.1);
	Cargo* c3 = new Cargo("three",5.7);

	VectorOfCargo cargoList;
	cargoList.addCargo(c1);
	cargoList.addCargo(c2);
	cargoList.addCargo(c3);

	Iterator* CI = cargoList.createIterator();

	cargoList.removeCargo(c2);

	while (!CI->isDone())
	{
		cout<<CI->next()->toString()<<endl;
		
	}

	////////////////////////////////////////////////////////////////

	SelectSimulation* select = new SelectSimulation();

	select->startSim();

	delete select;

	return 0;
}
