/****************************************************************************************************
 *  @file ./include/Loader.h
 *  @brief The header file for the Loader class.
 ***************************************************************************************************/

#ifndef LOADER_H
#define LOADER_H

#include "Dragon.h"

/****************************************************************************************************
 *  @class Loader
 *  @brief "Context for loading dragon rocket"
 ***************************************************************************************************/

class Loader
{
    private:
        Dragon* dragon; /**< The Dragon to load. */

    public:
        /**
         *  @fn Loader()
         *  @brief The constructor for the class.
         */
        Loader(Dragon*);

        /**
         *  @fn ~Loader()
         *  @brief The destructor for the class.
         */
        ~Loader();

        /**
         *  @fn load()
         *  @brief Performs load action on member dragon.
         *  @param[in] bool Indicate whether to print loading data
         *  @return void
         */
        void load(bool);

        /**
         *  @fn unload()
         *  @brief Performs unload action on member dragon.
         *  @param[in] bool Indicate whether to print loading data
         *  @return void
         */
        void unload(bool);

        /**
         *  @fn ~setDragon()
         *  @brief Changes the reference to the dragon that is going to be loaded.
         *  @return void
         */
        void setDragon(Dragon*);
};

#endif  //LOADER_H
