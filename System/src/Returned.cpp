#include "../include/Returned.h"
#include "../include/Idle.h"

Returned::~Returned() {}

void Returned::handleChange(Falcon* context) {
    context->setState(new Idle());
}

std::string Returned::getCurrentState() {
    return "Returned";
}
