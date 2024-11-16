/*
  Arduino sketch that generates an insulting sentence and displays it on a character display.
*/

#include "main.hpp"

uint8_t screenNumber = 1;
uint8_t brightness = 0xFF;
uint32_t timer = 0;
uint32_t timerOld = 0;

LiquidCrystal lcd(LCD_RS, LCD_EN, LCD_D4, LCD_D5, LCD_D6, LCD_D7);
DebouncedButton btnInsult(BUTTON_PIN, 50, LOW);
RandomNoDupes rndSplash;

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

void splashScreen() {
    debugPrintLn("Splash screen loaded");
    brightness = 255;
    screenNumber = 0;              // Set the screen status variable to 0
    timerOld = timer;              // Store the current value of the timer variable in the timerOld variable
    lcd.clear();                   // Clear screen (sometimes it loads up with garbage)
    lcd.setCursor(0, 0);           // Set the cursor to row 0, column 0
    lcd.print("INSULTATRON 9000"); // Print splash text
    lcd.setCursor(0, 1);           // Set the cursor to row 1, column 0

    // Scroll buffer
    char buffer[17] = {'\0'};

    analogWrite(BACKLIGHT_PIN, brightness);
    lcd.display();

    for (uint8_t scrollCount = 0; scrollCount < 2; scrollCount++) {
        // Pointer to one of the progmem arrays that contain splash screen messages
        const char *progmemMessage;
        memcpy_P(&progmemMessage, &splashMessage_table[rndSplash.next(splashCount)], sizeof(progmemMessage));
        uint8_t msgLength = strlen_P(progmemMessage);
        int8_t scrollPosition = -LCD_WIDTH;
        while (scrollPosition < msgLength + 1) {
            timer = millis();
            //btnInsult.update();
            if (timer - timerOld >= scrollTick) {
                updateScrollBuffer(buffer, progmemMessage, scrollPosition, LCD_WIDTH);
                lcd.setCursor(0, 1);
                lcd.print(buffer);
                debugPrintLn(buffer);
                scrollPosition++;
                timerOld = timer;
            }
            if (btnInsult.wasPressed()) {
                insultMe();
                return;
            }
        }
    }
    debugPrintLn("Finished scrolling");
}

void copyMessageSubset(char *dest, const char *progmemMessage, uint8_t start, uint8_t length) {
    for (uint8_t i = 0; i < length; i++) {
        dest[i] = pgm_read_byte(progmemMessage + start + i);
    }
    dest[length] = '\0'; // Null-terminate the string
}

void updateScrollBuffer(char *buffer, const char *message, int scrollPosition, uint8_t bufferSize) {
    memset(buffer, ' ', bufferSize);
    buffer[bufferSize] = '\0';

    for (uint8_t bufferIndex = 0; bufferIndex < bufferSize; bufferIndex++) {
        int8_t msgIndex = scrollPosition + bufferIndex;
        if (msgIndex >= 0 && msgIndex < strlen_P(message)) {
            buffer[bufferIndex] = pgm_read_byte(&message[msgIndex]);
        }
        // No need for else clause since buffer is already filled with spaces
    }
}

uint8_t randomNoDupes(uint8_t lastRandom, uint8_t range) {
    if (range < 2) {
        // Handle the edge case where range is less than 2
        return !lastRandom;
    }
    uint8_t newRandom = random(range);
    if (newRandom != lastRandom) {
        return newRandom;
    }
    // Return the result of the recursive call
    return randomNoDupes(lastRandom, range);
}
