#include "../include/MissionControl.h"

MissionControl::MissionControl() {}

MissionControl::~MissionControl() {}

void MissionControl::receiveRadioSignal(int satelliteID, std::string coords) {
    std::cout << "> Received Radio Signal from Satellite: " << satelliteID << " Position " << coords << "\n";
}

void MissionControl::sendRepositionRequest(Satelite * s) {
    std::cout << "> Sending reposition request to Satellite\n";
    s->positionSelf();
}
