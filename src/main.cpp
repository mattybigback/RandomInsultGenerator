/*
  Arduino sketch that generates an insulting sentence and displays it on a character display.
*/

#include "main.hpp"

uint8_t screenNumber = 1;
uint8_t brightness = 0xFF;
uint32_t timer = 0;
uint32_t timerOld = 0;

#ifdef BOARD_UNO_SHIELD
LiquidCrystal lcd(LCD_RS, LCD_EN, LCD_D4, LCD_D5, LCD_D6, LCD_D7);
#endif
#ifdef BOARD_NANO_OLED
LiquidCrystal lcd(LCD_RS, LCD_RW, LCD_EN, LCD_D4, LCD_D5, LCD_D6, LCD_D7);
#endif

DebouncedButton btnInsult(BUTTON_PIN, 50, LOW);

void setup() {
    debugSetup(BAUD_RATE);
    debugPrintLn("Booting...");
    pinMode(BUTTON_PIN, INPUT_PULLUP); // Set pinmode to input with internal pullup
    pinMode(BACKLIGHT_PIN, OUTPUT);    // Set pinmode to output
    digitalWrite(BACKLIGHT_PIN, HIGH); // Set backlight pin high
    uint8_t prngSeed = analogRead(RANDOM_SEED_PIN);
    debugPrint("PRNG seed value: ");
    debugPrintLn(prngSeed);
    randomSeed(prngSeed);             // Seed the random function with unconnected pin
    lcd.begin(LCD_WIDTH, LCD_HEIGHT); // Set up lcd display with correct size
    timer = millis();                 // Set up timer variable
    splashScreen();                   // Load splash screen
}

void loop() {
    if (btnInsult.wasPressed()) {  // If the button is in a different state to the last reading call the insult function
            insultMe();
    }
    timer = millis(); // Store the current timer value

    /*
      If there have been more than the set number of seconds between the old timer reading and
      the current timer reading AND the splash screen is not currently being displayed
      then call the splash screen
    */
    if (timer - timerOld >= insultTime && screenNumber == 1) {
        splashScreen();
    }

    /*
      If there have been more than the set numnber of seconds between the old timer reading and
      the current timer reading then dim the backlight and clear the screen.
    */
    if (screenNumber == 0 && brightness > 0) {
#if DEBUG == 1
        if (brightness == 255) {
            debugPrintLn("Dimming screen");
        }
#endif
        if (millis() % 50 == 0) {
            brightness--;
            analogWrite(BACKLIGHT_PIN, brightness);
        }
        if (brightness == 0) {
            lcd.clear();
            lcd.noDisplay();
            debugPrintLn("Screen powered down");
        }
    }
}