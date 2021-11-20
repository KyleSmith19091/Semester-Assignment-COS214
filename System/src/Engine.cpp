#include "../include/Engine.h"
#include <iostream>

Engine::Engine(){
    on = false;
}

Engine::Engine(MerlinCore* m){
    mediator = m;
}


Engine::~Engine(){
    if(mediator) {
        delete mediator;
    }  
}

void Engine::turnOn(){
    on=true;
}

void Engine::setOn(bool state) {
    on = state;
}

bool Engine::getOn() const {
    return on; 
}

void Engine::checkEngine(){
    checkTemperature();
    checkOil();
    startEngine();
    cout<<endl;	
}
