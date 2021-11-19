#include "../include/KeplerianCoords.h"
#include <string>

KeplerianCoords::KeplerianCoords() {
    angle = 0;
    semiMajorAxis = 0;
    trueAnomaly = 0;
    rightAscension = 0;
    argumentOfPerigree = 0;
    srand(time(0));
}

KeplerianCoords::KeplerianCoords(int angle,int semiMajorAxis,int trueAnomaly,
        int rightAscension,int argumentOfPerigree) {
    
    this->angle = angle;
    this->semiMajorAxis = semiMajorAxis;
    this->trueAnomaly = trueAnomaly;
    this->rightAscension = rightAscension;
    this->argumentOfPerigree = argumentOfPerigree;
}

KeplerianCoords::~KeplerianCoords() {}

std::string KeplerianCoords::toString() const {
    std::string returnString = "";
    returnString += "<";
    returnString += "angle: " + std::to_string(angle) + ", ";
    returnString += "Semi-Major-Axis: " + std::to_string(semiMajorAxis) + ", ";
    returnString += "Right-Ascension: " + std::to_string(trueAnomaly) + ", ";
    returnString += "Argument-Of-Perigree: " + std::to_string(argumentOfPerigree) + ", ";
    returnString += "Eccentricty: " + std::to_string(eccentricty) + ">";

    return returnString;
}

void KeplerianCoords::randomiseCoords() {
    angle = rand() % 360;
    semiMajorAxis = rand() % 12000;
    trueAnomaly = rand() % 360;
    rightAscension = rand() % 360;
    argumentOfPerigree = rand() % 360;
}

bool KeplerianCoords::operator<(const KeplerianCoords & other) {
    return this->angle < other.angle && this->rightAscension < other.rightAscension;
}
