#include "../include/Cluster.h"

Cluster::Cluster(Falcon* f) {
    this->falcon = f;
}

Cluster::~Cluster() {
    for(auto it : clusterSatellites){
        delete it;
    }
}

void Cluster::addSatellite(Satelite* s) {
    this->clusterSatellites.push_back(s);
}

void Cluster::generateSatellites(MissionControl* control, int numSatellites) {
    if(numSatellites < 0 || numSatellites > 60) {
        std::cout << "Please enter a valid a number of satellites\n";
        return;
    }

    Satelite* s = new Satelite();
    s->setMissionControl(control);
    this->clusterSatellites.push_back(s);        

    for(int i = 1; i < numSatellites; ++i) {
        Satelite* m = s->clone();
        this->clusterSatellites.push_back(m);
    }
}

void Cluster::spreadOutSatellites() {
    for(auto it : clusterSatellites) {
        it->positionSelf();
    }
}

Falcon* Cluster::getCraft() {
    return falcon;
}

int Cluster::getSize() {
    clusterSatellites.size();
}
