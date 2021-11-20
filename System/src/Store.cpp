#include "../include/Store.h"

Store::Store() {}

Store::~Store() {
    delete mem;
}

void Store::storeMemento(Memento* m) {
    mem = m;
}

Memento* Store::returnMemento() {
    return mem;
}