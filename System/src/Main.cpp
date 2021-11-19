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
#include <iostream>

const int iExit = 100;
bool bRunning = true;

void exitProgram();
void saveSimulation(/*sumulationObjectorType*/  );
void simTest();
void runSims(std::vector<State*> s);

int main() {
	simTest();

	return 0;
}

void simTest() {
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
            cout << "Please enter a 0 or a 1\n";
            cin >> optionSelector;
        }
        if (optionSelector==1)
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
                break;
            case 1:
                retVector.clear();
                sim->execute("s", &retVector);
                runSims(retVector);
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
	for (auto it = s.begin(); it != s.end(); it++) {
		cout << (*it)->getName() << endl;
	}
}