#include "SplashScreen.hpp"

RandomNoDupes rndSplash;

void splashScreen() {
    debugPrintLn("Splash screen loaded");
    brightness = 255;
    screenNumber = 0;
    timerOld = timer;
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("INSULTATRON 9000");
    lcd.setCursor(0, 1);

    char buffer[LCD_WIDTH + 1] = {'\0'};
    analogWrite(BACKLIGHT_PIN, brightness);
    lcd.display();

    for (uint8_t scrollCount = 0; scrollCount < 2; scrollCount++) {
        const char *progmemMessage;
        memcpy_P(&progmemMessage, &splashMessage_table[rndSplash.next(scrollCount)], sizeof(progmemMessage));
        uint8_t msgLength = strlen_P(progmemMessage);
        int8_t scrollPosition = -LCD_WIDTH;

        while (scrollPosition < msgLength + 1) {
            timer = millis();
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
