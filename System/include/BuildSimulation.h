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

        /**
         *  @fn startSim(std::vector<State*>)
         *  @brief Starts the build simulation from given simulation states.
         *  @param[in] std::vector<State*> List of states of the current simulation.
         *  @return void
         */
        virtual void startSim(std::vector<State*>* v) override;

        /**
         *  @fn buildSim()
         *  @brief Build a simulation.
         *  @return void
         */
        void buildMode();

        /**
         *  @fn buildTestMode()
         *  @brief Build a test simulation.
         *  @return void
         */
        void buildTestMode();

        /**
         *  @fn exitProgram()
         *  @brief Starts exit procedure.
         *  @return void
         */
        void exitProgram();

        /**
         *  @fn saveToFile()
         *  @brief Used to save data to a file.
         *  @return void
         */
        void saveToFile(State* s, int t);

        /**
         *  @fn buildSattelites()
         *  @brief Build satellites for simulation.
         *  @param[in] std::vector<State*> List of states of the current simulation.
         *  @return void
         */
        void buildSattelites();

        /**
         *  @fn buildCrew()
         *  @brief Build crew members for simulation.
         *  @return void
         */
        void buildCrew();

        /**
         *  @fn buildCargo()
         *  @brief Build cargo for simulation.
         *  @return void
         */
        void buildCargo();

        /**
         *  @fn test9()
         *  @brief Perform test procedure for a falcon 9 rocket.
         *  @return void
         */
        void test9();

        /**
         *  @fn testHeavy()
         *  @brief Perform test procedure for a falcon heavy rocket.
         *  @return void
         */
        void testHeavy();

        /**
         *  @fn testCargo()
         *  @brief Perform test procedure for cargo.
         *  @return void
         */
        void testCargo();
        
        /**
         *  @fn testCrewAndSatellite()
         *  @brief Perform test procedure for Crew members and Satellites.
         *  @return void
         */
        void testCrewAndSatellite();

        /**
         *  @fn testCrew()
         *  @brief Perform test procedure for crew members on dragon rocket.
         *  @return void
         */
        void testCrew();

        /**
         *  @fn testSatellites()
         *  @brief Perform test procedure for Satellites.
         *  @return void
         */
        void testSatellites();
};

#endif  //BUILDSIMULATION_H
