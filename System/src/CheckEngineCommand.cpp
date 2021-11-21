#include "../include/CheckEngineCommand.h"

CheckEngineCommand::CheckEngineCommand(std::vector<MerlinCore*> v, MerlinVacuumEngine* mv) {
    myCores = v;
    vacuumEng = mv;
}

CheckEngineCommand::~CheckEngineCommand() {

}

void CheckEngineCommand::execute() {
    for (auto it : myCores)
        it->initiateEngineChecks();

    vacuumEng->checkTemperature();
}