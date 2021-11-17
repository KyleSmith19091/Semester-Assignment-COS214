#include "../include/Simulate.h"

Simulate::Simulate() {}

Simulate::~Simulate() {}

void Simulate::select() {
    if (selectCommand != 0)
        selectCommand->execute();
    else
        std::cout << "No command set." << std::endl;
}

void Simulate::build() {
    if (buildCommand != 0)
        buildCommand->execute();
    else
        std::cout << "No command set." << std::endl;
}

void Simulate::setSelect(Command* c) {
    selectCommand = c;
}

void Simulate::setBuild(Command* c) {
    buildCommand = c;
}