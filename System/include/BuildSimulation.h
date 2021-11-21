/****************************************************************************************************
 *  @file inc/BuildSimulation.h
 *  @brief The header file for the BuildSimulation class.
 ***************************************************************************************************/

#ifndef BUILDSIMULATION_H
#define BUILDSIMULATION_H

#include <fstream>
#include <regex>

#include "Store.h"
#include "Simulation.h" 
/****************************************************************************************************
 *  @class BuildSimulation
 *  @brief The implementation of the building process.
 ***************************************************************************************************/
class BuildSimulation : public Simulation
{
    private:
        static const std::string DELIMITER;
        static const std::string TYPE_SATELLITE;
        static const std::string TYPE_CREW;
        static const std::string TYPE_CARGO;

        Store* rollBack;
        int iExit = 100;

        SpacecraftCreator* heavyCreator = new FalconHeavyCreator();
        SpacecraftCreator* nineCreator = new Falcon9Creator();

        std::vector<State*>* sVector;
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

        void buildMode();
        void buildTestMode();
        void exitProgram();
        void saveToFile(State* s, int t);

        void buildSattelites();
        void buildCrew();
        void buildCargo();

        void test9();
        void testHeavy();
        void testCargo();
        void testCrewAndSatellite();
        void testCrew();
        void testSatellites();
};

#endif  //BUILDSIMULATION_H
