#include "../include/SelectSimulation.h"
#include "../include/BuildCommand.h"
#include "../include/Cargo.h"
#include "../include/VectorOfCargo.h"
#include "../include/CargoIterator.h"
#include "../include/CarryType.h"
#include "../include/Simulate.h"
#include "../include/SelectCommand.h"
#include "../include/BuildCommand.h"
#include "../include/BuildSimulation.h"
#include "../include/Dragon.h"
#include "../include/CrewDragon.h"
#include "../include/CargoDragon.h"
#include "../include/Loader.h"
#include "../include/Falcon.h"
#include "../include/Satelite.h"
#include "../include/Cluster.h"
#include "../include/SatelliteCreator.h"
#include "../include/Falcon9Creator.h"
#include "../include/FalconHeavyCreator.h"
#include "../include/SpacecraftCreator.h"
#include <iostream>
#include <unistd.h>

const int iExit = 100;
bool bRunning = true;

void exitProgram();
void saveSimulation();
void simStart();
void runSims(std::vector<State*> s);

int main() {
	// ////////////////////////////////////////////////////////////////  State
    // std::cout << "----------------------------------------- STATE ---------------------------------------\n";
    // Falcon* falconWithState = new Falcon("Test");
    // std::cout << "Falcon current State: " << falconWithState->getCurrentState() << "\n";
    // falconWithState->change();
    // std::cout << "Falcon current State: " << falconWithState->getCurrentState() << "\n";
    // falconWithState->change();
    // std::cout << "Falcon current State: " << falconWithState->getCurrentState() << "\n";
    // falconWithState->change();
    // std::cout << "Falcon current State: " << falconWithState->getCurrentState() << "\n";
    // falconWithState->change();
    // std::cout << "Falcon current State: " << falconWithState->getCurrentState() << "\n";

	// ////////////////////////////////////////////////////////////////  Satelite
    // std::cout << "----------------------------------------- SATELLITE ---------------------------------------\n";
    // // Ground
    // MissionControl* control = new MissionControl();

    // Cluster* cluster = new Cluster(falconWithState);

    // cluster->generateSatellites(control,60);
    // cluster->spreadOutSatellites();

    // std::cout << "\n======Collision Testing======" << std::endl << std::endl << std::endl;

    // cluster->checkCollisions();

	//////////////////////////////////////////////////////////////// 
    std::cout << "----------------------------------------- SIM ---------------------------------------\n";

	simStart();

	return 0;
}

void simStart() {
    Command* sim = new Command();
    vector<State*> retVector;
    retVector.clear();
	SelectSimulation* selectSim = new SelectSimulation();
	BuildSimulation* buildSim = new BuildSimulation();
	SelectCommand* sCom = new SelectCommand(selectSim);
	BuildCommand* bCom = new BuildCommand(buildSim);

    sim->add(sCom);
    sim->add(bCom);
	
	while(bRunning == true){
        cout << "Welcome to Starlink. Here you can create and simulate various rockets.\n"
            	"Would you like to begin or exit?\n\t0: Begin\n\t1: Exit\n"
				"Please select the appropriate option: ";
        cin.clear();
        int optionSelector = -1;
        cin >> optionSelector;
        while (optionSelector != 0 && optionSelector != 1 && optionSelector != iExit){
            cout << "Please enter a 0 or a 1: \n";
            cin >> optionSelector;
        }
        if (optionSelector == 1)
            exitProgram();

        optionSelector = -1;
        cout << "\nWould you like to build a simulation or run a saved simulation. (At any point, input '100' to exit program)\n "
                "\t0: Build\n\t1: Load\n"
				"Please select the appropriate option: ";
        cin.clear();
        cin >> optionSelector;
        while (optionSelector != 0 && optionSelector != 1 && optionSelector !=iExit){
            cout << "Please enter a 0 or a 1: \n";
            cin >> optionSelector;
        }
        switch (optionSelector)
        {
            case 0:
                retVector.clear();
                sim->execute("b", &retVector);
                runSims(retVector);
                // delete sim;
				// delete sCom;
				// delete bCom;
				// delete selectSim;
				// delete buildSim;
                break;
            case 1:
                retVector.clear();
                sim->execute("s", &retVector);
                runSims(retVector);
                // delete sim;
				// delete sCom;
				// delete bCom;
				// delete selectSim;
				// delete buildSim;
                break;
            case iExit:
				delete sim;
				delete sCom;
				delete bCom;
				delete selectSim;
				delete buildSim;
                exitProgram();
                break;
        }
    }
}

void exitProgram(){
    cout << "\nAre you sure you want to exit?\n";
    cout << "Please type 'EXIT' if you wish to exit the program or a 0 if you do not \n";
    string optionSelector;
    cin >> optionSelector;
    while (optionSelector != "0"  && optionSelector !="EXIT"){
        cout << "Please type 'EXIT' or enter a 0:\n";
        cin >> optionSelector;
    }
    if (optionSelector=="EXIT")
        exit(0);
}

void runSims(vector<State*> s) {
    int i = 0;

    std::cout << "Would you like to run the returned simulation(s)?" << std::endl;
    std::cout << "\t0: Yes\n\t1: No and Exit\n";
    std::cout << "Please select the appropriate option: ";
    std::cin >> i;

    if (i < 0 || i > 1) {
        std::cout << "That was not a valid input." << std::endl;
        runSims(s);
    }

    if (i == 1)
        exitProgram();

	for (auto it = s.begin(); it != s.end(); it++) {
        std::cout << "=== Simulation " << ++i << " starting ===" << std::endl;
        (*it)->runCommands();
        
        if (s.size() > 1) {
            std::cout << "\nPreparing next simulation...\n" << std::endl;
            sleep(2);
        }
	}
}
