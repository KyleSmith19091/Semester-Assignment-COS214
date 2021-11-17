#include "../include/BuildSimulation.h"

BuildSimulation::BuildSimulation() {}

BuildSimulation::~BuildSimulation() {}

void BuildSimulation::startSim() {
    Memento* tmp = createMemento();

    std::cout << "Hello, I am a " << tmp->getState()->getName() << " ship." << std::endl;
}
