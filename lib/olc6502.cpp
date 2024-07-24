#include "olc6504.h"

olc6504::olc6504() {
}

olc6504::~olc6504() {
}

uint8_t olc6504::read(uint16_t a) {
    return bus->read(a, false);
}

void olc6504::write(uint16_t a, uint8_t d) {
    bus->write(a, d);
}