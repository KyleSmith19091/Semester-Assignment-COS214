#include "../include/Idle.h"
#include "../include/Launched.h"

Idle::~Idle() {}

void Idle::handleChange(Falcon* context) {
    context->setState(new Launched());
}

std::string Idle::getCurrentState() {
    return  "Idle";
}
