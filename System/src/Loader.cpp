#include "../include/Loader.h"

Loader::Loader(Dragon* dragon) {
    this->dragon = dragon;
}

Loader::~Loader() {
}

void Loader::load(bool doPrint) {
    this->dragon->load(doPrint);
}

void Loader::unload(bool doPrint) {
    this->dragon->unload(doPrint);
}

void Loader::setDragon(Dragon* newDragon) {
    delete dragon;
    this->dragon = newDragon;
}
