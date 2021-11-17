/****************************************************************************************************
 *  @file inc/BuildSimulation.h
 *  @brief The header file for the BuildSimulation class.
 ***************************************************************************************************/

#ifndef BUILDSIMULATION_H
#define BUILDSIMULATION_H

#include "Store.h"
#include "Simulation.h"
/****************************************************************************************************
 *  @class BuildSimulation
 *  @brief "Insert brief description here."
 ***************************************************************************************************/
class BuildSimulation : public Simulation
{
    private:
        Store* store;
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

        virtual void startSim() override;
};

#endif  //BUILDSIMULATION_H
