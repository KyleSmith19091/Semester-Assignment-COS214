#include "../include/Crew.h"
#include <iostream>

Crew::Crew(string name, string jobTitle){
    this->name = name;
    this->jobTitle = jobTitle;
}

Crew::~Crew() {
}

string Crew::getName(){
    return name;
}

string Crew::getJobTitle(){
    return jobTitle;
}

string Crew::toString(){
    return "["+name+"] => {Job Title: "+jobTitle + "}";
}
