/****************************************************************************************************
 *  @file ./include/Store.h
 *  @brief The header file for the Store class.
 ***************************************************************************************************/

#ifndef STORE_H
#define STORE_H

#include "Memento.h"
/****************************************************************************************************
 *  @class Store
 *  @brief "Insert brief description here."
 ***************************************************************************************************/
class Store
{
    private:
        Memento* mem;
    public:
        /**
         *  @fn Store()
         *  @brief The constructor for the class.
         */
        Store();

        /**
         *  @fn ~Store()
         *  @brief The destructor for the class.
         */
        ~Store();

        void storeMemento(Memento* m);

        Memento* returnMemento();
};

#endif  //STORE_H
