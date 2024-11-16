#ifndef OBSERVATION_TABLE_H
#define OBSERVATION_TABLE_H

#include "main.hpp"

const char observation_0[] PROGMEM = "You total";
const char observation_1[] PROGMEM = "You're a real";
const char observation_2[] PROGMEM = "You're such a";
const char observation_3[] PROGMEM = "You utter";
const char observation_4[] PROGMEM = "You complete";
const char observation_5[] PROGMEM = "You";
const char observation_6[] PROGMEM = "What an utter";
const char observation_7[] PROGMEM = "You're a";
const char observation_8[] PROGMEM = "You look like a";
const char observation_9[] PROGMEM = "You're a pukka";
const char observation_10[] PROGMEM = "You prized";
const char observation_11[] PROGMEM = "You're quite the";
const char observation_12[] PROGMEM = "Wow, you're a";
const char observation_13[] PROGMEM = "Gosh, what a";
const char observation_14[] PROGMEM = "What a perfect";
const char observation_15[] PROGMEM = "Gee, what a";





const char *const observation_table[] PROGMEM = {observation_0,
                                                 observation_1,
                                                 observation_2,
                                                 observation_3,
                                                 observation_4,
                                                 observation_5,
                                                 observation_6,
                                                 observation_7,
                                                 observation_8,
                                                 observation_9,
                                                 observation_10,
                                                 observation_11,
                                                 observation_12,
                                                 observation_13,
                                                 observation_14,
                                                 observation_15
                                                };

const uint8_t observationCount = sizeof(observation_table) / sizeof(observation_table[0]);

#endif
