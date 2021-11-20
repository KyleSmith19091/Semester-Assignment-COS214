#include "../include/Memento.h"

Memento::Memento() {}

Memento::~Memento() {}

void Memento::setState(State* s) {
    state = s;
}

State* Memento::getState() {
    return state;
}
