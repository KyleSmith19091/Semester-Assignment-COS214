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

#include <vector>

class CrewDragon : public Dragon {
    private: 
        std::vector<Crew*> crewMembers;
        std::vector<Cargo*> cargoList;

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
         *  @return void
         */
        void load() override;
};	
#endif
