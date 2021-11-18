#include "../include/SelectCommand.h"

SelectCommand::SelectCommand(SelectSimulation* s) : mySim(s) {}

SelectCommand::~SelectCommand() {}

std::vector<State*> SelectCommand::execute() {
    return mySim->startSim();
}