/****************************************************************************************************
 *  @file CargoDragon.h
 *  @brief The header file for the CargoDragon class.
 ***************************************************************************************************/

#ifndef CARGO_DRAGON_HPP 
#define CARGO_DRAGON_HPP

/****************************************************************************************************
 *  @class CargoDragon
 *  @brief "Dragon specialisation to carry cargo only"
 ***************************************************************************************************/

#include "Dragon.h"
#include "Falcon.h"
#include "Cargo.h"
#include "Engine.h"

#include <vector>

using namespace std;

class CargoDragon : public Dragon {
    private:
        vector<Cargo*> cargoList;         
        Falcon* falconHeavy;

    public:
        /**
         *  @fn CargoDragon()
         *  @brief The constructor for the class.
         *  @param[in] Falcon* Falcon carrying that will carry this dragon spacecraft
         *  @param[in] vector<Cargo*> List of cargo to load
         */
        CargoDragon(Falcon*, vector<Cargo*>);

        /**
         *  @fn ~CargoDragon()
         *  @brief The destructor for the class.
         */
        ~CargoDragon();

        /**
         *  @fn load()
         *  @brief Template method for loading Dragon content.
         *  @return void
         */
        void load() override;
};	
#endif
