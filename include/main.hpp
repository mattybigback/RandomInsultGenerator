/**
 * @file main.hpp
 * @brief Main header file for the project.
 *
 * @mainpage Project Documentation
 *
 * @section intro_sec Introduction
 * This is the main header file for the project. It includes key project details.
 *
 * @section project_info Project Information
 * - **Application Name:** Random Insult Generator
 * - **Repository:** [GitHub](https://github.com/mattybigback/RandomInsultGenerator)
 * - **Website:** [https://mjharrison.co.uk](https://mjharrison.co.uk)
 * - **Author:** Matt Harrison
 * - **Version:** 2.1.0
 */

#ifndef MAIN_H
#define MAIN_H

// Libraries
#include <Arduino.h>
#include <LiquidCrystal.h>
#include <avr/pgmspace.h>
#ifdef BOARD_NANO_OLED
#include <Wire.h>
#endif
#include <DebouncedButton.hpp>
#include <RandomNoDupes.hpp>
// Word Tables
#include <Tables.hpp>

#include "PrintMessage.hpp"
#include "InsultMe.hpp"
#include "SplashScreen.hpp"
#include "StringUtils.hpp"

//Pin Assignments
#ifdef BOARD_UNO_SHIELD
#define BUTTON_PIN A0
#define RANDOM_SEED_PIN A1
#define BACKLIGHT_PIN 10
#define LCD_RS 8
#define LCD_EN 9
#define LCD_D4 4
#define LCD_D5 5
#define LCD_D6 6
#define LCD_D7 7
#endif
#ifdef BOARD_NANO_OLED
#define BUTTON_PIN 2
#define RANDOM_SEED_PIN A0
#define BACKLIGHT_PIN 10
#define LCD_RS 7
#define LCD_RW 9
#define LCD_EN 8
#define LCD_D4 3
#define LCD_D5 4
#define LCD_D6 5
#define LCD_D7 6
#endif


//LCD Properties
#define LCD_WIDTH 16
#define LCD_HEIGHT 2
#define BUFFER_SIZE ((LCD_WIDTH * LCD_HEIGHT)+ LCD_HEIGHT) //Enough for a trailing space on each line

#define DEBOUNCE_TIME_MS 50
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

// Screen timings
// Time to hold an insult on screen
const uint16_t insultTime = 8000;
// Time to hold splash on screen
const uint16_t splashTime = 10000;
// Time between scroll ticks. Lower number = faster scrolling
const uint16_t scrollTick = 180;

//Message to print on the first row of the splash screen - should be <= LCD_WIDTH
const char titleRow[] = "INSULTATRON 9000";


// External variableas
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


#endif