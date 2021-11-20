#include "../include/Falcon.h"
#include "../include/Idle.h"

Falcon::Falcon() : Spacecraft("Falcon") {
    launchState = new Idle();
}

Falcon::~Falcon() {
    delete launchState;
}

string Falcon::getCurrentState() const {
    return launchState->getCurrentState(); 
}

void Falcon::change() {
    launchState->handleChange(this);
}

void Falcon::setState(FalconState * newState) {
    delete launchState;
    launchState = newState;
}