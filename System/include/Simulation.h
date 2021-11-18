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
        virtual std::vector<State*> startSim() = 0;

        std::string getFilePath();
};

#endif  //SIMULATION_H
