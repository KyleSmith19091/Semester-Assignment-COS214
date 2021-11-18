#include "../include/SelectSimulation.h"

SelectSimulation::SelectSimulation() : sVector() {}

SelectSimulation::~SelectSimulation() {
    Memento* tmp;
    State* tmpState;

    for (int i = 0; i < prefabs.size(); i++) {
        tmp = prefabs[i];
        tmpState = tmp->getState();

        delete tmp;
        delete tmpState;
    }
}

std::vector<State*> SelectSimulation::startSim() {
    this->loadPrefabs();

    cout << "\n==========You Have now entered the simulation phase.==========\n\n";
    cout << "Would you like to run a single simulation or a batch of simulations?\n";
    cout << "\t0: Single simulation\n\t1: Batch simulation\n";
	cout << "Please select the appropriate option: "; 
    int optionSelector = -1;
    cin >> optionSelector;
    while (optionSelector != 0 && optionSelector != 1 && optionSelector != iExit){
        cout << "Please enter a 0 or a 1\n";
        cin >> optionSelector;
    }
    switch (optionSelector)
    {
        case 0:
            cout << "===Simulation single mode===\n";
            this->simulateSingle();
            break;
        case 1:
            cout << "===Simulation batch mode===\n";
            this->simulateBatch();
            break;
        case 100:
            exitProgram();
            break;
    }
    cout << "Finished with simulation returning to main\n";
    return sVector;
}

void SelectSimulation::loadPrefabs() {
    Memento* tmp;
    State* tmpState;
    std::string inString;
    std::fstream inFile(getFilePath());

    std::string type;
    std::string name;
    prefabs.clear();

    while (std::getline(inFile, inString)) {
        tmp = new Memento();

        type = inString.substr(0, inString.find('#'));
        inString.erase(0, inString.find('#') + 1);
        name = inString;

        tmpState = new State(name);
        tmp->setState(tmpState);

        prefabs.push_back(tmp);
    }
}

void SelectSimulation::exitProgram() {
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

void SelectSimulation::simulateSingle() {
    int selection = 0;

    std::cout << "Please select the simulation you would like to run." << std::endl;

    for (auto it = prefabs.begin(); it != prefabs.end(); it++) {
        std::cout << "\t" << ++selection << "." << (*it)->getState()->getName() << std::endl;
    }
    
    selection = 0;
    std::cout << "Please select the appropriate number: ";
    std::cin >> selection;

    if (selection < 1 || selection > prefabs.size()) {
        std::cout << "The number that you input was not available in the provided selection." << std::endl << std::endl;
        return;
    }

    sVector.push_back(prefabs[--selection]->getState());
    std::vector<Memento*>::iterator rem = prefabs.begin() + selection;
    prefabs.erase(rem);
    //std::cout << "Hello, I am now a " << prefabs[--selection]->getState()->getName() << " ship." << std::endl;
}

void SelectSimulation::simulateBatch() {
    bool bFinished = false;
    while(bFinished == false){
        this->simulateSingle();

        cout << "\nWould you like to add another simulation.\n"
                "0:no, 1:Yes\n";
        int optionSelector=-1;
        cin.clear();
        cin >> optionSelector;
        while (optionSelector != 0 && optionSelector != 1 && optionSelector !=iExit){
            cout << "Please enter a 0 or a 1\n";
            cin.clear();
            cin >> optionSelector;
        }

        switch (optionSelector)
        {
            case 0:{
                bFinished = true;
                break;
            }
            case 1: {
                cout << "Simulation batch mode";
                break;
            }
            case 100:
                exitProgram();
                break;
        }
    }
    cout<<"finished with batch\n";
}