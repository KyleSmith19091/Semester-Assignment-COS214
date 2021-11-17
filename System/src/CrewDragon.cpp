#include "../include/CrewDragon.h"

CrewDragon::~CrewDragon() {
    for(auto it = crewMembers.begin(); it != crewMembers.end(); ++it) {
        delete (*it);
    }

    for(auto it = cargoList.begin(); it != crewMembers.end(); ++it) {
        delete (*it);
    }
}

void CrewDragon::load() {
}
