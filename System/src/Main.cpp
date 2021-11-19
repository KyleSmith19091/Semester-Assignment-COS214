#include "../include/SelectSimulation.h"
#include "../include/Cargo.h"
#include "../include/VectorOfCargo.h"
#include "../include/CargoIterator.h"
#include "../include/CarryType.h"
#include "../include/Dragon.h"
#include "../include/CrewDragon.h"
#include "../include/CargoDragon.h"
#include "../include/Loader.h"
#include "../include/Falcon.h"
#include "../include/Satelite.h"
#include "../include/Cluster.h"
#include <iostream>

int main() {
	//////////////////////////////////////////////////////////////// Iterator
    std::cout << "----------------------------------------- ITERATOR ---------------------------------------\n";
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

	////////////////////////////////////////////////////////////////  Strategy
    std::cout << "----------------------------------------- STRATEGY ---------------------------------------\n";
     Falcon* falconHeavy = new Falcon();
	 Dragon* dragon = new CrewDragon(falconHeavy);
     Loader* loader = new Loader(dragon); 
     loader->load();

     Dragon* cargoDragon = new CargoDragon(falconHeavy);
     loader->setDragon(cargoDragon);
     loader->load();

     delete loader;

	////////////////////////////////////////////////////////////////  State
    std::cout << "----------------------------------------- STATE ---------------------------------------\n";
     Falcon* falconWithState = new Falcon();
     std::cout << "Falcon current State: " << falconWithState->getCurrentState() << "\n";
     falconWithState->change();
     std::cout << "Falcon current State: " << falconWithState->getCurrentState() << "\n";
     falconWithState->change();
     std::cout << "Falcon current State: " << falconWithState->getCurrentState() << "\n";
     falconWithState->change();
     std::cout << "Falcon current State: " << falconWithState->getCurrentState() << "\n";
     falconWithState->change();
     std::cout << "Falcon current State: " << falconWithState->getCurrentState() << "\n";

	////////////////////////////////////////////////////////////////  Satelite
    std::cout << "----------------------------------------- SATELLITE ---------------------------------------\n";
    // Ground
     MissionControl* control = new MissionControl();
     Cluster* cluster = new Cluster(falconWithState);
     cluster->generateSatellites(control,4);
     cluster->spreadOutSatellites();

	//////////////////////////////////////////////////////////////// 
    std::cout << "----------------------------------------- SIM ---------------------------------------\n";

	SelectSimulation* select = new SelectSimulation();

	select->startSim();

	delete select;

	return 0;
}
