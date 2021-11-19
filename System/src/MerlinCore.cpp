#include "../include/MerlinCore.h"

/**
*  @fn MerlinCore()
*  @brief The constructor for the class.
*/
MerlinCore::MerlinCore(vector<Engine*> list) {
    engineList=list;
}

/* Destructor*/
MerlinCore::~MerlinCore() {
    for(auto it : engineList) {
        delete it;
    }
}

/*
 * @fn on(Engine* colleague)
 * @brief Sets the on to true for the engine parameter
 * @return void
*/
void MerlinCore::on(Engine *colleague) {
    colleague->setOn(true);
}

/*
 * @fn off(Engine* colleague)
 * @brief Sets the on to flase for the engine parameter
 * @return void
*/
void MerlinCore::off(Engine *colleague) {
    colleague->setOn(false);
}

void MerlinCore::initiateEngineChecks(){
    	vector<Engine*>::iterator it;

	for (it = engineList.begin(); it != engineList.end(); ++it)
		(*it)->checkEngine();
}
