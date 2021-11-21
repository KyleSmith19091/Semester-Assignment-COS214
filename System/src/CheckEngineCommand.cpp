#include "../include/CheckEngineCommand.h"

CheckEngineCommand::CheckEngineCommand(std::vector<MerlinCore*> v, MerlinVacuumEngine* mv) {
    myCores = v;
    vacuumEng = mv;
}

CheckEngineCommand::~CheckEngineCommand() {

}

void CheckEngineCommand::execute() {
    std::cout << "Static fire test starting in 3" << std::endl;
    sleep(1);
    std::cout << "Static fire test starting in 2" << std::endl;
    sleep(1);
    std::cout << "Static fire test starting in 1" << std::endl;
    sleep(1);

    for (auto it : myCores)
        it->initiateEngineChecks();

    vacuumEng->checkEngine();
}