#include "RandomNoDupes.hpp"

RandomNoDupes::RandomNoDupes() : lastRandom(255) {}

// Generates a random number within the specified range.
uint8_t RandomNoDupes::next(uint8_t range) {
    // If range is less than 2, toggle between 0 and 1 as meaningful random generation is not possible
    if (range < 2) {
        lastRandom = !lastRandom; // Flip between 0 and 1
        return lastRandom;
    }

    uint8_t newRandom;
    do {
        newRandom = random(range); // Generate a new random number in the given range
    } while (newRandom == lastRandom); // Repeat until the new number is not the same as the last one

    lastRandom = newRandom; // Update the last generated random number
    return newRandom; // Return the new random number
}
