#ifndef SPLASHMESSAGE_TABLE_H
#define SPLASHMESSAGE_TABLE_H

#include "main.hpp"

const char splashMessage_00[] PROGMEM = "Don't press my buttons if you can't handle the banter";
const char splashMessage_01[] PROGMEM = "Not suitable for children";
const char splashMessage_02[] PROGMEM = "For when you have too much self esteem";
const char splashMessage_03[] PROGMEM = "Do you really want to do this?";
const char splashMessage_04[] PROGMEM = "This won't make you feel good about yourself.";




const char *const splashMessage_table[] PROGMEM = {
                                        splashMessage_00,
                                        splashMessage_01,
                                        splashMessage_02,
                                        splashMessage_03,
                                        splashMessage_04
                                        };

const uint8_t splashCount = sizeof(splashMessage_table) / sizeof(splashMessage_table[0]);

#endif