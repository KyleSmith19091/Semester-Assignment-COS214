#include "../include/SelectSimulation.h"
#include "../include/Cargo.h"
#include "../include/VectorOfCargo.h"
#include "../include/CargoIterator.h"
#include "../include/CarryType.h"
#include "../include/Simulate.h"
#include "../include/SelectCommand.h"
#include <iostream>

void commandTest();

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

	delete CI;

	////////////////////////////////////////////////////////////////

	SelectSimulation* select = new SelectSimulation();

	select->startSim();

	delete select;

	/////////////////////////////////////////////////////////////// Command Implementation

	commandTest();

	/////////////////////////////////////////////////////////////// End of Command Implementation

	return 0;
}

void commandTest() {
	Simulate* sim = new Simulate();
	SelectSimulation* select = new SelectSimulation();
	SelectCommand* sCom = new SelectCommand(select);
	
	sim->setSelect(sCom);
	sim->select();

	delete sim;
	delete sCom;
	delete select;
}