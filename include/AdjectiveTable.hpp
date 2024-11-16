#ifndef ADJECTIVE_TABLE_H
#define ADJECTIVE_TABLE_H

#include <avr/pgmspace.h>

const char adjective_0[] PROGMEM =  "weak";
const char adjective_1[] PROGMEM =  "crusty";
const char adjective_2[] PROGMEM =  "ugly";
const char adjective_3[] PROGMEM =  "thick";
const char adjective_4[] PROGMEM =  "toxic";
const char adjective_5[] PROGMEM =  "utter";
const char adjective_6[] PROGMEM =  "brash";
const char adjective_7[] PROGMEM =  "stupid";
const char adjective_8[] PROGMEM =  "pompous";
const char adjective_9[] PROGMEM =  "spotty";
const char adjective_10[] PROGMEM = "zitty";
const char adjective_11[] PROGMEM = "dim";
const char adjective_12[] PROGMEM = "scabby";
const char adjective_13[] PROGMEM = "smelly";
const char adjective_14[] PROGMEM = "filthy";
const char adjective_15[] PROGMEM = "dirty";
const char adjective_16[] PROGMEM = "failed";
const char adjective_17[] PROGMEM = "daft";
const char adjective_18[] PROGMEM = "little";
const char adjective_19[] PROGMEM = "sweaty";
const char adjective_20[] PROGMEM = "silly";
const char adjective_21[] PROGMEM = "dozy";
const char adjective_22[] PROGMEM = "vapid";
const char adjective_23[] PROGMEM = "oozing";
const char adjective_24[] PROGMEM = "odorous";
const char adjective_25[] PROGMEM = "odious";
const char adjective_26[] PROGMEM = "old";
const char adjective_27[] PROGMEM = "wet";
const char adjective_28[] PROGMEM = "stinky";
const char adjective_29[] PROGMEM = "slimy";
const char adjective_30[] PROGMEM = "grimy";
const char adjective_31[] PROGMEM = "boring";
const char adjective_32[] PROGMEM = "dusty";
const char adjective_33[] PROGMEM = "foolish";
const char adjective_34[] PROGMEM = "sleazy";
const char adjective_35[] PROGMEM = "watery";
const char adjective_36[] PROGMEM = "dull";
const char adjective_37[] PROGMEM = "useless";
const char adjective_38[] PROGMEM = "oily";
const char adjective_39[] PROGMEM = "greasy";
const char adjective_40[] PROGMEM = "sodding";
const char adjective_41[] PROGMEM = "brash";
const char adjective_42[] PROGMEM = "shady";
const char adjective_43[] PROGMEM = "gaudy";
const char adjective_44[] PROGMEM = "stale";
const char adjective_45[] PROGMEM = "prickly";
const char adjective_46[] PROGMEM = "mangy";


const char *const adjective_table[] PROGMEM = { adjective_0,
                                                adjective_1,
                                                adjective_2,
                                                adjective_3,
                                                adjective_4,
                                                adjective_5,
                                                adjective_6,
                                                adjective_7,
                                                adjective_8,
                                                adjective_9,
                                                adjective_10,
                                                adjective_11,
                                                adjective_12,
                                                adjective_13,
                                                adjective_14,
                                                adjective_15,
                                                adjective_16,
                                                adjective_17,
                                                adjective_18,
                                                adjective_19,
                                                adjective_20,
                                                adjective_21,
                                                adjective_22,
                                                adjective_23,
                                                adjective_24,
                                                adjective_25,
                                                adjective_26,
                                                adjective_27,
                                                adjective_28,
                                                adjective_29,
                                                adjective_30,
                                                adjective_31,
                                                adjective_32,
                                                adjective_33,
                                                adjective_34,
                                                adjective_35,
                                                adjective_36,
                                                adjective_37,
                                                adjective_38,
                                                adjective_39,
                                                adjective_40,
                                                adjective_41,
                                                adjective_42,
                                                adjective_43,
                                                adjective_44,
                                                adjective_45
                                              };

const uint8_t adjectiveCount = sizeof(adjective_table) / sizeof(adjective_table[0]);

#endif
