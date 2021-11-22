/****************************************************************************************************
 *  @file ./include/CrewDragon
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
        LinkedListOfCrew* crewMembers; /**< The collection for the crew members. */
        VectorOfCargo* cargoList; /**< The collection for the cargo. */

    public:
        /**
         *  @fn CrewDragon(Falcon*)
         *  @brief The constructor for the class.
         *  @param[in] Faloon* Reference to Falcon carrying this Dragon
         */
        CrewDragon(Falcon*);

        /**
         *  @fn ~CrewDragon()
         *  @brief The destructor for the class.
         */
        ~CrewDragon();

        /**
         *  @fn load()
         *  @brief Method for loading Dragon content.
         *  @param[in] bool Indicate whether to print loading data
         *  @return void
         */
        void load(bool) override;

        /**
         *  @fn unload()
         *  @brief Method for unloading Dragon content.
         *  @param[in] bool Indicate whether to print loading data
         *  @return void
         */
        void unload(bool) override;
};	
#endif
