#include "../include/State.h"

State::State() : name("Base Name"), vessel(0), satellites(0) {}

State::State(State* s) {
    Falcon* tmpFalcon;
    Dragon* tmpDragon;
    Loader* tmpLoader;
    Cluster* tmpCluster;
    MissionControl* tmpControl;

    name = s->getName();
    vessel = s->getVessel();
    satellites = s->getCluster();

    if (vessel->getType() == "falcon-heavy") {
        tmpFalcon = new Falcon(vessel->getType());
        tmpDragon = new CargoDragon(tmpFalcon);
        tmpLoader = new Loader(tmpDragon);
        tmpLoader->load(false);

        vessel = tmpDragon;
    } else if (vessel->getType() == "falcon-9") {
        if (satellites == 0) {
            tmpFalcon = new Falcon(vessel->getType());
            tmpDragon = new CrewDragon(tmpFalcon);
            tmpLoader = new Loader(tmpDragon);
            tmpLoader->load(false);

            vessel = tmpDragon;
        } else {
            
        }
    }
}

State::State(std::string n, Spacecraft* s) : name(n), vessel(s), satellites(0) {}

State::State(std::string n, Cluster* c) : name(n), satellites(c), vessel(c->getCraft()) {}

State::~State() {}

std::string State::getName() {
    return name;
}

void State::setName(std::string s) {
    name = s;
}

Spacecraft* State::getVessel() {
    return vessel;
}

Cluster* State::getCluster() {
    return satellites;
}