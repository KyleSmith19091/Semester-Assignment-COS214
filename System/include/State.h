/****************************************************************************************************
 *  @file ./include/State.h
 *  @brief The header file for the State class.
 ***************************************************************************************************/

#ifndef STATE_H
#define STATE_H

#include <string>

#include "Spacecraft.h"
#include "Cluster.h"
#include "CrewDragon.h"
#include "CargoDragon.h"
#include "Loader.h"
#include "Command.h"

class Command;
/****************************************************************************************************
 *  @class State
 *  @brief The abstraction of the State of the simulation.
 ***************************************************************************************************/
class State
{
    private:
        std::string name;
        Spacecraft* vessel;
        Cluster* satellites;
        std::vector<Command*> commands;

    public:
        /**
         *  @fn State()
         *  @brief The constructor for the class.
         */
        State();

        /**
         *  @fn State()
         *  @brief The constructor for the class.
         */
        State(State* s);

        /**
         *  @fn State()
         *  @brief The constructor for the class.
         */
        State(std::string n, Spacecraft* s);

        /**
         *  @fn State()
         *  @brief The constructor for the class.
         */
        State(std::string n, Cluster* c);

        /**
         *  @fn ~State()
         *  @brief The destructor for the class.
         */
        ~State();

        std::string getName();
        void setName(std::string s);

        Spacecraft* getVessel();
        void setVessel(Spacecraft* s);

        Cluster* getCluster();
        void setCluster(Cluster* c);

        void addCommand(Command* c);
        void remLastCommand();
        void runCommands();
        std::vector<Command*> getCommands();
};

#endif  //STATE_H
