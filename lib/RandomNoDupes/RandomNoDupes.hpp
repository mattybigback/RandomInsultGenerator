// RandomNoDupes.hpp

#ifndef RANDOM_NO_DUPES_HPP
#define RANDOM_NO_DUPES_HPP

#include <Arduino.h>

class RandomNoDupes {
  private:
    uint8_t lastRandom;

  public:
    // Constructor initializes lastRandom to an impossible value
    RandomNoDupes();

    // Generates a new random number within the given range that is not equal to lastRandom
    uint8_t next(uint8_t range);
};

#endif // RANDOM_NO_DUPES_HPP
