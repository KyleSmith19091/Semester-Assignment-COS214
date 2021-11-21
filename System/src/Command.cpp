#include "../include/Command.h"

Command::Command() : next(0) {}

Command::~Command() {}

void Command::execute() {
    std::cout << "Please implement in child classes." << std::endl;
}

void Command::execute(std::string s, std::vector<State*>* v) {
    if (next) {
        next->execute(s, v);
    }
    else {
        std::cout << "Not able to execute." << std::endl;
    }
}

void Command::add(Command* c) {
    if (next) 
        next->add(c); 
    else 
        next = c;
}
