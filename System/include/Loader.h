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
        Dragon* dragon;

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
         *  @fn ~Loader()
         *  @brief Performs load action on member dragon.
         *  @return void
         */
        void load();
};

#endif  //LOADER_H
