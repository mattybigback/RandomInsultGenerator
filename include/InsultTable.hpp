#ifndef INSULT_TABLE_H
#define INSULT_TABLE_H

#include <avr/pgmspace.h>
const char insult_0[] PROGMEM =  "fuzzball";
const char insult_1[] PROGMEM =  "plumhole";
const char insult_2[] PROGMEM =  "twit";
const char insult_3[] PROGMEM =  "smeghead";
const char insult_4[] PROGMEM =  "cretin";
const char insult_5[] PROGMEM =  "jamstain";
const char insult_6[] PROGMEM =  "douche";
const char insult_7[] PROGMEM =  "dumbass";
const char insult_8[] PROGMEM =  "freak";
const char insult_9[] PROGMEM =  "rat";
const char insult_10[] PROGMEM = "lummox";
const char insult_11[] PROGMEM = "fool";
const char insult_12[] PROGMEM = "sod";
const char insult_13[] PROGMEM = "clot";
const char insult_14[] PROGMEM = "dolt";
const char insult_15[] PROGMEM = "moron";
const char insult_16[] PROGMEM = "nimrod";
const char insult_17[] PROGMEM = "poophead";
const char insult_18[] PROGMEM = "veruca";
const char insult_19[] PROGMEM = "poopsack";
const char insult_20[] PROGMEM = "plonker";
const char insult_21[] PROGMEM = "snob";
const char insult_22[] PROGMEM = "prat";
const char insult_23[] PROGMEM = "troll";
const char insult_24[] PROGMEM = "wretch";
const char insult_25[] PROGMEM = "failure";
const char insult_26[] PROGMEM = "wannabe";
const char insult_27[] PROGMEM = "weirdo";
const char insult_28[] PROGMEM = "noob";
const char insult_29[] PROGMEM = "oddball";
const char insult_30[] PROGMEM = "bunghole";
const char insult_31[] PROGMEM = "muppet";
const char insult_32[] PROGMEM = "bozo";
const char insult_33[] PROGMEM = "wazzock";
const char insult_34[] PROGMEM = "berk";
const char insult_35[] PROGMEM = "dingus";
const char insult_36[] PROGMEM = "meatbag";
const char insult_37[] PROGMEM = "pig";
const char insult_38[] PROGMEM = "coot";
const char insult_39[] PROGMEM = "parasite";
const char insult_40[] PROGMEM = "git";
const char insult_41[] PROGMEM = "pillock";
const char insult_42[] PROGMEM = "minger";
const char insult_43[] PROGMEM = "urchin";
const char insult_44[] PROGMEM = "egghead";
const char insult_45[] PROGMEM = "edgelord";
const char insult_46[] PROGMEM = "dullard";
const char insult_47[] PROGMEM = "dipstick";
const char insult_48[] PROGMEM = "goon";
const char insult_49[] PROGMEM = "fleabag";

const char *const insult_table[] PROGMEM = {    insult_0,
                                                insult_1,
                                                insult_2,
                                                insult_3,
                                                insult_4,
                                                insult_5,
                                                insult_6,
                                                insult_7,
                                                insult_8,
                                                insult_9,
                                                insult_10,
                                                insult_11,
                                                insult_12,
                                                insult_13,
                                                insult_14,
                                                insult_15,
                                                insult_16,
                                                insult_17,
                                                insult_18,
                                                insult_19,
                                                insult_20,
                                                insult_21,
                                                insult_22,
                                                insult_23,
                                                insult_24,
                                                insult_25,
                                                insult_26,
                                                insult_27,
                                                insult_28,
                                                insult_29,
                                                insult_30,
                                                insult_31,
                                                insult_32,
                                                insult_33,
                                                insult_34,
                                                insult_35,
                                                insult_36,
                                                insult_37,
                                                insult_38,
                                                insult_39,
                                                insult_40,
                                                insult_41,
                                                insult_42,
                                                insult_43,
                                                insult_44,
                                                insult_45,
                                                insult_46,
                                                insult_47,
                                                insult_48,
                                                insult_49
                                           };
const uint8_t insultCount = sizeof(insult_table) / sizeof(insult_table[0]);
#endif
