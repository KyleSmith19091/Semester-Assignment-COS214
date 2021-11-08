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

class CrewDragon : public Dragon {
    public:
        /**
         *  @fn CrewDragon()
         *  @brief The constructor for the class.
         */
        CrewDragon();

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
