#include "../include/UnloadCommand.h"

UnloadCommand::UnloadCommand(Loader* l) : myLoader(l) {}

UnloadCommand::~UnloadCommand() {}

void UnloadCommand::execute() {
    std::cout << "Docking at the ISS" << std::endl;
    sleep(2);

    myLoader->unload(true);

    std::cout << "Payload has been unloaded" << std::endl;
}