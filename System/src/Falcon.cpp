#include "../include/Falcon.h"
#include "../include/Idle.h"

Falcon::Falcon(std::string type) : Spacecraft(type) {
    launchState = new Idle();
    merlinVacuumEngine = new MerlinVacuumEngine();

    if(type.find("9") == string::npos) { // Falcon-Heavy
        this->coreList.push_back(new MerlinCore());
        this->coreList.push_back(new MerlinCore());
        this->coreList.push_back(new MerlinCore());
    } else { // Falcon-9
        this->coreList.push_back(new MerlinCore());
    }

}

Falcon::~Falcon() {
    delete launchState;

    for(auto it : coreList) {
        delete it;
    }

    delete merlinVacuumEngine;
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

vector<MerlinCore*> Falcon::getCoreList() const {
    return this->coreList;
} 

MerlinVacuumEngine* Falcon::getVacuumEngine() const {
    return this->merlinVacuumEngine;
}
