#include "../include/Cargo.h"
#include <iostream>

Cargo::Cargo(string type, double weight):CarryType(){
    this->type = type;
    this->weight = weight;
}

string Cargo::getType(){
    return type;
}

double Cargo::getWeight(){
    return weight;
}

void Cargo::setWeight(double d){
    weight = d;
}

void Cargo::setType(string s){
    type = s;
}

string Cargo::toString(){
    return "Cargo Type: "+type+" Cargo Weight: "+to_string(weight) ;
}
