#include "../include/SpreadCommand.h"

spreadCommand::spreadCommand(Cluster* c) {
    myCluster = c;
}

spreadCommand::~spreadCommand() {}

void spreadCommand::execute() {
    std::cout << "Satellites spreading into position in 3" << std::endl;
    sleep(1);
    std::cout << "Satellites spreading into position in 2" << std::endl;
    sleep(1);
    std::cout << "Satellites spreading into position in 1" << std::endl;
    sleep(1);

    myCluster->spreadOutSatellites();
}