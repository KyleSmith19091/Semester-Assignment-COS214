/****************************************************************************************************
 *  @file inc/SelectSimulation.h
 *  @brief The header file for the SelectSimulation class.
 ***************************************************************************************************/

#ifndef SELECTSIMULATION_H
#define SELECTSIMULATION_H

#include <fstream>

#include "Store.h"
#include "Simulation.h"
/****************************************************************************************************
 *  @class SelectSimulation
 *  @brief The implementation of the selection process.
 ***************************************************************************************************/
class SelectSimulation : public Simulation
{
    private:
        std::vector<State*> sVector;
        Store* store;
        std::vector<Memento*> prefabs;
        int iExit = 100;
    public:
        /**
         *  @fn SelectSimulation()
         *  @brief The constructor for the class.
         */
        SelectSimulation();

        /**
         *  @fn ~SelectSimulation()
         *  @brief The destructor for the class.
         */
        ~SelectSimulation();

        virtual std::vector<State*> startSim() override;

        void simulateSingle();
        void simulateBatch();
        void exitProgram();
        void loadPrefabs();
};

#endif  //SELECTSIMULATION_H
