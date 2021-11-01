#include "../inc/SelectSimulation.h"

#include <iostream>

int main() {
	SelectSimulation* select = new SelectSimulation();

	select->startSim();

	delete select;

	return 0;
}
