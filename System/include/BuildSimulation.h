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
        static const std::string DELIMITER; /**< Constant variable used to determine the delimiter of the information in the saved simulations. */
        static const std::string TYPE_SATELLITE; /**< Constant variable used to determine the type of payload. */
        static const std::string TYPE_CREW; /**< Constant variable used to determine the type of payload. */
        static const std::string TYPE_CARGO; /**< Constant variable used to determine the type of payload. */

        Store* rollBack; /**< The caretaker to be used when redoing a step of the test process. */
        int iExit = 100; /**< The code to exit the program. */

        SpacecraftCreator* heavyCreator = new FalconHeavyCreator(); /**< The factory used to create Falcon Heavy rockets. */
        SpacecraftCreator* nineCreator = new Falcon9Creator(); /**< The factory used to create Falcon 9 rockets. */

        std::vector<State*>* sVector; /**< A pointer to the vector of states used to run the simulations. */
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
         *  @fn startSim(std::vector<State*>* v)
         *  @brief Starts the build simulation.
         *  
         *  @param[in] v A pointer to the vector of states used to run the simulations.
         *  
         *  @return void
         */
        virtual void startSim(std::vector<State*>* v) override;

        /**
         *  @fn buildMode()
         *  @brief Build a simulation.
         *  
         *  @return void
         */
        void buildMode();

        /**
         *  @fn buildTestMode()
         *  @brief Build a simulation in test mode.
         *  
         *  @return void
         */
        void buildTestMode();

        /**
         *  @fn exitProgram()
         *  @brief Starts exit procedure.
         *  
         *  @return void
         */
        void exitProgram();

        /**
         *  @fn saveToFile(State* s, int t)
         *  @brief Used to save data to a file.
         *  
         *  @param[in]  s   The state to save to the file.
         *  @param[in]  t   The id used to determine the type of payload.
         *  
         *  @return void
         */
        void saveToFile(State* s, int t);

        /**
         *  @fn buildSattelites()
         *  @brief Build satellites for simulation.
         *  
         *  @return void
         */
        void buildSattelites();

        /**
         *  @fn buildCrew()
         *  @brief Build crew members for simulation.
         *  
         *  @return void
         */
        void buildCrew();

        /**
         *  @fn buildCargo()
         *  @brief Build cargo for simulation.
         *  
         *  @return void
         */
        void buildCargo();

        /**
         *  @fn test9()
         *  @brief Perform test procedure for a falcon 9 rocket.
         *  
         *  @return void
         */
        void test9();

        /**
         *  @fn testHeavy()
         *  @brief Perform test procedure for a falcon heavy rocket.
         *  
         *  @return void
         */
        void testHeavy();

        /**
         *  @fn testCargo()
         *  @brief Perform test procedure for cargo.
         *  
         *  @return void
         */
        void testCargo();
        
        /**
         *  @fn testCrewAndSatellite()
         *  @brief Perform test procedure for Crew members and Satellites.
         *  
         *  @return void
         */
        void testCrewAndSatellite();

        /**
         *  @fn testCrew()
         *  @brief Perform test procedure for crew members on dragon rocket.
         *  
         *  @return void
         */
        void testCrew();

        /**
         *  @fn testSatellites()
         *  @brief Perform test procedure for Satellites.
         *  
         *  @return void
         */
        void testSatellites();
};

#endif  //BUILDSIMULATION_H
