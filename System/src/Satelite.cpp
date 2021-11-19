#include "../include/Satelite.h"

Satelite::Satelite() : Spacecraft("Satelite") {
}

Satelite::Satelite(const Satelite& s) : Spacecraft("Satelite") {
}

Satelite* Satelite::clone() {
    return new Satelite(*this);
}

void Satelite::spreadOut() {
    std::cout << "Positioning 🛰...";
    for(int count = 0;count < 10; ++count){
        cout << ">";
        fflush(stdout);
        usleep(10000);
    }
    cout << endl << "Done" << "\n";
}
