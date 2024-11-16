#ifndef COMMAND_TABLE_H
#define COMMAND_TABLE_H

#include <avr/pgmspace.h>
const char command_0[] PROGMEM =   "Move it";
const char command_1[] PROGMEM =    "Get bent";
const char command_2[] PROGMEM =    "Suck it";
const char command_3[] PROGMEM =    "Eat poop";
const char command_4[] PROGMEM =    "Go to hell";
const char command_5[] PROGMEM =    "Bugger off";
const char command_6[] PROGMEM =    "Bog off";
const char command_7[] PROGMEM =   "Pipe down";
const char command_8[] PROGMEM =   "Pound sand";
const char command_9[] PROGMEM =   "Sod off";
const char command_10[] PROGMEM =   "Naff off";
const char command_11[] PROGMEM =   "Take a hike";
const char command_12[] PROGMEM =   "Get a wash";
const char command_13[] PROGMEM =   "Leave me be";
const char command_14[] PROGMEM =   "Swivel on it";
const char command_15[] PROGMEM =   "Shut it";
const char command_16[] PROGMEM =   "Belt up";
const char command_17[] PROGMEM =   "Bite me";
const char command_18[] PROGMEM =   "Give over";
const char command_19[] PROGMEM =   "Buzz off";
const char command_20[] PROGMEM =   "Go whistle";
const char command_21[] PROGMEM =   "Bore off";
const char command_22[] PROGMEM =   "Touch grass";
const char command_23[] PROGMEM =   "Stuff off";
const char command_24[] PROGMEM =   "Get stuffed";
const char command_25[] PROGMEM =   "Jog on";


const char *const command_table[] PROGMEM = {command_0,
                                             command_1,
                                             command_2,
                                             command_3,
                                             command_4,
                                             command_5,
                                             command_6,
                                             command_7,
                                             command_8,
                                             command_9,
                                             command_10,
                                             command_11,
                                             command_12,
                                             command_13,
                                             command_14,
                                             command_15,
                                             command_16,
                                             command_17,
                                             command_18,
                                             command_19,
                                             command_20,
                                             command_21,
                                             command_22,
                                             command_23,
                                             command_24,
                                             command_25
                                            };

const uint8_t commandCount = sizeof(command_table) / sizeof(command_table[0]);

#endif
