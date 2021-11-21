/****************************************************************************************************
 *  @file ./include/spreadCommand.h
 *  @brief The header file for the spreadCommand class.
 ***************************************************************************************************/

#ifndef SPREADCOMMAND_H
#define SPREADCOMMAND_H

#include "Command.h"
#include "Cluster.h"
/****************************************************************************************************
 *  @class spreadCommand
 *  @brief Command to spread out the satellites.
 ***************************************************************************************************/
class spreadCommand : public Command
{
    private:
        Cluster* myCluster;
    public:
        /**
         *  @fn spreadCommand()
         *  @brief The constructor for the class.
         */
        spreadCommand(Cluster* c);

        /**
         *  @fn ~spreadCommand()
         *  @brief The destructor for the class.
         */
        ~spreadCommand();

        void execute();
};

#endif  //SPREADCOMMAND_H
