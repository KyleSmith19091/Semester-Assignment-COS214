#include "../include/BuildCommand.h"

BuildCommand::BuildCommand(BuildSimulation* s) : mySim(s) {}

BuildCommand::~BuildCommand() {}

std::vector<State*> BuildCommand::execute() {
    return mySim->startSim();
}