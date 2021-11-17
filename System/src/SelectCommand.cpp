#include "../include/SelectCommand.h"

SelectCommand::SelectCommand(SelectSimulation* s) : mySim(s) {}

SelectCommand::~SelectCommand() {}

void SelectCommand::execute() {
    mySim->startSim();
}