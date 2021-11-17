#include "../include/Loader.h"

Loader::Loader(Dragon* dragon) {
    this->dragon = dragon;
}

Loader::~Loader() {
    if(dragon) {
        delete dragon;
    }
}

void Loader::load() {
    this->dragon->load();
}
