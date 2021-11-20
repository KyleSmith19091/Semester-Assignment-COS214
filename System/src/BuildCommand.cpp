#include "../include/BuildCommand.h"

BuildCommand::BuildCommand(BuildSimulation* s) : mySim(s) {
    Command();
}

BuildCommand::~BuildCommand() {}

void BuildCommand::execute(std::string s, std::vector<State*>* v) {
    if (s == "b") {
        mySim->startSim(v);
    }
    else
        Command::execute(s, v);
}