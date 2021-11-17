#include "../include/Loader.h"

Loader::Loader(Dragon* dragon) {
    this->dragon = dragon;
}

Loader::~Loader() {
}

void Loader::load() {
    this->dragon->load();
}

void Loader::setDragon(Dragon* newDragon) {
    delete dragon;
    this->dragon = newDragon;
}
