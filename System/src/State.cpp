#include "../inc/State.h"

State::State(std::string n) : name(n) {}

State::~State() {}

std::string State::getName() {
    return name;
}