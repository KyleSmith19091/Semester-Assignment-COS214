/****************************************************************************************************
 *  @file ./include/Engine.h
 *  @brief The header file for the Engine class.
 ***************************************************************************************************/

#ifndef ENGINE_H 
#define ENGINE_H

class MerlinCore;       

class Engine {
    private:
        MerlinCore* mediator; /**< The core with which the Engine is registered. */
        bool on; /**< Boolean to determine whether the Engine is on or off. */

    protected:
        /**
         *  @fn getOn()
         *  @brief Get on state.
         *  @return void
         */
        virtual bool getOn() const;

        /**
         *  @fn checkTemp()
         *  @brief Check Temperature of Engine.
         *  @return void
         */
        virtual void checkTemperature()=0;

        /**
         *  @fn startEngine()
         *  @brief Completes the check up and finally start up the Engine.
         *  @return void
         */
        virtual void startEngine()=0;

        /**
         *  @fn checkOil()
         *  @brief Check Oil level in Engine.
         *  @return void
         */
        virtual void checkOil()=0;
    
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
        Engine(MerlinCore* m);

        /**
         *  @fn ~Engine()
         *  @brief The destructor for the class.
         */
        virtual ~Engine();

        /**
         *  @fn turnOn()
         *  @brief Turn engine on.
         *  @return void
         */
        void turnOn();

        /**
         *  @fn checkEngine()
         *  @brief Template method to check the engine.
         *  @return void
         */
        void checkEngine();

        /**
         *  @fn setOn()
         *  @brief Set on state.
         *  @param[in] bool The boolean to set the on state of the engine to.
         *  @return void
         */
        void setOn(bool);

        /**
         *  @fn clone()
         *  @brief clone an engine.
         *  @return Engine*
         */
        virtual Engine* clone()=0;


};
#include "MerlinCore.h"	
#endif
