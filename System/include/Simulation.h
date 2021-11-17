/****************************************************************************************************
 *  @file inc/Simulation.h
 *  @brief The header file for the Simulation class.
 ***************************************************************************************************/

#ifndef SIMULATION_H
#define SIMULATION_H

#include <iostream>

#include "State.h"
#include "Memento.h"
/****************************************************************************************************
 *  @class Simulation
 *  @brief "Insert brief description here."
 ***************************************************************************************************/
class Simulation
{
    private:
        State* state;
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
         *  @fn virtual void startSim() = 0;
         *  @brief The pure virtual function to start the current sim.
         */
        virtual void startSim() = 0;
};

#endif  //SIMULATION_H
