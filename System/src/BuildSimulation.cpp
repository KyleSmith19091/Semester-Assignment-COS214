#include "../include/BuildSimulation.h"

int getOption() {
    std::string sOptionSelector;
    cin >> sOptionSelector;
    while (sOptionSelector != "0" && sOptionSelector != "1" && sOptionSelector != to_string(100)) {
        cout << "Please enter a 0 or a 1: \n";
        cin >> sOptionSelector;
    }
    return stoi(sOptionSelector);
}

const std::string BuildSimulation::DELIMITER = "#";
const std::string BuildSimulation::TYPE_SATELLITE = "0";
const std::string BuildSimulation::TYPE_CARGO = "1";
const std::string BuildSimulation::TYPE_CREW = "2";

BuildSimulation::BuildSimulation() : sVector() {
    rollBack = new Store;
}

BuildSimulation::~BuildSimulation() {
    delete rollBack;
}

void BuildSimulation::startSim(std::vector<State*>* v) {
    sVector = v;

    Memento* tmpMem;

    std::cout << "\n==========You Have now entered the building phase.==========\n";
    std::cout << "Would you like to build in test mode?\n\t0: No\n\t1: Yes\n";
    std::cout << "Please choose the apropriate option: ";
    int optionSelector = 0;
    optionSelector = getOption();

    switch (optionSelector)
    {
        case 0:
            buildMode();
            break;
        case 1:
            tmpMem = createMemento();
            rollBack->storeMemento(tmpMem);
            buildTestMode();
            break;

        case 100:
            exitProgram();
            break;
    }
}

void BuildSimulation::buildMode() {
    int selection = 0;

    std::cout << "\nWhat kind of rocket would you like to use?" << std::endl;
    std::cout << "\t0: Falcon 9\n\t1: Falcon Heavy" << std::endl;
    std::cout << "Please choose the apropriate option: ";

    selection = getOption();

    switch (selection)
    {
    case 0:
        selection = 0;
        std::cout << "\nWhat kind of payload would you like to send?" << std::endl;
        std::cout << "\t0: Crew and Cargo\n\t1: Sattelites" << std::endl;
        std::cout << "Please choose the apropriate option: ";
        selection = getOption();

        switch (selection)
        {
        case 0:
            this->buildCrew();
            break;

        case 1:
            this->buildSattelites();
            break;
        
        default:
            break;
        }
        break;

    case 1:
        selection = 0;
        std::cout << "\nWhat kind of payload would you like to send?" << std::endl;
        std::cout << "\t0: Cargo" << std::endl;
        std::cout << "Please choose the apropriate option: ";
        selection = getOption();

        switch (selection)
        {
        case 0:
            this->buildCargo();
            break;
        
        default:
            break;
        }
        break;
    
    default:
        break;
    }
}

void BuildSimulation::saveToFile(State* s, int t) {
    std::string selection = "";
    std::string outString = "";

    std::cout << "\nWhat would you like to name this simulation?" << std::endl;
    std::cout << "Please input a name for the simulation (Only letters, numbers and underscores ('_')): ";
    std::cin >> selection;

    while (selection.find(DELIMITER) != string::npos) {
         std::cout << "Name does not contain only letters, numbers and underscores ('_')." << std::endl;
         std::cout << "Please input a name for the simulation (Only letters, numbers and underscores ('_')): ";
         std::cin >> selection;
    }

    std::ofstream outFile;
    outFile.open(getFilePath(), std::ios_base::app);
    s->setName(selection);

    outString += s->getName();
    outString += DELIMITER;
    outString += (t == 0) ? TYPE_SATELLITE : (t == 1) ? TYPE_CARGO : TYPE_CREW;
    outString += DELIMITER;
    outString += (s->getCluster() == 0) ? "0" : to_string(s->getCluster()->getSize());
    outString += "\n";

    outFile << outString;

    std::cout << "=== DONE WRITING TO: " << getFilePath() << "\n";
}

void BuildSimulation::buildSattelites() {
    int satCount, selection = 0;
    CheckEngineCommand* engCom;
    spreadCommand* spCom;
    StateChangeCommand* scCom;

    std::cout << "\nHow many sattelites would you like to send?" << std::endl;
    std::cout << "Please input a number between 1 and 60 (inclusive): ";
    std::cin >> satCount;

    while(satCount < 0 || satCount > 60) {
        std::cout << "Please enter a valid amount of satellites\n";
        std::cout << "Please input a number between 1 and 60 (inclusive): ";
        std::cin >> satCount;
    }

    Falcon* tmpFalcon = new Falcon("falcon-9");
    Cluster* tmpCluster = new Cluster(tmpFalcon);
    MissionControl* tmpControl = new MissionControl();

    tmpCluster->generateSatellites(tmpControl, satCount);

    State* tmpState = new State("Base Name", tmpCluster);

    engCom = new CheckEngineCommand(tmpFalcon->getCoreList(), tmpFalcon->getVacuumEngine());
    tmpState->addCommand(engCom);

    scCom = new StateChangeCommand(tmpFalcon);
    tmpState->addCommand(scCom);

    spCom = new spreadCommand(tmpCluster);
    tmpState->addCommand(spCom);

    sVector->push_back(tmpState);

    std::cout << "\nWould you like to save the current sim?" << std::endl;
    std::cout << "\t0: Yes\n\t1: No" << std::endl;
    std::cout << "Please choose the apropriate option: ";
    selection = getOption();

    switch (selection)
    {
    case 0:
        this->saveToFile(tmpState, 0);
        break;
    
    default:
        break;
    }
}

void BuildSimulation::buildCrew() {
    int selection = 0;
    CheckEngineCommand* engCom;
    StateChangeCommand* scCom;
    UnloadCommand* uCom;

    Falcon* tmpFalcon = new Falcon("falcon-9");
    Dragon* tmpCrew = new CrewDragon(tmpFalcon);
    Loader* tmpLoader = new Loader(tmpCrew);
    tmpLoader->load(false);

    State* tmpState = new State("Base Name", tmpCrew);

    engCom = new CheckEngineCommand(tmpFalcon->getCoreList(), tmpFalcon->getVacuumEngine());
    tmpState->addCommand(engCom);

    scCom = new StateChangeCommand(tmpFalcon);
    tmpState->addCommand(scCom);

    uCom = new UnloadCommand(tmpLoader);
    tmpState->addCommand(uCom);

    sVector->push_back(tmpState);

    std::cout << "\nWould you like to save the current sim?" << std::endl;
    std::cout << "\t0: Yes\n\t1: No" << std::endl;
    std::cout << "Please choose the apropriate option: ";
    selection = getOption();

    switch (selection)
    {
    case 0:
        this->saveToFile(tmpState, 2);
        break;
    
    default:
        break;
    }
}

void BuildSimulation::buildCargo() {
    int selection = 0;
    CheckEngineCommand* engCom;
    StateChangeCommand* scCom;
    UnloadCommand* uCom;

    Falcon* tmpFalcon = new Falcon("falcon-heavy");
    Dragon* tmpCargo = new CargoDragon(tmpFalcon);
    Loader* tmpLoader = new Loader(tmpCargo);
    tmpLoader->load(false);

    State* tmpState = new State("Base Name", tmpCargo);

    engCom = new CheckEngineCommand(tmpFalcon->getCoreList(), tmpFalcon->getVacuumEngine());
    tmpState->addCommand(engCom);

    scCom = new StateChangeCommand(tmpFalcon);
    tmpState->addCommand(scCom);

    uCom = new UnloadCommand(tmpLoader);
    tmpState->addCommand(uCom);

    sVector->push_back(tmpState);

    std::cout << "\nWould you like to save the current sim?" << std::endl;
    std::cout << "\t0: Yes\n\t1: No" << std::endl;
    std::cout << "Please choose the apropriate option: ";
    std::string sOptionSelector;
    selection = getOption();

    switch (selection)
    {
    case 0:
        this->saveToFile(tmpState, 1);
        break;
    
    default:
        break;
    }
}

void BuildSimulation::buildTestMode() {
    int selection = 0;

    std::cout << "\nWhat kind of rocket would you like to use?" << std::endl;
    std::cout << "\t0: Falcon 9\n\t1: Falcon Heavy" << std::endl;
    std::cout << "Please choose the apropriate option: ";
    selection = getOption();

    switch (selection)
    {
    case 0:
        this->test9();
        break;

    case 1:
        this->testHeavy();
        break;
    
    default:
        break;
    }
}

void BuildSimulation::test9() {
    int selection = 0;
    State* tmpState = this->getState();
    Falcon* tmpFalcon = (Falcon*)nineCreator->createSpacecraft();
    tmpState->setVessel(tmpFalcon);
    CheckEngineCommand* engCom;

    std::cout << "\nFalcon 9 has been created and is in the and engines have been added." << std::endl;
    std::cout << "Starting the engine tests" << std::endl;

    engCom = new CheckEngineCommand(tmpFalcon->getCoreList(), tmpFalcon->getVacuumEngine());
    tmpState->addCommand(engCom);
    tmpState->runCommands();

    std::cout << "Would you like to change the previous step?" << std::endl;
    std::cout << "\t0: Yes, I would like to change it.\n\t1: No, I would like to continue with the building process." << std::endl;
    std::cout << "Please choose the apropriate option: ";
    selection = getOption();

    switch (selection)
    {
    case 0:
        this->setMemento(rollBack->returnMemento());
        tmpState->remLastCommand();
        this->buildTestMode();
        break;

    case 1:
        rollBack->storeMemento(this->createMemento());
        this->testCrewAndSatellite();
        break;
    
    default:
        break;
    }
}

void BuildSimulation::testHeavy() {
    int selection = 0;
    State* tmpState = this->getState();
    Falcon* tmpFalcon = (Falcon*)heavyCreator->createSpacecraft();
    tmpState->setVessel(tmpFalcon);
    CheckEngineCommand* engCom;

    std::cout << "\nFalcon Heavy has been created and is in the and engines have been added." << std::endl;
    std::cout << "Starting the engine tests" << std::endl;

    engCom = new CheckEngineCommand(tmpFalcon->getCoreList(), tmpFalcon->getVacuumEngine());
    tmpState->addCommand(engCom);
    tmpState->runCommands();

    std::cout << "Would you like to change the previous step?" << std::endl;
    std::cout << "\t0: Yes, I would like to change it.\n\t1: No, I would like to continue with the building process." << std::endl;
    std::cout << "Please choose the apropriate option: ";
    selection = getOption();

    switch (selection)
    {
    case 0:
        this->setMemento(rollBack->returnMemento());
        tmpState->remLastCommand();
        this->buildTestMode();
        break;

    case 1:
        rollBack->storeMemento(this->createMemento());
        this->testCargo();
        break;
    
    default:
        break;
    }
}

void BuildSimulation::testCargo() {
    int selection = 0;
    State* tmpState = this->getState();
    Dragon* cargo;
    Loader* tmpLoader;
    StateChangeCommand* scCom;
    UnloadCommand* uCom;

    std::cout << "\nWhat kind of payload would you like to send?" << std::endl;
    std::cout << "\t0: Cargo" << std::endl;
    std::cout << "Please choose the apropriate option: ";
    selection = getOption();

    switch (selection)
    {
    case 0:
        cargo = new CargoDragon((Falcon*)tmpState->getVessel());
        tmpLoader = new Loader(cargo);
        tmpLoader->load(true);
        //tmpState->setVessel(cargo);

        std::cout << "\nCargo Dragon has been created and the cargo has been loaded." << std::endl;

        std::cout << "\nWould you like to change the previous step?" << std::endl;
        std::cout << "\t0: Yes, I would like to change it.\n\t1: No, I would like to continue with the building process." << std::endl;
        std::cout << "Please choose the apropriate option: ";
        selection = getOption();

        switch (selection)
        {
        case 0:
            this->setMemento(rollBack->returnMemento());
            this->testCargo();
            break;

        case 1:
            scCom = new StateChangeCommand((Falcon*)this->getState()->getVessel());
            tmpState->addCommand(scCom);
            tmpState->getCommands()[1]->execute();

            uCom = new UnloadCommand(tmpLoader);
            tmpState->addCommand(uCom);
            tmpState->getCommands()[2]->execute();

            rollBack->storeMemento(this->createMemento());
            std::cout << "\nWould you like to save the current sim?" << std::endl;
            std::cout << "\t0: Yes\n\t1: No" << std::endl;
            std::cout << "Please choose the apropriate option: ";
            selection = getOption();

            switch (selection)
            {
            case 0:
                this->saveToFile(tmpState, 1);
                break;
            
            default:
                break;
            }

            sVector->push_back(tmpState);

            break;
        
        default:
            break;
        }
    
    default:
        break;
    }
}

void BuildSimulation::testCrewAndSatellite() {
    int selection = 0;

    std::cout << "\nWhat kind of payload would you like to send?" << std::endl;
    std::cout << "\t0: Cargo and Crew\n\t1: Satellites" << std::endl;
    std::cout << "Please choose the apropriate option: ";
    std::cin >> selection;

    if (selection < 0 || selection > 1) {
        std::cout << "Choice is not a valid option." << std::endl;
        testCargo();
    }

    switch (selection)
    {
    case 0:
        this->testCrew();
        break;

    case 1:
        this->testSatellites();
        break;
    
    default:
        break;
    }
}

void BuildSimulation::testCrew() {
    int selection = 0;
    State* tmpState = this->getState();
    Dragon* cargo;
    Loader* tmpLoader;
    StateChangeCommand* scCom;
    UnloadCommand* uCom;

    cargo = new CrewDragon((Falcon*)tmpState->getVessel());
    tmpLoader = new Loader(cargo);
    tmpLoader->load(true);
    //tmpState->setVessel(cargo);

    std::cout << "\nCrew Dragon has been created, the cargo has been loaded and the crew have boarded." << std::endl;

    std::cout << "\nWould you like to change the previous step?" << std::endl;
    std::cout << "\t0: Yes, I would like to change it.\n\t1: No, I would like to continue with the building process." << std::endl;
    std::cout << "Please choose the apropriate option: ";
    std::cin >> selection;
        
    switch (selection)
    {
    case 0:
        this->setMemento(rollBack->returnMemento());
        this->testCrewAndSatellite();
        break;

    case 1:
        scCom = new StateChangeCommand((Falcon*)this->getState()->getVessel());
        tmpState->addCommand(scCom);
        tmpState->getCommands()[1]->execute();

        uCom = new UnloadCommand(tmpLoader);
        tmpState->addCommand(uCom);
        tmpState->getCommands()[2]->execute();

        rollBack->storeMemento(this->createMemento());

        std::cout << "\nWould you like to save the current sim?" << std::endl;
        std::cout << "\t0: Yes\n\t1: No" << std::endl;
        std::cout << "Please choose the apropriate option: ";
        selection = getOption();

        switch (selection)
        {
        case 0:
            this->saveToFile(tmpState, 2);
            break;
        
        default:
            break;
        }

        sVector->push_back(tmpState);

        break;
    
    default:
        break;
    }
}

void BuildSimulation::testSatellites() {
    int satCount, selection = 0;
    State* tmpState = this->getState();
    Cluster* cluster;
    MissionControl* control;
    spreadCommand* spCom;
    StateChangeCommand* scCom;

    cluster = new Cluster((Falcon*)tmpState->getVessel());
    control = new MissionControl();

    std::cout << "\nHow many sattelites would you like to send?" << std::endl;
    std::cout << "Please input a number between 1 and 60 (inclusive): ";
    std::cin >> satCount;

    cluster->generateSatellites(control, satCount);
    tmpState->setCluster(cluster);

    std::cout << "\nCluster of " << satCount << " satellites has been created and loaded onto the rocket." << std::endl;

    scCom = new StateChangeCommand((Falcon*)this->getState()->getVessel());
    tmpState->addCommand(scCom);
    tmpState->getCommands()[1]->execute();

    spCom = new spreadCommand(cluster);
    tmpState->addCommand(spCom);
    tmpState->getCommands()[2]->execute();

    std::cout << "\nWould you like to change the previous step?" << std::endl;
    std::cout << "\t0: Yes, I would like to change it.\n\t1: No, I would like to continue with the building process." << std::endl;
    std::cout << "Please choose the apropriate option: ";
    selection = getOption();
        
    switch (selection)
    {
    case 0:
        this->setMemento(rollBack->returnMemento());
        tmpState->remLastCommand();
        tmpState->remLastCommand();
        this->testCrewAndSatellite();
        break;

    case 1:
        rollBack->storeMemento(this->createMemento());

        std::cout << "\nWould you like to save the current sim?" << std::endl;
        std::cout << "\t0: Yes\n\t1: No" << std::endl;
        std::cout << "Please choose the apropriate option: ";
        selection = getOption();

        switch (selection)
        {
        case 0:
            this->saveToFile(tmpState, 0);
            break;
        
        default:
            break;
        }

        sVector->push_back(tmpState);

        break;
    
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
