#include "../include/BuildSimulation.h"

const std::string BuildSimulation::DELIMITER = "#";
const std::string BuildSimulation::TYPE_SATELLITE = "0";
const std::string BuildSimulation::TYPE_CREW = "1";
const std::string BuildSimulation::TYPE_CARGO = "2";

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

    std::cout << "\nWhat kind of rocket would you like to use?" << std::endl;
    std::cout << "\t0: Falcon 9\n\t1: Falcon Heavy" << std::endl;
    std::cout << "Please choose the apropriate option: ";
    std::cin >> selection;

    if (selection < 0 || selection > 1) {
        std::cout << "Choice is not a valid option." << std::endl;
        buildMode(sVector);
    }

    switch (selection)
    {
    case 0:
        selection = 0;
        std::cout << "\nWhat kind of payload would you like to send?" << std::endl;
        std::cout << "\t0: Crew\n\t1: Sattelites" << std::endl;
        std::cout << "Please choose the apropriate option: ";
        std::cin >> selection;

        switch (selection)
        {
        case 0:
            this->buildCrew(sVector);
            break;

        case 1:
            this->buildSattelites(sVector);
        
        default:
            break;
        }
        break;

    case 1:
        selection = 0;
        std::cout << "\nWhat kind of payload would you like to send?" << std::endl;
        std::cout << "\t0: Cargo and Crew" << std::endl;
        std::cout << "Please choose the apropriate option: ";
        std::cin >> selection;

        switch (selection)
        {
        case 0:
            this->buildCargo(sVector);
            break;
        
        default:
            break;
        }
    
    default:
        break;
    }
}

void BuildSimulation::buildTestMode(std::vector<State*>* sVector) {
    int selection = 0;
    Falcon* falcon;

    Store* rollBack = new Store();
    State* tmpState;

    Memento* tmpMem = createMemento();
    rollBack->storeMemento(tmpMem);

    std::cout << "\nWhat kind of rocket would you like to use?" << std::endl;
    std::cout << "\t0: Falcon 9\n\t1: Falcon Heavy" << std::endl;
    std::cout << "Please choose the apropriate option: ";
    std::cin >> selection;

    if (selection < 0 || selection > 1) {
        std::cout << "Choice is not a valid option." << std::endl;
        buildTestMode(sVector);
    }

    switch (selection)
    {
    case 0:
        falcon = (Falcon*)nineCreator->createSpacecraft();

        selection = 0;
        std::cout << "\nWhat kind of payload would you like to send?" << std::endl;
        std::cout << "\t0: Crew\n\t1: Sattelites" << std::endl;
        std::cout << "Please choose the apropriate option: ";
        std::cin >> selection;

        switch (selection)
        {
        case 0:
            this->buildCrew(sVector);
            break;

        case 1:
            this->buildSattelites(sVector);
        
        default:
            break;
        }
        break;

    case 1:
        selection = 0;
        std::cout << "\nWhat kind of payload would you like to send?" << std::endl;
        std::cout << "\t0: Cargo and Crew" << std::endl;
        std::cout << "Please choose the apropriate option: ";
        std::cin >> selection;

        switch (selection)
        {
        case 0:
            this->buildCargo(sVector);
            break;
        
        default:
            break;
        }
    
    default:
        break;
    }
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

void BuildSimulation::saveToFile(State* s, int t) {
    std::string selection = "";
    std::string outString = "";

    std::cout << "\nWhat would you like to name this simulation?" << std::endl;
    std::cout << "Please input a name for the simulation (Only letters, numbers and underscores ('_')): ";
    std::cin >> selection;

    // if (!std::regex_match(selection, std::regex("^[[:w:]]$"))) {
    //     std::cout << "Name does not contain only letters, numbers and underscores ('_')." << std::endl;
    //     this->saveToFile(s);
    // }
    
    std::ofstream outFile;
    outFile.open(getFilePath(), std::ios_base::app);
    s->setName(selection);

    outString += s->getName();
    outString += DELIMITER;
    outString += (t == 0) ? TYPE_SATELLITE : (t == 1) ? TYPE_CREW : TYPE_CARGO;
    outString += DELIMITER;
    outString += (s->getCluster() == 0) ? "0" : to_string(s->getCluster()->getSize());

    outFile << "\n" << outString;
}

void BuildSimulation::buildSattelites(std::vector<State*>* sVector) {
    int satCount, selection = 0;

    std::cout << "\nHow many sattelites would you like to send?" << std::endl;
    std::cout << "Please input a number between 1 and 60 (inclusive): ";
    std::cin >> satCount;

    Falcon* tmpFalcon = new Falcon("falcon-9");
    Cluster* tmpCluster = new Cluster(tmpFalcon);
    MissionControl* tmpControl = new MissionControl();

    tmpCluster->generateSatellites(tmpControl, satCount);

    State* tmpState = new State("Base Name", tmpCluster);

    sVector->push_back(tmpState);

    std::cout << "\nWould you like to save the current sim?" << std::endl;
    std::cout << "\t0: Yes\n\t1: No" << std::endl;
    std::cout << "Please choose the apropriate option: ";
    std::cin >> selection;

    switch (selection)
    {
    case 0:
        this->saveToFile(tmpState, 0);
        break;
    
    default:
        break;
    }
}

void BuildSimulation::buildCrew(std::vector<State*>* sVector) {
    int selection = 0;

    Falcon* tmpFalcon = new Falcon("falcon-9");
    Dragon* tmpCrew = new CrewDragon(tmpFalcon);
    Loader* tmpLoader = new Loader(tmpCrew);
    tmpLoader->load(false);

    State* tmpState = new State("Base Name", tmpCrew);

    sVector->push_back(tmpState);

    std::cout << "\nWould you like to save the current sim?" << std::endl;
    std::cout << "\t0: Yes\n\t1: No" << std::endl;
    std::cout << "Please choose the apropriate option: ";
    std::cin >> selection;

    switch (selection)
    {
    case 0:
        this->saveToFile(tmpState, 1);
        break;
    
    default:
        break;
    }
}

void BuildSimulation::buildCargo(std::vector<State*>* sVector) {
    int selection = 0;

    Falcon* tmpFalcon = new Falcon("falcon-heavy");
    Dragon* tmpCargo = new CargoDragon(tmpFalcon);
    Loader* tmpLoader = new Loader(tmpCargo);
    tmpLoader->load(false);

    State* tmpState = new State("Base Name", tmpCargo);

    sVector->push_back(tmpState);

    std::cout << "\nWould you like to save the current sim?" << std::endl;
    std::cout << "\t0: Yes\n\t1: No" << std::endl;
    std::cout << "Please choose the apropriate option: ";
    std::cin >> selection;

    switch (selection)
    {
    case 0:
        this->saveToFile(tmpState, 1);
        break;
    
    default:
        break;
    }
}