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

    vacuumEng->checkTemperature();

    std::cout << "Launch starting in 5" << std::endl;
    sleep(1);
    std::cout << "Launch starting in 4" << std::endl;
    sleep(1);
    std::cout << "Launch starting in 3" << std::endl;
    sleep(1);
    std::cout << "Launch starting in 2" << std::endl;
    sleep(1);
    std::cout << "Launch starting in 1" << std::endl;
    sleep(1);
    std::cout << "Launch starting in now..." << std::endl;
}