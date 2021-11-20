#include "../include/CrewDragon.h"
#include <iostream>
#include <sstream>

CrewDragon::CrewDragon(Falcon* falcon) : Dragon(falcon) {
    crewMembers = new LinkedListOfCrew();
    cargoList = new VectorOfCargo();
}

CrewDragon::~CrewDragon() {
    delete cargoList;
    delete crewMembers;
}

void CrewDragon::load(bool doPrint) {
    std::ifstream crewData("../Data/CrewManifest.txt");

    if(crewData.is_open()) {
        std::string crewMember, name, title;
        while(getline(crewData,crewMember)) {
            std::stringstream ss(crewMember); 
            getline(ss,name,',');
            getline(ss,title,',');
            crewMembers->addCrewMember(new Crew(name,title));
            if(doPrint) {
                std::cout << "[" << name << "]" <<  " boarded Dragon\n";
            }
        }

    } else {
        std::cerr << __FILE__ << " " << __LINE__ << " Could not open CrewManifest";
    }

    std::ifstream cargoData("../Data/CargoList.txt");

    if(cargoData.is_open()) {
        std::string cargoItem, description, weight;
        while(getline(cargoData,cargoItem)) {
            std::stringstream ss(cargoItem); 
            getline(ss,description,',');
            getline(ss,weight);
            cargoList->addCargo(new Cargo(description,stod(weight)));
            if(doPrint) {
                std::cout << "Loaded [" << description << "]" << " {" << weight << "kg} into Dragon\n";
            }
        }
    } else {
        std::cerr << __FILE__ << " " << __LINE__ << " Could not open CargoList";
    }

}
