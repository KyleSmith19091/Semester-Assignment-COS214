#include "../include/BuildCommand.h"

BuildCommand::BuildCommand(BuildSimulation* s) : mySim(s) {}

BuildCommand::~BuildCommand() {}

void BuildCommand::execute() {
    mySim->startSim();
}