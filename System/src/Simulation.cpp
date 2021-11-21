#include "../include/Simulation.h"

Simulation::Simulation() {
    state = new State();
}

Simulation::~Simulation() {
    //delete state;
}

Memento* Simulation::createMemento() {
    if (state != 0) {
        Memento* tmp = new Memento();
        tmp->setState(state);
        return tmp;
    }
    return nullptr;
}

void Simulation::setMemento(Memento* m) {
    state = m->getState();
}

std::string Simulation::getFilePath() {
    return filePath;
}

State* Simulation::getState() {
    return state;
}
