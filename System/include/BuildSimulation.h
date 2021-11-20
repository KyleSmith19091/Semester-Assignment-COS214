/****************************************************************************************************
 *  @file inc/BuildSimulation.h
 *  @brief The header file for the BuildSimulation class.
 ***************************************************************************************************/

#ifndef BUILDSIMULATION_H
#define BUILDSIMULATION_H

#include <fstream>

#include "Store.h"
#include "Simulation.h" 
/****************************************************************************************************
 *  @class BuildSimulation
 *  @brief The implementation of the building process.
 ***************************************************************************************************/
class BuildSimulation : public Simulation
{
    private:
        Store* store;
        int iExit = 100;
    public:
        /**
         *  @fn BuildSimulation()
         *  @brief The constructor for the class.
         */
        BuildSimulation();

        /**
         *  @fn ~BuildSimulation()
         *  @brief The destructor for the class.
         */
        ~BuildSimulation();

        virtual void startSim(std::vector<State*>* v) override;

        void buildMode(std::vector<State*>* sVector);
        void buildTestMode(std::vector<State*>* sVector);
        void exitProgram();
        void saveToFile(State* s);

        void falconHeavy(int c, std::vector<State*>* sVector);
};

#endif  //BUILDSIMULATION_H
