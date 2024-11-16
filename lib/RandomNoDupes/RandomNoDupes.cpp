// RandomNoDupes.cpp

#include "RandomNoDupes.hpp"

RandomNoDupes::RandomNoDupes() : lastRandom(255) {}

uint8_t RandomNoDupes::next(uint8_t range) {
    if (range < 2) {
        // Handle edge cases where range is less than 2
        lastRandom = !lastRandom;
        return lastRandom;
    }

    uint8_t newRandom;
    do {
        newRandom = random(range);
    } while (newRandom == lastRandom);

    lastRandom = newRandom;
    return newRandom;
}
