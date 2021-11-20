#include "../include/SelectSimulation.h"

SelectSimulation::SelectSimulation() {}

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

void SelectSimulation::startSim(std::vector<State*>* sVector) {
    this->loadPrefabs();

    cout << "\n==========You Have now entered the simulation phase.==========\n\n";
    cout << "Would you like to run a single simulation or a batch of simulations?\n";
    cout << "\t0: Single simulation\n\t1: Batch simulation\n";
	cout << "Please select the appropriate option: "; 
    int optionSelector = -1;
    cin >> optionSelector;
    while (optionSelector != 0 && optionSelector != 1 && optionSelector != iExit){
        cout << "Please enter a 0 or a 1: \n";
        cin >> optionSelector;
    }
    std::cout << "\n";
    switch (optionSelector)
    {
        case 0:
            cout << "===Simulation single mode===\n";
            this->simulateSingle(sVector);
            break;
        case 1:
            cout << "===Simulation batch mode===\n";
            this->simulateBatch(sVector);
            break;
        case 100:
            exitProgram();
            break;
    }
    cout << "\n";
}

void SelectSimulation::loadPrefabs() {
    Memento* tmp;
    State* tmpState;
    std::string inString;
    std::fstream inFile(getFilePath());

    Falcon* falcon;
    Cluster* cluster;
    MissionControl* control;
    Dragon* dragon;
    Loader* loader;

    std::string name;
    int type;
    int satCount = 0;
    prefabs.clear();

    while (std::getline(inFile, inString)) {
        if (inString.substr(0, inString.find('#')) == "Name")
            continue;
        
        tmp = new Memento();

        name = inString.substr(0, inString.find('#'));
        inString.erase(0, inString.find('#') + 1);

        type = stoi(inString.substr(0, inString.find('#')));
        inString.erase(0, inString.find('#') + 1);

        satCount = stoi(inString);

        switch (type)
        {
        case 0:
            falcon = new Falcon("Falcon 9");
            cluster = new Cluster(falcon);
            control = new MissionControl();

            cluster->generateSatellites(control, satCount);

            tmpState = new State(name, cluster);
            tmp->setState(tmpState);

            prefabs.push_back(tmp);
            break;

        case 1:
            falcon = new Falcon("Falcon 9");
            dragon = new CrewDragon(falcon);
            loader = new Loader(dragon); 
            loader->load(false);

            tmpState = new State(name, dragon);
            tmp->setState(tmpState);

            prefabs.push_back(tmp);
            break;

        case 2:
            falcon = new Falcon("Falcon Heavy");
            dragon = new CargoDragon(falcon);
            loader = new Loader(dragon); 
            loader->load(false);

            tmpState = new State(name, dragon);
            tmp->setState(tmpState);

            prefabs.push_back(tmp);
            break;
        
        default:
            break;
        }
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

void SelectSimulation::simulateSingle(std::vector<State*>* sVector) {
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
        this->simulateSingle(sVector);
    }

    sVector->push_back(prefabs[--selection]->getState());
    std::vector<Memento*>::iterator rem = prefabs.begin() + selection;
    prefabs.erase(rem);
    //std::cout << "Hello, I am now a " << prefabs[--selection]->getState()->getName() << " ship." << std::endl;
}

void SelectSimulation::simulateBatch(std::vector<State*>* sVector) {
    bool bFinished = false;
    while(bFinished == false){
        this->simulateSingle(sVector);

        cout << "\nWould you like to add another simulation.\n"
                "\t0: No\n\t1: Yes\n";
        cout << "Please select the appropriate option: ";
        int optionSelector=-1;
        cin.clear();
        cin >> optionSelector;
        while (optionSelector != 0 && optionSelector != 1 && optionSelector !=iExit){
            cout << "Please enter a 0 or a 1: \n";
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
                cout << "===Simulation batch mode===\n";
                break;
            }
            case 100:
                exitProgram();
                break;
        }
    }
    cout<<"\n";
}