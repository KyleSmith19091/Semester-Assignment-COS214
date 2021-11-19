#include "../include/Launched.h"
#include "../include/Seperated.h"

Launched::~Launched() {}

void Launched::handleChange(Falcon* context) {
    context->setState(new Seperated());
}

std::string Launched::getCurrentState() {
    return "Launched";
}
