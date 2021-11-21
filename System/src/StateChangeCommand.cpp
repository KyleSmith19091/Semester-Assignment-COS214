#include "../include/StateChangeCommand.h"

StateChangeCommand::StateChangeCommand(Falcon* f) : myFalcon(f) {}

StateChangeCommand::~StateChangeCommand() {}

void StateChangeCommand::execute() {
    std::cout << "Current State is --> " << myFalcon->getCurrentState() << std::endl;

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
    myFalcon->change();

    std::cout << "Current State is --> " << myFalcon->getCurrentState() << std::endl;

    std::cout << "Waiting to almost reach orbit." << std::endl;
    sleep(1);
    std::cout << "Waiting to almost reach orbit." << std::endl;
    sleep(1);
    std::cout << "Waiting to almost reach orbit." << std::endl;
    sleep(1);
    std::cout << "Detaching first stage." << std::endl;
    sleep(1);

    myFalcon->change();
    std::cout << "Current State is --> " << myFalcon->getCurrentState() << std::endl;

    std::cout << "Using second stage to get to desired orbit and returning first stage." << std::endl;
    sleep(2);

    myFalcon->change();
    std::cout << "Current State is --> " << myFalcon->getCurrentState() << std::endl;
}