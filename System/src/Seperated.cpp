#include "../include/Seperated.h"
#include "../include/Returned.h"

Seperated::~Seperated() {}

void Seperated::handleChange(Falcon* context) {
    context->setState(new Returned());
}

std::string Seperated::getCurrentState() {
    return "Seperated";
}
