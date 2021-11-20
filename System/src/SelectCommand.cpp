#include "../include/SelectCommand.h"

SelectCommand::SelectCommand(SelectSimulation* s) : mySim(s) {
    Command();
}

SelectCommand::~SelectCommand() {}

void SelectCommand::execute(std::string s, std::vector<State*>* v) {
    if (s == "s") {
        mySim->startSim(v);
    }
    else
        Command::execute(s, v);
}