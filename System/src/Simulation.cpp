#include "../include/Simulation.h"

Simulation::Simulation() {
    state = new State("Cargo");
}

Simulation::~Simulation() {
    delete state;
}

Memento* Simulation::createMemento() {
    Memento* tmp = new Memento();
    tmp->setState(state);
    return tmp;
}

void Simulation::setMemento(Memento* m) {
    state = m->getState();
}
