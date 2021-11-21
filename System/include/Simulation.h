/****************************************************************************************************
 *  @file inc/Simulation.h
 *  @brief The header file for the Simulation class.
 ***************************************************************************************************/

#ifndef SIMULATION_H
#define SIMULATION_H

#include <iostream>
#include <vector>

#include "State.h"
#include "Memento.h"
#include "Cargo.h"
#include "VectorOfCargo.h"
#include "CargoIterator.h"
#include "CarryType.h"
#include "CrewDragon.h"
#include "CargoDragon.h"
#include "Loader.h"
#include "Falcon.h"
#include "Cluster.h"
#include "Falcon9Creator.h"
#include "FalconHeavyCreator.h"
/****************************************************************************************************
 *  @class Simulation
 *  @brief The interface for all Simulations.
 ***************************************************************************************************/
class Simulation
{
    private:
        State* state;
        std::string filePath = "../Data/prefabs.txt";
    public:
        /**
         *  @fn Simulation()
         *  @brief The constructor for the class.
         */
        Simulation();

        /**
         *  @fn virtual ~Simulation()
         *  @brief The destructor for the class.
         */
        virtual ~Simulation();

        /**
         *  @fn Memento* createMemento()
         *  @brief The function to create the memento.
         */
        Memento* createMemento();

        /**
         *  @fn void setMemento(Memento* m);
         *  @brief The function will set the state according to the memento.
         *  
         *  @param[in]  m   The passed in memento object.
         */
        void setMemento(Memento* m);

        /**
         *  @fn virtual std::vector<State*> startSim() = 0;
         *  @brief The pure virtual function to start the current sim.
         *  
         *  @return std::vector<State*>: States to run.
         */
        virtual void startSim(std::vector<State*>* sVector) = 0;

        std::string getFilePath();
};

#endif  //SIMULATION_H
