#include "../include/Falcon.h"
#include "../include/Launched.h"

Falcon::Falcon() : Spacecraft("Falcon") {
    launchState = new Launched();
}

Falcon::~Falcon() {
    for(auto it = coreList.begin(); it != coreList.end(); ++it) {
        delete (*it);
    }
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
