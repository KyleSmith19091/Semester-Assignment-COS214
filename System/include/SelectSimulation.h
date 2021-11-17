/****************************************************************************************************
 *  @file inc/SelectSimulation.h
 *  @brief The header file for the SelectSimulation class.
 ***************************************************************************************************/

#ifndef SELECTSIMULATION_H
#define SELECTSIMULATION_H

#include <vector>
#include <fstream>

#include "Store.h"
#include "Simulation.h"
/****************************************************************************************************
 *  @class SelectSimulation
 *  @brief "Insert brief description here."
 ***************************************************************************************************/
class SelectSimulation : public Simulation
{
    private:
        Store* store;
        std::vector<Memento*> prefabs;
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

        virtual void startSim() override;
};

#endif  //SELECTSIMULATION_H
