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

class Command;
/****************************************************************************************************
 *  @class State
 *  @brief The abstraction of the State of the simulation.
 ***************************************************************************************************/
class State
{
    private:
        std::string name; /**< The name of the simulation. */
        Spacecraft* vessel; /**< The current working spacecraft. */
        Cluster* satellites; /**< The cluster of satellites. */
        std::vector<Command*> commands; /**< The vector of commands to execute on the spacecraft. */

    public:
        /**
         *  @fn State()
         *  @brief The constructor for the class.
         */
        State();

        /**
         *  @fn State()
         *  @brief The copy constructor for the class.
         *  
         *  @param[in]  s   The State to copy.
         */
        State(State* s);

        /**
         *  @fn State()
         *  @brief The overloaded constructor for the class to be used with a name and a spacecraft.
         *  
         *  @param[in]  n   The name of the simulation.
         *  @param[in]  s   The spacecraft that will be used.
         */
        State(std::string n, Spacecraft* s);

        /**
         *  @fn State()
         *  @brief The overloade constructor for the class to be used with a name and a cluster.
         *  
         *  @param[in]  n   The name of the simulation.
         *  @param[in]  c   The cluster to be used.
         */
        State(std::string n, Cluster* c);

        /**
         *  @fn ~State()
         *  @brief The destructor for the class.
         */
        ~State();

        /**
         *  @fn getName()
         *  @brief The getter for the name of the simulation.
         *  
         *  @return std::string
         */
        std::string getName();

        /**
         *  @fn setName(std::string s)
         *  @brief The setter for the name of the simulation.
         *  
         *  @param[in]  s   The name of the simulation.
         *  
         *  @return void
         */
        void setName(std::string s);

        /**
         *  @fn getVessel()()
         *  @brief The getter for the spacecraft.
         *  
         *  @return Spacecraft*
         */
        Spacecraft* getVessel();

        /**
         *  @fn setVessel(Spacecraft* s)
         *  @brief The setter for the name of the simulation.
         *  
         *  @param[in]  s   The spacecraft.
         *  
         *  @return void
         */
        void setVessel(Spacecraft* s);

        /**
         *  @fn getCluster()
         *  @brief The getter for the cluster of satellites.
         *  
         *  @return Cluster*
         */
        Cluster* getCluster();

        /**
         *  @fn setCluster(Cluster* c)
         *  @brief The setter for the name of the simulation.
         *  
         *  @param[in]  c   The cluster of satellites.
         *  
         *  @return void
         */
        void setCluster(Cluster* c);

        /**
         *  @fn getCommands()
         *  @brief The getter for the commands to be executed.
         *  
         *  @return std::vector<Command*>
         */
        std::vector<Command*> getCommands();

        /**
         *  @fn addCommand(Command* c)
         *  @brief The method to add a command to the list of commands.
         *  
         *  @param[in]  c   The command to add.
         *  
         *  @return void
         */
        void addCommand(Command* c);

        /**
         *  @fn remLastCommand()
         *  @brief The method to pop the last command.
         *  
         *  @return void
         */
        void remLastCommand();

        /**
         *  @fn runCommands()
         *  @brief The method to execute all the commands in the list.
         *  
         *  @return void
         */
        void runCommands();
};

#include "Command.h"

#endif  //STATE_H
