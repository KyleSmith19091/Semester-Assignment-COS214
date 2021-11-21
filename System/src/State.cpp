#include "../include/State.h"

State::State() : name("Base Name"), vessel(0), satellites(0), commands() {}

State::State(State* s) : commands() {
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

State::State(std::string n, Spacecraft* s) : name(n), vessel(s), satellites(0), commands() {}

State::State(std::string n, Cluster* c) : name(n), satellites(c), vessel(c->getCraft()), commands() {}

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

void State::setVessel(Spacecraft* s) {
    vessel = s;
}

Cluster* State::getCluster() {
    return satellites;
}

void State::setCluster(Cluster* c) {
    satellites = c;
    vessel = c->getCraft();
}

void State::addCommand(Command* c) {
    commands.push_back(c);
}

void State::runCommands() {
    for (auto it : commands)
        it->execute();
}

std::vector<Command*> State::getCommands() {
    return commands;
}