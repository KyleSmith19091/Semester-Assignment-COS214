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
#include "CheckEngineCommand.h"
#include "SpreadCommand.h"
#include "StateChangeCommand.h"
#include "UnloadCommand.h"
/****************************************************************************************************
 *  @class Simulation
 *  @brief The interface for all Simulations, the Originator for the Memento Design Pattern and the Reciever for the Command Design Pattern.
 ***************************************************************************************************/
class Simulation
{
    private:
        State* state; /**< The abstraction of the current state of the simulation. */
        std::string filePath = "../Data/prefabs.txt"; /**< The file path to the saved simulations. */
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
         *  
         *  @return Memento*
         */
        Memento* createMemento();

        /**
         *  @fn void setMemento(Memento* m);
         *  @brief The function will set the state according to the memento.
         *  
         *  @param[in]  m   The passed in memento object that will be used to reinstate the State object.
         *  
         *  @return void
         */
        void setMemento(Memento* m);

        /**
         *  @fn virtual std::vector<State*> startSim() = 0;
         *  @brief The pure virtual function to start the current sim.
         *  
         *  @param[in]  sVector A pointer to the vector of states used to run the simulations.
         *  
         *  @return void
         */
        virtual void startSim(std::vector<State*>* sVector) = 0;

        /**
         *  @fn std::string getFilePath();
         *  @brief The getter for the file path to the saved simulations.
         *  
         *  @return std::string
         */
        std::string getFilePath();

        /**
         *  @fn State* getState();
         *  @brief The getter for the abstraction of the current state.
         *  
         *  @return State*
         */
        State* getState();
};

#endif  //SIMULATION_H
