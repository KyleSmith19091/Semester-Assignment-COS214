/****************************************************************************************************
 *  @file CrewDragon
 *  @brief The header file for the CrewDragon class.
 ***************************************************************************************************/

#ifndef CREW_DRAGON_H 
#define CREW_DRAGON_H

/****************************************************************************************************
 *  @class CrewDragon
 *  @brief "Specialisation for dragon to carry both cargo and crew"
 ***************************************************************************************************/

#include "Dragon.h"
#include "Crew.h"
#include "Cargo.h"
#include "LinkedListOfCrew.h"
#include "VectorOfCargo.h"

#include <vector>

class CrewDragon : public Dragon {
    private: 
        LinkedListOfCrew* crewMembers;
        VectorOfCargo* cargoList;

    public:
        CrewDragon(Falcon*);

        /**
         *  @fn ~CrewDragon()
         *  @brief The destructor for the class.
         */
        ~CrewDragon();

        /**
         *  @fn load()
         *  @brief Template Method for loading Dragon content.
         *  @param[in] bool Indicate whether to print loading data
         *  @return void
         */
        void load(bool) override;
};	
#endif
