/****************************************************************************************************
 *  @file Engine.h
 *  @brief The header file for the Engine class.
 ***************************************************************************************************/

#ifndef ENGINE_H 
#define ENGINE_H



/****************************************************************************************************
 *  @class Engine
 *  @brief "Interface for Engine"
 ***************************************************************************************************/

class MerlinCore;

class Engine {
    private:
        MerlinCore* mediator;
        bool on;

    protected:
        /**
         *  @fn getOn()
         *  @brief Get on state.
         *  @return void
         */
        virtual bool getOn() const;

        /**
         *  @fn setOn()
         *  @brief Set on state.
         *  @return void
         */
        virtual void setOn();

        /**
         *  @fn clone()
         *  @brief Clone current engine.
         *  @return Engine* 
         */
        virtual Engine* clone();

        /**
         *  @fn checkTemp()
         *  @brief Check Temperature of Engine.
         *  @return void
         */
        virtual void checkTemp();

        /**
         *  @fn checkOil()
         *  @brief Check Oil level in Engine.
         *  @return void
         */
        virtual void checkOil();

        /**
         *  @fn staticFire()
         *  @brief Perform Static Fire Test.
         *  @return void
         */
        virtual void staticFire();
    
    public:
        /**
         *  @fn Engine()
         *  @brief The constructor for the class.
         */
        Engine();

        /**
         *  @fn Engine()
         *  @brief The constructor for the class.
         *  @param[in] MerlinCore* Desc
         */
        Engine(MerlinCore*);

        /**
         *  @fn ~Engine()
         *  @brief The destructor for the class.
         */
        ~Engine();

        /**
         *  @fn turnOn()
         *  @brief Turn engine on.
         */
        void turnOn();

        /**
         *  @fn checkEngine()
         *  @brief Template method to check the engine.
         */
        void checkEngine();

};
#include "MerlinCore.h"	
#endif
