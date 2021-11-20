/****************************************************************************************************
 *  @file ./include/MerlinCore.h
 *  @brief The header file for the MerlinCore class.
 ***************************************************************************************************/

#ifndef MERLINCORE_H
#define MERLINCORE_H

#include <vector>

class Engine;

using namespace std;

/****************************************************************************************************
 *  @class MerlinCore
 *  @brief "Insert brief description here."
 ***************************************************************************************************/
class MerlinCore {

private:
    vector<Engine*> engineList;// list of engines
public:
    /**
     *  @fn MerlinCore()
     *  @brief The constructor for the class.
     */
    MerlinCore();

    /*
     * @fn on(Engine* colleague)
     * @brief Sets the on to true for the engine parameter
     * @param[in] Engine* that will be turned on
     * @return void
     */
    void on(Engine* colleague);

    /*
     * @fn off(Engine* colleague)
     * @brief Sets the on to false for the engine parameter
     * @param[in] Engine* that will be turned off
     * @return void
     */
    void off(Engine* colleague);
    /**
     *  @fn ~MerlinCore()
     *  @brief The destructor for the class.
     */
    ~MerlinCore();
    /*
     * @fn initiateEngineChecks()
     * @brief check every engine
     * @return void
     */
    void initiateEngineChecks();
};

#include "Engine.h"

#endif  //MERLINCORE_H
