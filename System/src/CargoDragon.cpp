#include "../include/CargoDragon.h"

#include <iostream>
#include <sstream>

CargoDragon::CargoDragon(Falcon* falcon) : Dragon(falcon) {
    cargoList = new VectorOfCargo();
}

CargoDragon::~CargoDragon() {
    delete cargoList;
}

void CargoDragon::load(bool doPrint) {
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

void CargoDragon::unload(bool doPrint) {
    if(doPrint) {
        auto cargoIterator = cargoList->createIterator();
        while(!cargoIterator->isDone()) {
            std::cout << "Unloaded " << cargoIterator->next()->toString() << " from Dragon\n";
        }
    }
}
