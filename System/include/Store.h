/****************************************************************************************************
 *  @file ./include/Store.h
 *  @brief The header file for the Store class.
 ***************************************************************************************************/

#ifndef STORE_H
#define STORE_H

#include "Memento.h"
/****************************************************************************************************
 *  @class Store
 *  @brief The Caretaker for the Memento Design Pattern.
 ***************************************************************************************************/
class Store
{
    private:
        Memento* mem; /**< The memento to save. */
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

        /**
         *  @fn storeMemento(Memento* m)
         *  @brief The method to store a memento.
         *  
         *  @param[in]  m   The memento to save.
         *  
         *  @return void
         */
        void storeMemento(Memento* m);

        /**
         *  @fn returnMemento()
         *  @brief The getter for the stored memento.
         *  
         *  @return Memento*
         */
        Memento* returnMemento();
};

#endif  //STORE_H
