// RandomNoDupes.hpp

#ifndef RANDOM_NO_DUPES_HPP
#define RANDOM_NO_DUPES_HPP

#include <Arduino.h>

/**
 * @class RandomNoDupes
 * @brief Generates random numbers within a specified range, ensuring no consecutive duplicates.
 */
class RandomNoDupes {
  private:
    uint8_t lastRandom; ///< Stores the last generated random number.

  public:
    /**
     * @brief Constructs a new RandomNoDupes object.
     * 
     * Initializes the last random number to 255.
     */
    RandomNoDupes();

    /**
     * @brief Generates a random number within the specified range.
     * 
     * Ensures that the returned random number is not equal to the previously generated number.
     * 
     * @param range The range of random numbers (0 to range - 1).
     * @return A random number within the specified range.
     */
    uint8_t next(uint8_t range);
};

#endif // RANDOM_NO_DUPES_HPP
