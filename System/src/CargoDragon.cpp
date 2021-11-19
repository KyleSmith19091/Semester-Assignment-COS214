#include "../include/CargoDragon.h"

#include <iostream>
#include <sstream>

CargoDragon::CargoDragon(Falcon* falcon) : Dragon(falcon) {
}

CargoDragon::~CargoDragon() {
    for(auto it = cargoList.begin(); it != cargoList.end(); ++it) {
        delete (*it);
    }
}

void CargoDragon::load() {
    std::ifstream cargoData("../Data/CargoList.txt");

    if(cargoData.is_open()) {
        std::string cargoItem, description, weight;
        while(getline(cargoData,cargoItem)) {
            std::stringstream ss(cargoItem); 
            getline(ss,description,',');
            getline(ss,weight);
            cargoList.push_back(new Cargo(description,stod(weight)));
        }
    } else {
        std::cerr << __FILE__ << " " << __LINE__ << " Could not open CargoList";
    }

}
