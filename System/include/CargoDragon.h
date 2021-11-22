/****************************************************************************************************
 *  @file ./include/CargoDragon.h
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
#include "VectorOfCargo.h"

using namespace std;

class CargoDragon : public Dragon {
    public:
        /**
         *  @fn CargoDragon()
         *  @brief The constructor for the class.
         *  @param[in] Falcon* Falcon carrying that will carry this dragon spacecraft
         */
        CargoDragon(Falcon*);

        /**
         *  @fn ~CargoDragon()
         *  @brief The destructor for the class.
         */
        ~CargoDragon();

        /**
         *  @fn load()
         *  @brief Template method for loading Dragon content.
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

    private:
        VectorOfCargo* cargoList;  /**< The list of all the cargo stored in the Cargo Dragon. */
};	
#endif
