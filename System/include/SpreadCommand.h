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
        Cluster* myCluster; /**< The cluster of satellites to be used as a reciever. */
    public:
        /**
         *  @fn spreadCommand()
         *  @brief The constructor for the class.
         *  
         *  @param[in]  c   The cluster to be used.
         */
        spreadCommand(Cluster* c);

        /**
         *  @fn ~spreadCommand()
         *  @brief The destructor for the class.
         */
        ~spreadCommand();

        /**
         *  @fn virtual void execute()
         *  @brief The implementation of the virtual execute method.
         *  
         *  @return void
         */
        void execute();
};

#endif  //SPREADCOMMAND_H
