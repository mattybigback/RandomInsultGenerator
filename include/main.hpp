/*
    Pin mappings changed to make use of the LCD keypad shield.

    lcd RS pin to digital pin 8
    lcd Enable pin to digital pin 9
    lcd D4 pin to digital pin 4
    lcd D5 pin to digital pin 5
    lcd D6 pin to digital pin 6
    lcd D7 pin to digital pin 7

    lcd backlight digital pin 10
    button to digital pin A0
    Leave A1 floating    
*/

#ifndef MAIN_H
#define MAIN_H

// Libraries
#include <Arduino.h>
#include <LiquidCrystal.h>
#include <avr/pgmspace.h>
#include <DebouncedButton.hpp>
#include <RandomNoDupes.hpp>
// Word Tables
#include <AdjectiveTable.hpp>
#include <CommandTable.hpp>
#include <InsultTable.hpp>
#include <ObservationTable.hpp>
#include <SplashMessages.hpp>

#include "PrintMessage.hpp"
#include "InsultMe.hpp"
#include "SplashScreen.hpp"
#include "StringUtils.hpp"

//Pin Assignments
#define BUTTON_PIN A0
#define RANDOM_SEED_PIN A1
#define BACKLIGHT_PIN 10
#define LCD_RS 8
#define LCD_EN 9
#define LCD_D4 4
#define LCD_D5 5
#define LCD_D6 6
#define LCD_D7 7


//LCD Properties
#define LCD_WIDTH 16
#define LCD_HEIGHT 2
#define BUFFER_SIZE ((LCD_WIDTH * LCD_HEIGHT)+ LCD_HEIGHT) //Enough for a trailing space on each line


#define BAUD_RATE 9600
#define DEBUG 0

#if DEBUG == 1
    #define debugPrint(x) Serial.print(x)
    #define debugPrintLn(x) Serial.println(x)
    #define debugWrite(x) Serial.write(x)
    #define debugSetup(x) Serial.begin(x)
    #else
    #define debugPrint(x)
    #define debugPrintLn(x)
    #define debugWrite(x)
    #define debugSetup(x)
#endif


const uint16_t insultTime = 8000;
const uint16_t splashTime = 10000;
const uint16_t scrollTick = 250;

// Holds the current and last states of the button
extern uint8_t buttonState;
extern uint8_t lastButtonState;

// Holds the current and previous timer readings
extern uint32_t timer;
extern uint32_t timerOld;

// Status variable that keeps track of which screen is visible
extern uint8_t screenNumber;
extern uint8_t brightness;

extern LiquidCrystal lcd;

extern DebouncedButton btnInsult;


// void splashScreen();
// void insultMe();
// void copyMessageSubset(char *dest, const char *progmemMessage, uint8_t start, uint8_t length);
// void printMessage(char *message);
// void updateScrollBuffer(char *buffer, const char *message, int scrollPosition, uint8_t bufferSize);

#endif