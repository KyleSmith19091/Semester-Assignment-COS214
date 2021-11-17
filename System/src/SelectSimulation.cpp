#include "../include/SelectSimulation.h"

SelectSimulation::SelectSimulation() {}

SelectSimulation::~SelectSimulation() {
    Memento* tmp;
    State* tmpState;

    // for (auto it = prefabs.begin(); prefabs.size() != 0; it++) {
    //     tmp = (*it);
    //     //prefabs.pop_back();
    //     tmpState = tmp->getState();
    //     prefabs.erase(it);

    //     delete tmp;
    //     delete tmpState;
    // }

    for (int i = 0; i < prefabs.size(); i++) {
        tmp = prefabs[i];
        tmpState = tmp->getState();

        delete tmp;
        delete tmpState;
    }
}

void SelectSimulation::startSim() {
    Memento* tmp;
    State* tmpState;
    
    tmp = createMemento();
    std::cout << "Hello, I am a " << tmp->getState()->getName() << " ship." << std::endl;
    delete tmp;

    std::fstream inFile("../Data/prefabs.txt");
    std::string inString;

    while (std::getline(inFile, inString)) {
        tmp = new Memento();
        tmpState = new State(inString);
        tmp->setState(tmpState);

        prefabs.push_back(tmp);
    }

    tmp = new Memento();

    for (auto it = prefabs.begin(); it != prefabs.end(); it++) {
        tmp->setState((*it)->getState());
        std::cout << "Hello, I am now a " << tmp->getState()->getName() << " ship." << std::endl;
    }

    delete tmp;
}
