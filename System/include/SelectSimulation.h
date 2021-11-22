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
        std::vector<Memento*> prefabs; /**< The vector of Mementos to load the saved simulations into. */
        int iExit = 100; /**< The exit code. */
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

        /**
         *  @fn startSim(std::vector<State*>* sVector)
         *  @brief Starts the select simulation.
         *  
         *  @param[in] sVector A pointer to the vector of states used to run the simulations.
         *  
         *  @return void
         */
        virtual void startSim(std::vector<State*>* sVector) override;

        /**
         *  @fn simulateSingle(std::vector<State*>* sVector)
         *  @brief Simulate a single simulation.
         *  
         *  @param[in] sVector A pointer to the vector of states used to run the simulations.
         *  
         *  @return void
         */
        void simulateSingle(std::vector<State*>* sVector);

        /**
         *  @fn simulateBatch(std::vector<State*>* sVector)
         *  @brief The simulate multiple simulations.
         *  
         *  @param[in] sVector A pointer to the vector of states used to run the simulations.
         *  
         *  @return void
         */
        void simulateBatch(std::vector<State*>* sVector);

        /**
         *  @fn exitProgram()
         *  @brief Starts exit procedure.
         *  
         *  @return void
         */
        void exitProgram();

        /**
         *  @fn loadPrefabs()
         *  @brief Load saved simulations fro a file.
         *  
         *  @return void.
         */
        void loadPrefabs();
};

#endif  //SELECTSIMULATION_H
