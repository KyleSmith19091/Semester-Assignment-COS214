#include "../include/Satelite.h"

Satelite::Satelite() : Spacecraft("Satelite") {
    coords = new KeplerianCoords();
    missionControl = nullptr;
}

Satelite::~Satelite() {
    if(missionControl) {
        delete missionControl;
    }
}

Satelite::Satelite(const Satelite& s) : Spacecraft("Satelite") {
    coords = new KeplerianCoords();
    this->missionControl = s.missionControl;
}

Satelite* Satelite::clone() {
    return new Satelite(*this);
}

void Satelite::positionSelf() {
    std::cout << "Positioning 🛰. ... ";
    coords->randomiseCoords();
    usleep(100000);
    std::cout << "DONE\n";

    sendGroundSignal();
}

void Satelite::sendGroundSignal() {
    missionControl->receiveRadioSignal(rand() % 1000,coords->toString());
}

void Satelite::sendSatelliteSignal(Satelite* s) {
    if(this->coords < s->coords) { // Possible collision so reposition
        std::cout << "! Possible Collision Detected ... Repositioning\n";
        this->positionSelf();
        s->positionSelf();
    }
}

void Satelite::setMissionControl(MissionControl * missionControl) {
    this->missionControl = missionControl;
}

KeplerianCoords* Satelite::getCoords() const {
    return this->coords;
}

