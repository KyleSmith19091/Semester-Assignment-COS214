#include "../include/BuildSimulation.h"

BuildSimulation::BuildSimulation() {}

BuildSimulation::~BuildSimulation() {}

void BuildSimulation::startSim(std::vector<State*>* sVector) {
    std::cout << "\n==========You Have now entered the building phase.==========\n";
    std::cout << "Would you like to build in test mode?\n\t0: No\n\t1: Yes\n";
    std::cout << "Please choose the apropriate option: ";
    int optionSelector = -1;
    cin >> optionSelector;
    while (optionSelector != 0 && optionSelector != 1 && optionSelector != iExit){
        std::cout << "Please enter a 0 or a 1: \n";
        std::cin >> optionSelector;
    }
    switch (optionSelector)
    {
        case 0:
            buildMode(sVector);
            break;
        case 1:{
            buildTestMode(sVector);
            break;

        }
        case 100:
            exitProgram();
            break;
    }
}

void BuildSimulation::buildMode(std::vector<State*>* sVector) {
    int selection = 0;

    std::cout << "What kind of payload do you want to send?" << std::endl;
    std::cout << "\t0: Satellites\n\t1: Crew\n\t2: Cargo and/or Crew" << std::endl;
    std::cout << "Please choose the apropriate option: ";
    std::cin >> selection;

    if (selection < 0 || selection > 2) {
        std::cout << "Choice is not a valid option." << std::endl;
        buildMode(sVector);
    }

    switch (selection)
    {
    case 0:
        selection = 0;
        std::cout << "What kind of rocket would you like to use?" << std::endl;
        std::cout << "\t0: Falcon Heavy\n" << std::endl;
        std::cout << "Please choose the apropriate option: ";
        std::cin >> selection;

        switch (selection)
        {
        case 0:
            this->falconHeavy(0, sVector);
            break;
        
        default:
            break;
        }
        break;
    
    default:
        break;
    }
}

void BuildSimulation::buildTestMode(std::vector<State*>* sVector) {

}

void BuildSimulation::exitProgram() {
    cout << "\nAre you sure you want to exit?\n";
    cout << "Please type 'EXIT' if you wish to exit the program or a 0 if you do not \n";
    string optionSelector;
    cin >> optionSelector;
    while (optionSelector != "0"  && optionSelector !="EXIT"){
        cout << "Please type 'EXIT' or enter a 0:\n";
        cin >> optionSelector;
    }
    if (optionSelector == "EXIT")
        exit(0);
}

void BuildSimulation::saveToFile(State* s) {
    std::ofstream outFile;
    outFile.open(getFilePath(), std::ios_base::app);

    outFile << "\n" << s->getName();
}

void BuildSimulation::falconHeavy(int c, std::vector<State*>* sVector) {
    int selection = 0;
    State* tmp;

    switch (c)
    {
    case 0:
        tmp = new State("Satellites on Falcon Heavy");
        sVector->push_back(tmp);

        std::cout << "Would you like to save the current sim?" << std::endl;
        std::cout << "\t0: Yes\n\t1: No\n" << std::endl;
        std::cout << "Please choose the apropriate option: ";
        std::cin >> selection;

        switch (selection)
        {
        case 0:
            this->saveToFile(tmp);
            break;
        
        default:
            break;
        }
        break;
    
    default:
        break;
    }
}