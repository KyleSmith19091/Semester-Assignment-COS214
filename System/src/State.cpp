#include "../include/State.h"

State::State(std::string n, Spacecraft* s) : name(n), vessel(s), satellites(0) {}

State::State(std::string n, Cluster* c) : name(n), satellites(c), vessel(c->getCraft()) {}

State::~State() {}

std::string State::getName() {
    return name;
}

Spacecraft* State::getVessel() {
    return vessel;
}

Cluster* State::getCluster() {
    return satellites;
}