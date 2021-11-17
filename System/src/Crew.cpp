#include "../include/Crew.h"
#include <iostream>

Crew::Crew(string name, string jobTitle){
    this->name = name;
    this->jobTitle = jobTitle;
}

string Crew::getName(){
    return name;
}

string Crew::getJobTitle(){
    return jobTitle;
}

string Crew::toString(){
    return "Crew Person Name: "+name+" Crew Person Job Title: "+jobTitle;
}
